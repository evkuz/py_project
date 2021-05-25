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
    if not serial.canReadLine(): return  # выходим если нечего читать
    rx = serial.readLine()
    rxs = str(rx, 'utf-8').strip()  # Данные в бинарном виде.
    data = rxs.split(',')
    print(rx)


def onOpen():
    # print("Done !")
    serial.setPortName(ui.comL.currentText())
    serial.open(QIODevice.ReadWrite)


def onClose():
    serial.close()


def onClamp():
    # data = [0x55, 0x22]
    # tx = str(data)
    # data = "A"
    data = "93 93 93 45 45 93"
    SerialSend(data.encode())


def SerialSend(data):  # список инт
    txs = ""
    for val in data:
        txs += str(val)
        txs += ','
    txs = txs[:-1]
    txs += ';'
    print(txs)
    serial.write(txs.encode())

    # tx = serial.write(data)


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

linedits = [ui.servo_1_lineEdit, ui.servo_2_lineEdit, ui.servo_3_lineEdit, ui.servo_4_lineEdit,
            ui.servo_5_lineEdit, ui.servo_6_lineEdit]
# linedits.append(ui.servo_1_lineEdit)
# linedits.append(ui.servo_2_lineEdit)
# linedits.append(ui.servo_3_lineEdit)
# linedits.append(ui.servo_4_lineEdit)
# linedits.append(ui.servo_5_lineEdit)
# linedits.append(ui.servo_6_lineEdit)

# serialData = []
# serialData.append(int(ui.servo_1_lineEdit.text()))
# serialData.append(int(ui.servo_2_lineEdit.text()))
# serialData.append(int(ui.servo_3_lineEdit.text()))
# serialData.append(int(ui.servo_4_lineEdit.text()))
# serialData.append(int(ui.servo_5_lineEdit.text()))
# serialData.append(int(ui.servo_6_lineEdit.text()))

# Создаем массив данных
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
