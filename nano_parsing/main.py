# This is a sample Python script.
from PyQt5 import QtWidgets, uic
from PyQt5.QtSerialPort import QSerialPort, QSerialPortInfo
from PyQt5.QtCore import QIODevice # , QByteArray
from PySide2.QtCore import QByteArray
import sys

import time


# /*Координаты начальной/стартовой позиции*/
hwr_Start_position = [93, 93, 93, 93, 93, 93]  # ; // servo1,,,servo6
sit_down_position = [93, 93, 93, 48, 48, 93]   # ; // Поза сидя. Сдвинуты 4,5 приводы (относительно 93)
horse_position = [93, 93, 0, 48, 48, 93]       # ;
horse_mirror_position = [45, 93, 180, 135, 135, 93]  # ;
ready_to_catch = [93, 93, 2, 15, 110, 93]            # ;
catch_box = [80, 93, 7, 10, 120, 93]                 # ;
opposite_catch = [93, 93, 180, 125, 40, 60]

#wrong_position = [93, 93, 2, 0, 10, 120]
wrong_position = [30, 30, 30, 30, 30, 30]

# b'From robot after get_all_servo  :  120, 93, 7, 10, 120, 93, \r\n'
# b'From robot after get_all_servo  :  93, 93, 2, 0, 10, 120, \r\n'

# 93, 93, 2, 15, 110, 93
# 93, 93, 93, 93, 93, 93


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


# Считываем данные из lineEdit в serialData
def prepare_data():
    for i in range(0, 6):
        serialData[i] = int(linedits[i].text())


def print_data_2_send():
    message = "Current data for Robot : "
    for i in range(0, 6):
        message += str(serialData[i])
        message += ", "
    print(message)




def onClamp():
    data = [45, 93, 93, 93, 93, 93]
    # tx = str(data)
    # data = "A"
    # data = [93, 93, 93, 45, 45, 93]
    # for i in range(0, 6):
        # linedits[i].setText(str(data[i]))
    linedits[0].setText("45")
    serialData[0] = int(linedits[0].text())
    SerialSend(data)


def onStandUP():
    # data = [0x55, 0x22]
    # tx = str(data)
    # data = "A"
    data = [93, 93, 93, 93, 93, 93]
    for i in range(0, 6):
        linedits[i].setText(str(data[i]))
    # SerialSend(data)


def onGetBox():
    for i in range(0, 6):
        linedits[i].setText(str(ready_to_catch[i]))
    prepare_data()
    SerialSend(serialData)  # Go to down position
    # Надо дождаться выполнения
    # wait for robot finish
    release_clamp() # Захват открывается одновременно с движением робота.
    for i in range(0, 6):
        linedits[i].setText(str(catch_box[i]))
    prepare_data()
    SerialSend(serialData) # make catch_box

    for i in range(0, 6):
        linedits[i].setText(str(ready_to_catch[i]))
    prepare_data()
    SerialSend(serialData)
    for i in range(0, 6):
        linedits[i].setText(str(hwr_Start_position[i]))
    prepare_data()
    print_data_2_send()
    SerialSend(serialData)



# Копируем фикс. данные позиции в текстровые окна
def onSitPosition():  # sit_down_position
    for i in range(0, 6):
        linedits[i].setText(str(sit_down_position[i]))
    for i in range(0, 6):
        serialData[i] = int(linedits[i].text())
    SerialSend(serialData)


def release_clamp():
    linedits[0].setText("45")
    prepare_data()
    SerialSend(serialData)


def onSetPosition():
    for i in range(0, 6):
        serialData[i] = int(linedits[i].text())
        # print(serialData[i])
    SerialSend(serialData)


def SerialSend(data):  # список инт
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
    tx = serial.writeData(qbdata)


# Обработка сигнала textChanged
# def S1_data_changed():
#    txs = ui.servo_1_lineEdit.text()
#   print(txs)


# Обработка сигнала editingFinished
def S1_data_changed():
    txs = ui.servo_1_lineEdit.text()
    print(txs)


def S2_data_changed():
    txs = ui.servo_2_lineEdit.text()
    print(txs)


def S3_data_changed():
    txs = ui.servo_3_lineEdit.text()
    print(txs)


def S4_data_changed():
    txs = ui.servo_4_lineEdit.text()
    print(txs)


def S5_data_changed():
    txs = ui.servo_5_lineEdit.text()
    print(txs)


def S6_data_changed():
    txs = ui.servo_6_lineEdit.text()
    print(txs)


# Добавляем данные из LineEdit в sData для отправки роботу
def onSerial_getData(sData):
    # Собираем данные из servo_[1-6]_lineEdit, кладем их в массив
    # Это и будет точка взятия данных для нейронной сети

    for i in range(0 - 6):
        sData[i] = linedits[i].text()

    return sData


serial.readyRead.connect(onRead)
ui.openButton.clicked.connect(onOpen)
ui.closeButton.clicked.connect(onClose)
ui.clampButton.clicked.connect(onClamp)
ui.stand_upButton.clicked.connect(onStandUP)
ui.set_posButton.clicked.connect(onSetPosition)
ui.sitButton.clicked.connect(onSitPosition)
ui.getBoxButton.clicked.connect(onGetBox)

linedits = [ui.servo_1_lineEdit, ui.servo_2_lineEdit, ui.servo_3_lineEdit, ui.servo_4_lineEdit,
            ui.servo_5_lineEdit, ui.servo_6_lineEdit]

# Создаем массив данных для   ОТПРАВКИ в порт
serialData = [int(ui.servo_1_lineEdit.text()), int(ui.servo_2_lineEdit.text()), int(ui.servo_3_lineEdit.text()),
              int(ui.servo_4_lineEdit.text()), int(ui.servo_5_lineEdit.text()), int(ui.servo_6_lineEdit.text())]

# А этот сигнал эмитируется каждый раз, когда в этом поле что-то меняется. т,е. если вводим 3 цифрцы, то среагирует
# 3 раза.
# ui.servo_1_lineEdit.textChanged.connect(S1_data_changed)

# Так лучше, т.к. сигнал срабатывает, когда уже фокус покинул это поле. Вместо реагирования на изменение
# Каждой цифры, которая вводится в этом поле.

ui.servo_1_lineEdit.editingFinished.connect(S1_data_changed)
ui.servo_2_lineEdit.editingFinished.connect(S2_data_changed)
ui.servo_3_lineEdit.editingFinished.connect(S3_data_changed)
ui.servo_4_lineEdit.editingFinished.connect(S4_data_changed)
ui.servo_5_lineEdit.editingFinished.connect(S5_data_changed)
ui.servo_6_lineEdit.editingFinished.connect(S6_data_changed)

ui.show()
app.exec()

# def print_hi(name):
# Use a breakpoint in the code line below to debug your script.
#    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
# if __name__ == '__main__':
#    print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
