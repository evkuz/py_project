﻿/*
Записи по проекту timer12_serial


- Правое - Am2
- Левое  - Am1 

При включении скорости 100 на 1с. имеем следующие показания М1, М2 :

АМ1 = 978
АМ2 = 1192
Ош  = 214

Либо

АМ1 = 1703
АМ2 = 2037
ОШ  = 334

AM1 = 3499
AM2 = 4125
ОШ = 626

AM1 = 5133
AM2 = 6086
ОШ = 953
*/
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
 * about SERIAL_TX_BUFFER_SIZE
 * https://github.com/arduino/ArduinoCore-avr/issues/177
 * 
 * Общие нюансы :
 * 
 * - Пол неровный, из-за этого колесо тормозит(почти до полнлой остановки) и тележка смещается
 * - при большой скорости колесо проскальзывает
 * - Инерционность отклика
 * 
 * //+++++++++++++++++
 * Сохраняем все на git
 * //++++++++++++++++++++++++++++++++++++++
 * Список команд
 *
 * char commandList = ["blink", "start", "stop", "moveon", "setPID", "reset", "getValues" ,"samplingTime"];
 *
 * Режимы работы
 *
 * char modeList = ["moving", "pid", "finish--", "stop", "starting"]
 *
 * - Правое колесо - Am2 поехало на скорости 22
 * - Левое - Am1 -||-                        29 - отстает
 * 
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 02.11.2023
 * Почему-то сразу после "started" заходит в "pid" (через 10мс), а должен еще дождаться, пока пройдет pidTime, а это 200мс.
 *
 * Массив *p++ = data; при выходе из ф-ции EK_split_str() теряются данные массива **p
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 31.10.2023
 * Коэффициент Ki не доходит до Ардуино из ПК по команде "setPID". [Поправил]
 * Вот теперь, когда все коэффициенты пишутся и указатели указывают правильно :) начнём подбор коэффициентов ПИД.
 * ...
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 17.10.2023
 * Следует отметить, что значения коэффициентов kP, ki, kD  для режимов “на вису” и “на полу” разные.
 * Соответственно можно проверить методику отбора в разных рабочих условиях.
 * 
 * Режим "на вису" нам крайне важен, т.к. в этом случае мы можем запитывать робота от сети питания.
 * Соответственно, надо переделывать ПО, чтобы учитывать в каком режиме работает робот.
 * От режима зависят следующие параметры :
 * 
 * - органичитель верхней/нижней скорости
 * - интервал времени PID, т.е. время, через которое вызывается пид-регулировка
 * - напряжение старта, при котором колесо начинает вращаться
 * - Напряжение остановки, при котором колесо перестает вращаться (не обязательно 0)
 * 
 * Создаем массив modeParameters[], куда будем записывать параметры текущего режима из соответствующего массива.
 * Т.е. будет 3 массива. 2 - с параметрами двух режимов, а 3-й - с параметрами текущего режима.
 * 
 * 
 * Перед всеми изменениями заливаем на git.
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 03.08.2023
 * Пора разбираться с эффектом перескока по времени, когда запись millis() соответствует 2-ному или 3-ному интервалу pidTime.
 * Почему так происходит ???
 * За это "тёмное" время разница E убегает очень далеко и ПО не вмешивается...
 * Есть обычная ситуация, где это разрыв между "stopped" и "started", там действительно большой интервал и никаких ПИД еще не включается.
 * Но кроме этого еще есть перескоки и посреди движения.
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 02.08.2023
 * Чуть уточнили скорости запуска.
 * //++++++++++++++++++++++++++++++++++++++
 * 01.08.2023
 * Добавляем значения переменных startM[12]Speed в посылку Ардуино--->ПК. (Уже сделано, переменные data.[lag,fwd]Speed_ptr)
 * Как раз значения скорости после уменьшения.
 * У нас есть 4 переменных типа int, которые сейчас не несут полезной нагрузки.
 * Kp==0 в файле data.csv - почему ???
 * В python-прогрмме до запуска потоков в Ардуину отправляются pid-коэффициенты. И где-то там Kp теряется...
 * ...
 * Мистика в ф-ции  int separate (String str, char **p, int size )
 *
 * При вызове этой ф-ции в виде
 *
 * #define SPTR_SIZE   20
 * char   *sPtr [SPTR_SIZE];
 *
 * int N = separate (str, sPtr, SPTR_SIZE);
 * Получаем массив sPtr с указателями на короткие строки.
 * Так вот при первом считывании данных из sPtr - всё норм, а при последующих сбивается адрес начала,
 * т.е. элемент sPtr[0] содержит мусор.
 * В итоге использую считывание sPtr[0] только 1 раз и все норм.
 *
 * При записи данных в data.csv все ПИД-коэффициенты записываются с огромным количеством знаков после точки.
 * Нам столько не надо, хватит и 4.
 * Поэтому, перед записью в файл округляем до 4 знаков после точки.
 * fDeriv = "%.4f" % fDeriv
 * И стало красиво.
 * И файл меньше размером.
 *
 * Теперь задача:
 * - "подкручивать" стартовые значения, чтобы начинала ехать ровнее.
 *   В конечном итоге все упирается в стартовые значения.
 *   А вот их тоже можно генетическим алгоритмом выбирать.
 * - Добавляем функционал по поиску мин/макс значений, выводу в консоль, записи в отдельный файл.
 *   Пригодятся для отбора потомков.
 *   Критерий отбора - максимально среднее Е за все время стремится к минимуму.
 *   ...
 *   Постановка задачи - уже отдельная тема.
 * - Подобрать ПИД коэффициенты.
 *
 *
 * Сохраняем на git
 *
 *
 *
 *
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 31.07.2023
 * Пишем ф-цию определение скорости "отрыва от земли" - сила тока, при которой каждое из колес начинает вращаться.
 * void findStartCurrent() - [Сделано.]
 *
 * - Значения startM[12]Speed следует записывать в файл. Чтобы при следующем запуске робота эти значения считывались.
 * - Уже пора отделить статус или режим работы от currCommand. Они в нормальном режиме "самоконтроля" должны влиять друг на друга.
 *   Так мы будем учитывать, что между приходом команды и тем, как она будет исполена есть некоторые промежуточные действия над роботом.
 *   И эти действия могут приводить к ошибкам, не выполняться и т.д.
 * ...
 * Значения для старта из положения "на вису" - намного меньше, чем в положении "на земле"
 * При работе ф-ции startPlatform платформа, конечно, трогается, но тут возникает ситуация, когда ток для "медленного" колеса еще недостаточный
 * для вращения, а у быстрого уже достаточный и быстрое начинает "тащить"  медленное - так платформа едет, но сразу криво, т.к. медленное колесо
 * фактическе без своего двигателя.
 * Вот тут по уму надо включать пид.
 * Или надо как-то зафиксировать, что колесо не от своего двигателя толкается, а от соседнего.
 *
 * Т.к. время настройки скоростей при трогании довольно большое, то надо elapsedTime отсчитывать с момента завершения ф-ции startPlatform
 * ...
 * Все работает :) Едет более-менее нормально.
 * ВОзможно надо поточнее настроить разницу скоростей при старте и замедлении.
 * Долго стартует.
 *
 *
 *
 *
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 28.07.2023
 * Определили разные значения для startM1Speed, startM2Speed
 * После начала движения у нас скорость понижается до startM1Speed, startM2Speed соответственно.
 * Это самая малая скорость движения. НО... есть неровности на дороге.
 * Поэтому после начала движения скорость замедляем не до [startM1Speed, startM2Speed] - это порог.
 * А до чуть большего - в данном случае на 5 - значения.
 * Для разных неровностей может быть разное, но пока такого оказалось достаточно.
 * А вообще, робот должен сам эти прибавки вычислять и обновлять. (на будущее)
 *
 * Далее будем тестировать фиксацию факта остановки из-за неровностей с последующим увеличением скорости.
 * Состояние остановки проверяем по таймеру.
 * Причем пришлось разделить переменные posAm1_prev - это внутри loop, и TimerA1_prev - это внутри таймера.
 * Иначе внутри таймера почти всегда значения posAm1_prev совпадают :).
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 26.07.2023
 * Создаем новый режим "starting". В этом режиме после начала движения тележки уменьшаем скорость до значения, близкого
 * к порогу остановки.
 * Вот теперь ищем это пороговое значение.
 * ...
 * - 18 для режима "на вису"
 *
 * Пока вся работа в статусе "на вису"
 * Поймав эти скорости, будем увеличивать начальную скорость "слабого" колеса, т.е. стремиться, чтобы колеса стартовали максимально
 * одновременно
 *
 * В таком случае команда "moveon" предполагает, что сначала тележка входит в режим "starting", а затем в "moving".
 * Т.е. полный цикл состояний(статусов)
 * "stop"--->"starting"--->"moving"
 *
 * Добавляем переменную status. Уже пора отделить статус или режим работы от currCommand.
 *
 * Тогда и логику работы в основном цикле меняем?
 * В статусе "stop" - принимаем команды
 * В статусе ""
 *
 * Нашли нижнее пороговое значение, при котором слабое колесо останавливается - фиксируем его.
 * Сегодня это 20 (позавчера было 18)
 * Сегодня старт слабого колеса на скорость 32 (позавчера 29)
 *
 * Плавно подходим к написанию ПО, которое будет каждый раз устанавливать оптимальные скорости для колес, при котрых у них
 * показания энкодеров будут соответствовать прямолинейному движению.
 *
 * - Вручную подобрали скорости близкие к порогу остановки
 * - На земле :
 *      VectorDiff=2, m1Speed=82, m2Speed=67
 *
 * Если замедление до 82/67 резко, то останавливается. Надо сделать плавнее
 *
 *
 * Нет движения после команд "m+", "A1+". Значения m1/2Speed увеличивается, а движения нет...
 * Возможно статус? Текущая команда ?
 *
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 25-26.07.2023
 * Ищем "вручную" минимальную скорость "отрыва" и "движения" для обоих колес в режиме "на полу"
 *
 * VectorDiff=1, m1Speed=28, m2Speed=26,
 *
 *

 *
 * 
 * //++++++++++++++++++++++++++++++++++++++
 * 24.07.2023
 * Поскольку в ПД-законе фигурирует сигнал "в предыдущий момент времени", то очень важно, чтобы интервал
 * времени сбора информации выдерживался как можно более строго. Если время "будет плавать", то ни о какой 
 * адекватности реакции системы речи быть не может.
 * При этом точность интервалов должна быть около 1% (!)
 * 
 * В нашем файле data.csv периодически наблюдаются "провалы" по времени, и это внутри цикла loop, без всяких таймеров...
 * 
 * Для этих целей следуеть попробовать отказаться от обработки прерываний от энкодерова B1, B2
 *
 * Установлено, что коэффициенты П И Д - получаем правильно.
 * А вот со временем measureTime pidTime какие-то проблемы.
 * НЕ увеличивает счетчик циклов...
 *
 * Добавляем в посылку поле strData длиной, скажем 43 байта. Будем там хранить отладочные данные.
 *
 * Теперь длина посылки 107 байт.
 * ...
 * Надо разделить время запуска, т.е. время на разгонку двигателей из состояния покоя и время measureTime
 * Т.е. сначала запускаем, а потом начинаем считать.
 * Хотя сейчас так и есть.
 * Сначала ф-ция startNoTimer увеличивает постепенно ток и как только девайс трогается с места выходим из ф-ции.
 * Далее фиксируем время и его считаем временем старта.
 *
 * Далее все в режиме "на вису"
 *
 * - Правое колесо - Am2 поехало на скорости 22
 * - Левое - Am1 -||-                        29
 * При этом, после Движения обоих колес на скорости 29 постепенно уменьшаем сорость до 20 и оба все еще едут.
 *
 * Соответственно, нужно вводить команду типа "minimalSpeed", которая будет находить минимальную скорость, при которой тележка трогается...
 * Вот вам и методика настройки ПИД.
 *
 * Сама по себе задача - "найти минимальную скорость, при которой тележка трогается" - тянет на отдельную программу.
 *
 * Считаем, что делаем ПО универсальную для разных покрытий. Поэтому вначале всегда потребуется найти минимальную скорость движения для
 * каждого конкретного случая.
 *
 * Алгоритм.
 * ...
 *
 * Добавили команды :
 * "setspeed" - устанавливает скорость обоих колес равную speedBottomLimit
 * "m+" - Увеличивает скорось обоих колес на 1
 * "m-" - Уменьшает скорость обоих колес на 1
 *
 * Ищем "вручную" минимальную скорость "отрыва" и "движения" для обоих колес в режиме "на полу"
 * При каждом запуске "на полу" эта скорость будет отличаться на +/- 5 пунктов...
 *
 * Со стороны ПК нам поможет ga_debuginfo_comport.py
 * 
 * //++++++++++++++++++++++++++++++++++++++
 * 18/07/2023
 * - Добавляем к списку параметров от ПК число циклов запуска платформы. [Сделано]
 * - Добавляем к списку параметров от ПК время в мс работы PID-коэффициентов, по умолчанию 200мс.
 * 
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 14.07.2023
 * Задаем время движения - measureTime - как параметр, передаваемый из ПК.
 * Соответственно, под это создаем здесь команду "samplingTime"
 * 
 * //++++++++++++++++++++++++++++++++++++++
 * 13.07.2023
 * - Цикл ком-порта ПК ---> Ардуино ---> ПК периодически блочит движение.
 *   Пока решаю паузой в 1с на стороне ПК, но это, конечно, костыль.
 *
 * - Сделано получение коэффициентов ПИД по команде "setPID".
 *   Значения коэффициентов приходят в строковом виде, преобразуются во float.
 *   Также пробовал передавать строковые значения long умноженные на 10000 float, а при получении в Ардуине - делить
 *   на 10000, соответственно. И так и так работает.
 *
 * - Жутко много времени угроблено на отлавливание, почему первый коэффициент передается 0, а 2й - нормально...
 *   ТАк и не понял. Само заработало в какой-то момент.
 * - Размер посылки Ардуино --> ПК теперь 64 байт. Это добавлены ПИД-коэффициенты. С расчетом на будущее, когда
 *   ПО будет по ГА менять ПИД-коэффциенты, передавать их в Ардуину, соответственно, чтоб была обратная связь и записано в файл.
 *
 * - Еще нужно сделать получение переменной measureTime по команде "setPID".  Когда тележка стоит на полу, то больше времени уходит на трогание
 *   с места.
 *
 * - Еще нужно добавить команды поворота на 30;45;60 и т.д градусов из положения покоя. Это нужно будет когда на прошлом цикле унесло и
 *   робот стартует уже в НЕправильном направлении. Тут надо будет руками возвращать в нужное направление.
 *
 * Чётко видна проблема, что на 2-ом цикле движения одно колесо сильно "уносит" и уже не вернешь. Тут надо проверять на более длительных
 * интервалах.
 *
 *
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 11.07.2023
 *  float Kp = 0.0235;
  float Kd = 0.0275;
  float Ki = 0.01;

   Иногда хорошая картинка - но не регулярно.
   Картинку оцениваю по последнему значению E. Должно быть в пределах encodersGAP

   - Делаем отправку ПИД-коэффициентов из ПК [В процессе]
   * - Получил рабочий код, в котором происходит отправка команды "setPID"
 * - Получил подтверждение, что Ардуина видит эту команду, добавляет данные от себя.
 * 
 * Пока обошел проблему с однократным циклом обмена отправка/прием ПК<----->Ардуина, но вообще-то надо разобраться.


  
 
 * //++++++++++++++++++++++++++++++++++++++
 * 10.07.2023
 * Добавляем запись в файл поля "char mystatus[8];" в структуре ENC
 * Так сможем отслеживать смену состояний, в том числе полную остановку платформы.
 *
 * В момент наибольшего dltE у нас как раз происходит смена отстающий-обгоняющий, они меняются местами.
 * В этот момент должно быть наибольшее u, но этого непроисходит из-за deltaT. В этот момент deltaT обычно в 5 раз больше(а поэтому и
 * de/dt в 5 раз меньше), чем на предыдущем шаге.
 * Почему так ? Почему такое большое deltaT ??? оно должно быть примерно одинаково.
 * Скачок в dltE всегда происходит при увеличенном интервале. И, соответственно, u - тоже увеличенное
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 07.07.2023
 * Залить на гит!
 * 
 * 
 * //++++++++++++++++++++++++++++++++++++++
 * 06.07.2023
 * Берем на заметку, что текущий размер посылки уже 48 байт, что больше стандартного размера 32 байт для буфера TX у компорта Ардуино.
 * Т.е. каждая посылка  уже в 2 захода...
 * Сохраняем переменные elapsedTime, movingTime.
 * ...
 * Нашел логическую ошибку в коде. Теперь заходим в ПИД чётко ! ЗАодно отработал технологию ловли таких вот тупых ошибок.
 *
 * Теперь задача :
 * - Фиксировать момент остановки колес. (т.е. включаем таймер после currCommand = "stopped")
 * - Отсылать значение E = posA1 - posA2  в ПК после полной остановки колес.
 *
 * Это значение (Е) как раз и будет анализировать ГА для формирования ПИД коэффициентов.
 * Учитываем, что есть разница между posA1 в момент истечения measureTime и к моменту полной остановки колеса !
 * - Записать эти значения в файл !!!
 *
 *
 * 
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 05.07.2023
 * - Установил минимальную скороть движения в режиме "колёса в воздухе" - 24
 * Будем работать на малых скоростях, чтобы pid успевал срабатывать.
 * Если пид будет срабатывать на малых скоростях, то колесо вообще может остановиться.
 * Поэтому рабочую начальную скорость сделаем равной 50.
 * 
 * Пока не закходит в pid() ...
 * ...
 * Заходит, но только один - самый первый раз. И т.к. это loop, то, пока не истечет время measureTime, - все время заходит в pid(), т.е. примерно каждые 4мс - что правильно.
 * Но после 1го срабатывания - пропускает.
 * 
 * ПОтом пропускает
 * Надо записывать в файл значения elapsedTime, movingTime - это еще 8 байт.
 * Для этого надо менять структуру.
 * 
 *
 * 
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 04.07.2023
 * Изменил смысл команды "moveON".
 * Теперь по этой команде платформа едет 5с., останавливается и передает в ПК значения posA1, posA2, и т.д.
 * НА стороне ПК полученные данные пишутся в файл.
 * Это прицел на будущую работу с ГА.
 * Планируется, что ГА будет запускать на 5с. тележку, анализировать значения энкодеров и т.д. и по результатам менять PID коэффициенты.
 * Под "менять коэффициенты" подразумевается, что ГА будет работать на стороне ПК, и отдельной командой отправлять значения ПИД-коэфиициентов.
 * И после смены оных, снова запускать "moveON".
 * 
 * Задача:
 * - Парсить строку из float-данных
 *   Сейчас из строки "setPID 0.25 1.37 2.2345"
 *   пока просто отрезаем первые 7 символов и получаем строку
 *   "0.25 1.37 2.2345"
 *   Дальше надо правильнро распарсить.
 *   Для начало было бы хорошо привести все числа к единому формату, когда после точки идут 4 цифры.
 *   Пишем парсер вручную, гугл в помощь.
 *
 * //++++++++++++++++++++++++++++++++++++++
 * 03.07.2023
 * Т.к. тестируем "на вису", то корректируем параметры
 * - начальная скорость
 * - время таймера
 * - порог срабатывания ПИД
 * 
 * //++++++++++++++++++++++++++++++++++++++
 * 30.06.2023
 * - Уменьшил время таймера до 60мс.
 * - Снизил порог срабатывания ПИД до 10.
 * Теперь ошибка уменьшается, но при этом тележка встает, т.к. скорости падают ниже порога начала движения.
 * ЧТобы тележка не вставала ввел нижний порог скорости speedBottomLimit = 65, ниже которого скорость не опускается.
 * И если скорость одного колеса снижается до порога, то другое колесо уменьшаем на 20% (А не шаманство ли это уже ?)
 * В какой-то момент начинают зашкаливать цифры для millis(), и дальше в файл пишутся космические значения скорости...
 * 
 * posA1 millis приходят сумасшедшие.
 * Увеличил время таймера до 0.25c - пропали глюки с космическими цифрами, программа завершается нормально.
 * Задача :
 * -  Сделать из файл вывода "demofile.txt" табличку, так более читаемо будет и смогу лучше анализ проводить.
 * - Проверить "инерционность" отклика через И/Д коэффициенты
 * 
 * //+++++++++++++++++++++++++++++++++++++++++++
 * 29.06.2023
 * Если ПИД уменьшает одно из колес так, что оно не едет, то начинается отлов этой ситуации - разница между прошлым и текущим значением равна 0.
 * Нот тут жеж колесо еще может ехать по инерции...
 * 
 * Также логический тупик.
 * Пид уменьшает скорость колеса, и если за цикл таймера колесо проезжает очень мало, то считаем, что колесо стоит.
 * А если так и нужно, чтобы колесо ехало очень медленно ? А вот не надо доводить до этого. Надо плавно менять скорость вращения.
 * 
 * Почемуто обнулилось. Т.е. случился stop
 * 
 * posA1= 493, posA2= 493, E= 0, Eprev= 14, m1Speed= 75, m2Speed= 107, dltE= -14
   diff_posAm1= 30, diff_posAm2= 44, millis = 24761, delta_T = 1234.5677490234375, de/dt = 0.7210000157356262, P = 0.0, py_dedt = -0.011340001398120289, I = 0.0, D = -0.0005670000699060145, u = 0

   posA1= 157, posA2= 182, E= -25, Eprev= 0, m1Speed= 94, m2Speed= 94, dltE= -25
   diff_posAm1= -336, diff_posAm2= -311, millis = 28317, delta_T = 1234.5677490234375, de/dt = 0.7210000157356262, P = -3.75, py_dedt = -0.020250002496643375, I = 0.0, D = -0.0010125001248321689, u = 4

Между записями 4с. Т.е. 

...
В целом ездит правильно. 
Теперь строим график E(t), смотрим, как "плавает" вверх-вниз ошибка.
 - Et_00.txt График из этого файла показывает, что ошибку "разносит" на длительном участке времени.
 Сохраняем на гит перед сменой коэффициентов.

 Файл Et_01.txt  Kp = 0.15; Kd = 0.05; Ki = 0.01;
                
                 Kp = 0.15; Kd = 0.05; Ki = 0.01; Et_02.png

                 Kp = 0.17; Kd = 0.05; Ki = 0.01; Et_03.png

 Отставание слабо сокращается. Увеличил все коэффициенты, чтобы ускорить.

                  Kp = 0.17; Kd = 0.1; Ki = 0.05;

 * 
 * 
 * 
 * 
 * //++++++++++++++++++++++++++++++++++++++++++++
 * 28.06.2023
 * Обращаем внимание, на первые 2 шага нашего  ПИД ( это 4 строчки лога)
 * 
 *posA1= 2070, posA2= 2110, E= -40, Eprev= -39, m1Speed= 73, m2Speed= 73, dltE= -1
 diff_posAm1= 2070, diff_posAm2= 2110, millis = 20945, delta_T = 0.12455199658870697, de/dt = -8.028775215148926, P = -10.0, py_dedt = -8.028775349962308, I = -0.004982079863548279, D = -0.4014387674981154, u = 10

posA1= 2463, posA2= 2418, E= 45, Eprev= 38, m1Speed= 83, m2Speed= 63, dltE= 7
 diff_posAm1= 393, diff_posAm2= 308, millis = 22821, delta_T = 0.12455199658870697, de/dt = 56.2014274597168, P = 11.25, py_dedt = 56.20142744973616, I = 0.0006227599829435349, D = 2.8100713724868083, u = 14

Время прошло почти 2 секунды !!! 
И все убежало за это время...

 * 
 * 
 * 
 * //+++++++++++++++++++++++++++++++++++++++++++++++
 * 27.06.2023
 * Создадим отдельную ф-цию для команды "start".
 * Будем вызыват её, если под действием PID тележка останавливается.
 * 
 * //++++++++++++++++++++++++++++++++
 * 22.06.2023
 * Нужно отладить через SerialMonitor Arduino вывод float значений delta_T и dedt. [Сделано]
 * При передаче через ком-порт есть фича в том, что данные приходят в bigendian формате, а это float число.
 * И как его правильно декодировать ?
 * Поэтому в сериал мониторе посмотрим сами float значения.
 * А потом разобраться, как это передать питону.
 * 
 * Есть ошибка в логике.
 * Если u<0, то оно все равно прибавляется к отстающему колесу, и оно отстает еще больше
 * И отрицательное значение вычитается из опережающего, т.е. оно в итоге опережает еще больше.
 * 
 * Т.е. коэффиценты ПИД должны быть такие, чтобы для отстающего колеса всегда было положительное u.
 * Нужна взаимосвязь меджу Kp и текущей скоростью. Если скороть больше, то и Kp должен быть больше.
 * 
 * - Поставил ограничение на величну u, чтобы колеса не разгонялись слишком.
 * 
 * В общем, надо разобраться со знаком для u
 * Если колесо m1 отстает, то E<0, что приводит к u<0
 * B de/dt < 0 при уменьшении E, т.е. E < Eprev
 * 
 * Получается, что P вносит меньшее воздействие, чем D. А это правильно ?
 * 
 * 
 * 
 * //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 21.06.2023
 * - Добавляем в структуру данных время, пока в millis() [Сделано]
 * - Добавляем регулировку через ПИД
 * 
 * u(t) = round((float)Kp*E(t) + (float)Ki*I + (float)Kd*dedt); // Управляеющее воздействие...  
 * 
 * E(t) = разница между posA1 posA2
 * Соответственно Коэффициент Kp должен быть связан с величиной ошибки и скоростью
 * Помним, что на скорости 100 совершаем 1 оборот за 1с. А таймер у нас срабатывает каждые 500мс.
 * 
 * Se(t)dt  = Eint + Edt
 * dedt = (E - Eprev)dt
 * 
 * Надо ввести параметр - скорость вращения. Это число оборотов за ед. времени. у нас это число оборотов относительно числа в счетчике таймера.
 * Оно разное в зависимости от скорости.
 * 
 * mxA - число отсчетов за 1 оборот
 * N = 1 оборот за 1с. на скорости 100, тогда на скорости 200 N = 2. Значит имеем формулу подсчета количества оборотов за данное
 *       время на определенной скорости:
 * 
 * N = (currSpeed/refSpeed)*(deltaT(ms)/1000), где
 * - currentSpeed - текущая скорость
 * - refSpeed - скорость, относительно которой считаем,  - базовая или референсная
 * - deltaT(ms) - время в мс, за которое считаем.
 * 
 * Соответственно, это число N - связано с величиной ошибки.
 * Ошибку E считаем в отсчетах энкодера. Е связано с N 
 * 
 * Чем больше Е относительно mxA, тем больше нужно управляющее воздействие.
 * 
 * Попробуем отказаться от идеи учесть все зависимости в одном коэффициенте П.
 * По самой идее пида П - пропорционален текущей ошибке, а 
 * Д - учитывает скорость изменения ошибки, и вот тут, наверное, надо учесть величину поворота колеса относительно полного 
 *     оборота в зависимости от скорости.
 * 
 * Уже остро чувствуется необходимость использовать git...
 * 
 * //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 23.06.2023
 * Нужно поймать момент, когда при текущих значениях скорости колеса поворачиваются на одинаковое значение энкодеров.
 * 39 - порог скорости, при котором тележка встает и больше не едет.
 * 
 * Задача :
 * Добавить в обработчик таймера проверку, что если ПИД не запускается, то сравнить показания энкодера между текущим значением
 * и предыдущим для каждого колеса, и если разница 0, значит колесо стоит ! итогда увеличиваем ток !
 *
 * 
 * //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 20.06.2023
 * - Колёса стартуют не одновременно, это четко видно. Даже при очень плавном пуске.
 * - При плавном пуске, если одно колесо стартует раньше, то второе может и не запуститься, т.к. для этого - второго всеравно не хватает тока.
 *   Тут должен включаться ПИД !
 * - Сделал очень плавный пуск. Ф-ция MoveIfStopped()
 *   Выяснилось, что при движении со скоростью примерно 75 (очень медленно, но едет !) на определенных участках пола
 *   настолько неровно, что тележка не может ехать.
 *   Поэтому ф-ция MoveIfStopped() добавлена в запуск из таймера по логическому флагу "startFlag"
 * - Ждем теста на полиогне. Сел аккум для Jetson NANO
 * - Даже при медленном движении тележка смещается из-за М1, которое крутится чуть быстрее. Разница в показаниях меньше 20.
 * - Переделал обмен с ПК. Теперь в посылке для ПК только численные данные, без строк. Это всего 12 байт, которые в Ардуино
 *   упакованы в структуру
 *   struct Enc {
        word A1_Enc;
        word A2_Enc;
        short diff;
        short diff_vector;
        int M1_Speed;  // Не более 255, знаем. Штатное значение - 100, поэтому для "торможения" или "обгона" 255 должно хватить 
        int M2_Speed;
        
      };
 * 
 * 
 * 
 * 
 * //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 19.06.2023
 * Включаем связь П-коэффициента с ошибкой.
 * 
 * //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 16.06.2023
 * Заливаем скрипт из ПК в тележку:
 * 
 * rsync -av /home/ubuntu/pyprojects/mobplatform/py_serial/bin_comport.py nvidia@192.168.1.176:/home/nvidia/pyprojects/mobplatform/py_serial/
 * 
 * После срабатывания условия в процедуре pid() перестаёт изменяться знечение энкодера А1.
 * При этом колесо крутится.
 * ...
 * А это потому что неправильно вычислялась строчка
 * 
 * delta = abs(abs(posAm1 - posAm2) - encodersGAP);
 * 
 * Которая выдавала отрицательные значения для delta
 * Пришлось разделить на 2 строчки :
 * 
 * delta0 = abs(posAm1 - posAm2);
 * delta = abs(delta0 - encodersGAP);
 * Так стало правильно вычислять delta
 * 
 * Также есть разница между строкой, выводимой по таймеру из ф-ции getValues() :
 * posAm1=7017, posAm2=6814, diff=203, diff_prev=376, VectorDiff=173, m1Speed=125, m2Speed=195
 * 
 * И строкой из ф-ции pid()
 * 
 * delta=173
 * Но в pid() еще отнимается encodersGAP, который равен 30, так что все сходится (см. выше строку для delta).
 * ...
 * 
 * Теперь колеса друг за другом "гоняются", то 1е за 2ым, то 2е за 1ым.
 * Вот тут надо включать полноценный PID.
 * Т.е. чем больше отставание, тем больше коэффициенты. Когда отставание сокращается, коэффициенты также должны меняться.
 * Сейчас действует только П-коэффициент, а пора добавлять Д, И, коэффициенты.
 * 
 * Пора сохранять на git
 * //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * 15.06.2023
 * /home/ubuntu/.arduino15/packages/arduino/hardware/megaavr/1.8.8/cores/arduino/UART.h
 * 09.06.2023
 * Стандартная проблема ком-порта в Ардуино - размер буфера Tx - 32 байта.
 * Поэтому, когда идет передача данных от Ардуино в ПК вся посылка разбивается на порции по 32 байта.
 * В текущем проекте строка вывода примерно такая :
 * posAm1=90647, posAm2=92754, diff=-2107, diff_prev=-2108, VectorDiff=1, m1Speed=60, m2Speed=60
 * это 93 символа, или 4 посылки
 *
 * 07.06.2023
 * Алгоритм настройки ПИД-коэффициентов
 *
 * - Определяем число отсчетов за 1 цикл работы таймера
 * - Вычисляем разницу в показаниях энкодеров для каждого колеса за 1 цикл работы таймера
 *   Смтотрим, линейно ли меняется это число при 2-3-4 и т.д. циклах таймера (это уже много кода на питоне)
 * - Вычисляем коэффициент П для отстающего колеса
 * 
 * 
 * 
 */
