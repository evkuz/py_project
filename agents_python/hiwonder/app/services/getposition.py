from iqrdevice.services import BaseService
from .. import device
from iqrdevice.utils.vision import OpenCVCamera, SimpleDetector
from math import atan2, pi


class CamDetectorService(BaseService):
    def __init__(self, cam:OpenCVCamera, detector:SimpleDetector):
        BaseService.__init__(self, "getposition")
        self.__cam = cam
        self.__detector = detector
    
    def get_info(self) -> dict:
        return self.make_info(
            "Returns detection state and position of cube"
        )

    def get_data(self, **kwargs):
        try:
            self.__cam.wait_for_new_frame()
            frame = self.__cam.get_last_frame()
            det_res = self.__detector.detect(frame)
            res = {
                "detected": det_res['detected'],
            }
            if 'x' in det_res:
                res['x'] = det_res['x']
                res['y'] = det_res['y']
                res['width'] = det_res['width']
                res['height'] = det_res['height']
                res['area'] = det_res['width'] * det_res['height']
                res['aspect_ratio'] = det_res['width'] / det_res['height']

        except Exception as e:
            res = str(e)

        return res
