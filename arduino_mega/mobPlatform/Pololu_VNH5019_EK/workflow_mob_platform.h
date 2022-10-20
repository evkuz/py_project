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
 * rostopic pub "toggle_led" std_msgs/String "start" --once
 * 
 * В новом терминале СТОП платформы
 * rostopic pub "toggle_led" std_msgs/String "stop" --once
 * 
 * Проверить работу топика можем так
 * в новом терминале
 * rostopic echo /toggle_led
 *
 * Задача :
 * Считываем данные, посылаемые из arduino в ROS [почти]
 * Смотрим данные топика chatter
 * rostopic echo /chatter 
---
data: "posAm1 91155"
---


 *
 */
#endif // WORKFLOW_MOB_PLATFORM_H
