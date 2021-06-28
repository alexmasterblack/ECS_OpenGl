#include "Light.h"

Light::Light(glm::vec3 direction, glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular) :
	direction(direction),
	ambient(ambient),
	diffuse(diffuse),
	specular(specular) {}
