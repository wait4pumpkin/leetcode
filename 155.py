class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.minVals = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.data.append(x)
        if self.minVals:
            self.minVals.append(min(self.minVals[-1], x))
        else:
            self.minVals.append(x)

    def pop(self):
        """
        :rtype: void
        """
        if self.data:
            del self.minVals[-1]
            self.data

    def top(self):
        """
        :rtype: int
        """
        if self.data:
            return self.data[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if self.data:
            return self.minVals[-1]
