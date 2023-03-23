import cv2


img = cv2.imread('./puppy.jpg',cv2.IMREAD_GRAYSCALE)
img_color = cv2.imread('./puppy.jpg',cv2.IMREAD_COLOR)
cat_color = cv2.imread('./cat.jpg',cv2.IMREAD_COLOR)

cat_color = cv2.resize(cat_color,(128,128))
img_color = cv2.resize(img_color,(128,128))

cv2.imwrite('./puppy_resize.jpg',img_color)
cv2.imwrite('./cat_resize.jpg',cat_color)
cv2.waitKey(0)