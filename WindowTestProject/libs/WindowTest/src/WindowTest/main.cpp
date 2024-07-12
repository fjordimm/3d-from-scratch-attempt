
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdio>
#include <cstdlib>

void checkShaderCompilation(GLuint shader)
{
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status == true)
	{ return; }
	else
	{
		static char buf[512];
		glGetShaderInfoLog(shader, 512, nullptr, buf);
		std::fprintf(stderr, "=== Shader did not compile ===\n");
		std::fprintf(stderr, "%s\n", buf);
		std::exit(EXIT_FAILURE);
	}
}

int main(void)
{
	std::printf("helooooooo\n");

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hiiii this is my test window", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	/* Initialize GLEW */
	glewExperimental = GL_TRUE;
	glewInit();

	/////////////////////////////////////////////////
	{
		float verts1[] =
		{
			0.0f, 0.5f,
			0.5f, -0.5f,
			-0.5f, -0.5f
		};

		GLuint vbo1;
		glGenBuffers(1, &vbo1);

		glBindBuffer(GL_ARRAY_BUFFER, vbo1);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts1), verts1, GL_STATIC_DRAW);

		const char* vertexShaderSource = R"glsl(
			#version 150 core

			in vec2 position;

			void main()
			{
				gl_Position = vec4(position, 0.0, 1.0);
			}
		)glsl";
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
		glCompileShader(vertexShader);
		checkShaderCompilation(vertexShader);

		const char* fragmentShaderSource = R"glsl(
			#version 150 core

			out vec4 outColor;

			void main()
			{
				outColor = vec4(1.0, 1.0, 1.0, 1.0);
			}
		)glsl";
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
		glCompileShader(fragmentShader);
		checkShaderCompilation(fragmentShader);
	}
	/////////////////////////////////////////////////

	// GLuint vertexBuffer;
	// glGenBuffers(1, &vertexBuffer);
	// std::printf("%u\n", vertexBuffer);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
		/* Process inputs */

        /* Render stuff */

		glClearColor(0.4f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		

        /* Do stuff required by GLFW */

		glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
