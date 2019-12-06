
<h2>Progress</h2>

**Week One - November 15-22**
- [X] Set up IDE and OpenFrameworks
- [X] Set up opencv library

**November 28**
- [X] Implemented play button to transition to game
- [X] Created enum + basic structure for the game
- [X] Added class to begin working on opencv and webcam recognition
- [X] Added catch for tests

**December 2**
- [X] Accessed webcam and setup view
- [X] Started learning and implementing gesture recognition 

**December 3**
- The old way didn't work
- [X] Figuring out how to focus on the hand
- [ ] Using contours to classify gesture
- I opened a bunch of different examples to try and follow and continue to explore tomorrow. 

**December 4**
- [X] Trying to implement different examples to find contours and find the hand - none of it works or makes sense
- [X] Went to office hours to try to get somewhere
- I tried implementing various different ways of recognizing and focus on an object and from there trying to find contours using contour deteection and convecity hull/defects. Most stuff didn't work, was too hard to follow (since I didn't understand most of the methods and code), and when I got everything compiling, it'd for example, show a black box.
I may try to revisit this in the future: here's what I tried: The following links, and GRIP.
    - https://github.com/udit043/Hand-Recognition-using-OpenCV
    - https://openframeworks.cc/documentation/ofxOpenCv/ofxCvContourFinder/
    - https://moustaphasaad.wordpress.com/2015/02/10/hand-recognition-finger-counter-opencv-and-c/
    - https://medium.com/@soffritti.pierfrancesco/handy-hands-detection-with-opencv-ac6e9fb3cec1
    
    This last one seemed the most promising, and had a great explanation, but it seemed like way too much code to copy, however the steps are laid out nicely and if I have time to experiment with this type of recognition, I will look back at this article.
- [X] Finally got hand ~~recognition~~ tracking to work and I have made basic movements correspond to gestures.

**My current resources:** https://www.opencv-srf.com/2010/09/object-detection-using-color-seperation.html, https://sites.google.com/site/ofauckland/examples/10-testing

**December 5**
- May switch to a game better suited to hand tracking as oppose to the recongition that Rock, Paper, Scissors required. Maybe snake, tic tac toe?
- [X] Decided to change the game to a maze controlled by hand movements

**December 6**
- [] Improving hand tracking (adding classifying by velocity to change direction)
- [] Getting snake game to work with my hand tracker so I can make sure the controls work via the webcam