<!-- Write your proposal here! Make sure to use properly-formatted Markdown! -->
<h1>Maze Game</h1>

<p> My final project is maze which you can control using your hand movements/position via the webcam. </p>

<h2>How to setup for the game</h2>

**Dependencies + External Libraries** 
OpenCV: used to capture and recognize hand movements 
OpenFrameWorks: used to update and graw GUI window for the game

**Compiling code**
As long as you add openframeworks OfxGUi and OfxOpenCv add ons, and the OpenCV library, you should have no problems. This game was built and ran using XCode on MacOS but the process should be similiar on other operating systems.

### Game

- For optiminal results it's best to isolate your hand using a glove/shirt, as the detection uses hue and color     detection to track the hand.

#### How to Play

| Key      | Action                                                      |
|----------|-------------------------------------------------------------|

| `SPACE`  | Play                                                        |
| `P`      | Pause                                                       |
| `F`      | Toggle full screen                                          |
| `W`      | Hide/show webcam                                            |   
| `S`      | Enable/disable slow mode                                    |
| `K`      | Toggle key mode                                             |

- Right now there is only one preset maze layout, I'm working towards implementing a fully functioning maze generation game.