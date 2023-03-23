import cv2
from matplotlib import pyplot as plt




catColor = cv2.imread('./cat.jpg',cv2.IMREAD_COLOR)
puppyColor = cv2.imread('./puppy.jpg',cv2.IMREAD_COLOR)

cat_resize = cv2.resize(catColor,(128,128))
puppy_resize = cv2.resize(puppyColor,(128,128))
# cv2.imwrite('./cat_resize_q3.jpg',cat_resize)
# cv2.imwrite('./puppy_resize_q3jpg',puppy_resize)

catGray = cv2.cvtColor(cat_resize,cv2.COLOR_BGR2GRAY)
puppyGray = cv2.cvtColor(puppy_resize,cv2.COLOR_BGR2GRAY)

WrappingImg= catGray + puppyGray
saturationImg = cv2.add(catGray,puppyGray)

plt.subplot(2,2,1)
plt.title('cat')
plt.imshow(catGray,cmap='gray')

plt.subplot(2,2,2)
plt.title('puppy')
plt.imshow(puppyGray,cmap='gray')

plt.subplot(2,2,3)
plt.title('Saturation')
plt.imshow(saturationImg,cmap='gray')

plt.subplot(2,2,4)
plt.title('Wrapping')
plt.imshow(WrappingImg,cmap='gray')
plt.show()

cv2.waitKey(0)
