#ifndef EVKUZ_H
#define EVKUZ_H


/*
 * https://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/
 * В к. 406Б использую kit : Qt 5.15.2 (gcc_64)
 * В к. 240Б использую       Qt 5.15.2 (gcc_64)for Desktop
 *
 *
 * Ветка hiwonder. Стационарный манипулятор
 * Теперь все через ЦУП, без GUI

 * Проект для более сложной презентации, где участвуют 5-6 роботов
 * Берем кубик с розовой полочки Хрёбота и кладём на пол, где "Ручник" подберет кубик и увезет куда надо.
 *
 * Запускаем supervisor  по адресу http://localhost:5050/
 *
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 09.05.2022
 * Работаем в праздники :) Одтохнули уже достаточно. Работа тянет :)
 * Решил спрятать все переменные класса jsoninfo из public в private. Лучше поздно чем никогда :)
 * А это тянет за собой переделку кода в части парсинга tcp-запроса от tcp-клиента.
 * Тогда переделываем по частям, как с mobman.
 * Перенес ф-цию MainProcess::Data_From_TcpClient_Slot(QString message) в отдельный файл "tcpParcing.cpp".
 * Для обработки команд добавил void MainProcess::ProcessAction(int indexOfCommand)
 * Сейчас ProcessAction обрабатывает только 2 кода : "status", "start".
 * В целом, понятно, как работать с json-данными и передавать их клиенту.
 * В итоге что имеем :
 *
 * При запуске программы инициализируются json-объекты, содержащие статусы, экшены и т.д
 * Далее запускается объединение разных json-объектов в один, и данные этого общего объекта выводятся.
 *
 * НА данный момент много избыточного кода. Потом сократим, когда будет полная картина с протоколом.
 *
 * Подключил файлы qsimpleserver.h/.cpp как библиотечные. ДЛя этого в .pro-файле добавил $$(EXTLIBS)/manipulator/qsimpleserver.h
 * Следует учесть, что при "вынимании" родного файла из проекта, он удаляется гитом с диска... но при этом каждый раз предлагает сохранить его с другим именем.
 * При этом файл библиотеки nlohmann подключается в проект просто через #include в проекте, без редактирования .pro-файла проекта.
 * Возможно в этом-то и вся стуть, что в nlohmann заголовки и код в одном файле .hpp (а такое возможно ?), а у меня в разных, т.е. .h и .cpp - соответственно.
 *
 * В общем, библиотеку nlohmann подключить намного удобнее, чем qsimpleserver. С этим следует разобраться. Пока будем так пользоваться.
 *
 * Подключил файлы qsocketthread.h/.cpp по аналогии. Однако, забыл в файле .pro поставить символ " \" - продожение списка source/headers и часа 1.5 разбирался,
 * почему же не подключаются файлы...
 *
 * Теперь встает проблема, что файлы библиотечные лежат в папке на уровень выше, чем папка репозитория, получается git их не будет отслеживать.
 * Надо будет со временем перенести внутрь репозитория.
 *
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 06.05.2022
 * Смотрим пример объединения json объектов :  https://stackoverflow.com/questions/64665582/how-to-merge-two-qjsonobjects-in-qt
 * Написал ф-цю конвертации структуры в ordered_json::nlohmann-объект.
 * void JsonInfo::struc_2_json(ordered_json &jsn, const StatusAnswer &header)
 * Проверено, работает.
 * ОСталось добавлять объект, представляющий данные об экшене к объекту StatusAnswer.[Сделано]
 * Написана ф-ция merge_json(jsnObj2, jsnObj), которая возвращает строку - данные json-объекта, собранного из jsnObj2, jsnObj.
 * Ф-ция вызывается внутри слота makeJson_Answer_Slot.
 * Сигнал для этого слота пока не написан.
 * Однако при объединении json-объектов первым всегда почему-то идет список, т.е. объект получается такой :
 *
 * {
    "action_clamp": [
        {
            "info": "Open/Close clamper",
            "name": "clamp",
            "rc": 0,
            "state": "inprogress | done | fail"
        }
    ],
    "info": "OK",
    "name": "HIWONDER",
    "rc": 0,
    "state": "Waiting"
}

 * Что портит весь вид. Местами объекты менял (т.е. кто с кем объединяется) все равно такой вид.
 *
 * Будем дуамать, как это победить.
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 05.05.2022
 * Продолжаем дорабатывать парсинг JSON.
 * Удобно использовать оба подхода - через библиотеку nlohmann,
 * Данные, ранее подготовленные для nlohmann конвертируем по цепочке nlohmann->std::string->QString->QJsonDocument->QJsonObject
 * Далее направляем данные QJsonObject в ранее написанную ф-цию traversJson(QJsonObject json_obj), которая рекурсивно проходит по всей структуре объекта JSON и пишет в лог
 * полученную структуру json-объекта. [Сделано]
 * Однако треубется доработать ф-цию traversJson(), т.к. она была написана под конкретный случай, где идет поиск конкретного ключа.
 * Теперь желательно, чтобы эта ф-ция делала полный парсинг JSON бъекта.[Сделано]
 * Сейчас, если внутри JSON-объекта попадается список (QJsonArray), то он не парсится, а надо.[СДЕЛАНО]
 * Следующая задача : готовить JSON-ответ супервизору, как набор json-объектов, которые объединяем вместе в один объект и отправляем клиенту.
 * Или, более конкретно, задача следующая :
 *
 * - json-Объект(ключ:список) nlohmann::jsnStatus парсить по значению экшена, т.е. "start", "clamp" и т.д., и по этому значению вытаскивать весь объект(элемент списка).
 *   Применяем цепочку nlohmann->std::string->QString->QJsonDocument->QJsonObject и далее работаем с QJsonObject штатными средствами Qt.
 * - Добавлять полученный объект в структуру StatusAnswer, так получаем готовый ответ tcp-клиенту
 *
 *
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 03.05.2022
 * Создан класс JsonInfo для формирования JSON-ответов tcp-клиенту.
 * Сознательно не стал добавлять работу с JSON в класс HiWonder, т.к. в будущем планируется сделать эти классы библиотечными и максимально избежать дублирования
 * кода при переходе от одного робота к другому.
 * Пока буду использовать оба подхода - через библиотеку nlohmann и через стандартный набор Qt -  QJsonDocument, QJsonObject и др.
 * Посмотрим, как удобнее будет.
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 29.04.2022
 * Вернул в рабочее состояние на 27.04.2022, убрав лишний вывод данных от ком-порта. Функционал не пострадал.
 * В итоге добавилось 3 команды.
 * Следующий шаг - добавляем статусы и json.
 * А пока Фиксим.
 *
 * + Добавляем команду "put_box"
 * + Добавляем JSON-вывод полной инфы по девайсу
 * + Добавил команду "info" которая выводит сводный список экшенов
 * + Добавил парсинг команд из списка QList<QString>  strcommand = { "/run?cmd=", "/service?name=", "/status", "/status?action="};
 * - Однако надо перенести парсинг tcp-данных из класса QSocketThread в MainProcess. Пусть QSocketThread отвечает только за обмен по TCP/ip тогда его легче будет выделить в отдельный
 *   файл, как библиотечный.
 * - Надо создать аналог GUI-клиента, сделанного для mobman
 * - Проверить с помощью GUI-клиента устойчивость работы при tcp-запросах с частотой 2Гц.
 *
 *
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 28.04.2022
 * Долго разбирался с подключением библиотеки.
 * Казалось бы самый просто путь - использовать EXTLIBS="/home/ubuntu/extlibs/json/single_include"
 * Но сейчас путь привязан к библиотеке json, а надо его сделать на 2 уровня выше...
 * Но, если этот путь исправить, то придется вносить изменения в проект mobman, пересобирать его, тестировать, в общем, пока отложили.
 *
 * ОБнаружилась проблема в прошивке arduino. Почему-то перестал открываться хват. Начал разбираться в коде.
 * Делал вывод в ком-порт промежуточных данных, снимал комменты с отладочных строчек.
 * Изменил размер TX-буфера в файле
 * /home/ubuntu/arduino-1.8.16/hardware/arduino/avr/cores/arduino/HardwareSerial.h
 * При компиляции моя среда Arduino 1.8.16 выдавала разные значения свободной памяти при смене размера TX-буфера, т.е. настройки применялись.
 * Однако в выводе лога все равно строка обрезалась на 32 символах. И это проблема в Arduino, т.к. перед чтеним ком-порт выводил, а сколько там данных есть в буфере.
 * Так вот, всегда не более 32.
 * Имеет смысл настроить вывод из ком-порта также в отдельный файл.
 *
 * + Добавлена tcp-команда "getservos" - передать значения углов сервоприводов
 * + Добавлена tcp-команда "lock" - сжать захвт
 * + Добавлена tcp-команда "unlock" - открыть захват
 *
 * В какой-то момент все заработало :) Но непонятно, что повлияло :(
 * Оставляю разбор на завтра. Будем обратно ставить комменты и смотреть, когда перестанет правильно работать :)
 * Фиксируем.

 * //+++++++++++++++++++++++++++++++++++++++++++
 * 27.04.2022
 * Для новой презентации меняем порядок действий для HiWonder.
 * - По команде "start" :
 *          сменить статус на "running",
 *          взять кубик, встать в исходное положение,
 *          сменить статус на "done"
 * - По команде "put_cube" :
 *          сменить статус на "running"
 *          положить кубик, встать в исходное положение,
 *          сменить статус на "done"
 *
 * + Нужно добавить чтение значений сервоприводов из Arduino [сделано 28.04.2022]
 * + Добавить команду "lock", т.е. сжать захват.  [сделано 28.04.2022]
 * + Добавить команду "unlock", т.е. открыть захват.  [сделано 28.04.2022]
 * - Доработать отправку/чтение данных в/из Serial Port по 32 байта (размер буфера Arduino по умолчанию).
 *
 *
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 26.04.2022
 * Удалены следующие лишние ф-ции из класса mainprocess :
 * - Data_From_Web_SLot(QString message);
 * - newConnection_Slot();
 * - server_New_Connect_Slot();
 * - on_openButton_clicked();
 * - on_closeButton_clicked();
 * - on_getXYButton_clicked();
 * - Return_EL_Slot(float EL);
 * - Return_FW_Kinematic_XYZ_Slot(int X, int Y, int Z, float EL);
 * - Pass_String_Slot(QString str);
 * - on_submitButton_clicked();
 *
 * Теперь весь код MainProcess.cpp - 398 строк.
 *
 * Далее пробуем выстроить некую иерархию класса.
 * Класс SerialDevice - аналог HiWonder, но без привязки к имени собственному. ОБъекты, например, - Nano, Mega - по названию плат.
 * Класс Robot (Manipulator) - Дочерний от SerialDevice. Вот тут уже свойства робота можно описывать - DOF, parcsel_size и т.д. Объекты - HiWonder, Mobman, Pinkman  - по названию робота.
 * Далее к объекту класса Robot надо прикручивать связь с другими роботами - создавать объект класса QTcpServer, работа с потоками, парсинг JSON и т.д.
 * Вот и подошли к потокам. Сейчас, выходит, что отправка данных в SerialPort выполняется в том же потоке, что и обмен по tcp/ip.
 * В случае с роботом HiWonder можно попробовать выделить отдельный поток для SerialPort-обмена, т.к. вся прога идет на стационарном ПК.
 * Вот когда это перейдет на mobman - там посмотрим.
 * Фиксируем.
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 25.04.2022
 * Различия начинают сказываться уже хотя бы в том, что у hiwonder - размер посылки в arduino - 8 байт, а у mobman - 6.
 * Число DOF для hiwonder - 6, а для mobman - 4.
 * Также добавляется код из-за использования протокола json, много новых переменных, и т.д. и для случая, когда просто робот управляется по tcp/ip это все лишнее.
 * Для начала удаляем ф-ции, используемые в GUI-версии и не нужные в данной, console-версии.
 * Удалено :
 * - void on_stand_upButton_clicked(); - Выполняется по команде через tcp/ip
 * - void on_sitButton_clicked();
 * - on_set_posButton_clicked();
 *
 * Добавляем важную фичу - перебор USB-Serial портов. Она есть в коде для mobman.
 * Для этого также придется отредактировать ф-цию HiWonder::Open_Port_Slot(QString portname)
 * А вот если бы эта ф-ция была добавлена в базовый класс, то сейчас не пришлось бы возиться с кодом...
 * А для этого надо продумать хранение, чтобы проекты mobman и hiwonder брали базовый класс в одном месте...
 *
 * Также на до проект threads переименовать в hiwonder-gui
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 13.04.2022
 * Пришла пора добавлять протокол взаимодействия роботов через ЦУП.
 * И встал вопрос наследования и масштабирования. А вопрос встал, потому что приходится дублировать код для HiWonder и Mobman.
 * Т.е. надо выделить отдельный код для работы с манипулятором - стационарным, либо мобильным.
 * Т.е. стоит подумать о создании нового класса типа RobotTCP, в котором вся обработка TCP-сообщений.
 * Тогда класс HiWonder - только для стационарного манипулятора.
 * класс Mobman - наследник HiWonder с добавлением функционала работы с CVDevice
 * класс RobotTCP - обработка TCP-сообщений.
 *
 * ДЛя начала попробуем просто выделить код в отдельные ф-ции и файлы. А для этго его надо унифицировать.
 * Чтобы в обоих проектах структура кода была одинаковая.
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 04.04.2022
 * Удалили c remote ветку
 * - mobman-json
 * - mobman
 * - embedded
 * - demo
 * - teseting-threads
 * Локально тоже это все почистили.
 * Фиксим.
 *
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 31.03.2022
 * Заменены файлы SocketClient.cpp/.h
 * Взяты тут
 * /home/ubuntu/agents_python/hiwounder/app/utils/test_client
 *
 * Теперь вместо картинки с камеры на весь экран заходим на
 * http://192.168.1.175:5001/
 * и там маленькая картинка.
 * Поменяли путь к файлу сокета. Теперь только на 1 уровень вверх.
 *
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 14.03.2022
 * Поработал с git-ом, теперь в ветке hiwonder актуальный код проекта "gui-client" для работы с Ручником.
 * Теперь намного проще тестировать одновременную работу HiWonder и mobman.
 *
 * Подходим к ситуации, когда надо писать свой аналог ЦУП для базовых тестов соместной работы роботов.
 *
 *
 *
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 10.03.2022
 * Взял проект embedded, добавил БЗ из проекта threads для розовой полочки.
 * Преобразовал команду "start" к виду :
 * - Взять кубик с розовой полочки
 * - В исходное положение
 * - Положить кубик на крестик в линолеуме, там мобман его возьмет
 * - В исходное положение.
 *
 * Но сейчас это все без всяких статусов, экшенов и json.
 *
 *
 *
 *
 *
 *
 * //+++++++++++++++++++++++++++++++++++++++++++++
 * Ветка embedded
 *
 *
 * //++++++++++++++++++++++++++++++++++++++++++++
 * Путь к Supervisor-у
 * file:///home/ubuntu/iqr_lit/supervisor/index.html
 *
 * //+++++++++++++++++++++++++++++++++++++++++++++
 * 26.10.2021
 * Крайняя запись в ветке embedded для стационарного робота. Начинаем разработку для мобильного робота.
 * Есть мысль не использовать ф-цию send_Data(), а каждый раз формировать массив на отправку роботу внутри on_trainButton_clicked().
 * Так видно, что отправляешь роботу.
 *
 * //+++++++++++++++++++++++
 * 20.10.2021
 * Поменял имена сигналов/слотов для обмена по TCP, в обе стороны, т.е.
 *
 * и "Сверху вниз", MainProcess--->QTcpServer--->QTcpSocket
 * и "Снизу вверх", QTcpSocket--->QTcpServer--->MainProcess
 *
 * //+++++++++++++++++++++++
 * Перешли на ветку embedded
 *
 * 19.10.2021
 * Тестировал работу консольного варианта управления роботом.
 * Выяснилось(прошел по всем сигналам-слотам снизу вверх), что "старый" вариант соединения сигналов со слотом тут, в консольном
 * варианте, не работает.
 * Те. не работает строка
 *
 * connect(&server, SIGNAL(Info_2_Log_Signal(QString)), this, SLOT(Info_2_Log_Slot(QString)));
 *
 * Поменял на "новый" стиль :
 *
 * connect(&server, &QSimpleServer::Info_2_Log_Signal, this, &MainProcess::Info_2_Log_Slot);
 *
 * И ЗАРАБОТАЛО !!!
 *
 * Фиксируем результат.
 *
 *
 * //+++++++++++++++++++++
 * 18.10.2021
 * После совещания отказались от манипулятора на одноплатном ПК.
 * Поэтому проект переводим в консольное приложение, взаимодействующее с ЦУП.
 * Теперь все через ЦУП, без GUI
 * //+++++++++++++++++++++
 * 15.10.2021
 * Чистим код перед заливкой проекта на одноплатный компьютер.
 * НА транспортере тоже будет стоять манипулятор и управляться данной прогой.
 *
 * Т.к. не будет GUI и все управление по TCP, то, на данном этапе, каждую кнопку заменим отдельной командой, передаваемой
 * по ТСР. Т.е ТСР-парсер теперь - основой центр управления.
 * Ветка embedded- только проект embed, а проект threads - не трогать, оставить как в threads/release
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 07.10.2021
 * Если настроить  QTcpServer на слушание любого ipv4 адреса, т.е. listen(QHostAddress::AnyIPv4, tcpport))
 * То QTcpServer::serverAddress() выдает "0.0.0.0".
 * А если настроить на специфичный адрес, то только его и будет слушать, т.е. даже localhost может не отзываться.
 *
 * Координаты вечером 692, 573
 *
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 06.10.2021
 * Начал создавать Блок-схему работы ПО для манипулятора.
 * Файл threads/Software_Scheme_HiWionder.odg
 * Наиболее интересно - организация работы
 * И, соответственно, передача информации "Сверху вниз", т.е. MainWindow--->QTcpServer--->QTcpSocket
 * и "Снизу вверх",                                      т.е. QTcpSocket--->QTcpServer--->MainWindow
 *
 * Добавил кнопку "PUT", которая повторяет операцию "положить кубик на тележку", чтобы кубик точнее попадал в рабочую
 * область.
 *
 *
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 05.10.2021
 * Со 2-й попытки получилась база, при которой манипулятор хорошо (все же не всегда) берет кубик.
 * Фиксиурем.
 * Также сформировал полноценную строку ответа серверу в формате json, но так Robot Control Center(RCC), написанный Мишей, не понимает ответ и считает,
 * что нет связи с роботом.
 * Пришлось вернуть обратно. Сейчас все работает.
 * Еще разве доработать движение манипулятора при установке кубика на тележку, т.е. чтобы приводы сначала двигались так :
 * 6
 * 3,4,5
 * 1
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 04.10.2021
 * 1140, 499 - координаты на момент ухода домой в конце дня. [Утром было 1140, 510]
 * Посмотрим, какие будут завтра с утра.
 *
 * ДОбавил кнопку  "Fix Data", которая записывает в файл точек координаты точки с камеры и позиции приводов.
 * Так намного быстрее протекает набор точек.
 *
 * Набрал за сегодня 130 точек. (час примерно добавлял кнопку со всем ф-ционалом, + в 12.00 собрание было.)
 * Реально было пол дня рабочих.
 *
 * ЗА выходные Миша прикрепил камеру на новый кронштейн (для подоконников из Стройера), подогнал крестики к шурупам по новой,
 * поэтому была набрана новая база точек.
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 30.09.2021
 *
 * Камера детектит кубик и на тележке 2230, 490
 *
 * Добавил слоты для сигналов quit(), deleteLater() для объекта класса QThread (было только для QSocketThread* tcpthread)
 * Теперь их Аж 3.
 *
 *  connect(tcpthread, SIGNAL(finished()), thread_A, SLOT(quit()));
 *  connect(tcpthread, SIGNAL(finished()), tcpthread, SLOT(deleteLater()));
 *  connect(thread_A, SIGNAL(finished()), thread_A, SLOT(deleteLater()));
 *
 *  И ушла ошибка
 *  (threads:15185): GLib-ERROR **: Creating pipes for GWakeup: Too many open files
 *
 * //++++++++++++++++++++++++++
 *
 *  29.09.2021
 *  Фиксируем результат.
 *  Сработала передача данных(команда) из tcp сокета наверх роботу.
 *  ТАкже сработал обратный ответ статуса от робота вниз в сокет.
 *  Вводим переменную HiWonder.current_staus, которая хранит значение статуса.
 *  В итоге у нас работает сквозной обмен данными из tcp-сокета "наверх" к роботу и обратно от робота "вниз" в tcp-сокет.
 *
 *  Теперь можно настраивать протокол обмена и делать этот обмен скоростным.
 *
 *  Решил проблему со сменой статуса. В ф-ции try_mcinfer была отправка команды роботу через on_set_position_clicked(), сама
 *  ф-ция - это слот нажатия кнопки, т.е., понятно, что это однрократная команда, поэтому там в конце стоял флаг, что это последняя
 *  команда, поэтому статус сразу done. Заменил на стандартный вариант  - send_data(lastcommand_value) - как в обработчике команды из tcp-сокета.
 *  Доработал смену статуса. Теперь робот воспринимает (и правильно реагирует) на следующие команды :
 *
 *  status
 *  reset
 *  start
 *
 * Уже пора составлять диаграмму-схему работы программы. Переключился на работу с классом TcpServer и через пару недель уже не помню какие
 * сигналы/слоты отвечают за работу с сериал-портом. Хотя пока еще искать по коду быстрее, чем искать схему :)
 *
 * Начнем готовить ответ в формате json. Пока заведем отдельную ф-цю в которой будем формировать строку json на основе
 * переменных.
 *
 *

 * //++++++++++
 * 25.09.2021
 *
 * Заработало!!!!!
 *
 * В общем, команду QTcpServer::listen(host, port) нужно задавать из класса MainWindow, а не из QSimpleServer...
 * //++++++++++++
 * 24.09.2021
 * Приступаем к парсингу GET запроса, который получает наш webserver извне, извлекаем команду для робота, передаем её роботу.
 *
 * В примере, на основе которого собран класс webserver считывание из сокета и отправка в сокет данных выполняется в одном бесконечном цикле.
 * Пришла пора разделить считывание данных из и отправка в на 2 разные ф-ции.
 * Слот Output_Data_From_Client_Slot остается только на СЧИТЫВАНИЕ.
 * Добавляем слот на запись. Слот срабаывает, когда робот подает сигнал, что команду завершил.
 * Такой слот уже есть - Moving_Done_Slot(), срабатываен по сигналу от робота Moving_Done_Signal()
 *
 * Надо вводит флаг, что был GET-запрос, чтобы данные отправлялись в сокет только есть есть запрос.
 *
 * Проблема с первой же строчкой кода, которая должна крутиться в потоке :
 *
 * client_fd = accept(this->sock, (struct sockaddr *) &cli_addr, &sin_len);
 * Если убрать код, работающий с сокетом, то поток работает нормально.
 * Оставлю такой вариант кода для дестов. Поместил его в отдельную ветку testing-threads
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 23.09.2021
 * А теперь со всей этой ... мы попытаемся взлететь :)
 * Протупил с выводом в лог из конструктора.
 *
 * Скорее всего в лог омжно выводить только после завершения конструктора, т.е. когда объект класса уже создан.
 * 14:55
 * Криво-косо, но данные GET-запроса получаем,
 *
 *
 *
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 22.09.2021
 *
 * Создаем отдельный поток для web-сервера.
 * Создал отдельную ветку - threads с этим функционалом.
 *
 *
 *
 * //+++++++++++++++++++++++++++++
 * 21.09.2021
 * Вводим дополнительный байт, - "Последняя команда" ДА/НЕТ.
 * Процессор, увидев что это последняя команда, вместо обычного
 * "Robot movement DONE! Total!!" ответит :
 * "Robot movement DONE! LAST !!"
 * По строке "LAST" ПК поймет, что это была последняя команда и
 * тогда можно будет посылать сообщение web-серверу.
 *
 * Пришлось сдублировать ф-цию Set_Position, clamp, stand_up,
 * чтобы сохранился прежний функционал работы через кнопки.
 * В них добавляется 8-й байт, - индикатор "Последняя команда" ДА/НЕТ.
 * ДОбавил пару сигнал/слот Moving_Done_Signal/Moving_Done_Slot
 * где обрабатывается событие завершения последней команды.
 * В слот, соответственно, надо добавть сообщение веб-серверу, что
 * команду выполнил (кубик опустил на тележку)
 *
 * [Сделано]
 *
 * //++++++++++++++++++++++++++++++
 * 20/09/2021
 *
 * По итогам совещания было принято решение :
 * 1. Для успешной презентации подготовить вариант 0 (ноль), который заключается в следующем :
 *
 * Создается Диспетчер (ответственный Семашко), управляющий роботами через http.
 * Соответственно, в текущую программу управления роботом необходимо добавить http-сервер, скелет С. Семашко уже прислал.
 *
 * В этой связи далее весь проект отпочковывается в новую ветку - demo, - где будет добавлена вышеуказанная фича.
 *
 * 2. Также, заодно следует добавить автоматическое, т.е. без нажатия кнопки, открытие serial-порта с именем ttyUSB0. Для
 * демонстрации так будет нагляднее (т.е. человек нажимает минимум кнопок для запуска взаимодействия роботов)
 *
 *
 * //+++++++++++++++++++++++++++++++++++++++++
 * 17/09/2021
 *
 * Зафиксировал размеры посылок в коде arduino:
 * - "Туда", т.е. от ПК к роботу - это 7 байт
 * - "Обратно", т.е от робота к ПК - это 32 байта.
 * Теперь даже если полезных символов в сообщении меньше 32, то в буффер уже на вставляются "посторонние" символы из последующих посылок,
 * т.к. оставшиеся байты уже проинициализированы в самом начале, т.е. нет места для "посторонних"

 * Задача :
 * В arduino проекте разместить код Go_To_Position() внутри parse_command (), чтобы не происходит перескок потока. И тогда, возможно,
 * сообщения в лог будут поступать последовательно.
 *
 * //+++++++++++++++++++++++++++++++++++++++++
 * 16.09.2021
 * Есть недоработка.
 * Если захват изображения не сработал NOT DETECTED
 *
 * Максимальная длина строки от робота имеет вид :
 * 110, 193, 129, 147, 140, 134, 49
 * Это как раз 32 байта - максимальный размер буфера TX arduino.
 * Вот поэтому один символ переходит в следующую отправку !!!
 *
 * Если в посылке от робота к ПК меньше 32 байт, то робот добавляет недостающее до 32 количество байт из последующей посылки... !!!
 * Это полное безобразие !!!
 *
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 15.09.2021
 * Встала задача сделать комплексное движение для робота :
 * - взять кубить, встать в исходное положение, положить кубик в другую область рабочего пространства робота.
 * Такой режим работы подразумевает отправку нескольких команд роботу, причем сначала должна отработать текущая команда,
 * и после этого отправляется следующая.
 * Как ПК узнает, что робот завершил текущую команду ?
 * Для этого после завершения движения всех приводов робот отправляет в ПК сообщение "Robot movevent DONE!"
 * ПК, получив такое сообщение от робота, отправляет следующую команду роботу.
 * Однако ранее робот был запрограммирован так, что получив сообщение от ПК он (робот) сразу же отправляет сообщение в ПК о полученных данных,
 * т.е. сообщает в пк, - "ДА, я получил вот такие данные". Т.е. получив 1 команду от ПК робот отправляет 2 сообщения :
 * 1 - "ДА, я получил вот такие данные"
 * 2 - "Robot movevent DONE!"
 *
 * Значит теперь, ПК, чтобы отправлять следующую команду, должен различать ответ "Robot movevent DONE!", т.е. нужно делать парсинг ответа от ПК.
 * Это сделано. ПК ищет в ответе строку "DONE!" и, найда такую, отправляет следующее сообщение.
 *
 * Как задумано это реализовать ?
 * QSerialPort имеет сигнал readyRead() (не путать с ф-цией waitForReadyRead()), означаютщий, что в RX-буфере ПК
 * есть несчитанные данные, т.е. пришла новая порция оных.
 * В класс HiWonder был добавлен обработчик сигнала readyRead() по имени ReadFromSerial_Slot();
 * Этот обработчик считывает данные из ком-порта, парсит в поисках строки "DONE!", и, если находит, то выставляет флаг MOVEMENT_DONE = true.
 * А слот, выполняющий комплексное движение робота, - MainWindow::on_trainButton_clicked(), - ждет пока этот флаг не будет установлен,
 * и после этого переходит к отправке следующей команды роботу.
 *
 * Так вот в реале прога зависает на этапе ожидания флага, т.е. вот на этой строчке
 * while (!Robot->MOVEMENT_DONE) {;}
 *
 * Как в итоге сделано ?
 *
 * Убрано ожидание установки флага.
 * Теперь все держится на том, что есть слот ReadFromSerial_Slot(), по которому данные считываются из буфера, но также важная ф-ция этого слота -
 * он блокирует остальные обращения к ком-порту, пока слот не будет обработан.
 * Благодаря этому следующая команда посылается в ком-порт только после обработки слота, однако, тогда это будет уже после первого же
 * подтверджения от робота "From Robot :", но этого не просиходит. И скорее всего, потому, что внутри робота еще не завершена ф-ция "parse_conmmand",
 * которая в этот момент запустила приводы в движение. И вот когда приводы закончат свое движение, ф-ция parse_command запустится в новом цикле,
 * и тогда только считает новую порцию из ком-порта, запустит приводы во вновь прибывшие координаты.
 *
 * "Robot movement DONE!" vs "Robot movement DONE! at all"
 *
 * //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 14.09.2021
 * Нарисовалась проблема с типом const char.
 *
 * Мы делаем отправку данных из ПК к роботу через ф-цию
 *
 * qint64 write(const char *data, qint64 len);
 *
 * Так вот при значениях угла более 127 уже не попадаем в char (который со знаком, т.е. signed char)
 *
 * сохранить ардуино файл !!!
 *
 * Пришлось руками редактировать Quiodevice.h
 *
 *
 * ##############################################
 * 10.09.2021
 * Если в поле для кнопки submit введено менее 6 параметров, разделенных запятой, то
 * по нажатию submit, в таком случае, меняется цвет фона кнопки и строки ввода.
 * В лог пишется соответствующее сообщение.
 * Программа уже не вылетает.
 * После ввода правильного количества параметров (пока 6) цвета меняются на значения по умолчанию, т.е.
 * рабочее окно программы приводится к исходному виду.
 * ##############################################
 * 03.09.2021
 * Если в строке для кнопки "Submit" вставить не 6 параметров, а 5, то прога тупо вылетает...
 * Это нужно исправить. [Сделано 10.09.2021, см. выше]
 * ##############################################
 * 02.09.2021
 * В позиции 319, 850, 0, 93, 80, 0, 130, 162 (т.е. угол 5 привода уже 130 и далеко от основания, по Y,- 850)
 * хват робота задевает кубик. ТОгда нужно двигать приводы в следующем порядке :
 * 6,5,1,4,3
 *
 * А в позиции 244, 820
 * хват поднимается недостаточно и при закрытии хватает кубик и тащит его наверх.
 * Значит при обратном движении надо сначала двигать приводы 3,4,1,5,6
 *
 * Решение :
 * Для позиций у дальнего края надо вводить поправку.
 * Если серво 5 >=130, то в ф-ции Go_To_Position(byte *pos) (код процессора) выполняется другая последовательность
 * движения приводов : 5,6,1,4,3 - так работает.
 * #################################################################################
 * 02.07.2021
 * Запустил упрощенный алгоритм FWK (Forward Kinematics).
 * Ф-ция FW_Kinemaic_Slot_02.
 * Также добавил отправку строки для записи в лог из класса RMath в MainWindow через сигнал слот Pass_StringSignal/Slot
 * соответственно.
 * Длина проекции робота на плоскость пола теперь 214.428mm ,:)
 * Будем думать, а пока фиксим на git.
 *
 * #######################################################
 * 01.07.2021
 *
 * Сделал проверку вычисления прямой кинематичесой задачи.
 * По нажатию кнопки "Get XY" внутри соответствующего слота запускаем сигнал
 * FW_Kinemaic_Signal(int S3, int S4, int S5, int l1, int l2, int l3)
 * На это внутри класса Robo_Math срабатывает слот FW_Kinemaic_Slot(int S3, int S4, int S5, int l1, int l2, int l3),
 * Который проводит вычисления x,y,z для всех 3 звеньев l1, l2, l3. И полученные конечные значения x3, y3, z3 отправляет
 * сигналом Return_FW_Kinematic_XYZ_Signal(x3, y3, z3) в класс MainWindow, где соответствующий слот
 * Return_FW_Kinematic_XYZ_Slot(int X, int Y, int Z) записывает эти данные в лог.
 *     Код работает, но в расчетах где-то ошибка, врет сильно.
 * Учёл, что координаты кубика начинаются с дальнего от робота угла. Т.к. при движении кубика от робота
 * координата Y будет уменьшаться. А координата x должна быть почти неизменной, т.к. снимали точки при движении вдоль оси Y.
 *
 * Тогда ключевой индикатор сейчас - координата Y, а она-то как раз близко : 362 вместо 356 !
 * Длина проекции робота на плоскость пола должна быть 230, а вычисляется 208.659
 * dl1 = 119,08
 * Экспериментальным путем увидел, что при угле 0 на приводе 4. Угол между 4 и 5 звеньями не 90, а заметно больше.
 * ДОбавил к вычислениям с углом привода 4 поправку в 15 градусов.
 * Измеренеия проекции на пол делал от центра основания, а надо от центра привода 5.
 * Т.е. в итоге длина короче на 12-15мм.
 * Сделал поправку в 7,150. Так же учел, что координаты x,y получем в пикселях, а при вычислениях используем мм.
 * Потом делаем обратное преобразование из мм. в пиксели.
 * НА участке в 200мм координата Y изменяется на 675 пикселей, значит на 1мм приходится 3.375 пикселя.
 * Сейчас после "подгонки" через поправку в 7.15 градусов значение проекции уже 227.351 - близко к 230.
 * Также понял, что можно по-другому считать все углы, и это упрощает общий алгоритм, и уменьшает число операций.
 * Поэтому пока фиксируем, а потом будем упрощать :)
 *
 * commit 64cddd400699a26d8a187d5d6c9839b68f25590f
 *
 *
 * #################################
 * 29.06.2021
 *
 * Создал класс class Robo_Math : public QObject
 * Для вычисления значений углов через длину робота -> через значения XY центра кубика и угол поворота привода 6.
 * Т.е. это дополнительный к нейронке способ вычисления.
 *
 * Жмем кнопку "Get XY", в соответствующем слоте получаем XY от simpledetector.
 * И передаем значения XY через сигнал Pass_XY_Signal в класс Robo_Math
 * В классе Robo_Math этот сигнал обрабатывается слотом Pass_XY_Slot.
 * Этот слот по значениям XY вычисляет длину EL(float) и передает значение EL обратно в класс MainWindow.
 * Передача проиходит через сигнал Return_EL_Signal(EL), а в классе MainWindow обработку проводит
 * слот Return_EL_Slot(float EL), который выводит значение EL в лог.
 *
 * Проверил на тестовых данных - все работает, данные из класса в класс передаются.
 * Теперь возникает следующая задача.
 *
 * ДЛя простоты считаем, что кубик лежит прямо напротив робота и привод 6 не надо поворачивать.
 * Тогда проекция робота на пол в момент, кода он готов взять кубик, это есть некая длина L.
 * Эту длину легко вычислить, зная углы приводов 5,4,3 и длину соответствующих плечей робота.
 * А вот как сделать обратные вычисления - зная длину L из координат центра кубика X,Y - как вычислить значения 3 углов ?
 * Подбором-перебором ?
 * Такая задача называется Inverse Kinematics (IK) technology
 * ######################################
 * 25.06.2021
 * Т.к. теперь мы разделяем движение "туда" и "обратно" были внесены необходимые изменения
 * во все соответствующие ф-ции.
 *
 * 02.09.2021 А теперь подробнее.
 * Теперь в посылку для робота добавляется 7-й параметр, он же 9-й в строке "Training data..."
 * При движении "Туда", т.е. в исходную позицию это код 0x31 == 49(в десятичной системе)
 * А при движении "Обратно", т.е. это в исходную точку по кнопке "Stand UP" - это код 0x30 == 48 (в десятичной системе)
 * ######################################
 * 19.06.2021
 * Добавил ввод данных для приводов из строки - All_Servos_lineEdit
 * И вслед за этим обновление текста в QSpinBox-ах.
 *
 * ##############################
 * 14.06.2021
 *
 * Кажись заработало "Пробуем QSpinBox вместо QLineEdit"
 * Т.к. большой размер шрифта, то и общее окно программы пришлось увеличить.
 * Фиксируем.
 * #######################
 * 12.06.2021
 * Пробуем QSpinBox вместо QLineEdit
 *
 * servo_1_lineEdit
 * servo_1_spinBox
 * servo_2_spinBox
 * ...
 * Очень много провозился.
 * Оказывается, если в окне "Change StyleSheet" сначала поставить размер шрифта, то все остальные настройки не считываются.
 * Поэтому размер шрифта меняем в самом окне QtDesigner, а далее через "Change StyleSheet"
 * #######################################
 * 10.06.2021
 * Each QWidget has slots repaint() (forced immediate) and update() (queued deferred)
 *
 * Выяснилось, что процедуру захвата лучше разделить на 4 этапа
 * 1. Позиционируем из исходной, захват горизонтально над кубиком. Далее 6 привод не меняется.
 * 2. ОТкрываем захват
 * 3. Чуть опускаем (3,4,5 приводы)
 * 4. Делаем захват.
 *
 * Можно сразу вставать в п.3
 *
 * Дальний ряд (ДР) - (4,5) = (45,155)
 *
 * #############################################
 * 08.06.2021
 * Заменил тип массива Servos на usigned char.
 * Для этого пришлось переписать ф-цию отправки данных роботу - HiWonder::GoToPosition(QByteArray &position),
 * и ф-ции вывода данных на печать.
 * Поведение робота от этого не изменилось, значит точно нейронка неправильно работает.
 *
 * Последний рабочий коммит 765014e4ae86b918485ae40a31d33f283eb85016
 * Фиксируем.
 * коммит с этим фиксом  ba7a1effc39f82f9073fc5d3ce7494d81a074cd0
 * #############################################
 * 07.06.2021
 * Подключаем библиотеку mcinfer
 * ...
 * Заработало. НЕ путаем сборку debug  и release :)
 *
 * Порядок работы :
 * Подключаем веб камеру по usb
 *
 * Запускаем скрипт
 * ~/qt-projects/iqr_lit/simpledetector_cpp/.run.sh
 *
 * Запусаем hiwonder-qt
 * По нажатию кнопки "Read Detetor" ( слот "on_socketButton_clicked()" ) Происходит считывание данных из сокета  - это координаты x,y центра кубика.
 * Далее эти координаты передаются в нейронную сеть fuzzy_model на обработку и сеть возвращает положения углов
 * приводов 3-6 робота - это 4 числа в диапазоне 0 - 180.
 * Приводы 1-2 почти не используются - это захват и положение захвата в горизонтальной плоскоскти.
 *
 * ###################################################
 * 03.06.2021
 * Работаем на ветке hw-qt-class
 * Запускаем класс hiwonder
 * ...
 * Запустил.
 * Скорее сего было лишним указывать, что класс HiWonder имеет родительский класс QOBJECT.
 * Закомментировал, работает и без этого.
 * Добавил ф-цию :
 * void GUI_Write_To_Log (int value, QString log_message); //Пишет в лог-файл номер ошибки value и сообщение message
 *
 * Теперь запись в лог (один и тот же) есть и в классе HiWonder и в MainWindow.
 * Делаем фикс перед последующим переносом работы с ком-портом в класс HiWonder.
 * Пока еще запись в ком-порт из главного окна.
 *
 * commit 797ac2dac91d262a6c282a2163f0e8285f08c54f
 * #####################
 *
 * Теперь переносим работу компорта в класс HiWonder из класса MainWindow.
 * По нажатию кнопки генерим сигнал Open_Port_Signal, в ответ запускается слот Robot->Open_Port_Slot
 * Работа с ком-портом перенесена в класс HiWonder.
 * Доработана запись в лог. Еще нужно данные записывать в лог в виде строки.
 *
 * На очереди считывание из ком-порта.
 *
 *
 *
 * +++++++++++++++++++++++++++++++++++++++++++
02.06.2021
Решено переписать на qt всю программу управления роботом, т.к. библиотека нейронной сети написана на С++
Попробовал подключить форму form.ui, сделанную ранее для python (однако в Qt Designer), и не пошло.
Проект не компилируется.
Оказалось, что в файле form.ui, переименованном в mainwindow.ui имя окна значилось "main", а надо "MainWindow"


- Открываем лог-файл, пишем сообщение о начале работы программы
- Открываем порт по нажатию кнопки "OPEN"
- Отправялем данные в порт (лампочки мигают)... и робот не реагирует
...
По ошибке отправлял hwr_Start_position вместо sit_down_position вот он и стоял на месте.
Теперь-то все работает :) !!!!!

- Работают кнопки "SIT" и "Stand UP"
- Переходим на ветку git hw_class и создаем в ней класс hiwonder

*/
#endif // EVKUZ_H
