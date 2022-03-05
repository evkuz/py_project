from time import sleep
from iqrdevice.action import BaseAction
from ..utils import SerialCommunication, CameraDetector
import logging


class CatchCubeAction (BaseAction):
    def __init__(self, arduino_device:SerialCommunication, cam:CameraDetector):
        self.logger = logging.getLogger("CatchCubeAction")
        BaseAction.__init__(self, "catchcube")
        self.__manip = arduino_device
        self.__camera = cam
        self.__pixToDegreeX = 60.0 / self.__camera.FrameWidth
        self.__pixToDegreeY = 50.0 / self.__camera.FrameHeight
        self.__pixToDegreeZ = 0.015

    def get_info(self) -> dict:
        return self.make_info(
            "Will try to catch cube with robot"
        )

    def run_action(self, **kwargs) -> int:
        res = 0
        tp_state = 0
        detectedSteps = 0
        notDetectedSteps = 0
        currentPos, dist = self.__manip.get_position()

        while self._workingFlag:
            if tp_state == 0:
                detected, x, y, w, h = self.__camera.get_position()
                if detected:
                    errZ = 0.7*self.__camera.FrameWidth - w
                    errX = x - self.__camera.FrameWidth / 2
                    errY = y - self.__camera.FrameHeight / 2

                    newPos = self.calc_next_position([errX,errY,errZ], currentPos)
                    currentPos, dist = self.move_manip(newPos)
                    
                    detectedSteps += 1
                    notDetectedSteps = 0
                else:
                    notDetectedSteps += 1
                if dist < 4:
                    currentPos[3] = 100
                    _ = self.move_manip(currentPos)
                    tp_state+=1
                if detectedSteps > 100 or notDetectedSteps > 200:
                    self._set_state_info("Can't get cube for too long!")
                    res = -10
                    _ = self.__manip.move_home(80)
                    break
            if tp_state == 1:
                pos = [
                    currentPos[0],
                    currentPos[1] + 20,
                    currentPos[2] + 10,
                    100
                ]
                _ = self.move_manip(pos)

                pos = [currentPos[0], 120, 60, 30]
                _ = self.move_manip(pos)
                break
        return res

    def reset_action(self) -> int:
        self.__manip.stop_moving()
        self.__manip.move_home(80, True)
        self._set_state_info(f"Stopped and returned home")
        return -126

    def move_manip(self, pos:list):
        self.__manip.move(pos, 80, True)
        pos, dist = self.__manip.get_position()
        self._set_state_info(f"Current position: ({pos})")
        return pos, dist

    def calc_next_position(self, objPos:list, manipPos:list):
        self.logger.info(f"Errors: {objPos}" )
        self.logger.info(f"CUR_POS: {manipPos}")

        newPos = [
            int(manipPos[0] - 0.2*(self.__pixToDegreeX * objPos[0])),
            int(manipPos[1] - 0.2*(self.__pixToDegreeY*objPos[1] + self.__pixToDegreeZ*objPos[2])),
            int(manipPos[2] - 0.3*(self.__pixToDegreeY*objPos[1] - self.__pixToDegreeZ*objPos[2])),
            180
        ]
        self.logger.info(f"NEW_POS: {newPos}")
        return newPos
