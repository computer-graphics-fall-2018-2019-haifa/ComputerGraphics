#pragma once
#include <memory>
#include <vector>
#include <string>
#include <glm/glm.hpp>

class Face
{
private:
	std::vector<int> vertexIndices;
	std::vector<int> normalIndices;
	std::vector<int> textureIndices;
	glm::vec3 centeroid; 

public:
	Face(std::istream& issLine);
	virtual ~Face();
	const int Face::GetVertexIndex(int index);
	const int Face::GetNormalIndex(int index);
	const int Face::GetTextureIndex(int index);
	const std::vector<int> Face::GetVertices();
	const glm::vec3 GetCenter() const { return this->centeroid; }
	void SetCenter(const glm::vec3 v) { this->centeroid = v; }
};