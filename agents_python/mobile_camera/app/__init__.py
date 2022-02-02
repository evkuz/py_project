import sys
import pathlib
module_path = pathlib.Path(__file__).parent.parent.parent.resolve()
sys.path.append(str(module_path))

import os
from iqrdevice import device, app

# создание экземпляра приложения
app.config.from_object(os.environ.get('FLASK_ENV') or 'config.DevelopementConfig')

from . import utils
cam = utils.CameraDetector(app.config['CAMERA_NUM'])

# import views
from . import views

# import robot features
from . import actions
from . import services

device.set_name("mobile camera")
getPositionService = services.CamDetectorService(cam)
device.register_service(getPositionService)
device.register_action(actions.MoveToTakeCube("http://192.168.1.80:8082", getPositionService))
