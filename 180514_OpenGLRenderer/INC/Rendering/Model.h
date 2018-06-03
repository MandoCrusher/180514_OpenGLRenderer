#pragma once

#include <vector>
#include <string>
#include <glm/vec4.hpp>

class Mesh;
class TextureWrapper;
class RenderCamera;
class PhongLight;
class ShaderWrapper;
struct aiNode;
struct aiMesh;
struct aiScene;
struct aiMaterial;

enum aiTextureType;

class Model {
public:
	Model(const char* a_filePath);
	~Model();

	void Draw(RenderCamera* a_camera,
		std::vector<PhongLight*> a_lights,
		const glm::vec4& a_globalAmbient, ShaderWrapper* a_ambientPass,
		ShaderWrapper* a_directionalPass, ShaderWrapper* a_pointPass, ShaderWrapper* a_spotPass);

protected:
private:
	std::vector<TextureWrapper*> m_loadedTextures;		// Hold onto loaded textures to avoid creating new ones for the same texture files
	std::vector<Mesh*> m_meshes;

	std::string m_modelDirectory;	// Hold onto directory model was loaded in for loading additional files e.g. textures

	/// Model loading functions
	void LoadModel(std::string a_filePath);
	void RecurReadNode(aiNode* a_node, const aiScene* a_modelScene);
	Mesh* ReadMesh(aiMesh* a_mesh, const aiScene* a_modelScene);
	std::vector<TextureWrapper*> ReadMaterialTextures(aiMaterial* a_meshMaterial, aiTextureType a_textureType, std::string a_typeName);
};