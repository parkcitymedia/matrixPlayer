#include <cstdlib>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h> // glfw to handle opengl
#include <chrono>		// not sure
#include <iostream>		// handles input & output
#include <map>			// keymapping
//#include <stdio.h>    // not needed atm
#include <stdlib.h> // random number stuff
#include <time.h>	// use time() to seed random numbers

// const GLint WIDTH = 1280, HEIGHT = 720;

// current / previous key checks
struct key
{
	bool cur, prev;
};

// iniitialize global attributes
std::map<int, key> keyMap;

// main takes no arguments
int main(void)
{
	// Vertex Shader Source / GLSL code for vertex buffers
	const GLchar *vertexShaderSource =
		"#version 400\n"
		"in vec3 vp;\n"
		"void main( ) {\n"
		"  gl_position = vec4( vp, 1.0 );\n"
		"}";

	// fragment shader source, colors
	const GLchar *fragmentShaderSource =
		"#version 400\n"
		"void main( ) {\n"
		"  out vec4 frag_color;\n"
		"  color = vec4( 1.0f, 0.5f, 0.2f, 1.0f );\n"
		"}";

	// window dimensions
	const GLint WIDTH = 1280, HEIGHT = 720;

	// abstract window and monitor instances
	GLFWwindow *window;
	GLFWmonitor *monitor;

	// test if running
	bool running, fullscreen;

	// update frame
	void update() {
		;
	}

	// take keyinput
	void input()
	{
		//
		glfwPollEvents();

		// if ESC pressed
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{

			// close window
			running = false;
			glfwSetWindowShouldClose(window, 1);
		}

		// if close button pressed
	}

	// draw to frame
	void draw()
	{

		// draw background color
		glClearColor(0.16, 0.2, 0.2, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		// draw on top of cleared color

		// swap GL buffers
		glfwSwapBuffers(window);
	}
	
	// check if initialized properly
	if (!glfwInit())
	{
		fprintf(stderr, "\n\nfailed to properly initialize GLFW\n\n");
	}

	// window hints
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	// set the window reference to create a window
	window = glfwCreateWindow(WIDTH, HEIGHT, "Matrix Player", nullptr, nullptr);

	if (window == nullptr)
	{

		// yells at user about it
		std::cout << "\n\nfailed to open GLFW window\n\n";

		// terminate GLFW instance ...
		// ... since it's obviously not working
		glfwTerminate();
	}

	// init values for screen width and height
	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	glfwMakeContextCurrent(window);
	monitor = glfwGetPrimaryMonitor();

	if (GLEW_OK != glewInit())
	{
		std::cout << "\n\nFailed to initialize GLEW!\n\n";
		return EXIT_FAILURE;
	}

	// define the viewport
	glViewport(0, 0, screenWidth, screenHeight);

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	//
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLint success;
	GLchar infoLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "\nERROR::SHADER::VERTEX::COMPILATION_FAILED\n\n";
	}

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n\n";
	}

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n\n";
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GLfloat vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
						  0.0f, 0.0f, 0.05f, 0.0f};

	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	running = true;
	fullscreen = false;

	// keep the window alive unless its told not to
	//   also loop through the primary methods for rendering
	while (running)
	{
		update();
		input();
		draw();
	}

	// end glfw loop
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}