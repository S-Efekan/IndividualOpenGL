#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback ( GLFWwindow* window, int width, int height )
{
	glViewport ( 0, 0, width, height );
}

void processInput ( GLFWwindow* window )
{
	if (glfwGetKey ( window, GLFW_KEY_ESCAPE ) == GLFW_PRESS)		//If it is not pressed glfwGetKey returns GLFS_RELEASE
		glfwSetWindowShouldClose ( window, true );
}


int main ( )
{
	glfwInit ( );
	glfwWindowHint ( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint ( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint ( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	GLFWwindow* window = glfwCreateWindow ( 800, 600, "OpenGL", NULL, NULL );

	if (window == NULL)
	{
		printf ( "Failed to create GLFW widnow!" );
		glfwTerminate ( );
		return -1;
	}
	glfwMakeContextCurrent ( window );

	if (!gladLoadGLLoader ( (GLADloadproc)glfwGetProcAddress ))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport ( 0, 0, 800, 600 );

	glfwSetFramebufferSizeCallback ( window, framebuffer_size_callback );


	// render loop
	while (!glfwWindowShouldClose ( window ))
	{
		processInput ( window );
		
		glClearColor ( 0.2f, 0.3f, 0.3f, 1.0f );
		glClear ( GL_COLOR_BUFFER_BIT );


		glfwSwapBuffers ( window );
		glfwPollEvents ( );
	}

	glfwTerminate ( );
	return 0;
}