/*
 *
 * В GUI-версии это класс MainWindow, или класс основного потока, поэтому в текущей, консольной версии - класс MainProcess
 *
*/

#ifndef MainProcess_H
#define MainProcess_H

#include <QtCore>
#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <stdint.h>
#include <QFile>
#include <QList>
#include <QDateTime>
#include <QTime>
#include "serialRobot.h"  // SerialRobot class
#include "manipulator/qsimpleserver.h"
#include "jsoninfo.h"
//#include "ProcessAction.h"

#include "cvdevice.h"
#include "protocol.h"

#include "clientsocket.h"

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <QMutex>
#include <QMutexLocker>
#include <QRecursiveMutex>


//#include "SocketClient.h"
//#include "jsoncpp/json/json.h"
//#include "${EXTLIBS}/nlohmann/json.hpp"
#include "nlohmann/json.hpp"
//#include <QJsonObject>
//#include <QJsonDocument>


#include <QTcpSocket>
#include <QDataStream>

#include <QSharedPointer>
#include <QMetaObject>


//QT_BEGIN_NAMESPACE
//namespace Ui { class MainProcess; }
//QT_END_NAMESPACE


//
//using json = nlohmann::json;
using ordered_json = nlohmann::ordered_json;

class MainProcess : public QObject
{
    Q_OBJECT

public:
    MainProcess(QObject *parent = nullptr);
    //MainProcess();
    ~MainProcess();
    QSerialPort serial;
    QByteArray *buff;

    QString     target_name;
    //char       *servos;    //unsigned char
    QByteArray LineEdits[6];

    SerialRobot *Robot;
//    Robo_Math * RMath;


    bool new_get_request; // Флаг сигнализирует, что есть неотвеченный GET-запрос от webserver.
    //QTcpServer* m_pTCPServer;

//    QSimpleServer server;
    QTcpSocket *socketCV;
    CVDevice *CVdevice;
    QThread *threadCV;

    //+++++++++++++++++++++++++++++ Threads +++++++++++++++
    int thread_counter ;

    QString rAnswer; // Ответ робота - статус, return_code, etc

    ordered_json jsnStatus; // Ответ на запрос статуса в формате json
    ordered_json jsnAction;  // Ответ на команду Action в формате json
    ordered_json jsnGetServicesAnswer; // Ответ на команду "/service?name=getservices"
    ordered_json jsnGetActionsAnswer; // Ответ на команду "/service?name=getactions"


    QJsonDocument jsnDoc;    // json-данные, полученные по tcp
    QJsonObject   jsnObj;    // ОБъект, хранящий весь JSON ответ от девайса
    QJsonObject   jsndataObj;// ОБъект, хранящий вложенный JSON-объект (вложенный внутри ответа jsnObj)
                             //   Тут как раз данные о distance
    QJsonObject   jsnActionAnswer; // Ответ на команду Action в формате json
    QJsonObject   jsnStatusActionAnswer; // Ответ на команду "status?action=getbox" в формате json

    //QJsonObject   jsnGetServicesAnswer; // Ответ на команду "/service?name=service_name"

    QJsonParseError jsonError; // ОШибка, если полученные данные - не JSON-объект
    JsonInfo    *jsnStore;
    // Важно ! Меняем значение mainjsnObj только, если экшен означает движение манипулятора. для остальных есть tempObj
    // Значение mainjsnObj используется после завершения опреаций для сервоприводов в слоте Moving_Done_Slot
    // В многопоточном режиме значение mainjsnObj не меняется, пока не завершится текущая операция.
    // ЗА этим следит переменная JsonInfo::isAnyActionRunning
    QJsonObject mainjsnObj; // temporal Текущий экшен, нужно т.к. при большой скорости опроса это значение постоянно меняется


    QJsonObject quickAnswerObj; // Ответ на запуск экшена

 //   QSharedPointer<QJsonObject> pJsnObject; //

//#define
// Актуально для разных размеров кубика
#define FULL_CLOSED 87 //75
#define FULL_OPENED 35

//static constexpr int AC = 25;
#define DOF 4     // mobman

#define FORWARD     0X31 //049
#define BACKWARD    0X30 //048
#define NOT_LAST    0xC8 //200  // Не последняя команда
#define LASTONE     0xDE //222  // Последняя команда роботу при комплексном движении
#define BEFORE_LAST 0xE9 //233  // Предпоследняя команда - положить кубик на тележку.
#define AFTER_PUT   0xF4 //244  Кубик на тележку положили, теперь грамотно убираем манипулятор.

#define MOBMAN_LOG "./mobman.log"
//++++++++++++++++++++++ JSON data +++++++++++++++++++++++++++++++++++++++++++++

#define DEVICE_NAME "MOBMAN"   // device name - mobile manipulator
#define RC_SUCCESS 0        // запрос выполнен успешно
#define RC_WRONG_VALUE -1   // неверные параметры
#define RC_UNDEFINED -2     // action с таким именем не найден
#define RC_FAIL      -3     // Ошибка самого манипулятора, не открыт serial port

#define AC_RUNNING 0        // action запущен
#define AC_WRONG_VALUE -1   // action с таким именем не найден
#define AC_FAILURE -2       // action с таким именем не запустился
#define AC_ALREADY_HAVE -3  // action с таким именем уже запущен


//+++++++++++++++++++++ CV device

#define CVDev_IP     "192.168.1.201"//"192.168.1.201"
#define CVDev_Port   5001
#define ARMDev_IP    CVDev_IP
#define ARMDev_Port  8383


    QString currentTcpdata; //Нужно, чтоб была глобальная.
    QDataStream in; // НА считывание данных из сокета CV

    //int parcel_size; // размер посылки в байтах от ПК к роботу

    int X, Y;//Координаты x,y
    bool DETECTED; // Флаг, показывающий, сработал ли захват изображения.

    int parcel_size ;
    unsigned char Servos [DOF] = {FULL_OPENED,90,57,180};//==formoving position //{93,93,93,93};
    QMutex mutex, mutex02;
    //QRecursiveMutex mutex, mutex02;
    int tcpSocketNumber; //Номер сокета, от которого пришёл запрос, и которому потом отправим ответ
    int currentCommandIndex; // Индекс выполняемой в данный момент команды в списке tcpCommand
                             // Только для команд, выполняемых манипулятором, чтобы отличать от прочих.

    QFile mobWebLogFile;

    unsigned int CVDistance;

    //void update_data_from_sliders(int index, int value);

    Q_INVOKABLE void GUI_Write_To_Log (int value, QString log_message); //Пишет в лог-файл номер ошибки value и сообщение message
    void Servos_To_Log(QString message);
    void try_mcinfer(int x, int y);
    void update_Servos_from_position(unsigned char *pos);

    void send_Data(unsigned char thelast);
    void make_json_answer();   // подготовка json-строки с полями ответа в TCP сокет.
    void init_json();
    void request_CV();
    void request_New_CV();
     int my_round(int n); // Округление целого числа до ближайшего кратного 10

    void traversJson(QJsonObject json_obj); // Рекурсивный Парсинг JSON
    double parseJSON(QString jsnData); // Парсинг JSON из HTTP

    int getIndexCommand(QString myCommand, QList<QString> theList);
    void ProcessAction(int indexOfCommand, QJsonObject &theObj); // Отрабатывает команду по заданному индексу из списка QList<QString> theList
    void LogFile_Open (QString fname);

    struct CV_Answer {
        double distance; // distance to Object calculated by CV
        bool   detected; // is there valid object detection ?
    };

    CV_Answer cvAnswer;
    QString pointer_to_qstring(void *ptr);
    void returnActionLaunch(QJsonObject &theObj, QObject *theSender);
    Q_INVOKABLE void StatusRequest_From_TcpClient(QObject* theSender);
    Q_INVOKABLE void ActionLaunch_From_TcpClient(QObject* theSender, QString actionName);
    Q_INVOKABLE void ServiceLaunch_From_TcpClient(QObject *theSender, QString serviceName);

private:
//    SocketClient readSocket;
    QObject *ptrTcpClient;   // Указатель на объект, приславший команду от Tcp-клиента
    QObject *newPtrTcpClient;
public slots:
    void Data_From_Web_SLot(QString message);
    Q_INVOKABLE void Data_From_TcpClient_Slot(QString message, int socketNumber, QObject* theSender);

//    void Data_from_TcpServer_Slot(QString tcpData);

    void newConnection_Slot();
    void server_New_Connect_Slot();

    void onSocketConnected_Slot(); // Слот обработки сигнала void QAbstractSocket::connected()
    void CV_onReadyRead_Slot();    // Слот обработка сигнала readyRead()
    void CV_onDisconnected();      // Слот обработки сигнала
    void CV_NEW_onReadyRead_Slot();    // Слот обработка сигнала readyRead() включая парсинг JSON
//    void GetBox(unsigned int distance); // Запускаем захват кубика по значению расстояния до него от камеры.
    void GetBox(double distance); // Запускаем захват кубика по значению расстояния до него от камеры.


void data_from_CVDevice_Slot(QString); // class CVDevice - слот обработки сигнала data_from_CVDevice_Signal(QString);

private slots:
    //void on_openButton_clicked();

    void on_sitButton_clicked();

    void on_stand_upButton_clicked();

    void on_closeButton_clicked();


    void on_set_posButton_clicked();


//    void on_socketButton_clicked();

    void on_clampButton_clicked();



    void on_getXYButton_clicked();
    void Return_EL_Slot(float EL);
    void Return_FW_Kinematic_XYZ_Slot(int X, int Y, int Z, float EL);
    void Pass_String_Slot(QString str);

//    void on_submitButton_clicked();

    void on_trainButton_clicked();
    void Moving_Done_Slot(); // ОБработка сигнала окончания движения


    //void TakeAndPutSlot();


//    void on_getBackButton_clicked();

//    void on_fixButton_clicked();

//    void on_PUTButton_clicked();

signals:
    void Open_Port_Signal(QString portname); // Сигнал даем по нажатию кнопки "OPEN"
    void Pass_XY_Signal(int x_pix, int y_pix); //Сигнал по нажатию кнопки "Get_XY"
    void FW_Kinemaic_Signal(int S3, int S4, int S5, int l1, int l2, int l3); // Углы приводов, длины соответствующих звеньев.
    void Write_2_TcpClient_Signal(QString, int); // Сигнал вебсерверу, - пересылка данных в сокет на отправку.
    void SetActionData_Signal(QJsonObject &theObj);
    //    void StartTakeAndPutSignal();

};


#endif // MainProcess_H
