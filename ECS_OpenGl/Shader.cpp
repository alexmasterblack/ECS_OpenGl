#include "Shader.h"

Shader& Shader::operator=(const Shader& other)
{
	shaderProgram = other.shaderProgram;
	return *this;
}

Shader::Shader(std::string vertexPath, std::string fragmentPath)
{
	shaderProgram = LoadShaders(vertexPath, fragmentPath);
}

void Shader::SetMat4(std::string id, const glm::mat4& data)
{
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, id.c_str()), 1, GL_FALSE, &data[0][0]);
}

void Shader::SetVec3(const std::string id, const glm::vec3& data)
{
	glUniform3fv(glGetUniformLocation(shaderProgram, id.c_str()), 1, &data[0]);
}

void Shader::SetInt(const std::string id, int data)
{
	glUniform1i(glGetUniformLocation(shaderProgram, id.c_str()), data);
}

void Shader::SetFloat(const std::string id, float data)
{
	glUniform1f(glGetUniformLocation(shaderProgram, id.c_str()), data);
}

void Shader::Use()
{
	glUseProgram(shaderProgram);
}

unsigned int Shader::GetId()
{
	return shaderProgram;
}
