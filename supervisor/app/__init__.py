from flask import Flask
import os, config

# создание экземпляра приложения
app = Flask(
    __name__,
    static_url_path='',
    static_folder='static',
    template_folder='templates'
)

app.config.from_object(os.environ.get('FLASK_ENV') or 'config.DevelopementConfig')

# import views
from . import views
# from . import forum_views
# from . import admin_views