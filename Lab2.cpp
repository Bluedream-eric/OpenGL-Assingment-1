////Lab 2
////modified from http://learnopengl.com/
//
//#include "stdafx.h"
//
//#include "..\glew\glew.h"	// include GL Extension Wrangler
//#include "..\glfw\glfw3.h"	// include GLFW helper library
//#include <stdio.h>
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <glm.hpp>
//#include <vector>
//
//using namespace std;
//
//// Window dimensions
//const GLuint WIDTH = 800, HEIGHT = 600;
//
//// Is called whenever a key is pressed/released via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	std::cout << key << std::endl;
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}
//
//// The MAIN function, from here we start the application and run the game loop
//int main()
//{
//	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
//	// Init GLFW
//	glfwInit();
//	// Set all the required options for GLFW
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	// Create a GLFWwindow object that we can use for GLFW's functions
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Triangle", nullptr, nullptr);
//	if (window == nullptr)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	// Set the required callback functions
//	glfwSetKeyCallback(window, key_callback);
//
//	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
//	glewExperimental = GL_TRUE;
//	// Initialize GLEW to setup the OpenGL Function pointers
//	if (glewInit() != GLEW_OK)
//	{
//		std::cout << "Failed to initialize GLEW" << std::endl;
//		return -1;
//	}
//
//	// Define the viewport dimensions
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//
//	glViewport(0, 0, width, height);
//
//	// Build and compile our shader program
//	// Vertex shader
//
//	// Read the Vertex Shader code from the file
//	string vertex_shader_path = "vertex.shader";
//	string VertexShaderCode;
//	std::ifstream VertexShaderStream(vertex_shader_path, ios::in);
//
//	if (VertexShaderStream.is_open()) {
//		string Line = "";
//		while (getline(VertexShaderStream, Line))
//			VertexShaderCode += "\n" + Line;
//		VertexShaderStream.close();
//	}
//	else {
//		printf("Impossible to open %s. Are you in the right directory ?\n", vertex_shader_path.c_str());
//		getchar();
//		exit(-1);
//	}
//
//	// Read the Fragment Shader code from the file
//	string fragment_shader_path = "fragment.shader";
//	std::string FragmentShaderCode;
//	std::ifstream FragmentShaderStream(fragment_shader_path, std::ios::in);
//
//	if (FragmentShaderStream.is_open()) {
//		std::string Line = "";
//		while (getline(FragmentShaderStream, Line))
//			FragmentShaderCode += "\n" + Line;
//		FragmentShaderStream.close();
//	}
//	else {
//		printf("Impossible to open %s. Are you in the right directory?\n", fragment_shader_path.c_str());
//		getchar();
//		exit(-1);
//	}
//
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	char const * VertexSourcePointer = VertexShaderCode.c_str();
//	glShaderSource(vertexShader, 1, &VertexSourcePointer, NULL);
//	glCompileShader(vertexShader);
//	// Check for compile time errors
//	GLint success;
//	GLchar infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// Fragment shader
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
//	glShaderSource(fragmentShader, 1, &FragmentSourcePointer, NULL);
//	glCompileShader(fragmentShader);
//	// Check for compile time errors
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// Link shaders
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	// Check for linking errors
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertexShader); //free up memory
//	glDeleteShader(fragmentShader);
//
//	glUseProgram(shaderProgram);
//
//	ifstream input;
//	input.open("translational_5x5_grid.txt");
//	int curveType;
//	int numLines;
//	string line;
//	input >> curveType;
//	cout << curveType << "OIIICh" << endl;
//	getline(input, line);
//	input >> numLines;
//	cout << numLines << " The other one" << endl;
//	float x = 0;
//	float y = 0;
//	float z = 0;
//	vector < glm::vec3*>* profile = new vector<glm::vec3*>;
//	getline(input, line);
//	for (int i = 0; i < numLines; i++)
//	{
//		input >> x;
//		input >> y;
//		input >> z;
//		profile->push_back(new glm::vec3(x, y, z));
//		cout << x << ", " << y << ", " << z << std::endl;
//		getline(input, line);
//	}
//	int numLines2;
//	input >> numLines2;
//	vector < glm::vec3*>* trajectory = new vector<glm::vec3*>;
//	for (int i = 0; i < numLines2; i++)
//	{
//		input >> x;
//		input >> y;
//		input >> z;
//		trajectory->push_back(new glm::vec3(x, y, z));
//		cout << x << ", " << y << ", " << z << std::endl;
//		getline(input, line);
//	}
//
//	int size = profile->size()*trajectory->size() * 6;
//	GLfloat* vertices2 = new GLfloat[size];
//
//	int pos = 0;
//	int indexEBO = 0;
//	int indexSize = (profile->size() - 1)*(trajectory->size() - 1) * 3 * 2;
//	int *indices = new int[indexSize];
//
//
//	for (int i = 0; i < profile->size(); i++)
//	{
//		for (int k = 0; k < trajectory->size(); k++)
//		{
//			float height = (float(i) / float(profile->size()));
//			
//			vertices2[pos] = profile->at(i)->x + trajectory->at(k)->x;
//			vertices2[pos+1] = profile->at(i)->y + trajectory->at(k)->y;
//			vertices2[pos+2] = profile->at(i)->z + trajectory->at(k)->z;
//			vertices2[pos+3] = height;
//			vertices2[pos+4] = height;
//			vertices2[pos+5] = 0;
//			pos += 6;
//
//			if (i > 0 && k > 0)
//			{
//
//				indices[indexEBO] = pos / 6 - 1;
//				indices[indexEBO + 1] = pos / 6 - 1 - 1;
//				indices[indexEBO + 2] = pos / 6 - trajectory->size() - 2;
//
//				indices[indexEBO +3] = pos / 6 - 1;
//				indices[indexEBO + 4] = pos / 6 - trajectory->size() -1;
//				indices[indexEBO + 5] = pos / 6 - trajectory->size() - 2;
//
//				indexEBO += 6;
//			}
//		}
//		
//	}
//	cout << "\nEBO size: " << indexSize << " VBO size: " << size << endl;
//
//	//TESTING
//	int c = 0;
//	for (int i = 0; i < size; i++)
//	{
//		printf("%f ", vertices2[i]);
//		c++;
//		if (c > 2)
//		{
//			c = 0;
//			std::cout << std::endl;
//		}
//	}
//	c = 0;
//	std::cout << "Indices " << indexSize << std::endl;
//	for (int i = 0; i < indexSize; i++)
//	{
//		printf("%d ", indices[i]);
//		c++;
//		if (c > 2)
//		{
//			c = 0;
//			std::cout << std::endl;
//		}
//	}
//
//
//	
//
//	GLfloat vertices[] = {
//		0.0f, 0.5f, 0.0f,  // Top
//		0.5f, -0.5f, 0.0f,  // Bottom Right
//		-0.5f, -0.5f, 0.0f,  // Bottom Left
//	};
//
//	GLuint VAO, VBO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	//Binding the VAO
//	glBindVertexArray(VAO);
//
//
//	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2)*size, vertices2, GL_STATIC_DRAW);
//
//	//EBO STUFF
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices)*indexSize, indices, GL_STATIC_DRAW);
//
//	//For the vertices
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	//For the colors
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//
//	
//
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
//
//	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO
//
//	// Game loop
//	while (!glfwWindowShouldClose(window))
//	{
//		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
//		glfwPollEvents();
//
//		// Render
//		// Clear the colorbuffer
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, indexSize, GL_UNSIGNED_INT, 0);
//		glBindVertexArray(0);
//
//		// Swap the screen buffers
//		glfwSwapBuffers(window);
//	}
//
//	// Terminate GLFW, clearing any resources allocated by GLFW.
//	glfwTerminate();
//	return 0;
//}
