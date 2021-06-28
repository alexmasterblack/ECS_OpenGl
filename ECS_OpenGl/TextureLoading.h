#pragma once

#include <vector>
#include <string>

class TextureLoading {
private:
	unsigned int texture;
public:
	TextureLoading() = default;

	TextureLoading& operator=(const TextureLoading& other);

	TextureLoading(std::vector<std::string> texture_faces);

	TextureLoading(const char* path);

	void Binding(int check = -1);

	unsigned int GetTexture();
};