/*

05-06.07.2021
main_01.py
При загрузка mnist-файла с тестовыми данными получаю ошибку :
ValueError: could not convert string to float: ''
Это руками сделанный файл mnist_train_100.csv, и у него для каждой строки последний символ выглядит как '0\n'
Вот на это он и ругается.

ПРобовал открыть файл так :
training_data_file = open("/home/evkuz/lit/mnist/mnist_train_100.csv", newline='', encoding='utf-8')
Не помогает.

Решил через :
    with open("/home/evkuz/lit/mnist/mnist_train_100.csv", newline='') as training_data_file:
        training_data_list = csv.reader(training_data_file, delimiter=' ', quotechar='|')

Теперь

#############################
28.06.2021
main.py
Подключаем нейронную сеть для распознавания изображений рукописных цифр.
Делаем все по этой книге 
Исходники кода лежат тут :
https://github.com/makeyourownneuralnetwork/makeyourownneuralnetwork/find/master


Создаем класс для нейронной сети - class neuralNetwork - со следующеими функциями :
- Инициализация сети  def __init__(self, inputnodes, hiddennodes, outputnodes, learningrate)
- Обучение сети       def train(self, inputs_list, targets_list)
- Запрос в сеть       def query(self, inputs_list)

Создаем структуру нейронной сети :
Задаем количество входных, скрытых и выходных узлов равным 3.
Задаем коэффициент обучения равным 0.3 - в целях тестирования самого факта работы сети - величина этого коэффициента не важна.

Для начала тестируем, что созданная структура нейроннй сети работает.
- Создаем массив весовых коэффициентов
    arr = numpy.random.rand(3, 3) - 0.5
- Выводим массив arr
- Выводим результат запроса в нсеть одной командой
  print(n.query([1.0, 0.5, -1.5]))
  Исходные значения выбираем любые, главное, чтобы они были :)
...
Our neural output :
[[0.35259296]
 [0.49404098]
 [0.57114242]]

Так мы проверили, что созданная структура сети работает.
Далее подгружаем в сеть данные для обучения. Пока ограничимся небольшим объемом.
- mnist_test_10.csv   - для тестирования сети, 10 изображения
- mnist_train_100.csv - для обучения сети, 100 изображений.
*/
