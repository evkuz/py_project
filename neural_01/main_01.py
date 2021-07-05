# This is a sample Python based neural network example
# The source code can be found here
# https://github.com/makeyourownneuralnetwork/makeyourownneuralnetwork/find/master


# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import numpy
import matplotlib.pyplot as plt

# библиотека scipy.special содержит сигмоиду expit()
import scipy.special


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
        pass

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

        # ошибки выходного слоя =
        # (целевое значение - фактическое значение)
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
        pass

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


# def print_hi(name):
#     # Use a breakpoint in the code line below to debug your script.
#     print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # print_hi('PyCharm')
    # количество входных, скрытых и выходных узлов
    input_nodes = 3
    hidden_nodes = 3
    output_nodes = 3
    # коэффициент обучения равен 0,3
    learning_rate = 0.3
    # создать экземпляр нейронной сети
    n = neuralNetwork(input_nodes, hidden_nodes, output_nodes, learning_rate)
    # Создаем массив весовых коэффициентов
    arr = numpy.random.rand(3, 3) - 0.5
    print(arr)
    print("Our neural output :")
    print(n.query([1.0, 0.5, -1.5]))
    # ================================ Берем из файла ТРЕНИРОВОЧНЫЕ (100) данные, выводим 1 элемент массива данных
    # try images mnist_train_100.csv
    train_data_file = open("/home/evkuz/lit/mnist/mnist_train_100.csv")
    train_data_list = train_data_file.readlines()
    train_data_file.close()
    print(len(train_data_list))
    print(train_data_list[1]) #
    # А теперь выводим одно из ТРЕНИРОВОЧНЫХ изображений, это "0"
    all_values = train_data_list[1].split(',')
    image_array = numpy.asfarray(all_values[1:]).reshape((28, 28))
    plt.imshow(image_array, cmap='Greys',interpolation='None')
    plt.show()

    # ================================ Берем из файла ТЕСТОВЫЕ данные (10), выводим 1 элемент массива данных \
    # для проверки
    # try images mnist_train_100.csv
    test_data_file = open("/home/evkuz/lit/mnist/mnist_test_10.csv")
    test_data_list = test_data_file.readlines()
    test_data_file.close()
    # Выводим количество элементов в списке
    print(len(test_data_list))
    # Выводим первый элемент списка - изображение числа 7
    print(test_data_list[0])
    # А теперь выводим одно из ТЕСТОВЫХ изображений, это "7"
    all_values = test_data_list[0].split(',')
    # выводим маркер - это "7"
    print(all_values[0])
    image_array = numpy.asfarray(all_values[1:]).reshape((28, 28))
    plt.imshow(image_array, cmap='Greys',interpolation='None')
    plt.show()


    # ==================================== А теперь тестим сеть - скармливаем тестовые данные =======================
    # ДО этой строки просто выводили массив чисел 28x28 в цвете.
    # Каждый эл-т массива - это численное значение цвета пикселя,
    # и таких пиксерелей - 28х28 штук.
    input_nodes = 784
    hidden_nodes = 100
    output_nodes = 10
    # коэффициент обучения равен 0,3
    learning_rate = 0.3
    # создать экземпляр нейронной сети
    n = neuralNetwork(input_nodes, hidden_nodes, output_nodes, learning_rate)



    # загрузить в список тестовый набор данных CSV-файла набора MNIST
    training_data_file = open("/home/evkuz/lit/mnist/mnist_train_100.csv")
    training_data_list = training_data_file.readlines()
    training_data_file.close()

    # ==================================== тренировка нейронной сети

    # перебрать все записи в тренировочном наборе данных
    for record in training_data_list:
        # получить список значений, используя символы запятой (1,1)
        # в качестве разделителей
        all_values = record.split(',')
        print(all_values)
        # масштабировать и сместить входные значения
        inputs = (numpy.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01
        # создать целевые выходные значения (все равны 0,01, за исключением
        # желаемого маркерного значения, равного 0,99)
        targets = numpy.zeros(output_nodes) + 0.01
        # all_values[0] - целевое маркерное значение для данной записи
        targets[int(all_values[0])] = 0.99
        n.train(inputs, targets)
        pass

    print(n.query(numpy.asfarray(all_values[1:]) / 255.0 * 0.99) + 0.01)
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
