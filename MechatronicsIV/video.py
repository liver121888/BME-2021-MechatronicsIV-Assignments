#!/usr/bin/env python
# import the opencv library
import cv2

# define a video capture object
vid = cv2.VideoCapture(-1)
#640 480
vid.set(cv2.CAP_PROP_FRAME_WIDTH, 160)
vid.set(cv2.CAP_PROP_FRAME_HEIGHT, 120)

while(True):
      
    # Capture the video frame
    #bvfxv by frame
    ret, frame = vid.read()
    # Display the resulting frame
    cv2.imshow('frame', frame)
    # the 'q' button is set as the
    # quitting button you may use any
    # desired button of your choice
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
  
# After the loop release the cap object
vid.release()
# Destroy all the windows
cv2.destroyAllWindows()
