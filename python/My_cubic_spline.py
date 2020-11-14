#coding=utf-8
import numpy as np
import bisect
import json

class Spline:
    """
    三次样条类
    """

    def __init__(self, x, y) :
        self.a,self.b,self.c,self.d = [],[],[],[]

        self.x = x
        self.y = y

        self.nx = len(x)        #dimension of x
        h = np.diff(x)

        #calc coefficient c
        self.a = [iy for iy in y]

        #calc coefficient c
        A = self.__calc_A(h)
        B = self.__calc_B(h)
        self.m = np.linalg.solve(A, B)
        self.c = self.m / 2.0

        # calc spline cofficient b and d
        for i in range(self.nx - 1) :
            self.d.append((self.c[i + 1] - self.c[i]) / (3.0 * h[i]))
            tb = (self.a[i + 1] - self.a[i]) / h[i] - h[i] * (self.c[i + 1] + 2.0 * self.c[i]) / 3.0
            self.b.append(tb)

    def __search_index(self, x) :
        return bisect.bisect(self.x, x) - 1

    def calc(self, t) :
        """
        计算位置
        当t超过边界，返回None
        """
        if t < self.x[0] :
            return None
        elif t > self.x[-1]:
                return None
        
        i = self.__search_index(t)
        dx = t - self.x[i]
        result = self.a[i] + self.b[i] *dx + self.c[i] * dx **2.0 + self.d[i] * dx ** 3.0

        return result

    def __calc_A(self, h) :
        """
        计算算法第二步中的等号左侧的矩阵表达式A
        """
        A = np.zeros((self.nx, self.nx))
        A[0, 0] = 1.0
        for i in range(self.nx - 1) :
            if i != (self.nx - 2) :
                A[i + 1, i + 1] = 2.0 * (h[i] + h[i +  1])
            A[i + 1, i] = h[i]
            A[i, i + 1] = h[i]
        
        A[0, 1] = 0.0
        A[self.nx - 1, self.nx - 2] = 0.0
        A[self.nx - 1, self.nx - 1] = 1.0

        return A
    
    def __calc_B(self, h) :
        """
        计算算法第二步中的等号右侧的矩阵表达式B
        """
        B = np.zeros(self.nx)
        for i in range(self.nx - 2) :
            B[i + 1] = 6.0 * (self.a[i +2] - self.a[i + 1]) / h[i + 1] - 6.0 * (self.a[i + 1] - self.a[i]) / h[i]
        return B

#import cubic_spline
# import numpy as np
import matplotlib.pyplot as plt 

def main() :
    # x = [-4, -2, 0.0, 2, 4, 6, 10]
    # y = [1.2, 0.6, 0.0, 1.5, 3.8, 5.0, 3.0]

    cx = []
    cy = []
    #解析json文件
    with open('./anchor_segment.json', encoding='utf-8') as f:
        json_data = json.load(f)
        segments = json_data['segments']
        for segmentsIdx in segments :
            if segmentsIdx['id'] == '2' :
                points_xyzs = segmentsIdx['segment']
                for pointsIdx in points_xyzs :
                    for point in pointsIdx['xyzs'] :
                        cx.append(point['x'])
                        cy.append(point['y'])
                # print(points_xyzs)
                # for point in points_xyzs['xyzs'] : 
                #     print('the first point x: ', point['x'])
                #     print('the first point y: ', point['y'])
                    # cx.append(point['x'])
                    # cy.append(point['y'])
                break
    # print('the first point x: ', cx[0])
    # print('the first point y: ', cy[0])

    # print('the cx.length: ', len(cx))

    spline = Spline(cx, cy)
    rx = np.arange(-4.0, 10, 0.01)
    ry = [spline.calc(i) for i in rx]

    plt.plot(cx, cy, "og")
    plt.plot(rx, ry, "-r")
    plt.grid(True)
    # plt.axis("equal")
    plt.xlim(784525,784650)
    plt.show()

if __name__ == "__main__":
    main()