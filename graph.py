c = [0, 0]
n = int(input())
c[0] = int(input())
c[1] = int(input())
r = int(input())

x1 = []
x2 = []
y1 = []
y2 = []

for i in range(n):
    x1.append(int(input()))
    y1.append(int(input()))
    x2.append(int(input()))
    y2.append(int(input()))


resp = 0

def dot(a, b):
    return a[0] * b[0] + a[1] * b[1]

for i in range(n):
    a = [0, 1]
    b = [0, 1]
    d = [0, 1]

    a[0] = x2[i] - x1[i]
    a[1] = y2[i] - y1[i]
    b[0] = c[0] - x1[i]
    b[1] = c[1] - y1[i]

    d[0] = b[0] * dot(a, a) - a[0] * dot(a, b)
    d[1] = b[1] * dot(a, a) - a[1] * dot(a, b)

    if (dot(d, d) <= r * r * dot(a, a) * dot(a, a)):
        resp += 1


import cv2
import numpy as np

canvas = np.ones((800, 1200, 3)) * 255
cv2.imshow("Canvas", canvas)

preto = (0, 0, 0)

cv2.circle(canvas, (c[1] * 50, c[0] * 50), r * 50, preto)
cv2.imshow("Canvas", canvas)

cv2.circle(canvas, (c[1] * 50, c[0] * 50), r, preto)
cv2.imshow("Canvas", canvas)

for i in range(n):
    red = (0, 0, 255)
    cv2.line(canvas, (x1[i] * 50, y1[i] * 50), (x2[i] * 50, y2[i] * 50), red)
    cv2.imshow("Canvas", canvas)

cv2.waitKey(0)
    
print(resp)