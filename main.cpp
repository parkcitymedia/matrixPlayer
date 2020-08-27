#include <GL/gl.h>
#include <iostream>
//#include <fstream>
#include <GLFW/glfw3.h> // use glfw for graphics
#include <cmath>        // for for loop comparisons
#include <stdlib.h>     // for rand
#include <time.h>       // to initialize rand

// Use c++ standard namespace
using namespace std;

// main
int main() {

  GLFWwindow *window;

  // initialize glfw
  if (!glfwInit()) {
    return -1;
  }

  // create glfw win and it's context
  window = glfwCreateWindow(640, 480, "Title", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  // make the win's context current
  glfwMakeContextCurrent(window);

  // keep the window open until closed
  while (glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0; // return ok val
}