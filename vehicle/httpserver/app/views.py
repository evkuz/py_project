from app import app
from flask import render_template, request, jsonify
from flask.wrappers import Response
import cv2
from .camera import Camera
from . import robot_api

activeCamera = Camera(app.config['CAMERA_NUM'])
robotApi = robot_api.RobotApi()

def gen(camera):
    while True:
        frame = camera.get_frame()
        (flag, encodedImage) = cv2.imencode(".jpeg", frame)
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + encodedImage.tobytes() + b'\r\n')


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/video_feed')
def video_feed():
    return Response(
        gen(activeCamera),
        mimetype='multipart/x-mixed-replace; boundary=frame'
    )


@app.route('/run', methods=['get'])
def run():
    args = request.args.to_dict()
    cmd = args.get("cmd")
    if cmd is not None:
        if cmd == "start":
            robotApi.move_robot(cmd)
        elif cmd == "reset":
            robotApi.reset()

    return jsonify(robotApi.status.__dict__)
