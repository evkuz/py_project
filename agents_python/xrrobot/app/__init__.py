import sys
import pathlib
module_path = pathlib.Path(__file__).parent.parent.parent.resolve()
sys.path.append(str(module_path))

import os
from iqrdevice import device, app

# создание экземпляра приложения
app.config.from_object(os.environ.get('FLASK_ENV') or 'config.DevelopementConfig')

# import views
from . import views

# import robot features
from . import actions
from . import services

device.set_name("Mobman move")
device.register_action(actions.MoveToAAction())
device.register_action(actions.MoveToBAction())
