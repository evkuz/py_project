#ifndef WORKFLOW_MOB_PLATFORM_H
#define WORKFLOW_MOB_PLATFORM_H
/*
 *  
 * 18.10.2022
 * Запускаем мобильную платформу.
 * Работаем с DC-двигателями (моторы) Pololu #4752
 * https://www.pololu.com/product/4752
 *
 * Для питания этих двигателей используем шилд
 * Pololu Dual VNH5019 Motor Driver Shield for Arduino
 * https://www.pololu.com/product/2507
 *
 * Двигатели запускаем на токе М1 = 100, М2 = (-100)
 *
 * Так вот данные с энкодеров А и В разные для М2 !!!
 *
 * Для М1 данные с энкодеров примерно одинаковы.
 * posAm1 26956
 * posBm1 26957
 * А для М2 - разные !
 * posAm2 -20629
 * posBm2 29392
 * Вообще, мотор М2 крутится дольше, чем М1. Поэтому и число posBm2 больше, чем posBm1.
 *
 * Данные по одометрии.
 * НА свежем аккумуляторе
 * 
 * smooth_speed=90
 * 
 * 1 rotation forward comes at i=68
 * 1 rotation backward comes at i=70
 * 
 * 
 * //+++++++++++++++++++++++++++++++++++++++++++++++
 * 24.11.2022
 * Имеем следующие команды управления
 * - "start". "stop", "rear", "left", "right" - просто движение согласно команде, без пауз.
 * - "moveit", "moveback" - 1 оборот колеса вперед, либо назад.
 * 
 * Наша программа должна принимать команду на движение и ждать следующие команды - замедление, поворот, остановка, задний ход.
 * Добавляем ф-ции
 * decSpeed, incSpeed - соответственно, уменьшение, увеличение скорости.
 * Этим ф-циям соответствуют команды "slowdown", "faster"
 * //+++++++++++++++++++++++++++++++++++++++++++++++
 * 23.11.2022
 * НА сегодня имеем
 * 1. Запускаем пакет rplidar_ros, получаем карту местности в RVIZ
 *    roslaunch rplidar_ros view_rplidar.launch
 *    
 * 2. Имеем каркас пакета 
 *    rosrun robot_setup_tf tf_listener
 *    rosrun robot_setup_tf tf_broadcaster
 *    
  *    
 * 
 * //+++++++++++++++++++++++++++++++++++
 * 22.11.2022
 * Go on with ros navigation tutorial
 * http://wiki.ros.org/navigation/Tutorials
 *
 * Now make "Transform Configuration"
 * http://wiki.ros.org/navigation/Tutorials/RobotSetup/TF
 * $ cd %TOP_DIR_YOUR_CATKIN_WS%/src
 * $ catkin_create_pkg robot_setup_tf roscpp tf geometry_msgs
 * $ nano src/tf_broadcaster.cpp 
 * 
 * The next step is to replace the PointStamped we used for this example with sensor streams that come over ROS.
 * http://wiki.ros.org/navigation/Tutorials/RobotSetup/Sensors
 * 
 * 
 * //+++++++++++++++++++++++++++++++++++
 * 09.11.2022
 * В прокете РОС-пакета mobplatform  создал папку scripts/, а в ней скрипт movingPlatform.bash
 * Который в качестве единственного аргумента принимает команду, которая идет в топик mobplatform в качестве аргумента
 * Путь 
 * ~/catkin_ws/src/mobplatform/script
 * 
 * Запуск
 * ./movingPlatform.bash start|stop|rear|moveit|reset|moveback
 * 
 * Теперь задача - подклчюить лидар  A1M8-R5
 * 
 * RPLIDAR A2M6-R4 S/N: C4939AF2C1EA98D4BEEB9CF04B403517
 * 
 * 
 * //+++++++++++++++++++++++++++++++++++
 * 08.11.2022
 * Создал каркас для запуска платоформы как ROS пакета. Пакет называется mobplatform.
 * 
 * Запускается командой 
 * $ roslaunch mobplatform mobplatform.launch
 * Соответствующий launch-файл: ~/catkin_ws/src/mobplatform/launch/mobplatform.launch
 * 
 * Пора сохранять в git папку  ~/catkin_ws/src/
 * Далее наращиваем функционал пакета mobplatform.
 * 
 * Нужно добавить запуск платформы по команде из tcp/ip
 * Создаем в python аналог QTcpServer 
 * 
 * По 1-му скрипту на каждую команду ?
 * 
 * 
 * //+++++++++++++++++++++++++++++++++++
 * 07.11.2022
 * Задача:
 * - По нажатию кнопки клавиатуры отправлять сообщение "start/stop/rear/moveit/moveback/reset/get_vslues" в топик "mobplatform"
 * 
 * Для вычисления расстояни, пройденного роботом вводим понятия :
 * - Пройденное каждым колесом расстояние. Хранится в виде количества оборотов колеса в штуках.
 * - Текущая скорость вращения колеса в единицах силы тока в диапазоне (-400; 400)
 * - Текущая скорость вращения колеса в радианах в секунду (!)
 * 
 * Объединить запуск ROS node
 * - rosrun rosserial_python serial_node.py /dev/ttyACM0
 * - rostopic pub "mobplatform" std_msgs/String "start/stop/rear/moveit/moveback/reset/get_vslues" --once
 * 
 * 
 * 
 * 
 * Задача :
 * - Передавать в сообщения std_msgs/Float64 расстояния, пройденные колесами
 * - Передавать в сообщения std_msgs/Float64 текущие скорости вращения колес.
 * - Публиковать эти сообщения в соответствующие топки (определиться с названиями топиков)
 * - Настройка PID-контроллера для управления скоростью вращения колес.
 * 
 * 
 * //+++++++++++++++++++++++++++++++++++
 * 02.11.2022 
 * После отключения тока от двигателя колесо еще по инерции крутится какое-то время.
 * Поэтому не происходит полное обнуление счетчиков.
 * Надо, кстати, проверить обнуление после завершения ф-ции stop(), только после неё ток отключается.
 * Поэтому счетчики обнуляются в самом начале ф-ции однократного движения move_fwd.
 * Так гарантировано происходит однократное движение.
 *  
 * //+++++++++++++++++++++++++++++++++++
 * 01.11.2022
 * Предполагаемый набор ф-ций для движения мобильной платформы :
 * - вперед, назад равномерно с заданной скоростью
 * -
 * - поворот направо, налево с заданной скоростью
 * - Алгоритм, математика для планирования маршрута
 * - Добавление тока(скорость), если поверхность трудно проходима.(т.е. тут надо проверять, сдвинулся ли хотя бы на четверть оборота)
 *

//+++++++++++++++++++++++++++++++++++++
31.10.2022
Разобрался почему не едет. Потому, что знает, что сделала уже 1 оборот :)
НАдо засылать ресет, тогда можно еще один оборот проехать.
Т.е. надо доработать коэфффициенты m1A/B_k чтобы оба колеса поворачивались на 1 оборот.
 Сейчас разница видна невооруженным взглядом.
При этом данные с энкодеров :
data: "m1_count 0.9228"
---
data: "m2_count 1.0053"

Т.е. м1 не доворачивает на 0.08 - и это видно глазом !
В общем, работаем, подбираем коэффициенты.


//+++++++++++++++++++++++++++++++++++++
28.10.2022

cd /home/nvidia/iqr_lit
rsync -ar arduino_mega/mobPlatform/Pololu_VNH5019_EK /home/nvidia/Arduino/
sed -i '/^---/d' encoders.txt
rsync -ar /home/nvidia/Arduino/Pololu_VNH5019_EK arduino_mega/mobPlatform
 Провел калибровку значений энкодеров для 1 полного оборота колеса.
В процессе отладки, т.к. сел единственный рабочий аккумулятор.
 * //+++++++++++++++++++++++++++++++++++++
 * 27.10.2022
 * Поменял subscriber "toggle_led" на "mobplatform"
 * ...
 *
 * Поменял publisher "chatter" на "encoders"
 *
 * Также мотор М2, у которого сильно (несколько сотен) различались значения энкодеров А и В, посадил на прерывания с ножками 20, 21 (вместо 2,3)
 * И вот так значения А и В отличаются всего лишь на 2.
 * Следующим номером калибруем, сколько отсчетов даст энкодер на 1 оборот каждого из 2 колес.
 * И начинаем полноценную одометрию.
 * По размеру колеса и количеству его боротов рассчитываем расстояние пройденное роботом.
 *
nvidia@tegra-ubuntu:~$ rosrun rosserial_python serial_node.py /dev/ttyACM0
[INFO] [1666884337.376983]: ROS Serial Python Node
[INFO] [1666884337.417194]: Connecting to /dev/ttyACM0 at 57600 baud
[INFO] [1666884339.532458]: Requesting topics...
[INFO] [1666884339.572045]: Note: publish buffer size is 512 bytes
[INFO] [1666884339.578394]: Setup publisher on encoders [std_msgs/String]
[INFO] [1666884339.598692]: Note: subscribe buffer size is 512 bytes
[INFO] [1666884339.604493]: Setup subscriber on mobplatform [std_msgs/String]

 * //+++++++++++++++++++++++++++++++++++++
 * 20.10.2022
 * Нужный функционал получен.
 * Подключаем ардуино либу #include "DualVNH5019MotorShield.h"
 * Создаем объект класса DualVNH5019MotorShield :
 * DualVNH5019MotorShield md;
 *
 * Создаем нодХолдер - объект класса  ros::NodeHandle:
 * ros::NodeHandle  nh;
 *
 * Создаем "публикователь" сообщений типа String, который в ROS будет виден как encoders:
 * std_msgs::String str_msg;
 * ros::Publisher chatter("encoders", &str_msg);
 *
 * Создаем "подписчика" на сообщения типа std_msgs::String топика "tofggle_led" из ROS :
 * ros::Subscriber<std_msgs::String> sub("toggle_led", &messageCb );
 *
 * Топик "toggle_led" - посылаем строковые команды(из ROS).
 * "toggle_led" - задается в ROS
 * Внутри ардуино мы подписываемся на этот топик
 *
 *
 * ros::Subscriber<std_msgs::String> sub("toggle_led", &messageCb );
 * ...
 * setup {
 * ...
 * nh.subscribe(sub);
 * ...
 * }
 * Данные с этого топика обрабатывает ф-ция messageCb.
 * Внутри ф-ции messageCb считываем данные из топика :
 *
 * currCommand = toggle_msg.data;
 *
 * Внутри loop парсим команду и вызываем соответствующие ф-ции
 * if (currCommand == "start") {
 *     forward();
 * }
 *
 * ....
 *
 * Для отправки данных из ардуино в serial port и далее в ROS создаем через нодХолдер
 * nh.advertise(chatter);
 * Для отправки в сериал порт кладем данные в переменную data и публикуем:
 *
 * str_msg.data = char_BM1_array;
 * chatter.publish( &str_msg );
 *
 *
 *
 * Также внути ардуино создаем
 * publisher "toggle_led"
 *
 * Задача :
 * Поменять топик "toggle_led" на "movingON". [Сделано]
 *
 * //++++++++++++++++++++++++++++++++
 * 19.10.2022
 * Запускаем связку ROS<--->Arduino.
 * Нам необходимо наладить обмен данными между ROS и  Arduiono через serial порт.
 *
 * Задача минимум :
 * - Отправляем из ROS в serialport  команду "start". Робот ловит эту команду и запускает работу
 *   двигателей в заранее заданном режиме. При этом робот начинает выдавать в serial port 
 *   значения  энкодеров для обоих двигателей. [Сделано]
 *
 * - Отправляем из ROS в serialport  команду "stop". Робот останавливает двигатели, ждет новую    
 *   команду.[Сделано]
 *
 * Для запуска мобильной платформы из ROS выполняем следующие команды:
 * В новом терминале
 * roscore
 *
 * В новом терминале
 * rosrun rosserial_python serial_node.py /dev/ttyACM0
 *
 * В новом терминале   ЗАПУСК платформы
 * rostopic pub "mobplatform" std_msgs/String "start" --once
 * 
 * В новом терминале СТОП платформы
 * rostopic pub "mobplatform" std_msgs/String "stop" --once
 * 
 * Проверить работу топика можем так
 * в новом терминале
 * rostopic echo /encoders
 *
 * Задача :
 * Считываем данные, посылаемые из arduino в ROS [почти]
 * Смотрим данные топика encoders
 * rostopic echo /encoders
---
data: "posAm1 91155"
---


 *
 */
#endif // WORKFLOW_MOB_PLATFORM_H
