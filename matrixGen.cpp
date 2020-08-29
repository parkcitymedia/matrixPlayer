#include <GL/glew.h>    // ??
#include <GLFW/glfw3.h> // glfw to handle opengl
#include <iostream>     // handles input & output
#include <stdlib.h>     // random number stuff
#include <time.h>       // use time() to seed random numbers

GLFWwindow *window;
GLFWmonitor *display;
bool running = 1, fullscreen = 0;
map<int, key> Keymap;

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

  // initialize random seed
  srand(time(NULL));
  while (running) {
    update();
    input();
    draw();
  }

  class matrixObj {
  private:
    // initialize
    int worldSize = 2;
    const int worldSizeMax = 16;
    string worldName;

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

  return 0;
}