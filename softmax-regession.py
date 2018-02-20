
import math
import pandas as pd
import numpy as np
import random
import time
import logging
import datetime

from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

class Softmax(object):

    def __init__(self):
        self.lr = 0.000001
        self.max_iteration = 100000
        self.wdecay = 0.01

    def cal_e(self, x, j):
        theta_j = self.w[j]
        dot_ = np.dot(theta_j, x)
        return math.exp(dot_)

    def cal_probability(self, x, j):
        molecule = self.cal_e(x, j)
        denominator = sum([self.cal_e(x, i) for i in range(self.k)])
        return molecule / denominator

    def cal_partial_derivative(self, x, y, j):
        first = int(y==j)                   # 计算第一项示性函数
        second = self.cal_probability(x, j) # 计算第二项概率

        return -x * (first - second) + self.wdecay * self.w[j] # 有正则项
        # return -x * (first - second)                 # 无正则项

        pass

    def train(self, features, labels):
        self.k = len(set(labels))
        self.w = np.zeros((self.k, len(features[0]) + 1))
        num = 0
        while num < self.max_iteration:
            num += 1
            print("num: %d" % num)
            index = random.randint(0, len(labels) - 1)
            x = features[index]
            y = labels[index]
            x = list(x)
            x.append(1.0)
            x = np.array(x)

            derivatives = [self.cal_partial_derivative(x, y, j) for j in range(self.k)]

            self.lr = 1/(num*10000) + 0.000001
            for j in range(self.k):
                self.w[j] -= self.lr * derivatives[j]

    def predict_(self, x):
        result = np.dot(self.w, x)
        row, column = result.shape

        # 找最大值所在的列
        _positon = np.argmax(result)
        m, n = divmod(_positon, column)

        return m

    def predict(self, features):
        labels = []
        for feature in features:
            x = list(feature)
            x.append(1)

            x = np.matrix(x)
            x = np.transpose(x)

            labels.append(self.predict_(x))
        return labels





if __name__ == '__main__':
    """
    设置日志打印
    """
    # 日志格式
    logger = logging.getLogger(__name__)
    formatter1 = logging.Formatter(
        '%(asctime)-16s - %(thread)-4s - %(levelname)-7s - %(lineno)d - [%(funcName)s] - %(message)s')
    
    # 文件日志
    file_handler = logging.FileHandler('softmax-regression.log')
    file_handler.setLevel(logging.INFO)
    file_handler.setFormatter(formatter1)
    
    logger.addHandler(file_handler)
    
    # 最低输出级别
    logger.setLevel(logging.INFO)
    logger.info("------------------------START-----------------------")
    logger.info(" compress app start at :%s" % datetime.datetime.now())
    
    time_1 = time.time()

    raw_data = pd.read_csv('F:/Data/KaggleMnist/train.csv')
    data = raw_data.values

    imgs = data[:, 1:]
    labels = data[:, 0]

    train_features, test_features, train_labels, test_labels = \
        train_test_split(imgs, labels, test_size=0.33, random_state = 23323)

    time_2 = time.time()

    softmax = Softmax()
    softmax.train(train_features, train_labels)

    time_3 = time.time()
    logger.info("train cost: %d" % (time_3 - time_2))

    test_predict = softmax.predict(test_features)
    time_4 = time.time()
    logger.info("train data predict cost: %d" % (time_4 - time_3))

    score = accuracy_score(test_labels, test_predict)
    logger.info("train data accuracy rate: %f" % score)

    raw_data = pd.read_csv('F:/Data/KaggleMnist/test.csv')
    data = raw_data.values
    imgs = data[:, :]
    test_predict = softmax.predict(imgs)
    predict = [[i+1, value] for i, value in enumerate(test_predict)]
    result = pd.DataFrame(predict, columns=['ImageId', 'Label'])
    result.to_csv('result.csv', index=False)
    
    

    
    
    