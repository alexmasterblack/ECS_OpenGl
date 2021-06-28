#pragma once
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"

class Light {
public:
	glm::vec3 direction;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

	Light() = default;

	Light(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular);
};

