from PyQt5 import QtWidgets, uic


app = QtWidgets.QApplication([])
ui = uic.loadUi("form.ui")
ui.setWindowTitle("SerialGUI")

ui.show()
app.exec()
