#ifndef NEURON_H
#define NEURON_H

//#include "mcinfer.h"
#include "mainwindow.h"
//#include "model/model1.h"
//#include "model/model2.h"
//#include "model/model3.h"
//#include "model/model4.h"

//#include "model/SP_test_13_5.h"
//#include "model/4.h"
//include "model/2_BP.h"
//#include "model/5.h" // хуже 2_ВР
//#include "model/1.h"
// Лучшая #include "model/3.h"

//#include "model/2_1_BP.h" более-менее
//#include "model/2_1_P_BP.h"
#include "model/2_1_M.h" // ЛУчше всех
//#include "model/2_1_P.h"
//+++++++++++++++++ Вспомогательные переменные

float in[3] = {0,0,0}; //массив для ввода
float outKB[4]= {0,0,0,0}; // массив для вывода

//float Kp = 15.2;//4.2;         //1.25
//float Ki = 1.2; //0.91;          //1 PID proportional control Gain
//float Kd = 15.7;//5.8;




//float actAngle=5;
//float e_Arr_Max=20;
//float de=0.1;



//+++++++++++++++++  Сама нейронка - как структура данных


#endif // NEURON_H
