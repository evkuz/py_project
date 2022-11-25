#include "mainprocess.h"
#include "positions.h"
//#include "tcpParcing.h"

/*
преобразование строки параметров
?a=12&a=12432354&b=123&c=1241234
в массив ['a', '12'] ['a', '12432354'] ['b', '123'] ['c', '1241234']
        lst = str(request.args)
        lst2 = lst.find('[')
        a = lst[lst2:-1].replace('\'','\"').replace('(','[').replace(')',']')
        aa = json.loads(a)
*/
//+++++++ Получили данные (запрос) от клиента. Парсим.
//   0          1                    3                      5                           7                                   9
//{"clamp", "get_box", "parking", "ready", "status", "getactions", "getservices", "setservos=", "srvfromfile",  "status?action=get_box", "formoving"};


// Парсим запрос Tcp-клиента.
// ОТправляем ответ.
// ВАЖНО !!!!
// т.к. при ответе мы закрываем сокет, то ответ посылаем 1 раз.
// И это либо быстрый ответ на запуск экшена, либо ответ на RESET, либо на запрос статуса.
// Если посылать ответ еще, то сокета уже нет и будет ошибка.

void MainProcess::Data_From_TcpClient_Slot(QString message, int socketNumber, QObject* theSender)
{
    QString str, substr;
    int value = 0xf00f;

//    QMutexLocker locker(&mutex);

    ptrTcpClient = theSender;
    this->tcpSocketNumber =  socketNumber;
    new_get_request = true;
    str = "From TCP Get new command : "; str += message;
    GUI_Write_To_Log(value, str);

//    str = "$$$$$$$$$$$$$$$$$$$$$$ <Data_From_TcpClient_Slot>'s thread is ";
    //str += QString("0x%1").arg((qintptr)this->QObject::thread(),8);
//    str += pointer_to_qstring(QObject::thread());
//    GUI_Write_To_Log(value, str);

//    QString mystr = "Pointer to SENDER QObject is ";
//    mystr += pointer_to_qstring(ptrTcpClient);
//    GUI_Write_To_Log(value, mystr);



    substr = message;

    //mutex.lock();
    int comIndex = getIndexCommand(substr, tcpCommand);


    // So here we've got the index of elemnt representing the command received by TCP
    //jsnStore->createActionList();
    //mutex.unlock();

    // And now make decision
    // Если не запрос статуса и нет активных экшенов, меняем active_command, идем дальше
    // active_command != экшен

//    if (comIndex > 0 && !(jsnStore->isAnyActionRunning)){
//        //mutex.lock();
//        Robot->active_command = tcpCommand.at(comIndex);

//        //mutex.unlock();
//        str = "Current active command is ";
//        str += Robot->active_command;
//        str += " and isAnyActionRunning is ";
//        str += QVariant(jsnStore->isAnyActionRunning).toString();

//        GUI_Write_To_Log(value, str);

//    }

    // Если не запрос статуса, И не reset, но ЕСТЬ активный экшен (еще вопрос - тот же самый или другой ?)
    // Меняем у запрошенного, - если не текущий, - экшена статус - на "не запустился"
    // Другими словами - во время выполняения экшена приходит команда выполнить другой экшен...
    // Манипулятор не может 2 экшена выполнять одновременно.
    // comIndex > 0 && comIndex != 1
    // #################### ВНИМАНИЕ !!! ТУТ НЕТ ЗАПИСИ В ЛОГ, только ответ клиенту. ЧТОБ БЫСТРЕЕ БЫЛО #########

    QJsonObject tempObj;

    if (comIndex > 1 && jsnStore->isAnyActionRunning ){

                     tempObj = {
                         {"name", substr},
                         {"info", "Another action is already running"},
                         {"rc", RC_UNDEFINED}

                     };

        // ставим экшену статус -2... Если это отличный от текущего
        if (comIndex != currentCommandIndex)
        {
//                {"state", "Not applied"},
            tempObj["rc"] = jsnStore->AC_Launch_RC_FAILURE;
         }
        else        //if (comIndex == currentCommandIndex)
        {
            tempObj["info"] = "This action is STILL running";
            tempObj["rc"] = jsnStore->AC_Launch_RC_ALREADY_HAVE; // Уже запущен

        }
        // set aimed action values to tempObj
        // Here we are managed to not getting dangling pointer.
        // Ничего не меняем в состояниях экшена, так проще
//        jsnStore->setActionData(tempObj);
        //launchActionAnswer = tempObj;
        str = QJsonDocument(tempObj).toJson(QJsonDocument::Indented);
        // отправляем ответ на запуск экшена
        //emit Write_2_TcpClient_Signal(str, socketNumber);
        QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, str));


        return;
    }

// А теперь быстрый ответ, если НЕ запрос статуса, НЕ reset, И НЕТ активных экшенов.

    QJsonObject quickAnswerObj;
if (comIndex > 1 && !jsnStore->isAnyActionRunning ){
    quickAnswerObj = {
        {"name", substr},
        {"info", "Request accepted"},
        {"rc", RC_SUCCESS}

    };
    //...
    //И вот тут нужно ловить, а сущесвтует ли еще объект Q_ARG(qintptr, tcpSocketNumber));

    str = QJsonDocument(quickAnswerObj).toJson(QJsonDocument::Indented);
    QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                              Qt::QueuedConnection,
                              Q_ARG(QString, str));

} // if на быстрый ответ, если НЕ запрос статуса, И НЕТ активных экшенов.
// Если в данный момент есть работающий экшен, то уже нельзя менять значение mainjsnObj...



//    str = "Before switch";
//    str += " and isAnyActionRunning is ";
//    str += QVariant(jsnStore->isAnyActionRunning).toString();

//    GUI_Write_To_Log(value, str);

QStringList list1;
    switch (comIndex) {
    case 0: // status

        // Нужно добавлять активный экшен, либо пустой список
        str = jsnStore->createActionList(); // формируем список, записываем данные в jsnData, делаем merge (jsnActionList, jsnHeadStatus)

        GUI_Write_To_Log(value, str);
        QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, str));

        break;
    case -1: // Unknown Action !!! or Error message
        if (substr.startsWith("socketError")) {
            GUI_Write_To_Log(value, substr);
            return;
        }
        else
        {
// Неизвестный экшен не должен выполняться...
          tempObj = jsnStore->returnJsnActionsUnKnown();
          str = QJsonDocument(tempObj).toJson(QJsonDocument::Indented);
          GUI_Write_To_Log(value, str);
          QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, str));
        }
        break;

    case 1:  // reset
        // Robot->active_command = "reset";
        jsnStore->resetAllActions(); // all actions to "done"
        jsnStore->isAnyActionRunning = false;


        tempObj = {
            {"name", "reset"},
            {"rc", RC_SUCCESS}, //RC_SUCCESS
            {"info", "Reset successful"}
        };


        str = QJsonDocument(tempObj).toJson(QJsonDocument::Indented);
        GUI_Write_To_Log(value, str);
        QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                                Qt::QueuedConnection,
                                Q_ARG(QString, str));

        break;

    case 2: // clamp
        mainjsnObj = jsnStore->returnJsnActionClamp();
        break;

    case 3: // "get_box"
        mainjsnObj = jsnStore->returnJsnActionGetBox();
        request_CV();
//      Тут нет returnActionLaunch(mainjsnObj); т.к.
//      Может не быть детекции. Быстрый ответ отпрвляем из
//      MainProcess::CV_NEW_onReadyRead_Slot() если детекция есть.
        break;

    case 4: // "parking"
        mainjsnObj = jsnStore->returnJsnActionParking();
        returnActionLaunch(mainjsnObj); // Отправляем быстрый ответ

        memcpy(Servos, mob_parking_position, DOF);
        this->send_Data(LASTONE);

        break;
    case 5: // "ready"
        mainjsnObj = jsnStore->returnJsnActionReady();
        returnActionLaunch(mainjsnObj);
        memcpy(Servos, mob_ready_position, DOF);
        this->send_Data(LASTONE);
        break;

    case 6: //getactions
        jsnStore->isAnyActionRunning = false;
        //tempObj = jsnStore->returnAllActions();
        str = jsnStore->returnAllActions(); //jsnStore->jsnData;
        QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, str));

        str += str.insert(0, "Total action_list : \n");

        GUI_Write_To_Log(value, str);

        //Преобразовать каждый элемент QJsonArray  jsnObjArray в ordered_json
        // А значит нужна ф-ция QJsonObject -> ordered_json
        // Можно попробовать QJsonObject -> QString -> oredered_json


        break;
    case 8: // "setservos="
        mainjsnObj = jsnStore->returnJsnAcionSetservos();
        returnActionLaunch(mainjsnObj);

        substr = substr.remove("setservos=");
        list1 = substr.split(QLatin1Char(','));
        for (int i=0; i<DOF; ++i)
        {
            Servos[i] = list1.at(i).toUInt();
        }//for

        this->send_Data(LASTONE);

        break;

    case 11: // "formoving"
        mainjsnObj = jsnStore->returnJsnActionForMoving();
        returnActionLaunch(mainjsnObj);
        // Хват полностью сжат
        memcpy(Servos, mob_2_moving_position, DOF); // Для малого кубика

        //Servos[0] = 120;
        this->send_Data(LASTONE);

       break;

    case 12: // "put_box"
        mainjsnObj = jsnStore->returnJsnActionPutbox();
        returnActionLaunch(mainjsnObj); // Отправляем быстрый ответ

        memcpy(Servos, mob_put_23, DOF);
        this->send_Data(NOT_LAST);

        // Открываем
        Servos[0] = 45;
        this->send_Data(NOT_LAST);

        //Поднимаем крайний привод, чтобы снова не схватить кубик при движении обратно
        Servos[3] = 65;
        this->send_Data(NOT_LAST); // NOT_LAST


        // в позицию "formoving", хват постепенно закрывается
        memcpy(Servos, mob_2_moving_position, DOF);
        this->send_Data(LASTONE);

       break;


    case 13: //lock
        mainjsnObj = jsnStore->returnJsnActionLock();
        returnActionLaunch(mainjsnObj);
        //GUI_Write_To_Log(value, "BEFORE lock ");
//        Servos_To_Log("BEFORE lock ");
        Servos[0]=FULL_CLOSED;
        this->send_Data(LASTONE); //NOT_LAST LASTONE

       break;
    case 14: //unlock
        mainjsnObj = jsnStore->returnJsnActionUnLock();
        returnActionLaunch(mainjsnObj);
        Servos[0]=FULL_OPENED;
        this->send_Data(LASTONE); //NOT_LAST LASTONE

       break;
    case 15: // "detach"
        jsnStore->isAnyActionRunning = false;
        for (int i=0; i<DOF; ++i)
        {
            Servos[i] = 250; //0xFA
        }//for

        this->send_Data(LASTONE); //NOT_LAST

        tempObj = jsnStore->returnJsnActionDetach();
        str = QJsonDocument(tempObj).toJson(QJsonDocument::Indented);
        GUI_Write_To_Log(value, str);

        QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                                Qt::QueuedConnection,
                                Q_ARG(QString, str),
                                Q_ARG(qintptr, tcpSocketNumber));


        tempObj = {
            {"rc", RC_SUCCESS}, //RC_SUCCESS
            {"state", "Running, but all servos are detached"},
            {"info", "Action performing"}
        };

        jsnStore->setJsnHeadStatus(tempObj);

       break;

    case 16: // "attach"
        jsnStore->isAnyActionRunning = false;
        for (int i=0; i<DOF; ++i)
        {
            Servos[i] = 252; //0xFC
        }//for

        this->send_Data(LASTONE); //NOT_LAST
        tempObj = jsnStore->returnJsnActionAttach();
        str = QJsonDocument(tempObj).toJson(QJsonDocument::Indented);
        GUI_Write_To_Log(value, str);
        QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                                Qt::QueuedConnection,
                                Q_ARG(QString, str),
                                Q_ARG(qintptr, tcpSocketNumber));
        tempObj = {
            {"rc", RC_SUCCESS}, //RC_SUCCESS
            {"state", "Running"},
            {"info", "Action performing"}
        };

        jsnStore->setJsnHeadStatus(tempObj);


        break;

    case 17: // "isAttached?"
        jsnStore->isAnyActionRunning = false;
        for (int i=0; i<DOF; ++i)
        {
            Servos[i] = 254; //0xFE
        }//for

        this->send_Data(LASTONE); //NOT_LAST
        tempObj = jsnStore->returnJsnActionAttach();
        str = QJsonDocument(tempObj).toJson(QJsonDocument::Indented);
        GUI_Write_To_Log(value, str);
        QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                                Qt::QueuedConnection,
                                Q_ARG(QString, str),
                                Q_ARG(qintptr, tcpSocketNumber));
        tempObj = {
            {"rc", RC_SUCCESS}, //RC_SUCCESS
            {"state", "Running"},
            {"info", "Action performing"}
        };

        jsnStore->setJsnHeadStatus(tempObj);


        break;

    default:
        str = "The Command with index ";
        str += QString::number(comIndex);
        str += " is not found";
        GUI_Write_To_Log(value, str);
        break;
    } //switch (comIndex)

    // ++++++++++++++++++++++++++++++++ Теперь всё остальное

    if (substr == "close") {
        Robot->serial.close();

    }

    if (substr == "info") {
        // Вот тут делаем присвоение статуса.
        str = Robot->GetCurrentStatus();
        jsnStore->setCurrentAction(substr);
        str = "Old MacDonald Have a farm";
//        str = QJsonDocument(jsnStore->returnJsnInfo()).toJson(QJsonDocument::Indented);

        GUI_Write_To_Log(value, "!!!!!!!!!!! Current INFO is ");
        GUI_Write_To_Log(value, str);

        //str = QJsonDocument(jsnStatus).toJson(QJsonDocument::Compact);


        emit Write_2_TcpClient_Signal (str, this->tcpSocketNumber);

    }

}// Data_From_TcpClient_Slot
//++++++++++++++++++++++++++++++++++++++
// Ответ на запрос статуса
// формируем JSON action_list[], отправляем его

void MainProcess::StatusRequest_From_TcpClient(QObject* theSender)
{
    QString str;
    int value = 0xf01f;

    ptrTcpClient = theSender; // ? ... чтобы не переписалось из другого потока ?

    str = jsnStore->createActionList(); // формируем список, записываем данные в jsnData, делаем merge (jsnActionList, jsnHeadStatus)
    GUI_Write_To_Log(value, str);

//    qintptr tcpSocketNumber = 0xCCCC;
    QMetaObject::invokeMethod(this->ptrTcpClient, "Data_2_TcpClient_Slot",
                              Qt::QueuedConnection,
                              Q_ARG(QString, str)); //



} // StatusRequest_From_TcpClient
//+++++++++++++++++++++++++++++++++++++++++++++
// Отправляем быстрый ответ на запуск экшена, запускаем сам экшен.
void MainProcess::ActionLaunch_From_TcpClient(QObject *theSender, QString actionName)
{
    QString str, substr;
    QString statParam;
    int value = 0xf02f;
    int sPosition;
    int distance;

    QJsonObject quickAnswerObj; // Ответ на запуск экшена

    QJsonObject tempObj;


    substr = actionName;

    str = "From TCP Get new command : "; str += substr;
    Robot->Write_To_Log(value, str);


    int comIndex = getIndexCommand(substr, tcpCommand);
//            str = "Current active command index is ";
//            str += QString::number(currentCommandIndex);
//            str += " and isAnyActionRunning is ";
//            str += QVariant(jsnStore->isAnyActionRunning).toString();
//            Robot->Write_To_Log(value, str);

    //        GUI_Write_To_Log(value, str);
    // Готовим быстрый ответ
    quickAnswerObj = {
        {"name", actionName},
        {"info", "Request accepted"},
        {"rc", RC_SUCCESS}

    };

    // Отправляем быстрый ответ. В лог не пишем, ибо нужно быстро ответить.
//    str = QJsonDocument(quickAnswerObj).toJson(QJsonDocument::Indented);
    str = jsnStore->returnActionLaunch(quickAnswerObj);

    QMetaObject::invokeMethod(theSender, "Data_2_TcpClient_Slot", // правильно, закрываем сокет после быстрого ответа.
                            Qt::QueuedConnection,
                            Q_ARG(QString, str));



// Проверяем, есть ли запущенный экшен, и если ДА, то НЕ ШЛЁМ быстрый ответ,
// только меняем JSON-данные по запрошенному экшену.
    if (jsnStore->isAnyActionRunning ){
        tempObj = {
         {"name", substr},

        };

        // ставим экшену статус [-2], Если это отличный от текущего,
        // и [-3], если текущий, т.е. уже запущен.
        if (comIndex != currentCommandIndex)
        {
            tempObj["state"] = "Another action is already running";
            tempObj["result"] = jsnStore->AC_Launch_RC_FAILURE; // Экшен не запустился
            // А теперь меняем JSON-объект экшена.
         }
        else        //if (comIndex == currentCommandIndex)
        {
            tempObj["state"] = "This action is STILL running";
            tempObj["result"] = jsnStore->AC_Launch_RC_ALREADY_HAVE; // Уже запущен

        }
//      Получаем строку в формате JSON для отправки tcp-клиенту
        str = QJsonDocument(tempObj).toJson(QJsonDocument::Indented);
        // отправляем ответ на запуск экшена
        QMetaObject::invokeMethod(theSender, "Data_2_TcpClient_Slot", //this->ptrTcpClient
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, str));

        // А теперь меняем данные у запрошенного экшена
        jsnStore->setActionData(tempObj);
        // Пишем в лог Serial device, чтобы не затеряться в основном логе  среди перманентных
        // запросов статуса
        str.insert(0, "tcpParcing.cpp QJSON data AFTER action LAUNCH REQUEST : \n");
        Robot->Write_To_Log(value,str);


        return;
    } //if (jsnStore->isAnyActionRunning )


    jsnStore->isAnyActionRunning = true;
    currentCommandIndex = comIndex;


    //А теперь запускаем экшен
    QStringList list1; // Понадобится для setservos
    switch (comIndex) {
    case 1:  // reset
        jsnStore->resetAllActions(); // all actions to "done"
        jsnStore->isAnyActionRunning = false;

        break;
    case 2: // clamp
        mainjsnObj = jsnStore->returnJsnActionClamp();
        break;
    case 3: // "get_box"
        mainjsnObj = jsnStore->returnJsnActionGetBox();
        returnActionLaunch(mainjsnObj); // Отправляем быстрый ответ
        if (substr.contains("get_box&distance=")){
            sPosition = 17; // next after get_box&distance=
            statParam = substr.mid(sPosition);
            distance = statParam.toDouble(); // Вот тут получается 0, если длинное значение
            str = "The command is get_box&distance=";
//            str += statParam;
//            Robot->Write_To_Log(value, str);
            GetBox(distance);
        }
        else {
            str = "Going to request CV  "; str += substr;
            Robot->Write_To_Log(value, str);

            request_CV();
        }
//      Тут нет returnActionLaunch(mainjsnObj); т.к.
//      Может не быть детекции. Быстрый ответ отпрвляем из
//      MainProcess::CV_NEW_onReadyRead_Slot() если детекция есть.
        break;

    case 4: // "parking"
        mainjsnObj = jsnStore->returnJsnActionParking();
        returnActionLaunch(mainjsnObj); // Отправляем быстрый ответ


        memcpy(Servos, mob_parking_position, DOF);
        this->send_Data(LASTONE);
        break;

    case 5: // "ready"
        mainjsnObj = jsnStore->returnJsnActionReady();
        returnActionLaunch(mainjsnObj);

        memcpy(Servos, mob_ready_position, DOF);
        this->send_Data(LASTONE);

        break;

    case 8: // "setservos="
        mainjsnObj = jsnStore->returnJsnAcionSetservos();
        returnActionLaunch(mainjsnObj);

        substr = substr.remove("setservos=");
        list1 = substr.split(QLatin1Char(','));
        for (int i=0; i<DOF; ++i)
        {
            Servos[i] = list1.at(i).toUInt();
        }//for

        this->send_Data(LASTONE);

        break;


    case 11: // "formoving"
        mainjsnObj = jsnStore->returnJsnActionForMoving();
        returnActionLaunch(mainjsnObj);
        // Хват полностью сжат
        memcpy(Servos, mob_2_moving_position, DOF); // Для малого кубика

        //Servos[0] = 120;
        this->send_Data(LASTONE);

       break;

    case 12: // "put_box"
        mainjsnObj = jsnStore->returnJsnActionPutbox();
        returnActionLaunch(mainjsnObj); // Отправляем быстрый ответ

        memcpy(Servos, mob_put_23, DOF);
        this->send_Data(NOT_LAST);

        // Открываем
        Servos[0] = FULL_OPENED;
        this->send_Data(NOT_LAST);

        //Поднимаем крайний привод(подняв 3 привод), чтобы снова не схватить кубик при движении обратно
        Servos[3] = 65;
        this->send_Data(NOT_LAST); // NOT_LAST


        // в позицию "formoving", хват постепенно закрывается
        memcpy(Servos, mob_2_moving_position, DOF);
        this->send_Data(LASTONE);

       break;

    case 13: //lock
        mainjsnObj = jsnStore->returnJsnActionLock();
        returnActionLaunch(mainjsnObj);
        Servos[0]=FULL_CLOSED;
        this->send_Data(LASTONE); //NOT_LAST LASTONE

       break;
    case 14: //unlock
        mainjsnObj = jsnStore->returnJsnActionUnLock();
        returnActionLaunch(mainjsnObj);
        Servos[0]=FULL_OPENED;
        this->send_Data(LASTONE); //NOT_LAST LASTONE

       break;
    case 15: // "detach"
        mainjsnObj = jsnStore->returnJsnActionDetach();
        returnActionLaunch(mainjsnObj);
        jsnStore->isAnyActionRunning = false;
        for (int i=0; i<DOF; ++i)
        {
            Servos[i] = 250; //0xFA
        }//for

        this->send_Data(LASTONE); //NOT_LAST
       break;

    case 16: // "attach"
        mainjsnObj = jsnStore->returnJsnActionAttach();
        returnActionLaunch(mainjsnObj);
        jsnStore->isAnyActionRunning = false;
        for (int i=0; i<DOF; ++i)
        {
            Servos[i] = 252; //0xFC
        }//for

        this->send_Data(LASTONE); //NOT_LAST
        break;


    default:
        jsnStore->isAnyActionRunning = false;
        str = "The Action with index ";
        str += QString::number(comIndex);
        str += " is not found";
        GUI_Write_To_Log(value, str);
        break;
    } //switch (comIndex)

}
//+++++++++++++++++++++++++++++++++++++++++++++
// Ответ на запрос информации из service.

void MainProcess::ServiceLaunch_From_TcpClient(QObject *theSender, QString serviceName)
{
    int value = 0xF03F;
    QString str;
    jsnStore->isAnyActionRunning = false;
    str = serviceName;
    int comIndex = getIndexCommand(str, tcpCommand);

    switch (comIndex) {
    case 6: //"getactions"
        str = jsnStore->returnAllActions(); //jsnStore->jsnData;
        break;

    case 7: //"getservices"
        str = jsnStore->returnAllServices();

        break;

    }//switch (comIndex)

// Строку JSON сформировали, отправляем tcp-клиенту.
    QMetaObject::invokeMethod(theSender, "Data_2_TcpClient_Slot",
                              Qt::QueuedConnection,
                              Q_ARG(QString, str));

    str += str.insert(0, "Total service_list : \n");

    GUI_Write_To_Log(value, str);

}
//+++++++++++++++++++++++++++++++++++++++++++++++++
// Подготовка и отправка ответа на запрос "/status?action=<action name>"
// через paramName передаем имя экшена
void MainProcess::StatusParamRequest_From_TcpClient(QObject *theSender, QString paramName)
{
    QString str;
//    int value = 0xf04f;
    str = jsnStore->createStatusParamList(paramName);
    // Строку JSON сформировали, отправляем tcp-клиенту.
    QMetaObject::invokeMethod(theSender, "Data_2_TcpClient_Slot",
                              Qt::QueuedConnection,
                              Q_ARG(QString, str));

}
//+++++++++++++++++++++++++++++++++++++++++++++


