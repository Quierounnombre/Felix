/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flx_putimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:11:25 by vicgarci          #+#    #+#             */
/*   Updated: 2022/12/01 14:09:57 by vicgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Felix.h"

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

void	flx_putimg(GLFWwindow *window)
{
	GLfloat v[] =
	{
		-0.5f, -0.5f * (float)sqrt(4) / 4, 0.0f,
		0.5f, -0.5f * (float)sqrt(4) / 4, 0.0f,
		0.5f, 0.5f * (float)sqrt(4)  / 4, 0.0f,
		-0.5f, 0.5f * (float)sqrt(4) / 4, 0.0f,
	};
	GLuint vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexshader);

	GLuint fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentshader);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexshader);
	glAttachShader(shaderProgram, fragmentshader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexshader);
	glDeleteShader(fragmentshader);
	

	GLuint VBO;
	GLuint VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(VAO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		//glUseProgram(shaderProgram);
		//glBindVertexArray(VAO);
		//glDrawArrays(GL_IMAGE_2D, 0, 3);
		glBegin(GL_LINES);
			glVertex2f(10, 10);
			glVertex2f(20, 0.75f);
		glEnd();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
}
