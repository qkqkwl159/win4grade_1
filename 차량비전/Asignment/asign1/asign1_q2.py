import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('./rena.png')
rgb_img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
gray = cv2.cvtColor(rgb_img ,cv2.COLOR_BGR2GRAY)

red,green,blue = cv2.split(rgb_img)



plt.subplot(3,3,1)
plt.title("GrayScale")
plt.imshow(gray,cmap='gray')
cv2.imwrite('./gray_scale.png',gray)

minp,maxp,minLoc,maxLoc = cv2.minMaxLoc(gray)
print(f'  min : {minp} , max : {maxp}')
print('  avg : ',gray.mean())

plt.subplot(3,3,2)
plt.title("rgb")
plt.imshow(rgb_img)

plt.subplot(3,3,4)
plt.title('red')
plt.imshow(red,cmap='Reds')


plt.subplot(3,3,5)
plt.title("green")
plt.imshow(green,cmap='Greens')

plt.subplot(3,3,6)
plt.title("blue")
plt.imshow(blue,cmap='Blues')

_, dst = cv2.threshold(gray,0,255,cv2.THRESH_OTSU)
plt.subplot(3,3,3)
plt.title("binary")
plt.imshow(dst,cmap='binary')

plt.show()  
