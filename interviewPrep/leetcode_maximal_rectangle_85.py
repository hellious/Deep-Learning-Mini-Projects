class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if len(matrix) == 0:
            return 0
        max_area = -1
        rows = len(matrix)
        cols = len(matrix[0])
        matrix = [list(map(int,x)) for x in matrix]
        for i in range(1,rows):
            for j in range(0,cols):
                if matrix[i][j]!= 0:
                    matrix[i][j] = (matrix[i][j]) + (matrix[i-1][j])
        #print matrix
        for i in range(0,rows):
            temp_area = self.getMaxArea(matrix[i],cols)
            if temp_area > max_area:
                max_area = temp_area
        return max_area
        
    def getMaxArea(self,item,cols):
        max_area = 0
        index = 0
        stk = Stack()
        while index < cols:
            if stk.isEmpty():   #when stack is empty
                stk.push(index)
                index += 1
            elif item[stk.top()] <= item[index]:   #when stack is not empty and current ite is grater than top of stack
                stk.push(index)
                index += 1
            else:               #when stack is not empty and current element is less than top element of stack
                val = stk.pop()
                if stk.isEmpty():
                    temp_area = item[val]*index
                else:
                    temp_area = item[val]*(index-1-stk.top())
                if max_area < temp_area:
                    max_area = temp_area
        while not stk.isEmpty():
            val = stk.pop()
            if stk.isEmpty():
                    temp_area = item[val]*index
            else:
                temp_area = item[val]*(index-1-stk.top())
            if max_area < temp_area:
                max_area = temp_area
        #print "max_area : ",max_area
        return max_area
        
class Stack:
    def __init__(self):
        self.item = []
    def push(self,i):
        self.item.append(i)
    def pop(self):
        return self.item.pop()
    def isEmpty(self):
        return len(self.item) == 0
    def top(self):
        length = len(self.item)
        if length == 0:
            return None
        return self.item[length-1]
        
        