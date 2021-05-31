from PyQt5 import QtWidgets, uic
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
from PyQt5.QtCore import QIODevice, QByteArray
# from PySide2.QtCore import QByteArray

import time

# /*Координаты начальной/стартовой позиции*/
hwr_Start_position = [93, 93, 93, 93, 93, 93]  # ; // servo1,,,servo6
sit_down_position = [93, 93, 93, 48, 48, 93]  # ; // Поза сидя. Сдвинуты 4,5 приводы (относительно 93)

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
    if not serial.canReadLine(): return  # выходим если нечего читать
    rx = serial.readLine()
    rxs = str(rx, 'utf-8').strip()  # Данные в бинарном виде.
    # data = rxs.split(',')
    print(rx)


def onOpen():
    # print("Done !")
    serial.setPortName(ui.comL.currentText())
    serial.open(QIODevice.ReadWrite)


def onClose():
    serial.close()


def onClamp():
    GoToPosition(sit_down_position)
    time.sleep(3)
    GoToPosition(hwr_Start_position)


# def prepare_data():
#     for i in range(0, 6):
#         serialData[i] = int(linedits[i].text())


def SerialSend(data):  # список инт
    global cameFrom
    txs = ""
    for val in data:
        txs += str(val)
        txs += ','
    txs = txs[:-1]
    txs += ';'
    # txs = ','.join(str(data)) + ';'
    print(txs)
    # serial.write(txs.encode())
    dd = bytes(data)
    qbdata = QByteArray(QByteArray.fromRawData(dd))
    # serial.clear()
    tx = serial.writeData(qbdata)


def GoToPosition(pos):
    # for i in range(0, 6):
    #     linedits[i].setText(str(pos[i]))  # Делаем захват, т.е. чуть опускаемся и закрываем захват
    for i in range(0, 6):
        serialData[i] = pos[i]

    SerialSend(serialData)  # make catch_box


serial.readyRead.connect(onRead)
ui.openButton.clicked.connect(onOpen)
ui.closeButton.clicked.connect(onClose)
ui.clampButton.clicked.connect(onClamp)

serialData = [93, 93, 93, 93, 93, 93]

ui.show()
app.exec()
