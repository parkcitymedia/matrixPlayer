#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h> // glfw to handle opengl
#include <chrono>
#include <iostream> // handles input & output
#include <map>      // keymapping
#include <stdio.h>
#include <stdlib.h> // random number stuff
#include <time.h>   // use time() to seed random numbers

const GLint WIDTH = 1280, HEIGHT = 720;

// Vertex Shader Source / GLSL code for vertexes
const GLchar *vertexShaderSource =
    "#version 330 core\n"
    "layout ( location = 0 ) in vec3 position;\n"
    "void main( ) {\n"
    "gl_position = vec4( position.x, position.y, position.z, 1.0 );\n"
    "}";

// fragment shader source, colors
const GLchar *fragmentShaderSource = "#version 330 core\n"
                                     "void main( ) {\n"
                                     "color = vec4( 1.0f, 0.5f, 0.2f, 1.0f );\n"
                                     "}";

// current / previous key checks
struct key {
  bool cur, prev;
};

// iniitialize global attributes

bool running = 1, fullscreen;
std::map<int, key> keyMap;

class GLFWObj {
private:
  // initialize private vars / methods

public:
  // abstract window and monitor instances
  GLFWwindow *window;
  GLFWmonitor *monitor;

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
  GLFWInstance.window =
      glfwCreateWindow(WIDTH, HEIGHT, "Matrix Player", NULL, NULL);

  if (GLFWInstance.window == NULL) {

    // yells at user about it
    std::cout << "\n\nfailed to open GLFW window\n\n";

    // terminate GLFW instance ...
    // ... since it's obviously not working
    glfwTerminate();
  }

  // make window context current?
  glfwMakeContextCurrent(GLFWInstance.window);

  // set primary monitor
  GLFWInstance.monitor = glfwGetPrimaryMonitor();

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
  glfwDestroyWindow(GLFWInstance.window);
  glfwTerminate();
  return 0;
}