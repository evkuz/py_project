# This is a sample Python based neural network example
# The source code can be found here
# https://github.com/makeyourownneuralnetwork/makeyourownneuralnetwork/find/master

# //+++++++++++++++++++++++++++++++
# main_07
# Сохраняем весовые коэффициенты слоев в файл. И когда получим сеть с высокой степенью распознавания (>97.0%)
# То просто сохраним эти коэффициенты и не надо будет каждый раз обучать сеть перед распознаванием изображения.
# Имя файла ek_neuron.txt. ПРичем путь должен быть абсолютный.
# Массивы весовых коэффициентов разделены в файле строкой '########################################'
# Чтобы узнать номер строки из shell : sed -n '/#################.*/=' ek_neuron.txt
# 19471
#
# Чтобы в less перейти на нужный номер строки набираем ng - где n - номер строки.
# Улучшаем дальше. Пробуем увеличение количества узлов
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9584 Прогонов 4
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9593 Прогонов 5
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9581 Прогонов 6
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9569 Прогонов 7
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9585 Прогонов 8
# Узлов : 200 Коэффициент обучения : 0.12 эффективность = 0.9574 Прогонов 5
# Узлов : 200 Коэффициент обучения : 0.09 эффективность = 0.9572 Прогонов 5
# Узлов : 200 Коэффициент обучения : 0.11 эффективность = 0.9585 Прогонов 5
# Узлов : 200 Коэффициент обучения : 0.2 эффективность = 0.9552 Прогонов 5
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9588 Прогонов 5
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9575 Прогонов 7
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9578 Прогонов 8

# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9624 Прогонов 10

# Узлов : 200 Коэффициент обучения : 0.095 эффективность = 0.96 Прогонов 10
# Узлов : 200 Коэффициент обучения : 0.098 эффективность = 0.9573 Прогонов 15
# Узлов : 200 Коэффициент обучения : 0.099 эффективность = 0.9565 Прогонов 15
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9577 Прогонов 15
# Узлов : 300 Коэффициент обучения : 0.1 эффективность = 0.9593 Прогонов 10
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9599 Прогонов 10
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9607 Прогонов 12
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9586 Прогонов 13
# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9607 Прогонов 14
# Узлов : 250 Коэффициент обучения : 0.1 эффективность = 0.9592 Прогонов 10
# Узлов : 250 Коэффициент обучения : 0.1 эффективность = 0.9575 Прогонов 15
# Узлов : 250 Коэффициент обучения : 0.097 эффективность = 0.9603 Прогонов 10
# Узлов : 250 Коэффициент обучения : 0.097 эффективность = 0.9598 Прогонов 12
# Узлов : 400 Коэффициент обучения : 0.097 эффективность = 0.9591 Прогонов 10
# Узлов : 400 Коэффициент обучения : 0.1 эффективность = 0.9587 Прогонов 10
# Узлов : 400 Коэффициент обучения : 0.1 эффективность = 0.9596 Прогонов 12
# Узлов : 400 Коэффициент обучения : 0.1 эффективность = 0.9595 Прогонов 13

# Узлов : 300 Коэффициент обучения : 0.098 эффективность = 0.9625 Прогонов 10
# Узлов : 300 Коэффициент обучения : 0.098 эффективность = 0.9575 Прогонов 12
# Узлов : 500 Коэффициент обучения : 0.1 эффективность = 0.9599 Прогонов 5

# Узлов : 200 Коэффициент обучения : 0.1 эффективность = 0.9742 Прогонов 6
#
# //+++++++++++++++++++++++++++++++
# main_06
# Улучшаем дальше. Пробуем многократное повторение тренировочных циклов, комбинируем с коэффицентом обучения.
# Т.е. тренировку делаем несколько раз, а потом посылаем 1 раз запрос в сеть.
# Коэффициент обучения :  0.1  эффективность =  0.9517 Прогонов 2
# Коэффициент обучения :  0.1  эффективность =  0.9512 Прогонов 3 (подозрительно быстро 2 и 3 прогоны прошли)
# Коэффициент обучения :  0.1  эффективность =  0.9522 Прогонов 4
# Коэффициент обучения :  0.1  эффективность =  0.9494 Прогонов 5
# Коэффициент обучения :  0.1  эффективность =  0.9474 Прогонов 6
# Коэффициент обучения :  0.1  эффективность =  0.9519 Прогонов 7
# Коэффициент обучения :  0.1  эффективность =  0.9483 Прогонов 8
# Коэффициент обучения :  0.1  эффективность =  0.9505 Прогонов 9
# Коэффициент обучения :  0.09 эффективность =  0.9517 Прогонов 4
#
# Коэффициент обучения :  0.11 эффективность =  0.953  Прогонов 4
# Коэффициент обучения :  0.11 эффективность =  0.9522 Прогонов 5
#
#

# //+++++++++++++++++++++++++++++++
# main_05
# Улучшаем работу сети. Настройка коэффициента обучения. Останавливаемся на 0.1
# Коэффициент обучения :  0.095 эффективность =  0.9503
# Коэффициент обучения :  0.15  эффективность =  0.9507
# Коэффициент обучения :  0.085 эффективность =  0.9488
# Коэффициент обучения :  0.2  эффективность =  0.9486
# Коэффициент обучения :  0.01 эффективность =  0.9239 (малые шаги уменьшают скорость градиентного спуска)
# Коэффициент обучения :  0.1  эффективность =  0.9532
# Коэффициент обучения :  0.6  эффективность =  0.9104 (перескок через минимум)
# Коэффициент обучения :  0.3  эффективность =  0.9429
# //++++++++++++++++++++++++++++++
# main_04
# Тренировка и тестирование нейронной сети с использованием полной базы данных
# Размер scorecard :  10000
# эффективность =  0.9429
# Т.е. мы сделали 10000 запросов в сеть после обучения на 60000 изображений, и правильный результат
# был получен в 94% случаев !!!

# //+++++++++++++++++++++++++++++++
# main_03
# Задача - проверить, насколько хорошо нейронная сеть справляется с остальной частью набора данных,
# и провести подсчет правильных результатов, чтобы впоследствии мы могли оценивать плодотворность
# своих будущих идей по совершенствованию способности сети обучаться.
# Доля правильных результатов составила 50%

# //+++++++++++++++++++++++++++++++
# main_02
# Мы обучили нашу нейронную сеть и добились того, что она смогла определить цифру,
# предоставленную ей в виде изображения.
# Помним, что до этого сеть не сталкивалась с данным изображением, поскольку оно не входило
# в тренировочный набор данных.
# Это важно - разделять тренировочный и тестовый наборы данных.
# !!!!!!!!!!!!!!!!!!!! ВАЖНО !!!!!!!!!!!!!!!!!!!!
# Пример кода из книги не работает в PyCharm из-за csv формата.
# Поэтмоу пришлось применить модуль csv,  и, соответственно, код отличается от книжного.


import numpy
import matplotlib.pyplot as plt

# библиотека scipy.special содержит сигмоиду expit()
import scipy.special
import csv


class neuralNetwork:
    # инициализация сети
    def __init__(self, inputnodes, hiddennodes, outputnodes, learningrate):
        # задать количество узлов во входном, скрытом и выходном слое
        self.inodes = inputnodes
        self.hnodes = hiddennodes
        self.onodes = outputnodes
        # Матрицы весовых коэффициентов связей wih(между входным и скрытым слоями) и
        # who(между скрытым и выходным слоями).
        # Весовые коэффициенты связей между узлом i и узлом j следующего слоя обозначены как w_i_j:
        # w11 w21
        # w12 w22 и т.д.
        self.wih = numpy.random.normal(0.0, pow(self.hnodes, -0.5), (self.hnodes, self.inodes))
        self.who = numpy.random.normal(0.0, pow(self.onodes, -0.5), (self.onodes, self.hnodes))

        # коэффициент обучения
        self.lr = learningrate

        # использование сигмоиды в качестве функции активации
        self.activation_function = lambda x: scipy.special.expit(x)

    # Обучение, тренировака сети
    def train(self, inputs_list, targets_list):
        # convert inputs list to 2d array
        inputs = numpy.array(inputs_list, ndmin=2).T
        targets = numpy.array(targets_list, ndmin=2).T

        # рассчитать входящие сигналы для скрытого слоя
        hidden_inputs = numpy.dot(self.wih, inputs)
        # рассчитать исходящие сигналы для скрытого слоя (emerging - возникающие)
        hidden_outputs = self.activation_function(hidden_inputs)

        # рассчитать входящие сигналы для выходного слоя
        final_inputs = numpy.dot(self.who, hidden_outputs)
        # рассчитать исходящие сигналы для выходного слоя
        final_outputs = self.activation_function(final_inputs)

        # ошибки выходного слоя = (целевое значение - фактическое значение)
        output_errors = targets - final_outputs
        # hidden layer error is the output_errors, split by weights, recombined at hidden nodes

        # ошибки скрытого слоя - это ошибки output_errors,
        # распределенные пропорционально весовым коэффициентам связей
        # и рекомбинированные на скрытых узлах
        hidden_errors = numpy.dot(self.who.T, output_errors)

        # update the weights for the links between the hidden and output layers
        # обновить весовые коэффициенты для связей между скрытым и выходным слоями
        self.who += self.lr * numpy.dot((output_errors * final_outputs * (1.0 - final_outputs)),
                                        numpy.transpose(hidden_outputs))

        # update the weights for the links between the input and hidden layers
        # обновить весовые коэффициенты для связей между входным и скрытым слоями
        self.wih += self.lr * numpy.dot((hidden_errors * hidden_outputs * (1.0 - hidden_outputs)),
                                        numpy.transpose(inputs))

    # Опрос сети
    def query(self, inputs_list):
        # преобразовать список входных значений
        # в двухмерный массив
        inputs = numpy.array(inputs_list, ndmin=2).T
        # рассчитать входящие сигналы для скрытого слоя
        hidden_inputs = numpy.dot(self.wih, inputs)
        # рассчитать исходящие сигналы для скрытого слоя
        hidden_outputs = self.activation_function(hidden_inputs)
        # рассчитать входящие сигналы для выходного слоя
        final_inputs = numpy.dot(self.who, hidden_outputs)
        # рассчитать исходящие сигналы для выходного слоя
        final_outputs = self.activation_function(final_inputs)
        return final_outputs


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # =============================== Используем полный набор данных для работы сети ==================
    # ==================================== Сначала обучаем =====================
    # ДО этой строки просто выводили массив чисел 28x28 в цвете.
    # Каждый эл-т массива - это численное значение цвета пикселя,
    # и таких пиксерелей - 28х28 штук.
    input_nodes = 784
    hidden_nodes = 200
    output_nodes = 10
    # коэффициент обучения
    learning_rate = 0.1
    # создать экземпляр нейронной сети
    n = neuralNetwork(input_nodes, hidden_nodes, output_nodes, learning_rate)
    # =============================== ОБУЧАЕМ =======================================
    # переменная epochs указывает, сколько раз тренировочный
    # набор данных используется для тренировки сети

    # загрузить в список тренировочный набор данных - ПОЛНЫЙ - CSV-файла набора MNIST
    training_data_file = open("/home/evkuz/lit/mnist/mnist_train.csv")
    training_data_list = training_data_file.readlines()
    training_data_file.close()

    epochs = 6
    for epo in range(epochs):
        print("Epochs value : ", epo)
        # ==================================== тренировка нейронной сети
        # перебрать все записи в тренировочном наборе данных
        for record in training_data_list:
            # получить список значений, используя символы запятой (1,1)
            all_values = record.split(',')
            # в качестве разделителей
            # масштабировать и сместить входные значения
            inputs = (numpy.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01
            # создать целевые выходные значения (все равны 0,01, за исключением
            # желаемого маркерного значения, равного 0,99)
            targets = numpy.zeros(output_nodes) + 0.01
            # all_values[0] - целевое маркерное значение для данной записи
            targets[int(all_values[0])] = 0.99
            # Запускаем обучение сети
            n.train(inputs, targets)
            pass
        scorecard = []
        # Делаем запрос в сеть из ПОЛНОГО тестового набора
        test_data_file = open("/home/evkuz/lit/mnist/mnist_test.csv", 'r')
        test_data_list = test_data_file.readlines()
        test_data_file.close()

        # ==================================== тренировка нейронной сети
        # перебрать все записи в тренировочном наборе данных
        # журнал оценок работы сети, первоначально пустой
        for record in test_data_list:
            all_values = record.split(',')
            # правильный ответ - первое значение
            correct_label = int(all_values[0])
            # print(correct_label, "истинный маркер")
            # масштабировать и сместить входные значения
            inputs = (numpy.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01
            # опрос сети
            outputs = n.query(inputs)
            # индекс наибольшего значения является маркерным значением
            label = numpy.argmax(outputs)
            # print(label, "ответ сети")
            # присоединить оценку ответа сети к концу списка
            if label == correct_label:
                # в случае правильного ответа сети присоединить
                # к списку значение 1
                scorecard.append(1)
            else:
                # в случае неправильного ответа сети присоединить
                # к списку значение 0
                scorecard.append(0)
                pass
            pass

        scorecard_array = numpy.asarray(scorecard)
        # print("Узлов :", hidden_nodes, "Коэффициент обучения :", learning_rate, "эффективность =",
        #       scorecard_array.sum() / scorecard_array.size, "Прогонов", epochs)
        print("эффективность =", scorecard_array.sum() / scorecard_array.size)
        pass
    # Save weight coefficients to file
    # lit-ubu-406 : /home/evkuz/py_project/neural_01/ek_neuron.txt
    # x542bp : /home/evkuz/PycharmProjects/py_project/neural_01/ek_neuron.txt
    with open('/home/evkuz/PycharmProjects/py_project/neural_01/ek_neuron.txt', 'w') as f:
        for item in n.wih:
            f.write("%s\n" % item)
        f.write("###############################################################################\n")

        for item in n.who:
            f.write("%s\n" % item)
        perf = scorecard_array.sum() / scorecard_array.size
        f.write("!!!!!!!!!!!!!!!!!!!!!!!! performance = %s\n" % perf)
    # print(scorecard)
    # рассчитать показатель эффективности в виде доли правильных ответов
        # print("Коэффициент обучения : ", learning_rate)
    # print("Размер scorecard : ", scorecard_array.size)
    # print("эффективность = ", scorecard_array.sum()/scorecard_array.size)



