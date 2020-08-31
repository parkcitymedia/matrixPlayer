#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h> // glfw to handle opengl
#include <chrono>
#include <iostream> // handles input & output
#include <map>      // keymapping
//#include <stdio.h> // not needed atm
#include <stdlib.h> // random number stuff
#include <time.h>   // use time() to seed random numbers

const GLint WIDTH = 1280, HEIGHT = 720;

// current / previous key checks
struct key {
  bool cur, prev;
};

// iniitialize global attributes
std::map<int, key> keyMap;

/* //using different tutorial

// Vertex Shader Source / GLSL code for vertexes
const GLchar *vertexShaderSource = "\
  #version 330 core\n\
  layout ( location = 0 ) in vec3 position;\n\
  void main( ) {\n\
  gl_position = vec4( position.x, position.y, position.z, 1.0 );\n\
  }";

// fragment shader source, colors
const GLchar *fragmentShaderSource = "\
  #version 330 core\n\
  void main( ) {\n\
  color = vec4( 1.0f, 0.5f, 0.2f, 1.0f );\n\
  }\
  ";

*/

class GLFWObj {
private:
  // initialize private vars / methods

public:
  // abstract window and monitor instances
  GLFWwindow *window;
  GLFWmonitor *monitor;

  // test if running
  bool running, fullscreen;

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

  // window hints
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

  // check if initialized properly
  if (!glfwInit()) {
    fprintf(stderr, "\n\nfailed to properly initialize GLFW\n\n");
  }

  // create GLFWObj instance GLFWInst
  GLFWObj GLFWInst;

  // set the window reference to create a window
  GLFWInst.window =
      glfwCreateWindow(WIDTH, HEIGHT, "Matrix Player", nullptr, nullptr);

  if (GLFWInst.window == nullptr) {

    // yells at user about it
    std::cout << "\n\nfailed to open GLFW window\n\n";

    // terminate GLFW instance ...
    // ... since it's obviously not working
    glfwTerminate();
  }

  glfwMakeContextCurrent(GLFWInst.window);
  GLFWInst.monitor = glfwGetPrimaryMonitor();

  GLFWInst.running = true;
  GLFWInst.fullscreen = false;

  // keep the window alive unless its told not to
  while (GLFWInst.running) {
    GLFWInst.update();
    GLFWInst.input();
    GLFWInst.draw();
  }

  // end glfw loop
  glfwDestroyWindow(GLFWInst.window);
  glfwTerminate();
  return 0;
}