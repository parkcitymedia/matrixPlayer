#define GLEW_STATIC
#include <GL/glew.h> 
#include <GL/gl.h>   // ?? opengl stuff?
#include <GLFW/glfw3.h> // glfw to handle opengl
#include <chrono>
#include <iostream> // handles input & output
#include <map>      // keymapping
#include <stdio.h>
#include <stdlib.h> // random number stuff
#include <time.h>   // use time() to seed random numbers

const GLint WIDTH = 1280, HEIGHT = 720;

/*
// moved to GLint type
#define WIDTH 800
#define HEIGHT 600
*/

struct key {
  bool cur, prev;
};

// iniitialize global attributes
GLFWwindow *window;
GLFWmonitor *monitor;
bool running = 1, fullscreen;
std::map<int, key> keyMap;

class GLFWObj {
private:
  // initialize private vars / methods

public:
  // update frame
  void update() {
    // update frame
  }

  // take keyinput
  void input() {
    //
    glfwPollEvents();

    // if ESC pressed
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {

      // close window
      running = false;
      glfwSetWindowShouldClose(window, 1);
    }

    // if close button pressed
  }

  // draw to frame
  void draw() {

    // draw background color
    glClearColor(0.16, 0.2, 0.2, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // draw on top of cleared color

    // swap GL buffers
    glfwSwapBuffers(window);
  }
};

int main() {

  // instance GLFWInstance
  GLFWObj GLFWInstance;

  // window hints
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

  // check if initialized properly
  if (!glfwInit()) {
    fprintf(stderr, "\n\nfailed to properly initialize GLFW\n\n");
  }

  // set the window reference to create a window
  window = glfwCreateWindow(WIDTH, HEIGHT, "Matrix Player", NULL, NULL);

  if (window == NULL) {

    // yells at user about it
    std::cout << "\n\nfailed to open GLFW window\n\n";

    // terminate GLFW instance ...
    // ... since it's obviously not working
    glfwTerminate();
  }

  // make window context current?
  glfwMakeContextCurrent(window);

  // set primary monitor
  monitor = glfwGetPrimaryMonitor();

  running = true;
  fullscreen = false;

  // keep the window alive unless its told not to
  while (running) {
    GLFWInstance.update();
    GLFWInstance.input();
    GLFWInstance.draw();
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

        // loop through all z for all y for all x and assign values
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

  // end glfw loop
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}