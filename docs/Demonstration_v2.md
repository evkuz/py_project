# Демонстрация взаимодействия группы роботов

## Описание

В демонстрации задествованы 6 роботов. На одном из мобильных роботов запущено 4 сервиса: управление движением по одометрам, МЗ поиск положения кубика, движение по ключевым точкам по помощи лидара, управление манипулятором.  

## Описание техпроцесса

**Агенты:**

1. PinkMan
2. XRRobot
3. Hiwonder
4. Mobman_camera
5. Mobman_manip
6. Mobman
7. Blueman
8. WheelTec

**Шаги:**

1. Pinkman - захват кубика; XRRobot - встать на позицию приёма кубика
2. PinkMan - установить кубик на XRRobot
3. XRRobot - переместиться к Hiwonder; PinkMan - вернуться в стартовое положение
4. Hiwonder - захватить кубик
5. Hiwonder - положить кубик; Mobman - переместиться к пункту захвата кубика
6. Mobman_camera - захватить кубик (подъехать, схватить)
7. Mobman - переместиться к Blueman. Wheeltec переместиться к Blueman
8. Blueman - захватить кубик
9. Blueman - установить кубик на Wheeltec
10. Wheeltec - переместиться к Pinkman; Blueman - вернуться в стартовое положение