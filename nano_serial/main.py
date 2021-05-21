# This is a sample Python script.
from PyQt5 import QtWidgets, uic
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
from PyQt5.QtCore import QIODevice

app = QtWidgets.QApplication([])
ui = uic.loadUi("form.ui")
ui.setWindowTitle("SerialGUI")

serial = QSerialPort()
serial.setBaudRate(115200)
portList = []
ports = QSerialPortInfo().availablePorts()
for port in ports:
    portList.append(port.portName())
# print(portList)
ui.comL.addItems(portList)


def onRead():
    # if not serial.canReadLine(): return     # выходим если нечего читать
    rx = serial.readLine()
   # rxs = str(rx, 'utf-8').strip() # Данные в бинарном виде.
    print(rx)


def onOpen():
    # print("Done !")
    serial.setPortName(ui.comL.currentText())
    serial.open(QIODevice.ReadWrite)


def onClose():
    serial.close()


def onClamp():
    #data = [0x55, 0x22]
    #tx = str(data)
    data = "A"
    SerialSend(data.encode())


def SerialSend(data):   # список инт
    tx = serial.write(data)


serial.readyRead.connect(onRead)
ui.openButton.clicked.connect(onOpen)
ui.closeButton.clicked.connect(onClose)
ui.clampButton.clicked.connect(onClamp)


ui.show()
app.exec()

# def print_hi(name):
# Use a breakpoint in the code line below to debug your script.
#    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
# if __name__ == '__main__':
#    print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
