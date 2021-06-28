#pragma once
#include <SFML/Window.hpp>
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera {
public:
	Camera();

	glm::mat4 GetViewMatrix();

	glm::mat4 GetProjectionMatrix();

	glm::vec3 GetPosition();

	glm::vec3 GetFront();

	glm::vec3 GetRight();

	float GetSpeed();

	std::pair<float, float> GetPos();

	float GetYaw();

	float GetPitch();

	void SetPosition(glm::vec3 position);

	void SetPos(std::pair<float, float> pos);

	void SetYaw(float yaw);

	void SetPitch(float pitch);

	void UpdateCameraVectors();
private:
	glm::vec3 positionCamera;
	glm::vec3 frontCamera;
	glm::vec3 upCamera;
	glm::vec3 right;
	glm::vec3 up;

	float speed = 0.05f;
	float speedMouse = 0.0005f;
	float yaw;
	float pitch;
	float xPos = 800 / 2.0f;
	float yPos = 600 / 2.0f;
	bool mouseMove = true;

	float horizontalAngle = 3.14f;
	float verticalAngle = 0.0f;
};