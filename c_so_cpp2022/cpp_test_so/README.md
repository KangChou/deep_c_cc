import numpy as np
import cv2

# Create a black image
img = np.zeros((512,512,3), np.uint8)

# Draw a diagonal blue line with thickness of 5 px
cv2.line(img,(0,0),(511,511),(255,0,0),5)
cv2.imshow('line',img)
cv2.waitKey()   

#apt-get update
#apt-get install ffmpeg libsm6 libxext6  -y
#apt-get update && apt-get install -y opencv-python-headless
#pip install opencv-python-headless
#apt-get update && apt-get install libgl1
