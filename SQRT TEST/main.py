import math
import matplotlib.pyplot as plt

y = []
x = []
with open('points_sqrt.txt') as f:
    cnt = 1
    for i in f.readlines():
        temp = i.split('/')
        y.append(math.log10(int(temp[0]) / int(temp[1])))
        x.append(cnt)
        cnt += 1

plt.plot(x, y, 'o')
plt.title('SQRT 17')
plt.xlabel('X')
plt.ylabel('Y')
plt.savefig('SQRT17')
plt.show()