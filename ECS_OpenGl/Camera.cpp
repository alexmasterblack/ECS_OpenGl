#include "Camera.h"

Camera::Camera() {
	positionCamera = glm::vec3(0.0f, 0.0f, 3.0f);
	frontCamera = glm::vec3(0.0f, 0.0f, -1.0f);
	upCamera = glm::vec3(0.0f, 1.0f, 0.0f);
	pitch = 0.0f;
	yaw = -90.0f;

	UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(positionCamera, positionCamera + frontCamera, upCamera);
}

glm::mat4 Camera::GetProjectionMatrix() {
	return glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

glm::vec3 Camera::GetPosition() {
	return positionCamera;
}

glm::vec3 Camera::GetFront() {
	return frontCamera;
}

glm::vec3 Camera::GetRight() {
	return right;
}

float Camera::GetSpeed() {
	return speed;
}

std::pair<float, float> Camera::GetPos() {
	return std::pair<float, float>(xPos, yPos);
}

float Camera::GetYaw() {
	return yaw;
}

float Camera::GetPitch() {
	return pitch;
}

void Camera::SetPosition(glm::vec3 position) {
	positionCamera = position;
}

void Camera::SetPos(std::pair<float, float> pos) {
	xPos = pos.first;
	yPos = pos.second;
}

void Camera::SetYaw(float yaw) {
	this->yaw = yaw;
}

void Camera::SetPitch(float pitch) {
	this->pitch = pitch;
}

void Camera::UpdateCameraVectors() {
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	frontCamera = glm::normalize(front);
	right = glm::normalize(glm::cross(frontCamera, upCamera));
}