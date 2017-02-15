# sample_submission.py
import numpy as np


class xor_net(object):
    """
    This is a sample class for miniproject 1.

    Args:
        data: Is a tuple, ``(x,y)``
              ``x`` is a two or one dimensional ndarray ordered such that axis 0 is independent
              data and data is spread along axis 1. If the array had only one dimension, it implies
              that data is 1D.
              ``y`` is a 1D ndarray it will be of the same length as axis 0 or x.

    """

    def __init__(self, data, labels):
        self.x = data
        self.y = labels
        self.no_layer = 3
        self.unit_layer = [2, 3, 1]
        pass

        # set bias for different layers
        self.bias = []
        for row in self.unit_layer[1:]:
            self.bias.append(np.random.randn(row, 1))
        # self.biases = [np.zeros((y, 1)) for y in self.unit_layer[1:]]
        # set the weight for each layer
        self.weights = []
        for x, y in zip( self.unit_layer[1:],self.unit_layer[:-1]):
            self.weights.append(np.random.rand(x, y)/np.sqrt(y))


        #number of epochs
        for i in range(0, 5000):
            if i < 2000:
                eta = 0.6
            elif i < 3000:
                eta = 0.2
            else:
                eta = 0.1

            # adjust weight for each row of data
            for x_in in range(0, 100):
                z_list = []
                y_op = np.reshape(self.y, (100, 1))[x_in]
                activation = np.reshape(self.x[x_in, :], (2, 1))
                activation_list = [activation]

                for w, b in zip(self.weights, self.bias):
                    #print " w ",w.shape," b ",b.shape
                    z = np.dot(w, activation) + b
                    z_list.append(z)
                    #if w.shape[0] == 1:
                    #    activation = self.activation_func_last(z)
                    #else:
                    activation = self.activation_func(z)
                    activation_list.append(activation)
                    # print "z list length ",len(z_list),"z 1: ",z_list[0].shape," z 2: ",z_list[1].shape
                    # print "activatio lenght ",len(activation_list)," a 1 ",activation_list[0].shape," a 2 ",activation_list[1].shape," a 2 ",activation_list[2].shape

                # print "activation ",activation_list[-1]," y : ",y_op
                delta_w, delta_b = self.calDelta(y_op, activation_list, z_list)
                # for rest layer we will propogate the daata
                # print "delta : ",delta
                # print "wt : ",wt," w: ",self.weights
                self.weights = [w - eta * dw for dw, w in zip(delta_w, self.weights)]
                self.bias = [b - eta * db for db, b in zip(delta_b, self.bias)]
                # print self.weights


    def calDelta(self, y, activation_list, z_list):

        """
        Method : This method is used to calulcate the delta function for backpropagtion
        :param y: the ouput label for the given sample of x
        :param activation_list: This list is storing the actication value for each layer which is being used for calcuating
        delta function
        :param z_list: This list is used to store the input value 'z = w*a + b ' to each node in the layer where w is weight
        a is activation and b is bias for the node
        :return: delta value for weight and bias
        """

        delta_w = [np.zeros(w.shape) for w in self.weights]
        delta_b = [np.zeros(b.shape) for b in self.bias]
        delta = (activation_list[-1] - y) * self.activation_derivation(z_list[-1])
        delta_b[-1] = delta
        delta_w[-1] = np.dot(delta, activation_list[-2].T)
        for layer in range(2, self.no_layer):
            z = z_list[-layer]
            dr_val = self.activation_derivation(z)
            delta = np.dot(self.weights[-layer + 1].T, delta) * dr_val
            delta_b[-layer] = delta
            delta_w[-layer] = np.dot(delta, activation_list[-layer - 1].T)
        return (delta_w, delta_b)

    def activation_func(self, val):
        """
        Method : This function is used to calculate the activation value
        :param val: The input is the dot product of previous activation function and weight. Adding bias to previous value
        :return: This function return the activation value for the layer
        """
        #return np.log(1+np.exp(val))
        #return (np.tanh(val))
        return (1.0 / (1.0 + np.exp(-val)))

    def activation_derivation(self, val):
        """
        Method : This calculate the valu
        :param val:  the activation valute for the given layer 
        :return: Compute the derivate of activation function value for the layer
        """
        #return (1.0 / (1.0 + np.exp(-val)))
        #return (1 - self.activation_func(val) * self.activation_func(val))
        return self.activation_func(val) * (1 - self.activation_func(val))


    def get_params(self):
        """ 
        Method that should return the model parameters.

        Returns:
            tuple of numpy.ndarray: (w, b). 

        Notes:
            This code will return an empty list for demonstration purposes. A list of tuples of 
            weoghts and bias for each layer. Ordering should from input to outputt

        """
        self.params = (self.weights, self.bias)
        #print "self weight ", self.weights, " bias ", self.bias
        return self.params

    def get_predictions(self, x):
        """
        Method should return the outputs given unseen data

        Args:
            x: array similar to ``x`` in ``data``. Might be of different size.

        Returns:    
            numpy.ndarray: ``y`` which is a 1D array of predictions of the same length as axis 0 of 
                            ``x`` 
        Notes:
            Temporarily returns random numpy array for demonstration purposes.                            
        """
        y_res = []
        row = x.shape[1]
        for x_in in range(0, 100):
            z_list = []
            activation = np.reshape(x[x_in, :], (row, 1))
            activation_list = [activation]
            for wt, b in zip(self.weights, self.bias):
                # print "activation shape : ",activation.shape," w ",w.shape," b ",b.shape
                z = np.dot(wt, activation) + b
                activation = self.activation_func(z)
                z_list.append(z)
                activation_list.append(self.activation_func(z))
            # print "activationlist list : ",activation_list[-1]
            temp = activation_list[-1][0]
            y_res.append(round(temp[0]))
        return y_res






class mlnn(xor_net):
    """
    At the moment just inheriting the network above. 
    """

    def __init__(self, data, labels):
        self.x = data
        self.y = labels
        self.no_layer = 4
        self.unit_layer = [784, 7, 3, 1]
        # set bias for different layers
        self.bias = []
        for row in self.unit_layer[1:]:
            self.bias.append(np.random.rand(row, 1))
        # self.biases = [np.zeros((y, 1)) for y in self.unit_layer[1:]]
        # set the weight for each layer
        self.weights = []
        for x, y in zip(self.unit_layer[1:], self.unit_layer[:-1]):
            self.weights.append(np.random.rand(x, y)/np.sqrt(y))
        # number of epochs
        for i in range(0, 500):
            if i<100:
                eta = 0.6
            elif i<200:
                eta = 0.2
            else:
                eta = 0.1
            # adjust weight for each row of data
            for x_in in range(0, 100):
                z_list = []
                y_op = np.reshape(self.y, (100, 1))[x_in]
                activation = np.reshape(self.x[x_in, :], (784, 1))
                activation_list = [activation]

                for w, b in zip(self.weights, self.bias):
                    # print "activation shape : ",activation.shape," w ",w.shape," b ",b.shape
                    z = np.dot(w, activation) + b
                    z_list.append(z)
                    activation = self.activation_func(z)
                    activation_list.append(activation)
                    # print "z list length ",len(z_list),"z 1: ",z_list[0].shape," z 2: ",z_list[1].shape
                    # print "activatio lenght ",len(activation_list)," a 1 ",activation_list[0].shape," a 2 ",activation_list[1].shape," a 2 ",activation_list[2].shape

                # print "activation ",activation_list[-1]," y : ",y_op
                delta_w, delta_b = self.calDelta(y_op, activation_list, z_list)
                # for rest layer we will propogate the daata
                # print "delta : ",delta
                # print "wt : ",wt," w: ",self.weights
                self.weights = [w - eta * dw for dw, w in zip(delta_w, self.weights)]
                self.bias = [b - eta * db for db, b in zip(delta_b, self.bias)]
                # print self.weights
                # print "$$$$$$$$$$$$$$$$$$$$$$$$$$$$"



if __name__ == '__main__':
    pass 
