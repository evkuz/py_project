from time import sleep
from iqrdevice.action import BaseAction
from ..utils import SerialCommunication
from . import GRIP_CLOSED, GRIP_OPENED


class PutCubeAction (BaseAction):
    def __init__(self, arduino_device:SerialCommunication):
        BaseAction.__init__(self, "putcube")
        self.__manip = arduino_device

    def get_info(self) -> dict:
        return self.make_info(
            "Will put cube to predefined position"
        )

    def run_action(self, **kwargs) -> int:
        res = 0
        if self._workingFlag:
            _ = self.move_manip([180, 150, 30, 90, GRIP_CLOSED])
        if self._workingFlag:
            _ = self.move_manip([180, 130, 45, 90, GRIP_CLOSED])
        if self._workingFlag:
            _ = self.move_manip([180, 130, 45, 90, GRIP_OPENED])
        if self._workingFlag:
            _ = self.move_manip([180, 150, 30, 90, GRIP_OPENED])
        if self._workingFlag:
            _ = self.move_manip([91, 120, 60, 90, GRIP_OPENED])
        if self._workingFlag:
            self.__manip.move_home()
            pos, dist = self.__manip.get_position()
            self._set_state_info(f"Current position: ({pos})")
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