#include "qsimpleserver.h"

QSimpleServer::QSimpleServer(QObject *parent) :
    QTcpServer(parent)
{
    //Включает прослушивание сервером 8383 порта
    // server.listen(QHostAddress("127.0.0.1"),8888);
    // {
    // QHostAddress adr;
    // adr.setAddress("192.168.1.175");
    // if(listen(adr, tcpport)){
    // Так не слушает даже localhost, а только указанный ip
    // if(listen(QHostAddress("192.168.1.175"), tcpport))

    // Запускаем слушание порта
    if(listen(QHostAddress::AnyIPv4, tcpport)){
        qDebug() << "Listening port " << tcpport;
    //current_status = "wait";
        QTcpServer::setMaxPendingConnections(150);

    }
}

//++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++  В конце генерирует сигнал newConnection(). Finally newConnection() is emitted
//++++++++++++++ Слот этого сигнала - &MainWindow::newConnection_Slot - дает роботу команду.
void QSimpleServer::incomingConnection(qintptr sDescriptor)
{
    // Создание объекта потока QObject
    thread_A = new QThread;
    //Создание объекта потока для сокета
    QSocketThread* tcpthread = new QSocketThread(sDescriptor);

    //Соединение сигнала завершения потока со слотом отложенного удаления
    connect(tcpthread, &QSocketThread::finished, tcpthread, &QSocketThread::deleteLater);
    connect(tcpthread, &QSocketThread::finished, thread_A, &QThread::quit);
    connect(thread_A, &QThread::started, tcpthread, &QSocketThread::process_TheSocket, Qt::QueuedConnection); //, Qt::QueuedConnection)
    connect(thread_A, &QThread::finished, thread_A,  &QThread::deleteLater);


    connect(tcpthread, &QSocketThread::Command_4_Parsing_Signal, this, &QSimpleServer::Command_4_Parsing_Slot);
    connect(this, &QSimpleServer::Data_2_TcpClient_Signal, tcpthread, &QSocketThread::Data_2_TcpClient_Slot);

    tcpthread->moveToThread(thread_A);

    //Запуск потока
    thread_A->start();
    //addPendingConnection(sDescriptor);
}
//++++++++++++++++
// Слот отправки данных от робота клиенту в сокет (в ЦУП)
void QSimpleServer::Write_2_TcpClient_SLot(QString data)
{
    // Передаем данные дальше вниз в qtcpsocket
    emit Data_2_TcpClient_Signal(data);
}
//++++++++++++
// ОТправляем команду наверх, роботу на выполнение.
void QSimpleServer::Command_4_Parsing_Slot(QString message)
{
  emit Data_From_TcpClient_Signal(message); // works ???
    qDebug() << "!!!!!!!!!!!!!!!!!!!!! Get COMMAND FROM QSimpleServer->Command_4_Parsing_Slot !!!!!!!!!!!!!!!!!!!";
    qDebug() << message;

}

//++++++++++++
//Added by Miksarus
//void QSimpleServer::SetCurrentState(QString newStatus){
//    //this->current_status = newStatus;
//    ;
//}
