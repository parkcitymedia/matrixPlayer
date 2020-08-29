#include <GL/glew.h>    // ?? opengl stuff?
#include <GLFW/glfw3.h> // glfw to handle opengl
#include <chrono>
#include <iostream> // handles input & output
#include <map>      // keymapping
#include <stdio.h>
#include <stdlib.h> // random number stuff
#include <time.h>   // use time() to seed random numbers

#define WIDTH 800
#define HEIGHT 600

struct key {
  bool cur, prev;
};

GLFWwindow *window;
GLFWmonitor *display;
bool running = 1, fullscreen = 0;
std::map<int, key> keyMap;

void update() {
  // update frame
}
void input() {
  // input frame
}
void draw() {
  // draw to frame
}

int main() {

  // keep the window alive unless its told not to
  while (running) {
    update();
    input();
    draw();
  }

  /* // EVERYTHING MATRIX-BASED NOT RUNNING RN
  class matrixObj {
  private:
    // initialize
    int worldSize = 2;
    const int worldSizeMax = 16;
    std::string worldName;

  public:
    // generate a 3d cubic matrix of n^3 items
    int generate() {

      // ask for world name
      cout << "world name: ";
      cin >> worldName;

      // ask for world size
      cout << "world size (max " << worldSizeMax << "): ";
      cin >> worldSize;

      if (worldSize > worldSizeMax) { // check if world size is bigger than 16
        cout << "world size can be no larger than " << to_string(worldSizeMax);
      } else {
        // initialize random seed
        srand(time(NULL));
        
        // generate world of size worldSize
        cout << "generating world of size [" << to_string(worldSize)
             << "] with [" << worldSize * worldSize * worldSize
             << "] elements...\n";
        int world[worldSize][worldSize][worldSize];
        for (int xpos = 0; xpos < worldSize; xpos++) {
          for (int ypos = 0; ypos < worldSize; ypos++) {
            for (int zpos = 0; zpos < worldSize; zpos++) {
              world[xpos][ypos][zpos] = rand() % 4;
              cout << "world[" << to_string(xpos) << "," << to_string(ypos)
                   << "," << to_string(zpos)
                   << "]: " << to_string(world[xpos][ypos][zpos]) << "\n";
            }
          }
        }
      }
      return 0;
    }

    // free resources?
    int cleanUp() { return 0; }
  };

  // instance of matrixObj called matrixWorld
  matrixObj matrixWorld;

  // via the matrixWorld instance, generate a matrix
  matrixWorld.generate();
  */

  return 0;
}