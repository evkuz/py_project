import sys
import pathlib
module_path = pathlib.Path(__file__).parent.parent.parent.resolve()
sys.path.append(str(module_path))

import os
from iqrdevice import device, app

# создание экземпляра приложения
app.config.from_object(os.environ.get('FLASK_ENV') or 'config.DevelopementConfig')

from . import utils
rosrun = utils.RosRun("rosrun.sh", "rosrunkill.sh")
mvrasp = utils.RunMVRasp()

# import views
from . import views

# import robot features
from . import actions
from . import services

device.set_name("Mobman move")

device.register_action(actions.MoveToAAction())
device.register_action(actions.MoveToBAction())

device.register_service(services.StopRosRunService(rosrun))
device.register_service(services.StartRosRunService(rosrun))

device.register_service(services.StartMVRaspService(mvrasp))
device.register_service(services.StopMVRaspService(mvrasp))

#rosrun.run()
#mvrasp.run()
