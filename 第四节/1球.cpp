//#define GLEW_STATIC
///*
//֡����->Ŀ�����ڻ滭��Ϻ󲻳���,���������޸�
//��;:ģ��,�˾���Ч��
//
//*/
//#include<GL/glew.h>
//#include<GLFW/glfw3.h>
//#include<iostream>
//#include<random>
//#include<SDL.h>
//#include<SDL_image.h>
//#include <algorithm> // for std::find_if
//#include"Shader.h"
//#include"Camera.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include<math.h>
//#include <glm/gtc/type_ptr.hpp>
//#include"Material.h"
//#include"LightDirectional.h"
//#include"LightPoint.h"
//#include"LightSpot.h"
//#include"Mesh.h"
//#include"Model.h"
///*
//ԭ��:���Ǻ�������һ��
//���ݷ�������� �����������������  ֮��ļн�������  ���������밵
//
//
//
//*/
//#pragma region ģ�Ͷ���
////ģ������
//struct S_Objects
//{
//	//����Ӧ���ļ������Ӱ��
//	std::vector<int> PEffectLight;
//
//	//����Ӧ���ļ���ֱ�߹�Ӱ��
//	std::vector<int> DEffectLight;
//	//ģ��
//	Model model = Model("", GL_RGB);
//	//λ��
//	glm::vec3 position;
//	//����
//	glm::vec3 size;
//	//�Ƕ�
//	glm::vec3 range;
//	//float�ĽǶ�
//	float Angle;
//	//����
//	std::string name;
//};
////ģ��
//std::vector<S_Objects> Objects;
////������ѡģ��[������]
//int NowChoice = 0;
////����ģ�͵ĺ���
//void LoadModel(std::vector<std::string> Line, std::vector<GLint> Mode) {
//	S_Objects obj;
//	for (int i = 0; i < Line.size(); i++) {
//		Model newModel(Line[i], Mode[i]);
//
//		// �ҵ����һ�� '/' ��λ��
//		size_t pos = Line[i].find_last_of('/');
//
//		// ��ȡ�ļ�������
//		std::string filename = (pos == std::string::npos) ? Line[i] : Line[i].substr(pos + 1);
//
//		obj.model = newModel;
//		obj.name = filename;
//		obj.position = { 0,0,0 };
//		obj.range = { 1.0f,1.0f,1.0f };
//		obj.size = { 1.0f,1.0f,1.0f };
//		Objects.push_back(obj);
//		std::cout << "�Ѽ���:" << Line[i] << " �ǵ�" << i + 1 << "��ģ��" << std::endl;
//	}
//}
//
//
//
//#pragma endregion
//
//#pragma region �ƹⶨ��
////ֱ���
//struct S_DLight
//{
//	std::string name;
//	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
//	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
//	glm::vec3 angle = glm::vec3(glm::radians(45.0f), glm::radians(0.0f), 0);
//	LightDirectional light = LightDirectional(
//		position
//		, angle
//		, color);
//};
//std::vector<S_DLight> DLight;
////���
//struct S_PLight
//{
//	std::string name;
//	glm::vec3 position;
//	glm::vec3 color;
//	glm::vec3 range;
//	LightPoint light = LightPoint(
//		position
//		, glm::vec3(glm::radians(45.0f), glm::radians(0.0f), 0)
//		, color);
//};
//std::vector<S_PLight> PLight;
//#pragma endregion
//
//#pragma region ��������
////��ǰѡ��xyz[123]
//int nowChoicexyz = 1;
//
////�Ƿ���ʾ���
//bool hindCurse = false;
////��ǰѡ��������廹�ǵƹ� 0���� 1�ƹ�
//int nowChoiceLightObjcet = 0;
////���������ǰ����
//void printfNowContext() {
//	std::string nowfix;//�����޸ĵ�����
//	if (nowChoicexyz == 1)nowfix = "����X";
//	if (nowChoicexyz == 2)nowfix = "����Y";
//	if (nowChoicexyz == 3)nowfix = "����Z";
//	if (nowChoicexyz == 4)nowfix = "��תX";
//	if (nowChoicexyz == 5)nowfix = "��תY";
//	if (nowChoicexyz == 6)nowfix = "��תZ";
//	if (nowChoiceLightObjcet == 0) {
//		if (nowChoicexyz == 7)nowfix = "����X";
//		if (nowChoicexyz == 8)nowfix = "����Y";
//		if (nowChoicexyz == 9)nowfix = "����Z";
//	}
//	if (nowChoiceLightObjcet == 1) {
//		if (nowChoicexyz == 7)nowfix = "��ɫR";
//		if (nowChoicexyz == 8)nowfix = "��ɫG";
//		if (nowChoicexyz == 9)nowfix = "��ɫB";
//	}
//	//����ģʽ
//	if (nowChoiceLightObjcet == 0) {
//		std::cout << "ģ������:[" << Objects[NowChoice].name << "]    ���:[" << NowChoice << "]" << std::endl;
//		std::cout << "[M]ѡ�����  [N]�л�����  [B]�л��ƹ�  [��][��]�л�ģʽ  [��][��]�л���ֵ\n------------------------------------" << std::endl;
//		std::cout << "�����޸ĵ���:[" << nowfix << "]" << std::endl;
//		std::cout << "����:[ X:" << Objects[NowChoice].position.x << " Y:" << Objects[NowChoice].position.y << " Z:" << Objects[NowChoice].position.z << "]" << std::endl;
//		std::cout << "�Ƕ�:[ X:" << Objects[NowChoice].range.x << " Y:" << Objects[NowChoice].range.y << " Z:" << Objects[NowChoice].range.z << "]" << std::endl;
//		std::cout << "����:[ X:" << Objects[NowChoice].size.x << " Y:" << Objects[NowChoice].size.y << " Z:" << Objects[NowChoice].size.z << "]" << std::endl;
//	}
//	//�ƹ�ģʽ
//	if (nowChoiceLightObjcet == 1) {
//		std::cout << "�ƹ�����:[" << PLight[NowChoice].name << "]    ���:[" << NowChoice << "]" << std::endl;
//		std::cout << "[M]ѡ�����  [N]�л�����  [B]�л��ƹ�  [��][��]�л�ģʽ  [��][��]�л���ֵ\n------------------------------------" << std::endl;
//		std::cout << "�����޸ĵ���:[" << nowfix << "]" << std::endl;
//		std::cout << "����:[ X:" << PLight[NowChoice].position.x << " Y:" << PLight[NowChoice].position.y << " Z:" << PLight[NowChoice].position.z << "]" << std::endl;
//		std::cout << "�Ƕ�:[ X:" << PLight[NowChoice].range.x << " Y:" << PLight[NowChoice].range.y << " Z:" << PLight[NowChoice].range.z << "]" << std::endl;
//		std::cout << "��ɫ:[ X:" << PLight[NowChoice].color.x << " Y:" << PLight[NowChoice].color.y << " Z:" << PLight[NowChoice].color.z << "]" << std::endl;
//	}
//}
//
//#pragma endregion
//
//
//#pragma region ����
//
//
//
//
////�����
//Camera camera(glm::vec3(0, 0, 3.0f), glm::radians(15.0f), glm::radians(180.0f), glm::vec3(0, 1.0f, 0));
//
//glm::mat4 viewMat;
////�¼�
//// ���ڼ�¼������ǰһ״̬
//
//bool keyLeftPressedLastFrame = false;
//bool keyRightPressedLastFrame = false;
//bool keyNPressedLastFrame = false;
//bool keyBPressedLastFrame = false;
//bool keyESCPressedLastFrame = false;
//SDL_Event event;
//
//float vertices[] = {
//	// positions          // normals           // texture coords
//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//};
//glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//};
///* ��������ĺ���
//·��--------��ɫģʽ-----------ͨ��------
//<·��><GL_RGB || GL_RGBA><GL_TEXTURE0~15>
//
//*/
//GLuint loadTexture(const char* path, GLint Mode, GLenum Num) {
//	// ʹ��SDL_image����ͼ��
//	SDL_Surface* surface = IMG_Load(path);
//	if (!surface) {
//		std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
//		return 0;
//	}
//
//	// ����OpenGL�������
//	GLuint textureID;
//	glGenTextures(1, &textureID);
//	//����ͨ��,�Ա���
//	glActiveTexture(Num);
//	glBindTexture(GL_TEXTURE_2D, textureID);
//
//	// �����������
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// �ϴ�ͼ������
//	glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);
//
//	// ����mipmap
//	glGenerateMipmap(GL_TEXTURE_2D);
//	// �ͷ�SDL_Surface����
//	SDL_FreeSurface(surface);
//
//	return textureID;
//}
//#undef main
//float NowAngle[10] = {
//
//};
//float lastX;
//float lastY;
//
////������ƶ���ʱ��ִ�����
//void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
//	if (!hindCurse) {
//		float deltaX;
//		float deltaY;
//		deltaX = xpos - lastX;
//		deltaY = ypos - lastY;
//
//
//		lastX = xpos;
//		lastY = ypos;
//
//		camera.ProessMouseMovement(deltaX, deltaY);
//	}
//}
//
//#pragma endregion
//
//// ��main�����������
//float deltaTimew = 0.0f;
//float lastFrame = 0.0f;
//
//#pragma region �¼�
//void Run_Event(GLFWwindow *win) {
//	float moveSpeed = -10.0f;
//	float objSpeed = 0.01f;
//
//	if (NowChoice >= Objects.size())NowChoice = 0;
//	if (NowChoice < 0)NowChoice = Objects.size() - 1;
//
//	if (nowChoicexyz >= 10)nowChoicexyz = 1;
//	if (nowChoicexyz < 1)nowChoicexyz = 9;
//
//
//
//
//
//	if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS && !keyESCPressedLastFrame) {
//		if (hindCurse) {
//			hindCurse = false;
//			glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//		}
//		else
//		{
//			hindCurse = true;
//
//			glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
//		}
//	}
//	if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS) {
//		camera.SpeedX = moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS) {
//		camera.SpeedX = -moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS) {
//		camera.SpeedZ = moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS) {
//		camera.SpeedZ = -moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_SPACE) == GLFW_PRESS) {
//		camera.SpeedY = -moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
//		camera.SpeedY = moveSpeed;
//	}
//
//	//ģ������
//	if (glfwGetKey(win, GLFW_KEY_N) == GLFW_PRESS && !keyNPressedLastFrame) {//n
//		if (nowChoiceLightObjcet == 0)NowChoice++;
//		if (nowChoiceLightObjcet == 1)nowChoiceLightObjcet = 0;
//
//
//	}
//	if (glfwGetKey(win, GLFW_KEY_B) == GLFW_PRESS && !keyBPressedLastFrame) {//b
//		if (nowChoiceLightObjcet == 1)NowChoice++;
//		if (nowChoiceLightObjcet == 0)nowChoiceLightObjcet = 1;
//
//	}
//	if (glfwGetKey(win, GLFW_KEY_1) == GLFW_PRESS && !keyBPressedLastFrame) {//1
//		Objects[NowChoice].Angle += objSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_2) == GLFW_PRESS && !keyBPressedLastFrame) {//2
//		Objects[NowChoice].Angle -= objSpeed;
//
//	}
//	if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS) {//��
//		if (nowChoiceLightObjcet == 0) {
//			if (nowChoicexyz == 1)Objects[NowChoice].position.x += objSpeed;
//			if (nowChoicexyz == 2)Objects[NowChoice].position.y += objSpeed;
//			if (nowChoicexyz == 3)Objects[NowChoice].position.z += objSpeed;
//			if (nowChoicexyz == 4)Objects[NowChoice].range.x += objSpeed;
//			if (nowChoicexyz == 5)Objects[NowChoice].range.y += objSpeed;
//			if (nowChoicexyz == 6)Objects[NowChoice].range.z += objSpeed;
//			if (nowChoicexyz == 7)Objects[NowChoice].size.x += objSpeed;
//			if (nowChoicexyz == 8)Objects[NowChoice].size.y += objSpeed;
//			if (nowChoicexyz == 9)Objects[NowChoice].size.z += objSpeed;
//		}
//		if (nowChoiceLightObjcet == 1) {
//			if (nowChoicexyz == 1)PLight[NowChoice].position.x += objSpeed;
//			if (nowChoicexyz == 2)PLight[NowChoice].position.y += objSpeed;
//			if (nowChoicexyz == 3)PLight[NowChoice].position.z += objSpeed;
//			if (nowChoicexyz == 4)PLight[NowChoice].range.x += objSpeed;
//			if (nowChoicexyz == 5)PLight[NowChoice].range.y += objSpeed;
//			if (nowChoicexyz == 6)PLight[NowChoice].range.z += objSpeed;
//			if (nowChoicexyz == 7)PLight[NowChoice].color.x += objSpeed;
//			if (nowChoicexyz == 8)PLight[NowChoice].color.y += objSpeed;
//			if (nowChoicexyz == 9)PLight[NowChoice].color.z += objSpeed;
//		}
//	}
//	if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS) {//��
//		if (nowChoiceLightObjcet == 0) {
//			if (nowChoicexyz == 1)Objects[NowChoice].position.x -= objSpeed;
//			if (nowChoicexyz == 2)Objects[NowChoice].position.y -= objSpeed;
//			if (nowChoicexyz == 3)Objects[NowChoice].position.z -= objSpeed;
//			if (nowChoicexyz == 4)Objects[NowChoice].range.x -= objSpeed;
//			if (nowChoicexyz == 5)Objects[NowChoice].range.y -= objSpeed;
//			if (nowChoicexyz == 6)Objects[NowChoice].range.z -= objSpeed;
//			if (nowChoicexyz == 7)Objects[NowChoice].size.x -= objSpeed;
//			if (nowChoicexyz == 8)Objects[NowChoice].size.y -= objSpeed;
//			if (nowChoicexyz == 9)Objects[NowChoice].size.z -= objSpeed;
//		}
//		if (nowChoiceLightObjcet == 1) {
//			if (nowChoicexyz == 1)PLight[NowChoice].position.x -= objSpeed;
//			if (nowChoicexyz == 2)PLight[NowChoice].position.y -= objSpeed;
//			if (nowChoicexyz == 3)PLight[NowChoice].position.z -= objSpeed;
//			if (nowChoicexyz == 4)PLight[NowChoice].range.x -= objSpeed;
//			if (nowChoicexyz == 5)PLight[NowChoice].range.y -= objSpeed;
//			if (nowChoicexyz == 6)PLight[NowChoice].range.z -= objSpeed;
//			if (nowChoicexyz == 7)PLight[NowChoice].color.x -= objSpeed;
//			if (nowChoicexyz == 8)PLight[NowChoice].color.y -= objSpeed;
//			if (nowChoicexyz == 9)PLight[NowChoice].color.z -= objSpeed;
//		}
//	}
//	if (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS && !keyLeftPressedLastFrame) {//��
//		nowChoicexyz--;
//
//	}
//	if (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS && !keyRightPressedLastFrame) {//��
//		nowChoicexyz++;
//
//	}
//
//
//	if (glfwGetKey(win, GLFW_KEY_1) == GLFW_PRESS) {//��x
//		Objects[NowChoice].position.x += moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_2) == GLFW_PRESS) {//��x
//		Objects[NowChoice].position.x -= moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_3) == GLFW_PRESS) {//��y
//		Objects[NowChoice].position.y += moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_4) == GLFW_PRESS) {//��y
//		Objects[NowChoice].position.y -= moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_5) == GLFW_PRESS) {//��z
//		Objects[NowChoice].position.z += moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_6) == GLFW_PRESS) {//��z
//		Objects[NowChoice].position.z -= moveSpeed;
//	}
//
//
//	if (glfwGetKey(win, GLFW_KEY_ENTER) == GLFW_PRESS) {//���
//		system("cls");
//
//		std::cout << "����-----------------------------------------" << std::endl;
//		std::cout << "����:" << std::endl;
//		for (int i = 0; i < Objects.size(); i++) {
//			std::cout << "glm::vec3(" << Objects[i].position.x << "f,"
//				<< Objects[i].position.y << "f," << Objects[i].position.z << "f)," << std::endl;
//
//		}
//		std::cout << "����:" << std::endl;
//		for (int i = 0; i < Objects.size(); i++) {
//			std::cout << "glm::vec3(" << Objects[i].size.x << "f,"
//				<< Objects[i].size.y << "f," << Objects[i].size.z << "f)," << std::endl;
//
//		}
//		std::cout << "�ƹ�-----------------------------------------" << std::endl;
//		std::cout << "����:" << std::endl;
//		for (int i = 0; i < PLight.size(); i++) {
//			std::cout << "glm::vec3(" << PLight[i].position.x << "f,"
//				<< PLight[i].position.y << "f," << PLight[i].position.z << "f)," << std::endl;
//
//		}
//		std::cout << "��ɫ:" << std::endl;
//		for (int i = 0; i < PLight.size(); i++) {
//			std::cout << "glm::vec3(" << PLight[i].color.x << "f,"
//				<< PLight[i].color.y << "f," << PLight[i].color.z << "f)," << std::endl;
//
//		}
//		system("pause");
//	}
//
//
//
//	// ���°�����ǰһ״̬
//
//	keyLeftPressedLastFrame = (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS);
//	keyRightPressedLastFrame = (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS);
//	keyNPressedLastFrame = (glfwGetKey(win, GLFW_KEY_N) == GLFW_PRESS);
//	keyBPressedLastFrame = (glfwGetKey(win, GLFW_KEY_B) == GLFW_PRESS);
//	keyESCPressedLastFrame = (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS);
//	if (NowChoice >= Objects.size())NowChoice = 0;
//	if (NowChoice < 0)NowChoice = Objects.size() - 1;
//	if (nowChoicexyz >= 10)nowChoicexyz = 1;
//	if (nowChoicexyz < 1)nowChoicexyz = 9;
//
//}
//
//#pragma endregion
//
//#pragma region ֡������
//
//
////֡��-------------------
//
//// ��ʼ��֡�ʼ�����
//void initFPSCounter(Uint64& startTime, Uint64& lastTimeChecked, int& frameCount) {
//	startTime = SDL_GetPerformanceCounter();
//	lastTimeChecked = startTime;
//	frameCount = 0;
//}
//
//// ����֡�ʼ���������ȡ��ǰ��FPS
//float updateFPSCounter(Uint64& startTime, Uint64& lastTimeChecked, int& frameCount) {
//	Uint64 currentTime = SDL_GetPerformanceCounter();
//	frameCount++;
//
//	// ����Ƿ��ѹ�һ�루�����ʱ�䣩���Լ���FPS
//	if (currentTime - lastTimeChecked >= SDL_GetPerformanceFrequency()) {
//		float fps = frameCount * (SDL_GetPerformanceFrequency() / (float)(currentTime - lastTimeChecked));
//		// ���ü�����
//		lastTimeChecked = currentTime;
//		frameCount = 0;
//		return fps; // ���ؼ������FPS
//	}
//
//	// ���û�й�һ�룬�򷵻�-1��ʾ����Ҫ����FPS��ʾ
//	return -1.0f;
//}
//float deltaTime;
//float lastFPS;
//
//#pragma endregion
//
//#pragma region �������(�ƹ������)
////���ֱ��
//void Add_DLight(std::string name, glm::vec3 color, glm::vec3 angle) {
//	LightDirectional Light = LightDirectional(
//		glm::vec3(0.0f, 5.0f, 0.0f)
//		, glm::vec3(glm::radians(45.0f), glm::radians(0.0f), 0)
//		, glm::vec3(1.0f, 1.0f, 1.0f));
//
//	S_DLight tempdlight;
//	tempdlight.name == name;
//	tempdlight.color = color;
//	tempdlight.position = glm::vec3(1.0f, 1.0f, 1.0f);
//	tempdlight.angle = angle;
//	tempdlight.light = Light;
//	DLight.push_back(tempdlight);
//}
////��ӵ��
//void Add_PLight(std::string name, glm::vec3 color, glm::vec3 position) {
//	//��ӵ��
//	S_PLight tempLight;
//	tempLight.name = name;
//	tempLight.color = color;
//	tempLight.position = position;
//	PLight.push_back(tempLight);
//}
//
//#pragma endregion
//
////�ɼ��뾶
//float seeR = 1000.0f;
//
//// ֡����ƽ��
//float quadVertices[] = {
//	// λ�� (NDC)      // ��������
//	-1.0f,  1.0f, 0.0f,  0.0f, 1.0f,  // ����
//	-1.0f, -1.0f, 0.0f,  0.0f, 0.0f,  // ����
//	 1.0f,  1.0f, 0.0f,  1.0f, 1.0f,  // ����
//	 1.0f, -1.0f, 0.0f,  1.0f, 0.0f   // ����
//};
//
//
//
//GLuint texture3D;  // ���ڴ洢3D�����OpenGL����ID
//#pragma region  ��������
//
//// Perlin���������ṹ��
//
//
//struct Vec3 {
//	float x, y, z;
//	Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
//	Vec3 normalized() const {
//		float len = sqrt(x*x + y * y + z * z);  // ����ģ��
//		const float epsilon = 1e-6f;         // ��ֹ�������С��
//
//		// ����ģ���ӽ�������������������
//		if (len < epsilon) {
//			return Vec3(0, 0, 0);  // ����������
//		}
//
//		float invLen = 1.0f / len;  // Ԥ�ȼ��㵹�����Ч��
//		return Vec3(x * invLen, y * invLen, z * invLen);
//	}
//};
//
//// �̶��ݶȱ�ȷ�����ظ��ԣ�
//const std::vector<Vec3> gradients3D = {
//	Vec3(1,1,0).normalized(), Vec3(-1,1,0).normalized(),
//	Vec3(1,-1,0).normalized(), Vec3(-1,-1,0).normalized(),
//	Vec3(1,0,1).normalized(), Vec3(-1,0,1).normalized(),
//	Vec3(1,0,-1).normalized(), Vec3(-1,0,-1).normalized(),
//	Vec3(0,1,1).normalized(), Vec3(0,-1,1).normalized(),
//	Vec3(0,1,-1).normalized(), Vec3(0,-1,-1).normalized(),
//	Vec3(1,1,1).normalized(), Vec3(-1,1,1).normalized(), // ���Ӹ�����ά����
//	Vec3(1,-1,1).normalized(), Vec3(-1,-1,1).normalized(),
//	Vec3(1,1,-1).normalized(), Vec3(-1,1,-1).normalized(),
//	Vec3(1,-1,-1).normalized(), Vec3(-1,-1,-1).normalized()
//};
//
//
//// �޸ĺ�Ĺ�ϣ����������������֧�֣�
//int hash(int x, int y, int z, int wrapX, int wrapY, int wrapZ) {
//	const int p1 = 73856093;
//	const int p2 = 19349663;
//	const int p3 = 83492791;
//
//	// ȷ��������[0, wrap)��Χ��ѭ��
//	x = (x % wrapX + wrapX) % wrapX;
//	y = (y % wrapY + wrapY) % wrapY;
//	z = (z % wrapZ + wrapZ) % wrapZ;
//
//	return (x * p1) ^ (y * p2) ^ (z * p3);
//}
//// ���뺯��
//float fade(float t) {
//	return t * t*t*(t*(t * 6 - 15) + 10);
//}
//// ������Բ�ֵ����
//inline float lerp(float a, float b, float t) {
//	return a + t * (b - a);
//}
//// �������Perlin����ʵ��
//float perlinNoise(float x, float y, float z) {
//	// ���徧���ظ����ڣ�����ʹ������ߴ磩
//	const int wrapX = 64;  // ��texture���һ��
//	const int wrapY = 14;  // ����ʵ����Ҫ����
//	const int wrapZ = 64;  // ��texture���һ��
//
//	int xi = (int)floor(x);
//	int yi = (int)floor(y);
//	int zi = (int)floor(z);
//
//	float xf = x - xi;
//	float yf = y - yi;
//	float zf = z - zi;
//
//	float u = fade(xf);
//	float v = fade(yf);
//	float w = fade(zf);
//
//	// ��ȡ8��������ѭ����ϣֵ
//	int h[8];
//	h[0] = hash(xi, yi, zi, wrapX, wrapY, wrapZ) % gradients3D.size();
//	h[1] = hash(xi + 1, yi, zi, wrapX, wrapY, wrapZ) % gradients3D.size();
//	h[2] = hash(xi, yi + 1, zi, wrapX, wrapY, wrapZ) % gradients3D.size();
//	h[3] = hash(xi + 1, yi + 1, zi, wrapX, wrapY, wrapZ) % gradients3D.size();
//	h[4] = hash(xi, yi, zi + 1, wrapX, wrapY, wrapZ) % gradients3D.size();
//	h[5] = hash(xi + 1, yi, zi + 1, wrapX, wrapY, wrapZ) % gradients3D.size();
//	h[6] = hash(xi, yi + 1, zi + 1, wrapX, wrapY, wrapZ) % gradients3D.size();
//	h[7] = hash(xi + 1, yi + 1, zi + 1, wrapX, wrapY, wrapZ) % gradients3D.size();
//
//	// ����8����Ĺ���ֵ
//	float contributions[8];
//	for (int i = 0; i < 8; ++i) {
//		Vec3 grad = gradients3D[h[i]];
//		float dx = xf - (i & 1);
//		float dy = yf - ((i >> 1) & 1);
//		float dz = zf - ((i >> 2) & 1);
//		contributions[i] = grad.x*dx + grad.y*dy + grad.z*dz;
//	}
//
//	// �����Բ�ֵ
//	float x1 = lerp(contributions[0], contributions[1], u);
//	float x2 = lerp(contributions[2], contributions[3], u);
//	float y1 = lerp(x1, x2, v);
//
//	float x3 = lerp(contributions[4], contributions[5], u);
//	float x4 = lerp(contributions[6], contributions[7], u);
//	float y2 = lerp(x3, x4, v);
//
//	return lerp(y1, y2, w); // �������[-1,1]��Χ��
//}
//
//float smoothstep(float edge0, float edge1, float x) {
//	// ���� edge0 >= edge1 �ı߽����
//	if (edge0 >= edge1) {
//		return 0.0f;  // ����GLSL�淶����0.0
//	}
//
//	// �����ֵϵ�� t���Զ���������㣩
//	float t = (x - edge0) / (edge1 - edge0);
//
//	// Ӧ�����ζ���ʽ��ֵ����ǯλ��
//	if (t < 0.0f) {
//		return 0.0f;
//	}
//	else if (t > 1.0f) {
//		return 1.0f;
//	}
//	else {
//		return t * t * (3.0f - 2.0f * t);
//	}
//}
////����3D����
//void generate3DTexture() {
//	const int width = 64;  // ����ʹ��2���ݴγߴ�
//	const int height = 24;
//	const int depth = 64;
//	GLubyte* data = new GLubyte[width * height * depth * 4];
//
//	// �޸ĺ�ķ�����������
//	const int octaves = 6;             // �ʵ����ٲ�����������
//	const float persistence = 0.5f;    // ƽ��ϸ��˥��
//	const float lacunarity = 2.0f;     // ���ֺ���Ƶ������
//	const float noiseScale = 0.05f;    // ȫ����������
//
//	// �����������Ʋ����������ɵ�����
//	const float aspectRatioX = 10.0f;  // �����
//	const float aspectRatioY = 2.0f;   // �߶ȱ�
//	const float aspectRatioZ = 10.0f;  // ��ȱ�
//
//
//	for (int z = 0; z < depth; ++z) {
//		for (int y = 0; y < height; ++y) {
//			for (int x = 0; x < width; ++x) {
//				// ��һ�����߼��ռ�����
//				float logicalX = (float)x / width * aspectRatioX;
//				float logicalY = (float)y / height * aspectRatioY;
//				float logicalZ = (float)z / depth * aspectRatioZ;
//
//				// ������������
//				float total = 0.0f;
//				float frequency = 1.0f;
//				float amplitude = 1.0f;
//				float maxAmplitude = 0.0f;
//
//				for (int i = 0; i < octaves; ++i) {
//					float nx = logicalX * frequency * noiseScale;
//					float ny = logicalY * frequency * noiseScale;
//					float nz = logicalZ * frequency * noiseScale;
//
//					total += perlinNoise(nx, ny, nz) * amplitude;
//					maxAmplitude += amplitude;
//					amplitude *= persistence;
//					frequency *= lacunarity;
//				}
//				total /= maxAmplitude; // ��һ��
//
//				// �޸ĺ���ܶȼ��㣨��ǿ���ɸУ�
//				float base = smoothstep(-0.2f, 0.5f, total);       // ������״
//				float detail = smoothstep(0.1f, 0.8f, total*1.2f); // ���ϸ��
//				float density = base * 0.8f + detail * 0.2f;       // ��ϼ���
//
//				// �����ɫ���䣨ģ���ƶ���գ�
//				float shadow = smoothstep(0.3f, 0.7f, density);
//				float highlight = smoothstep(0.6f, 1.0f, density);
//				// д�����������ɫ���䣩
//				int index = (z*height*width + y * width + x) * 4;
//				data[index] = static_cast<GLubyte>((shadow*0.8 + highlight * 0.2) * 255);  // R
//				data[index + 1] = static_cast<GLubyte>((shadow*0.9 + highlight * 0.3) * 255); // G
//				data[index + 2] = static_cast<GLubyte>((shadow*1.0 + highlight * 0.5) * 255); // B
//				data[index + 3] = static_cast<GLubyte>(density * 255);                      // Alpha
//			}
//		}
//	}
//	// ��������3D����
//	glGenTextures(1, &texture3D);
//	glBindTexture(GL_TEXTURE_3D, texture3D);
//	glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, width, height, depth,
//		0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//
//	// �����������
//	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
//
//	delete[] data;
//}
//struct Vertexw {
//	GLfloat position[3];
//	GLfloat texCoord[3]; // ��Ϊ3D��������
//};
//
//#pragma endregion
//void GLAPIENTRY DebugCallback(
//	GLenum source,
//	GLenum type,
//	GLuint id,
//	GLenum severity,
//	GLsizei length,
//	const GLchar* message,
//	const void* userParam
//) {
//	if (severity == GL_DEBUG_SEVERITY_NOTIFICATION) return;
//	std::cout << "OpenGL Debug: " << message << std::endl;
//}
//
//
//
//int main(int argc, const char* argv[]) {//argv[0]ָ����·��
//	
//
//#pragma region ��ʼ��
//#pragma region �������øĵ�
//#pragma region VAO,VBO
//
//	//glfw��ʼ��
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow *win = glfwCreateWindow(800, 600, "a", NULL, NULL);
//	glfwMakeContextCurrent(win);
//	//����ָ��
//	glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	//������ƶ���ʱ��ִ�еڶ�������
//	glfwSetCursorPosCallback(win, mouse_callback);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//	glViewport(0, 0, 800, 600);
//
//	//shader�Ĺ���
//	Shader *testShader = new Shader("bin/TWO/vertexSource.vert", "bin/TWO/fragmentSource.frag");
//	//�ƹ�shader
//	Shader *ShaderLight = new Shader("bin/TWO/vertexSource.vert", "bin/TWO/fragmentSource.frag");
//	// ֡������ɫ��
//	Shader* frameShader = new Shader("planeVertex.vert", "planeFrag.frag");
//	
//	Shader *cloudShader = new Shader("fogVertex.vert", "fogFragment.frag");
//
//
//	glm::mat4 trans;
//
//	//����ϵͳ
//	glm::mat4 modelMat;
//	modelMat = glm::rotate(modelMat, glm::radians(-45.0f), glm::vec3(1.0f, 2.0f, -1.0f));
//
//	//����������
//	//�ƶ��������3,���������ƶ�-3
//
//
//	glm::mat4 projMat;
//	projMat = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, seeR);
//
//	//������Ȳ���glEnable(GL_DEPTH_TEST);
//	glEnable(GL_DEPTH_TEST);
//
//	//��ʼ�����ó�ʼ�Ƕ�
//	for (int i = 0; i < 10; i++) {
//		//NowAngle[i] = 20.0f * (i + 1);
//		NowAngle[i] = 0;
//	}
//#pragma endregion
//
//#pragma region ���ʳ�ʼ��
//	Material *myMaterial = new Material(testShader,
//		loadTexture("bin/container2.png", GL_RGBA, GL_TEXTURE0),
//		glm::vec3(1.0f, 1.0f, 1.0f),
//		loadTexture("bin/container2_specular.png", GL_RGBA, GL_TEXTURE1),
//		32.0
//	);
//
//#pragma endregion
//
//#pragma region �����ʼ��
//	//����
//	//unsigned int TexBuffera = loadTexture("bin/gold_block.png", GL_RGBA, GL_TEXTURE0);
//
//#pragma endregion
//
//#pragma region ֡�ʳ�ʼ��
////֡�����
//	Uint64 startTime = 0;
//	Uint64 lastTimeChecked = 0;
//	int frameCount = 0;
//
//	initFPSCounter(startTime, lastTimeChecked, frameCount);
//
//
//#pragma endregion 
//
//#pragma endregion
//
//
//
//#pragma region �ƹ��ʼ��
//	//����ƹ���ɫԽ��Խ�����ǹ̶�����1.0f
//	//ֱ���
//	Add_DLight("ֱ���1", glm::vec3(0.85f, 0.49f, 0.06f), glm::vec3(glm::radians(45.0f), glm::radians(45.0f), 0));
//	Add_DLight("ֱ���2", glm::vec3(0.085f, 0.049f, 0.006f), glm::vec3(glm::radians(45.0f), glm::radians(45.0f), 0));
//
//
//	//���
//	Add_PLight("���ӵĵƹ�1", glm::vec3(3.0f, 2.7f, 0.83f), glm::vec3(-1.19f, -0.57f, 1.83f));
//	Add_PLight("���ӵĵƹ�2", glm::vec3(3.0f, 2.7f, 0.83f), glm::vec3(-1.19f, -0.57f, 1.83f));
//	Add_PLight("����ĵƹ�1", glm::vec3(3.0f, 2.7f, 0.83f), glm::vec3(13.7702f, 3.77f, -1.56f));
//	//����ʼλ��
//	std::vector<glm::vec3> kkkLightposiot = {
//		 glm::vec3(-1.19f, -0.57f, 1.83f),
//		 glm::vec3(1.31f,-0.57f,1.83f),
//		 glm::vec3(13.7702f, 3.77f, -1.56f)
//	};
//
//
//
//
//
//	//����⸳ֵ
//	for (int i = 0; i < kkkLightposiot.size(); i++) {
//		PLight[i].position = kkkLightposiot[i];
//	}
//#pragma endregion
//
//
//
//#pragma region ģ�ͳ�ʼ��
//
//
//	//����ģ�����õĵط�------------------------------------------------------------
//	LoadModel(
//		{
//		"bin/4/model/ground/ground.obj",
//		"bin/4/model/grass/grass.obj",
//		"bin/4/model/cube/cube.obj",
//		"bin/4/model/glass2/glass2.obj",
//		"bin/4/model/glass1/glass1.obj",
//		},
//		{ GL_RGBA ,GL_RGBA,GL_RGBA,GL_RGBA,GL_RGBA }
//	);
//
//	//����ֱ�߹�Ӱ���
//	Objects[0].DEffectLight = { 0 };
//	Objects[1].DEffectLight = { 0 };
//	Objects[2].DEffectLight = { 0 };
//	Objects[3].DEffectLight = { 0 };
//	Objects[4].DEffectLight = { 0 };
//
//	//���õ��ӰӰ���
//	Objects[0].PEffectLight = { 0,1 };
//	Objects[1].PEffectLight = { 0,1 };
//	Objects[2].PEffectLight = { 0 ,1 };
//	Objects[3].PEffectLight = { 0 ,1 };
//	Objects[4].PEffectLight = { 0 ,1 };
//
//	//�ƹ�ģ��
//	Model lightModel("bin/model/light.obj", GL_RGBA);
//
//
//	//ģ�ͳ�ʼλ��
//	std::vector<glm::vec3> kkkpositon = {
//
//	glm::vec3(0.0f,0.0f,0.0f),
//	glm::vec3(0.0f,0.0f,0.0f),
//	glm::vec3(0.0f,0.0f,0.0f),
//	glm::vec3(0.0f,0.0f,0.0f),
//	glm::vec3(0.0f,0.0f,0.0f),
//	};
//	//ģ�ͳ�ʼ��С
//	std::vector<glm::vec3> kkksize = {
//
//	glm::vec3(1.0f,1.0f,1.0f),
//	glm::vec3(1.0f,1.0f,1.0f),
//	glm::vec3(1.0f,1.0f,1.0f),
//	glm::vec3(1.0f,1.0f,1.0f),
//	glm::vec3(1.0f,1.0f,1.0f),
//	};
//
//	//���ý���----------------------------------------------------------------
//
//
//	//��ģ�͵���λ��
//	for (int i = 0; i < Objects.size(); i++) {
//		Objects[i].position = kkkpositon[i];
//		Objects[i].size = kkksize[i];
//	}
//#pragma endregion
//
//
//#pragma endregion
//
//	generate3DTexture();
//	//������ĻVAO,VBO
//	unsigned int quadVAO, quadVBO;
//	glGenVertexArrays(1,&quadVAO);
//	glGenBuffers(1, &quadVBO);
//	glBindVertexArray(quadVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
//
//	
//
//	
//	//���������shader
//	Shader *qiuShader = new Shader("qiuVertex.vert", "qiuFrag.frag");
//
//	generate3DTexture();
//
//
//	glEnable(GL_DEBUG_OUTPUT);
//	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
//	glDebugMessageCallback(DebugCallback, nullptr);
//
//
//	//����ģ�����
//	glEnable(GL_STENCIL_TEST);
//	glfwWindowHint(GLFW_STENCIL_BITS, 8); // ����8λģ�建��
//
//	//���Ų���
//	bool resizea = false;
//
//	//����FBO
//	unsigned int framebuffer;
//	glGenFramebuffers(1, &framebuffer);
//	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//
//	//����������
//	unsigned int RTO;
//	glGenTextures(1, &RTO);
//	glBindTexture(GL_TEXTURE_2D, RTO);
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//�������ӵ�buffer
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, RTO, 0);
//
//	//����RBO
//	unsigned int rbo;
//	glGenRenderbuffers(1, &rbo);
//	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
//	//����Depth Sencil����
//	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 600);
//	//����Ⱦ���󸽼ӵ�buffer
//	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
//	
//	//���������
//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
//		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
//	}
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//
//
//	while (!glfwWindowShouldClose(win)) {
//		// 1. ����Ⱦ��֡����
//		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//		glEnable(GL_DEPTH_TEST);
//		glClearColor(0.1f, 0.116f, 0.0339f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//		// ����ʱ���
//		float currentFrame = glfwGetTime();
//		deltaTimew = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//#pragma region ֡�����
//		// ����֡�ʼ����������Ի�ȡFPS
//		float fps = updateFPSCounter(startTime, lastTimeChecked, frameCount);
//		if (fps != -1.0f) {
//
//			system("cls");
//
//			std::cout << "FPS: " << fps << std::endl;
//
//			
//			lastFPS = fps;
//		}
//
//
//
//
//#pragma endregion
//
//
//
//		Run_Event(win);
//		
//
//
//		//	glBindVertexArray(VAO);
//
//
//#pragma region �滭����
//
//		//ת�������
//		viewMat = camera.GetViewMatrix();
//		for (int i = 0; i < Objects.size(); i++) {
//
//			if (i == 3 || 4) {
//				//���û��
//				glEnable(GL_BLEND);
//				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//			}
//			else
//			{
//				//���û��
//				glDisable(GL_BLEND);
//			}
//			// ��ʼ��ģ�;���Ϊ��λ����
//			glm::mat4 modelMat2 = glm::mat4(1.0f);
//			// Ӧ������
//			modelMat2 = glm::scale(modelMat2, Objects[i].size); // ����Ϊԭ���� 1%
//			// Ӧ����ת
//		//	modelMat2 = glm::rotate(modelMat2, glm::radians(Objects[NowChoice].Angle), Objects[i].range);
//			// Ӧ��ƽ��
//			modelMat2 = glm::translate(modelMat2, Objects[i].position);
//
//			testShader->use();
//
//#pragma region uniform����
//			glUniform1i(glGetUniformLocation(testShader->ID, "DrawLine"), 0);
//			glUniformMatrix4fv(glGetUniformLocation(testShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat2));
//			glUniformMatrix4fv(glGetUniformLocation(testShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//			glUniformMatrix4fv(glGetUniformLocation(testShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
//
//
//
//
//			//�����λ��,���ھ��淴��
//			glUniform3f(glGetUniformLocation(testShader->ID, "cameraPos"), camera.Position.x, camera.Position.y, camera.Position.z);
//
//
//
//#pragma endregion
//			Objects[i].model.Draw(testShader);
//			//glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		}
//#pragma endregion
//		
//
//#pragma region �滭����
//		qiuShader->use();
//		glBindVertexArray(quadVAO);
//		glUniform3f(glGetUniformLocation(qiuShader->ID, "cameraPos"), camera.Position.x, camera.Position.y, camera.Position.z);
//
//				//����3D����
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_3D, texture3D);
//
//		glUniform1i(glGetUniformLocation(qiuShader->ID, "noise"), 0);
//		glUniform3f(glGetUniformLocation(qiuShader->ID, "Up"), camera.Up.x, camera.Up.y, camera.Up.z);
//		glUniform3f(glGetUniformLocation(qiuShader->ID, "Right"), camera.Right.x, camera.Right.y, camera.Right.z);
//		glUniform3f(glGetUniformLocation(qiuShader->ID, "Forward"), camera.Foword.x, camera.Foword.y, camera.Foword.z);
//		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//
//
//#pragma endregion
//
//
//#pragma region ֡��������
//		// 3. �л���Ĭ��֡���壨��Ļ��
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//		glDisable(GL_DEPTH_TEST);  // ������Ȳ��ԣ�ȷ��ƽ������ǰ��
//		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		//�������
//		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
//			std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
//		
//		}
//	
//		// 4. ��Ⱦ֡����ƽ�棨��ɫЧ����
//		frameShader->use();
//		glBindVertexArray(quadVAO);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, RTO);  // ��֡��������
//		glUniform1i(glGetUniformLocation(frameShader->ID, "screenTexture"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, rbo);  // �������
//		glUniform1i(glGetUniformLocation(frameShader->ID, "depthTexture"), 1);
//
//		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//#pragma endregion
//
//
//		//���߲���������
//
//		glfwPollEvents();
//		glfwSwapBuffers(win);
//		camera.UpdateCameraPos(deltaTimew);
//	}
//
//}