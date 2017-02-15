#sample_submission.py

import numpy as np

class regressor(object):
    """
    This is a sample class for miniproject 1.

    Args:
        data: Is a tuple, ``(x,y)``
              ``x`` is a two or one dimensional ndarray ordered such that axis 0 is independent 
              data and data is spread along axis 1. If the array had only one dimension, it implies
              that data is 1D.
              ``y`` is a 1D ndarray it will be of the same length as axis 0 or x.   
                          
    """
    def __init__(self, data):
        self.x, self.y = data        
        # Here is where your training and all the other magic should happen. 
        # Once trained you should have these parameters with ready.
        #print "self x shape 1 ", self.x.shape
        global_wt = np.random.rand(self.x.shape[1], 1)
        global_b = np.random.rand(1)
        self.x = np.insert(self.x,0,1,axis=1)
        length = self.x.shape[0]
        index = int((85*length)/100)
        train , test = self.x[0:index],self.x[index:]
        test = np.delete(test, 0, axis=1)
        #print " test shape ",test.shape," training ",train.shape
        y_train,y_test =  self.y[0:index],self.y[index:]
        #print "self x shape 2 ",self.x.shape


        # doing cross validation and saving the best parameter for the model based on rmse error
        #global rmse error
        rmse_error = 100
        for no_steps in range(0,6):
            alpha = 0.1 + no_steps*0.3
            for i in range (5,8):
                eta = pow(10,-i)
                for j in range(0,9):
                    self.w = np.random.rand(train.shape[1], 1)
                    self.b = np.random.rand(1)
                    I = np.identity(train.shape[1])
                    if j<=5:
                        limit = 2000 + j*300
                    else:
                        limit = 2000 + j*500
                    #print " train shape ", train.shape, " w ", self.w.shape, " train_y ",y_train.shape," I ",I.shape
                    for k in range(0,limit):
                       # print self.w
                       self.w = self.w - eta * (-2 * (np.dot(train.T, y_train)) + 2 * (
                        np.dot(np.dot(train.T, train), self.w)) + 2 * alpha * np.dot(I, self.w))

                    #self.x = np.delete(self.x, 0, axis=1)
                    self.b = self.w[0]
                    self.w = self.w[1:]
                    #test predict
                    #print " test shape ", test.shape, " w ", self.w.shape
                    pred = np.dot(test,self.w)+self.b
                    rmse_new = np.sqrt(np.mean((y_test - pred) ** 2))
                    #print "rmse_new ",rmse_new, " rmse_error",rmse_error
                    if rmse_new < rmse_error:
                        rmse_error = rmse_new
                        global_wt = self.w
                        global_b = self.b
                    if rmse_new > rmse_error and (rmse_new - rmse_error)>0.2:
                        break
        #print "final rmse : ",rmse_error
        self.w = global_wt
        self.b = global_b

        
    def get_params(self):
        """ 
        Method that should return the model parameters.

        Returns:
            tuple of numpy.ndarray: (w, b). 

        Notes:
            This code will return a random numpy array for demonstration purposes.

        """

        return (self.w, self.b)

    def get_predictions (self, x):
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
        # Here is where you write a code to evaluate the data and produce predictions.
        return np.dot(x,self.w)+self.b

if __name__ == '__main__':
    pass 
