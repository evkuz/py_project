# This is a sample Python based neural network example
# The source code can be found here
# https://github.com/makeyourownneuralnetwork/makeyourownneuralnetwork/find/master
#
# Каркас сети + вывод ТРЕНИРОВОЧНОГО изображения

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

    # Обучение сети
    def train(self, inputs_list, targets_list):
        # convert inputs list to 2d array
        inputs = numpy.array(inputs_list, ndmin=2).T
        targets = numpy.array(targets_list, ndmin=2).T

        # calculate signals into hidden layer
        hidden_inputs = numpy.dot(self.wih, inputs)
        # calculate the signals emerging from hidden layer
        hidden_outputs = self.activation_function(hidden_inputs)

        # calculate signals into final output layer
        final_inputs = numpy.dot(self.who, hidden_outputs)
        # calculate the signals emerging from final output layer
        final_outputs = self.activation_function(final_inputs)

        # output layer error is the (target - actual)
        output_errors = targets - final_outputs
        # hidden layer error is the output_errors, split by weights, recombined at hidden nodes
        hidden_errors = numpy.dot(self.who.T, output_errors)

        # update the weights for the links between the hidden and output layers
        self.who += self.lr * numpy.dot((output_errors * final_outputs * (1.0 - final_outputs)),
                                        numpy.transpose(hidden_outputs))

        # update the weights for the links between the input and hidden layers
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


def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')
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
    # try images mnist_train_100.csv
    data_file = open("/home/evkuz/lit/mnist/mnist_train_100.csv")
    data_list = data_file.readlines()
    data_file.close()
    print(len(data_list))
    print(data_list[0])
    # А теперь выводим одно из ТРЕНИРОВОЧНЫХ изображений, это "5"
    all_values = data_list[0].split(',')
    image_array = numpy.asfarray(all_values[1:]).reshape((28, 28))
    plt.imshow(image_array, cmap='Greys',interpolation='None')
    plt.show()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
