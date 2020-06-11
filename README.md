# Racer

#### Quick Start
1. Clone repository
2. Build (e.g. using board 5):
 
    `mkdir -p builds && cd builds && cmake -DTARGET_BOARD=5 ../ && make && cd ../`
    > Target board is the index of the board starting from the left.
    
3. Connect to the board and run.

    `chmod 700 run_board.sh && ./runboard`

![Game View](./docs/images/game_view.png)

##### About

**Racer** is a course project for computer architectures course. This work aims to develop an application
for [MicroZed](http://microzed.org/product/microzed) board. Due to remote development, user interaction is
done through the console.

##### Vision

**[Racer is a simple racing game](https://github.com/elumixor/racer/docs/vision.md)**, where the player controls
a car and has to evade obstacles. Player scores points as he manages to stay on the racing track and not crash.
[(More in docs)](https://github.com/elumixor/racer/docs/vision.md)

##### Architecture

The program is written in C++, with parts of C, containing low-level board-interaction. 
**[Architecture](https://github.com/elumixor/racer/docs/architecture.md)** was somewhat inspired by Unity and
OpenGL, those familiar with it might find some resemblance. 
[(More in docs)](https://github.com/elumixor/racer/docs/architecture.md)