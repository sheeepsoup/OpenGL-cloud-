#include "Model.h"
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>

Model::Model(std::string path, GLint LoadModew)
{
	loadModle(path);
	LoadMode = LoadModew;

}

void Model::Draw(Shader * shader)
{

	for (unsigned int i = 0; i < meshes.size(); i++) {
		meshes[i].Draw(shader);
	}
}

void Model::loadModle(std::string path)
{

	//ģ������
	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	//�������
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
	{
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}
	else {
		//	std::cout << "success" << std::endl;
	}

	//������һ���ļ���
//	directory = path.substr(0, path.find_last_of('\\'));

	// ����Ŀ¼·����ȡ��ʽ
	size_t lastSlash = path.find_last_of("/\\");
	directory = (lastSlash != std::string::npos) ?
		path.substr(0, lastSlash) :
		"";
	// ͳһ�滻ΪUnix���·���ָ���
	std::replace(directory.begin(), directory.end(), '\\', '/');
	//SDL_Delay(88888);
	std::cout << directory;
	processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode * node, const aiScene * scene)
{
	//std::cout << node->mName.data << std::endl;
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh *curMesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(curMesh, scene));
	}
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}
// �޸����������غ���
GLuint loadTexturea(const char* path, GLint Mode, GLenum Num) {
	SDL_Surface* surface = IMG_Load(path);
	if (!surface) {
		std::cerr << "IMG_Load failed: " << IMG_GetError() << std::endl;
		return 0;
	}

	// ת��ΪRGBA��ʽ
	SDL_Surface* converted = SDL_ConvertSurfaceFormat(
		surface,
		SDL_PIXELFORMAT_RGBA32,
		0
	);
	SDL_FreeSurface(surface);

	// ����OpenGL����
	GLuint textureID;
	glGenTextures(1, &textureID);
	glActiveTexture(Num);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// �����ڴ����
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// �ϴ�����
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,  // �ڲ���ʽ
		converted->w,
		converted->h,
		0,
		GL_RGBA,  // ���ݸ�ʽ
		GL_UNSIGNED_BYTE,
		converted->pixels
	);

	glGenerateMipmap(GL_TEXTURE_2D);
	SDL_FreeSurface(converted);

	// �����������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return textureID;
}
// �޸ĺ��loadMaterialTextures
std::vector<Texture> Model::loadMaterialTextures(
	aiMaterial* mat,
	aiTextureType type,
	std::string typeName
) {
	std::vector<Texture> textures;
	for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
		aiString str;
		mat->GetTexture(type, i, &str);

		// ͳһ·����ʽ
		std::string texturePath = str.C_Str();
		std::replace(texturePath.begin(), texturePath.end(), '\\', '/');

		bool skip = false;
		for (auto& loaded : textures_loaded) {
			if (loaded.path == texturePath) { // �Ƚ�ͳһ���·��
				textures.push_back(loaded);
				skip = true;
				break;
			}
		}
		if (!skip) {
			std::string fullPath = directory + "/" + texturePath;
			Texture texture;
			texture.id = loadTexturea(fullPath.c_str(), LoadMode, GL_TEXTURE0);
			texture.type = typeName;
			texture.path = texturePath; // ����ͳһ���·��

			textures.push_back(texture);
			textures_loaded.push_back(texture);
		}
	}
	return textures;
}


Mesh Model::processMesh(aiMesh * mesh, const aiScene * scene)
{
	// data to fill
	std::vector<Vertex> tempVertices;
	std::vector<unsigned int> tempIndices;
	std::vector<Texture> tempTextures;

	glm::vec3 tempVec;
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex tempvertex;
		tempvertex.Position.x = mesh->mVertices[i].x;
		tempvertex.Position.y = mesh->mVertices[i].y;
		tempvertex.Position.z = mesh->mVertices[i].z;

		tempvertex.Normal.x = mesh->mNormals[i].x;
		tempvertex.Normal.y = mesh->mNormals[i].y;
		tempvertex.Normal.z = mesh->mNormals[i].z;

		// �������꣨��Y�ᷭת��
		if (mesh->mTextureCoords[0]) {
			tempvertex.TexCoords = glm::vec2(
				mesh->mTextureCoords[0][i].x,
				mesh->mTextureCoords[0][i].y
			);
		}
		else {
			tempvertex.TexCoords = glm::vec2(0.0f);
		}

		tempVertices.push_back(tempvertex);
	}

	for (unsigned int i = 0; i < mesh->mNumFaces; i++) {

		for (unsigned int j = 0; j < mesh->mFaces[i].mNumIndices; j++)
		{
			tempIndices.push_back(mesh->mFaces[i].mIndices[j]);
		}
	}

	// �������
	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

	// 1. ��������ͼ
	std::vector<Texture> diffuseMaps = loadMaterialTextures(
		material,
		aiTextureType_DIFFUSE,
		"texture_diffuse"
	);
	tempTextures.insert(tempTextures.end(), diffuseMaps.begin(), diffuseMaps.end());
	// ��processMesh��������ӣ�
// 2. ���淴����ͼ
	std::vector<Texture> specularMaps = loadMaterialTextures(
		material,
		aiTextureType_SPECULAR,
		"texture_specular"
	);
	tempTextures.insert(tempTextures.end(), specularMaps.begin(), specularMaps.end());

	// ���ذ��������Mesh
	return Mesh(tempVertices, tempIndices, tempTextures); // ������������

}
