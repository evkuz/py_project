#include <QObject>
#include "hiwonder.h"
#include <QDataStream>
#include <QTextStream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <QSerialPort>
#include <QSerialPortInfo>


//HiWonder::HiWonder(QObject *parent) : QObject(parent)
HiWonder::HiWonder()
{
    // Инициализируем буфер данными QByteArray
    memset(byInputBuffer, 0xEE, robot_buffer_SIZE); //sizeof(byInputBuffer)
    MOVEMENT_DONE = true;
    SerialIsOpened = false;
    qbuf.resize (robot_buffer_SIZE);
    memset(outputData, 0xDD, szData); //Инициализация массива с данными для отправки
   // this->SetCurrentStatus ("wait");
    current_st_index = 0;
    this->current_status = statuslst.at(current_st_index); // "init" state //"Ready";

    // Инициализируем все экшены
    getbox_Action.name = "get_box";
    getbox_Action.rc = -4;
    getbox_Action.info = "waiting";

    parking_Action.name = "parking";
    parking_Action.rc = -4;
    parking_Action.info = "waiting";

    ready_Action.name = "ready";
    ready_Action.rc = -4;
    ready_Action.info = "waiting";

    forMoving_Action.name = "formoving";
    forMoving_Action.rc = -4;
    forMoving_Action.info = "waiting"; //Get ready for moving accross

    putbox_Action.name = "put_box";
    putbox_Action.rc = -4;
    putbox_Action.info = "waiting";

  //  STAT_getbox_Action = {"MOBMAN", 0, "Action is accepted", "init", };

  //  ActionState putbox_Action {"put_box", -4, "waiting"};

    ManipulatorState.action = "Nothhing";
    ManipulatorState.state = statuslst.at(0); // "init" state
    active_command = "nothing"; //this->actionlst.at(1); // "nothing"

}
//+++++++++++++++++
HiWonder::~HiWonder()
{
    LogFile.close();
    }
//++++++++++++++++++++++++++++++
void HiWonder::Log_File_Open(QString lname)
{
    LogFile.setFileName(lname);
    LogFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
}
//+++++++++++++++++++++
// ОТкрытие файла для записи координат и углов. Для ускорения процесса набора тестовых точек
void HiWonder::Source_Points_File_Open(QString fname)
{
    SourceFile.setFileName(fname);         //QIODevice::Truncate
    SourceFile.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text);

}
//++++++++++++++++++++++++++++++
void HiWonder::Write_To_Log (int value, QString log_message)
{
    QDateTime curdate ;
    QTextStream uin(&LogFile);

    QString str, str2;
    //int value = 0xf000;
    curdate = QDateTime::currentDateTime();

    str = curdate.toString("yyyy-MM-dd__hh:mm:ss:z").toLocal8Bit(); str.append(" > ");
    str2 = QString("0x%1: ").arg(value, 4, 16, QChar('0'));

    uin << str << str2 << log_message << "\n";

}
//++++++++++++++++++++++++++++
void HiWonder::Write_To_Source(int value, QString points_data)
{
    QDateTime curdate ;
    QTextStream uin(&SourceFile);

    QString str, str2;
    //int value = 0xf000;
    curdate = QDateTime::currentDateTime();
    str = QString::number(value); // Убрать варнинг о неиспользуемом value

    //str = curdate.toString("yyyy-MM-dd__hh:mm:ss:z").toLocal8Bit(); str.append(" > ");
   // str = "X, Y";
    //str2 = QString("0x%1: ").arg(value, 4, 16, QChar('0'));

    uin << points_data << "\n";


}
//++++++++++++++++ REMEMBER WHILE OPENING PORT !!!!!
/*
 * Для работы arduino-плат через com-порт dialout, добавляемся в группу
 * sudo usermod -a -G dialout <username>

where <username> is your Linux user name. You will need to log out and log in again for this change to take effect.

*/
//+++++++++++ Open Serial port
void HiWonder::Open_Port_Slot(QString portname)

{
    bool OK;
    int serial_error;
    QString stt;

    serial.setPortName(portname); //portname == "ttyUSB0"
    OK = true;
    serial_error = 777;
   // OK = serial.open(QIODevice::ReadWrite);
    if (!serial.open(QIODevice::ReadWrite))
    {
        OK = false; serial_error = serial.error();
        this->Write_To_Log(0xFF00, "Error opening Serial port !!!");
        SerialIsOpened = false;
        stt = "Error code is ";
        stt += QString::number (serial_error);
        if (serial_error == 1) { stt += " - Device NOT found.";}
        this->Write_To_Log(0xFF00,stt);

        return;
       //Тут запускаем таймер и открываем порт в таймере

    } //"Error opening Serial port !!!");}

    SerialIsOpened = true;
    // https://www.linuxhowtos.org/data/6/perror.txt
//    if (!serial.open(QIODevice::ReadWrite)) {
//        processError(tr("Can't open %1, error code %2")
//                     .arg(serial.portName()).arg()));


    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    QString str = "Serial port "; str += portname; str += " is opened";
    if (OK) this->Write_To_Log(0xFF00, str);

}
//++++++++++++++++++++++
// Задаем роботу углы для нужной позиции - отправляем данные для углов в Serial port
void HiWonder::GoToPosition(QByteArray &position)//, const char *servo)
{
   QString str;
   int value = 0xF002;
   this->MOVEMENT_DONE = false;

   if (!SerialIsOpened) {str = "WARNING !!!! Serial port is NOT opened ! The data has NOT been sent."; this->Write_To_Log(0xF001, str); return;}
   position.resize (szData);
   serial.write(position);
   serial.waitForBytesWritten();

//    void *const tmp = const_cast<char*>(servo);
//    unsigned char* sData = static_cast<unsigned char*>(tmp);
   //unsigned char sData [7]= {0,0,0,0,0,0,0};
   memcpy(&outputData, position,szData);
// Данные роботу отправили, теперь запись в лог об этом

    str = "To Robot: ";
    for (int i=0; i< szData; i++){
    //    str += QString::number(sData[i]);
        //str+= QString::number(position.at(i));
        str+= QString::number(outputData[i]);
        str+= ", ";

    }
    this->Write_To_Log(value, str);

}
//+++++++++++++++++++++++++++++++
// Слот сигнала &QSerialPort::readyRead
// Считываем данные из Serial port, т.е. от робота.  code From Robot :
void HiWonder::ReadFromSerial_Slot ()
{
    QString str;
    int value = 0xF001;
    qint64 numBytes;
        numBytes = serial.bytesAvailable ();

        str = "There are "; //
        str += QString::number (numBytes);
        str += " bytes from robot to read";
        this->Write_To_Log(value, str);

        qbuf = serial.readAll();
        str = "From Robot : ";
        str += QString(qbuf);
        this->Write_To_Log(value, str);
        // И вот теперь надо вводить флаг проверки текста сообщения на предмет наличия "DONE"

        std::cout<<"From Serial:" << str.toStdString ()<< std::endl;
        QStringList list_str = str.split(QLatin1Char(' '), Qt::SkipEmptyParts);
//        for (int i=0; i< list_str.size (); i++){
//            this->Write_To_Log(value, list_str.at (i));
//            str = list_str.at (i);
//            if ( str == "DONE!"){this->MOVEMENT_DONE = true;}

//        }
        str="DONE!";
        if (list_str.contains (str)) {this->MOVEMENT_DONE = true; this->Write_To_Log(value, "Robot finished"); }
        else this->Write_To_Log(value, "Robot still running");


        str="LAST";
        if (list_str.contains (str)) {
            this->MOVEMENT_DONE = true;
            this->Write_To_Log(value, "Robot finished complex command");
            this->current_status = "done";
            emit this->Moving_Done_Signal();
        }

//   if (this->MOVEMENT_DONE) this->Write_To_Log(value, "Robot finished");
//

}
//++++++++++++++++++++++++
void HiWonder::SetCurrentStatus(QString newStatus) {
    this->current_status = newStatus;
//    emit this->StatusChangedSignal(newStatus);

}
