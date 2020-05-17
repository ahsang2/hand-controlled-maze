<!-- Write your proposal here! Make sure to use properly-formatted Markdown! -->
<h1>Maze Game</h1>

<p> I created a maze game which supports random maze generation for any sized board. The graph algorithms used were a variation of BFS and a randomized version of Kruskal's algorithm using a disjoint sets data structure written from scratch.</p>

<p> Currently, I am researching ways to improve the hand tracking conrtols of the game by exploring the best strategies for real-time object tracking.</p>

<h2>How to setup for the game</h2>

**Dependencies + External Libraries**  

OpenCV: used to capture and recognize hand movements 

OpenFrameWorks: used to update and graw GUI window for the game

**Compiling Code**

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
