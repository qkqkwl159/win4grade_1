import numpy as np
import cv2
import matplotlib.pyplot as plt

# ------- 영상의 덧셈(연산) , cv2 add()함수사용 비교 -------

#img1 = cv2.imread('./images/aero2.bmp')
#img2 = cv2.imread('./images/milkdrop.bmp')
#
#
#img_plus = img1+img2
#img_add=cv2.add(img1,img2)
#
#
#plt.figure(figsize=(20,20))
#plt.subplot(1,2,1) # 1행 4열ㅔ서 1번ㅐ 열  plt.title("First image")
#plt.title("Plus Image")
#plt.imshow(img_plus)
#plt.axis("off")
#plt.subplot(1,2,2) # 1row 4col , 1st clo / plt.title(First image)
#plt.title("Saturation")
#plt.imshow(img_add)
#plt.axis("off")
#plt.show()

# --------------------------------------------------------


# 픽셀 빼기 연산 -------------------------------------------------

path1 = './images/aero2.bmp'
path2 = './images/milkdrop.bmp'

img1 = cv2.imread(path1)
img2 = cv2.imread(path1)
img_sub=cv2.subtract(img1,img2)
img_sub2=cv2.absdiff(img1,img2)

plt.figure(figsize=(20,20))
plt.subplot(1,2,1)
plt.title("Image1")
plt.imshow(img_sub)
# --------------------------------------------------------