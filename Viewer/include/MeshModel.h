#pragma once
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <memory>
#include "Face.h"
#include "Vertex.h"

typedef struct Cube {
	float front, back, right, left, top, bottom;
	glm::vec4 cPoints[8];  
	glm::vec4 color; 
}Cube;

/*
 * MeshModel class.
 * This class represents a mesh model (with faces and normals informations).
 * You can use Utils::LoadMeshModel to create instances of this class from .obj files.
 */
class MeshModel
{
private:
	std::vector<Face> faces;
	std::vector<glm::vec3> vertices;
	std::vector<Vertex> vertexs;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> v_normals;
	std::vector<glm::vec4> centerLine; 

	glm::mat4 localTransform;
	glm::mat4 scaleTransform;
	glm::mat4 rotationTransform;
	glm::mat4 translationTransform, worldTranslation, xRotationWorld, yRotationWorld, zRotationWorld;

	glm::mat4 worldRotation;
	glm::mat4 xRotation;
	glm::mat4 yRotation;
	glm::mat4 zRotation;
	glm::mat4x4 worldTransform;
	glm::vec4 color;
	std::string modelName;
	bool draw;
	bool drawCube;
	void createCube();
	void createNormals();
	void createCenterLines();
	bool isCurrentModel;
	Cube cube; 

public:
	//ctor
	MeshModel(const std::vector<Face>& faces, const std::vector<glm::vec3>& vertices, const std::vector<glm::vec3>& normals, const std::string& modelName = "");
	MeshModel(const std::vector<Face>& faces, const std::vector<Vertex>& vertices, const std::vector<glm::vec3>& normals, const std::string& modelName);
	MeshModel(const std::vector<Face>& faces, const std::vector<Vertex>& vertices, const std::vector<glm::vec3>& normals, const std::string& modelName, const bool &isCurrent);
	virtual ~MeshModel();
	MeshModel();

	void addVertexNormal(glm::vec3 &n) { this->v_normals.push_back(n); }
	void SetWorldTransformation(const glm::mat4& worldTransform);
	const glm::mat4& GetWorldTransformation() const;
	const glm::mat4& GetLocalTransform() const;
	const glm::mat4& GetScaleTransform() const;
	const glm::mat4& GetTranslationTransform() const;
	const glm::mat4& GetRotationTransform() const;
	const glm::mat4& GetWorldTranslate() const;
	const glm::mat4& GetWorldRotation() const;
	const glm::vec4& GetColor() const;
	

	//getters-setters
	void SetColor(const glm::vec4& color);
	void setDraw(const bool b) { this->draw = b; }
	void setScaleTransform(float xFactor, float yFactor, float zFactor);
	void setRotationTransform(float xDegree, float yDegree, float zDegree);
	void setTranslationTransform(float x, float y, float z);
	void setWorldTranslation(float x, float y, float z);
	void setWorldRotation(float xDegree, float yDegree, float zDegree);
	void setCube(const Cube c) { this->cube = c; }
	void setDrawCube(const bool b) { this->drawCube = b; }
	void setCenteLines(const std::vector<glm::vec4> c) { this->centerLine = c; }
	void setIsCurrentModel(const bool& b) { this->isCurrentModel = b; }

	const bool& getDraw() { return this->draw; }
	const std::string& GetModelName();
	const std::vector<Face>& GetFaces();
	const std::vector<glm::vec3>& GetVertices();
	const std::vector<glm::vec3>& GetNormals();
	const glm::mat4& getTranslationTransform() const;	
	const Cube getCube() const { return this->cube; }
	const bool getDrawCube() { return this->drawCube; }
	const std::vector<glm::vec4> getCenteLines() const { return this->centerLine; }	
	bool getIsCurrentModel() const { return this->isCurrentModel; }
	std::vector<Vertex> getVertexs() const { return this->vertexs; }
	const void setVertexs(const std::vector<Vertex> &v) { this->vertexs = v; } 
	
	
};
