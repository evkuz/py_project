import sys
import pathlib
module_path = pathlib.Path(__file__).parent.parent.parent.resolve()
sys.path.append(str(module_path))

import os
from iqrdevice import device, app

# создание экземпляра приложения
app.config.from_object(os.environ.get('FLASK_ENV') or 'config.DevelopementConfig')

from .camera import CameraDetector
cam = CameraDetector(app.config['CAMERA_NUM'])

# import views
from . import views
from . import actions
from . import services

device.set_name("mobile camera")
device.register_service(services.CamDetectorService(cam))
