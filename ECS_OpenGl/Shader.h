#pragma once
#include <string>
#include <GL/glew.h>
#include "glm/mat4x4.hpp"
#include "glm/vec3.hpp"
#include "shaderLoader.h"

class Shader {
private:
	unsigned int shaderProgram;
public:
	Shader() = default;

	Shader& operator=(const Shader& other);

	Shader(std::string vertexPath, std::string fragmentPath);

	void SetMat4(std::string id, const glm::mat4& data);

	void SetVec3(const std::string id, const glm::vec3& data);

	void SetInt(const std::string id, int data);

	void SetFloat(const std::string id, float data);

	void Use();

	unsigned int GetId();
};