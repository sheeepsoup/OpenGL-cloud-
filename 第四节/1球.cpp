//#define GLEW_STATIC
///*
//帧缓冲->目的在于绘画完毕后不呈现,可以自行修改
//用途:模糊,滤镜等效果
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
//原理:还是和漫反射一样
//根据反射光线与 摄像机到反射点的向量  之间的夹角来决定  看到的明与暗
//
//
//
//*/
//#pragma region 模型定义
////模型内容
//struct S_Objects
//{
//	//所对应受哪几个点光影响
//	std::vector<int> PEffectLight;
//
//	//所对应受哪几个直线光影响
//	std::vector<int> DEffectLight;
//	//模型
//	Model model = Model("", GL_RGB);
//	//位置
//	glm::vec3 position;
//	//缩放
//	glm::vec3 size;
//	//角度
//	glm::vec3 range;
//	//float的角度
//	float Angle;
//	//名称
//	std::string name;
//};
////模型
//std::vector<S_Objects> Objects;
////现在所选模型[调试用]
//int NowChoice = 0;
////加载模型的函数
//void LoadModel(std::vector<std::string> Line, std::vector<GLint> Mode) {
//	S_Objects obj;
//	for (int i = 0; i < Line.size(); i++) {
//		Model newModel(Line[i], Mode[i]);
//
//		// 找到最后一个 '/' 的位置
//		size_t pos = Line[i].find_last_of('/');
//
//		// 提取文件名部分
//		std::string filename = (pos == std::string::npos) ? Line[i] : Line[i].substr(pos + 1);
//
//		obj.model = newModel;
//		obj.name = filename;
//		obj.position = { 0,0,0 };
//		obj.range = { 1.0f,1.0f,1.0f };
//		obj.size = { 1.0f,1.0f,1.0f };
//		Objects.push_back(obj);
//		std::cout << "已加载:" << Line[i] << " 是第" << i + 1 << "个模型" << std::endl;
//	}
//}
//
//
//
//#pragma endregion
//
//#pragma region 灯光定义
////直射光
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
////点光
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
//#pragma region 引擎内容
////当前选择xyz[123]
//int nowChoicexyz = 1;
//
////是否显示光标
//bool hindCurse = false;
////当前选择的是物体还是灯光 0物体 1灯光
//int nowChoiceLightObjcet = 0;
////用于输出当前内容
//void printfNowContext() {
//	std::string nowfix;//现在修改的内容
//	if (nowChoicexyz == 1)nowfix = "坐标X";
//	if (nowChoicexyz == 2)nowfix = "坐标Y";
//	if (nowChoicexyz == 3)nowfix = "坐标Z";
//	if (nowChoicexyz == 4)nowfix = "旋转X";
//	if (nowChoicexyz == 5)nowfix = "旋转Y";
//	if (nowChoicexyz == 6)nowfix = "旋转Z";
//	if (nowChoiceLightObjcet == 0) {
//		if (nowChoicexyz == 7)nowfix = "缩放X";
//		if (nowChoicexyz == 8)nowfix = "缩放Y";
//		if (nowChoicexyz == 9)nowfix = "缩放Z";
//	}
//	if (nowChoiceLightObjcet == 1) {
//		if (nowChoicexyz == 7)nowfix = "颜色R";
//		if (nowChoicexyz == 8)nowfix = "颜色G";
//		if (nowChoicexyz == 9)nowfix = "颜色B";
//	}
//	//物体模式
//	if (nowChoiceLightObjcet == 0) {
//		std::cout << "模型名称:[" << Objects[NowChoice].name << "]    编号:[" << NowChoice << "]" << std::endl;
//		std::cout << "[M]选择高亮  [N]切换物体  [B]切换灯光  [←][→]切换模式  [↑][↓]切换数值\n------------------------------------" << std::endl;
//		std::cout << "现在修改的是:[" << nowfix << "]" << std::endl;
//		std::cout << "坐标:[ X:" << Objects[NowChoice].position.x << " Y:" << Objects[NowChoice].position.y << " Z:" << Objects[NowChoice].position.z << "]" << std::endl;
//		std::cout << "角度:[ X:" << Objects[NowChoice].range.x << " Y:" << Objects[NowChoice].range.y << " Z:" << Objects[NowChoice].range.z << "]" << std::endl;
//		std::cout << "缩放:[ X:" << Objects[NowChoice].size.x << " Y:" << Objects[NowChoice].size.y << " Z:" << Objects[NowChoice].size.z << "]" << std::endl;
//	}
//	//灯光模式
//	if (nowChoiceLightObjcet == 1) {
//		std::cout << "灯光名称:[" << PLight[NowChoice].name << "]    编号:[" << NowChoice << "]" << std::endl;
//		std::cout << "[M]选择高亮  [N]切换物体  [B]切换灯光  [←][→]切换模式  [↑][↓]切换数值\n------------------------------------" << std::endl;
//		std::cout << "现在修改的是:[" << nowfix << "]" << std::endl;
//		std::cout << "坐标:[ X:" << PLight[NowChoice].position.x << " Y:" << PLight[NowChoice].position.y << " Z:" << PLight[NowChoice].position.z << "]" << std::endl;
//		std::cout << "角度:[ X:" << PLight[NowChoice].range.x << " Y:" << PLight[NowChoice].range.y << " Z:" << PLight[NowChoice].range.z << "]" << std::endl;
//		std::cout << "颜色:[ X:" << PLight[NowChoice].color.x << " Y:" << PLight[NowChoice].color.y << " Z:" << PLight[NowChoice].color.z << "]" << std::endl;
//	}
//}
//
//#pragma endregion
//
//
//#pragma region 定义
//
//
//
//
////摄像机
//Camera camera(glm::vec3(0, 0, 3.0f), glm::radians(15.0f), glm::radians(180.0f), glm::vec3(0, 1.0f, 0));
//
//glm::mat4 viewMat;
////事件
//// 用于记录按键的前一状态
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
///* 加载纹理的函数
//路径--------颜色模式-----------通道------
//<路径><GL_RGB || GL_RGBA><GL_TEXTURE0~15>
//
//*/
//GLuint loadTexture(const char* path, GLint Mode, GLenum Num) {
//	// 使用SDL_image加载图像
//	SDL_Surface* surface = IMG_Load(path);
//	if (!surface) {
//		std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
//		return 0;
//	}
//
//	// 生成OpenGL纹理对象
//	GLuint textureID;
//	glGenTextures(1, &textureID);
//	//设置通道,以便多个
//	glActiveTexture(Num);
//	glBindTexture(GL_TEXTURE_2D, textureID);
//
//	// 设置纹理参数
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// 上传图像数据
//	glTexImage2D(GL_TEXTURE_2D, 0, Mode, surface->w, surface->h, 0, Mode, GL_UNSIGNED_BYTE, surface->pixels);
//
//	// 生成mipmap
//	glGenerateMipmap(GL_TEXTURE_2D);
//	// 释放SDL_Surface数据
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
////当鼠标移动的时候执行这个
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
//// 在main函数顶部添加
//float deltaTimew = 0.0f;
//float lastFrame = 0.0f;
//
//#pragma region 事件
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
//	//模型内容
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
//	if (glfwGetKey(win, GLFW_KEY_UP) == GLFW_PRESS) {//上
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
//	if (glfwGetKey(win, GLFW_KEY_DOWN) == GLFW_PRESS) {//下
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
//	if (glfwGetKey(win, GLFW_KEY_LEFT) == GLFW_PRESS && !keyLeftPressedLastFrame) {//左
//		nowChoicexyz--;
//
//	}
//	if (glfwGetKey(win, GLFW_KEY_RIGHT) == GLFW_PRESS && !keyRightPressedLastFrame) {//右
//		nowChoicexyz++;
//
//	}
//
//
//	if (glfwGetKey(win, GLFW_KEY_1) == GLFW_PRESS) {//上x
//		Objects[NowChoice].position.x += moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_2) == GLFW_PRESS) {//下x
//		Objects[NowChoice].position.x -= moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_3) == GLFW_PRESS) {//上y
//		Objects[NowChoice].position.y += moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_4) == GLFW_PRESS) {//下y
//		Objects[NowChoice].position.y -= moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_5) == GLFW_PRESS) {//上z
//		Objects[NowChoice].position.z += moveSpeed;
//	}
//	if (glfwGetKey(win, GLFW_KEY_6) == GLFW_PRESS) {//下z
//		Objects[NowChoice].position.z -= moveSpeed;
//	}
//
//
//	if (glfwGetKey(win, GLFW_KEY_ENTER) == GLFW_PRESS) {//输出
//		system("cls");
//
//		std::cout << "物体-----------------------------------------" << std::endl;
//		std::cout << "坐标:" << std::endl;
//		for (int i = 0; i < Objects.size(); i++) {
//			std::cout << "glm::vec3(" << Objects[i].position.x << "f,"
//				<< Objects[i].position.y << "f," << Objects[i].position.z << "f)," << std::endl;
//
//		}
//		std::cout << "缩放:" << std::endl;
//		for (int i = 0; i < Objects.size(); i++) {
//			std::cout << "glm::vec3(" << Objects[i].size.x << "f,"
//				<< Objects[i].size.y << "f," << Objects[i].size.z << "f)," << std::endl;
//
//		}
//		std::cout << "灯光-----------------------------------------" << std::endl;
//		std::cout << "坐标:" << std::endl;
//		for (int i = 0; i < PLight.size(); i++) {
//			std::cout << "glm::vec3(" << PLight[i].position.x << "f,"
//				<< PLight[i].position.y << "f," << PLight[i].position.z << "f)," << std::endl;
//
//		}
//		std::cout << "颜色:" << std::endl;
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
//	// 更新按键的前一状态
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
//#pragma region 帧率内容
//
//
////帧率-------------------
//
//// 初始化帧率计数器
//void initFPSCounter(Uint64& startTime, Uint64& lastTimeChecked, int& frameCount) {
//	startTime = SDL_GetPerformanceCounter();
//	lastTimeChecked = startTime;
//	frameCount = 0;
//}
//
//// 更新帧率计数器并获取当前的FPS
//float updateFPSCounter(Uint64& startTime, Uint64& lastTimeChecked, int& frameCount) {
//	Uint64 currentTime = SDL_GetPerformanceCounter();
//	frameCount++;
//
//	// 检查是否已过一秒（或更长时间），以计算FPS
//	if (currentTime - lastTimeChecked >= SDL_GetPerformanceFrequency()) {
//		float fps = frameCount * (SDL_GetPerformanceFrequency() / (float)(currentTime - lastTimeChecked));
//		// 重置计数器
//		lastTimeChecked = currentTime;
//		frameCount = 0;
//		return fps; // 返回计算出的FPS
//	}
//
//	// 如果没有过一秒，则返回-1表示不需要更新FPS显示
//	return -1.0f;
//}
//float deltaTime;
//float lastFPS;
//
//#pragma endregion
//
//#pragma region 添加内容(灯光物体等)
////添加直光
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
////添加点光
//void Add_PLight(std::string name, glm::vec3 color, glm::vec3 position) {
//	//添加点光
//	S_PLight tempLight;
//	tempLight.name = name;
//	tempLight.color = color;
//	tempLight.position = position;
//	PLight.push_back(tempLight);
//}
//
//#pragma endregion
//
////可见半径
//float seeR = 1000.0f;
//
//// 帧缓冲平面
//float quadVertices[] = {
//	// 位置 (NDC)      // 纹理坐标
//	-1.0f,  1.0f, 0.0f,  0.0f, 1.0f,  // 左上
//	-1.0f, -1.0f, 0.0f,  0.0f, 0.0f,  // 左下
//	 1.0f,  1.0f, 0.0f,  1.0f, 1.0f,  // 右上
//	 1.0f, -1.0f, 0.0f,  1.0f, 0.0f   // 右下
//};
//
//
//
//GLuint texture3D;  // 用于存储3D纹理的OpenGL对象ID
//#pragma region  噪声生成
//
//// Perlin噪声辅助结构体
//
//
//struct Vec3 {
//	float x, y, z;
//	Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
//	Vec3 normalized() const {
//		float len = sqrt(x*x + y * y + z * z);  // 计算模长
//		const float epsilon = 1e-6f;         // 防止除以零的小量
//
//		// 处理模长接近零的情况（避免除零错误）
//		if (len < epsilon) {
//			return Vec3(0, 0, 0);  // 返回零向量
//		}
//
//		float invLen = 1.0f / len;  // 预先计算倒数提高效率
//		return Vec3(x * invLen, y * invLen, z * invLen);
//	}
//};
//
//// 固定梯度表（确保可重复性）
//const std::vector<Vec3> gradients3D = {
//	Vec3(1,1,0).normalized(), Vec3(-1,1,0).normalized(),
//	Vec3(1,-1,0).normalized(), Vec3(-1,-1,0).normalized(),
//	Vec3(1,0,1).normalized(), Vec3(-1,0,1).normalized(),
//	Vec3(1,0,-1).normalized(), Vec3(-1,0,-1).normalized(),
//	Vec3(0,1,1).normalized(), Vec3(0,-1,1).normalized(),
//	Vec3(0,1,-1).normalized(), Vec3(0,-1,-1).normalized(),
//	Vec3(1,1,1).normalized(), Vec3(-1,1,1).normalized(), // 增加更多三维方向
//	Vec3(1,-1,1).normalized(), Vec3(-1,-1,1).normalized(),
//	Vec3(1,1,-1).normalized(), Vec3(-1,1,-1).normalized(),
//	Vec3(1,-1,-1).normalized(), Vec3(-1,-1,-1).normalized()
//};
//
//
//// 修改后的哈希函数（增加周期性支持）
//int hash(int x, int y, int z, int wrapX, int wrapY, int wrapZ) {
//	const int p1 = 73856093;
//	const int p2 = 19349663;
//	const int p3 = 83492791;
//
//	// 确保坐标在[0, wrap)范围内循环
//	x = (x % wrapX + wrapX) % wrapX;
//	y = (y % wrapY + wrapY) % wrapY;
//	z = (z % wrapZ + wrapZ) % wrapZ;
//
//	return (x * p1) ^ (y * p2) ^ (z * p3);
//}
//// 淡入函数
//float fade(float t) {
//	return t * t*t*(t*(t * 6 - 15) + 10);
//}
//// 添加线性插值函数
//inline float lerp(float a, float b, float t) {
//	return a + t * (b - a);
//}
//// 修正后的Perlin噪声实现
//float perlinNoise(float x, float y, float z) {
//	// 定义晶格重复周期（建议使用纹理尺寸）
//	const int wrapX = 64;  // 与texture宽度一致
//	const int wrapY = 14;  // 根据实际需要调整
//	const int wrapZ = 64;  // 与texture深度一致
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
//	// 获取8个晶格点的循环哈希值
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
//	// 计算8个点的贡献值
//	float contributions[8];
//	for (int i = 0; i < 8; ++i) {
//		Vec3 grad = gradients3D[h[i]];
//		float dx = xf - (i & 1);
//		float dy = yf - ((i >> 1) & 1);
//		float dz = zf - ((i >> 2) & 1);
//		contributions[i] = grad.x*dx + grad.y*dy + grad.z*dz;
//	}
//
//	// 三线性插值
//	float x1 = lerp(contributions[0], contributions[1], u);
//	float x2 = lerp(contributions[2], contributions[3], u);
//	float y1 = lerp(x1, x2, v);
//
//	float x3 = lerp(contributions[4], contributions[5], u);
//	float x4 = lerp(contributions[6], contributions[7], u);
//	float y2 = lerp(x3, x4, v);
//
//	return lerp(y1, y2, w); // 结果已在[-1,1]范围内
//}
//
//float smoothstep(float edge0, float edge1, float x) {
//	// 处理 edge0 >= edge1 的边界情况
//	if (edge0 >= edge1) {
//		return 0.0f;  // 根据GLSL规范返回0.0
//	}
//
//	// 计算插值系数 t（自动处理除以零）
//	float t = (x - edge0) / (edge1 - edge0);
//
//	// 应用三次多项式插值（带钳位）
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
////生成3D纹理
//void generate3DTexture() {
//	const int width = 64;  // 建议使用2的幂次尺寸
//	const int height = 24;
//	const int depth = 64;
//	GLubyte* data = new GLubyte[width * height * depth * 4];
//
//	// 修改后的分形噪声参数
//	const int octaves = 6;             // 适当减少层数保持性能
//	const float persistence = 0.5f;    // 平衡细节衰减
//	const float lacunarity = 2.0f;     // 保持合理频率增长
//	const float noiseScale = 0.05f;    // 全局噪声比例
//
//	// 新增比例控制参数（可自由调整）
//	const float aspectRatioX = 10.0f;  // 长宽比
//	const float aspectRatioY = 2.0f;   // 高度比
//	const float aspectRatioZ = 10.0f;  // 深度比
//
//
//	for (int z = 0; z < depth; ++z) {
//		for (int y = 0; y < height; ++y) {
//			for (int x = 0; x < width; ++x) {
//				// 归一化到逻辑空间坐标
//				float logicalX = (float)x / width * aspectRatioX;
//				float logicalY = (float)y / height * aspectRatioY;
//				float logicalZ = (float)z / depth * aspectRatioZ;
//
//				// 分形噪声计算
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
//				total /= maxAmplitude; // 归一化
//
//				// 修改后的密度计算（增强蓬松感）
//				float base = smoothstep(-0.2f, 0.5f, total);       // 基础形状
//				float detail = smoothstep(0.1f, 0.8f, total*1.2f); // 添加细节
//				float density = base * 0.8f + detail * 0.2f;       // 混合计算
//
//				// 添加颜色渐变（模拟云朵光照）
//				float shadow = smoothstep(0.3f, 0.7f, density);
//				float highlight = smoothstep(0.6f, 1.0f, density);
//				// 写入纹理（添加颜色渐变）
//				int index = (z*height*width + y * width + x) * 4;
//				data[index] = static_cast<GLubyte>((shadow*0.8 + highlight * 0.2) * 255);  // R
//				data[index + 1] = static_cast<GLubyte>((shadow*0.9 + highlight * 0.3) * 255); // G
//				data[index + 2] = static_cast<GLubyte>((shadow*1.0 + highlight * 0.5) * 255); // B
//				data[index + 3] = static_cast<GLubyte>(density * 255);                      // Alpha
//			}
//		}
//	}
//	// 创建并绑定3D纹理
//	glGenTextures(1, &texture3D);
//	glBindTexture(GL_TEXTURE_3D, texture3D);
//	glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, width, height, depth,
//		0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//
//	// 设置纹理参数
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
//	GLfloat texCoord[3]; // 改为3D纹理坐标
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
//int main(int argc, const char* argv[]) {//argv[0]指运行路径
//	
//
//#pragma region 初始化
//#pragma region 正常不用改的
//#pragma region VAO,VBO
//
//	//glfw初始化
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	GLFWwindow *win = glfwCreateWindow(800, 600, "a", NULL, NULL);
//	glfwMakeContextCurrent(win);
//	//隐藏指针
//	glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	//当鼠标移动的时候执行第二个函数
//	glfwSetCursorPosCallback(win, mouse_callback);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//	glViewport(0, 0, 800, 600);
//
//	//shader的构建
//	Shader *testShader = new Shader("bin/TWO/vertexSource.vert", "bin/TWO/fragmentSource.frag");
//	//灯光shader
//	Shader *ShaderLight = new Shader("bin/TWO/vertexSource.vert", "bin/TWO/fragmentSource.frag");
//	// 帧缓冲着色器
//	Shader* frameShader = new Shader("planeVertex.vert", "planeFrag.frag");
//	
//	Shader *cloudShader = new Shader("fogVertex.vert", "fogFragment.frag");
//
//
//	glm::mat4 trans;
//
//	//坐标系统
//	glm::mat4 modelMat;
//	modelMat = glm::rotate(modelMat, glm::radians(-45.0f), glm::vec3(1.0f, 2.0f, -1.0f));
//
//	//摄像西部分
//	//移动摄像机到3,所有物体移动-3
//
//
//	glm::mat4 projMat;
//	projMat = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, seeR);
//
//	//启用深度测试glEnable(GL_DEPTH_TEST);
//	glEnable(GL_DEPTH_TEST);
//
//	//初始化重置初始角度
//	for (int i = 0; i < 10; i++) {
//		//NowAngle[i] = 20.0f * (i + 1);
//		NowAngle[i] = 0;
//	}
//#pragma endregion
//
//#pragma region 材质初始化
//	Material *myMaterial = new Material(testShader,
//		loadTexture("bin/container2.png", GL_RGBA, GL_TEXTURE0),
//		glm::vec3(1.0f, 1.0f, 1.0f),
//		loadTexture("bin/container2_specular.png", GL_RGBA, GL_TEXTURE1),
//		32.0
//	);
//
//#pragma endregion
//
//#pragma region 纹理初始化
//	//纹理
//	//unsigned int TexBuffera = loadTexture("bin/gold_block.png", GL_RGBA, GL_TEXTURE0);
//
//#pragma endregion
//
//#pragma region 帧率初始化
////帧率相关
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
//#pragma region 灯光初始化
//	//这里灯光颜色越高越亮而非固定在了1.0f
//	//直射光
//	Add_DLight("直射光1", glm::vec3(0.85f, 0.49f, 0.06f), glm::vec3(glm::radians(45.0f), glm::radians(45.0f), 0));
//	Add_DLight("直射光2", glm::vec3(0.085f, 0.049f, 0.006f), glm::vec3(glm::radians(45.0f), glm::radians(45.0f), 0));
//
//
//	//点光
//	Add_PLight("屋子的灯光1", glm::vec3(3.0f, 2.7f, 0.83f), glm::vec3(-1.19f, -0.57f, 1.83f));
//	Add_PLight("屋子的灯光2", glm::vec3(3.0f, 2.7f, 0.83f), glm::vec3(-1.19f, -0.57f, 1.83f));
//	Add_PLight("户外的灯光1", glm::vec3(3.0f, 2.7f, 0.83f), glm::vec3(13.7702f, 3.77f, -1.56f));
//	//点光初始位置
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
//	//给点光赋值
//	for (int i = 0; i < kkkLightposiot.size(); i++) {
//		PLight[i].position = kkkLightposiot[i];
//	}
//#pragma endregion
//
//
//
//#pragma region 模型初始化
//
//
//	//增加模型设置的地方------------------------------------------------------------
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
//	//设置直线光影响的
//	Objects[0].DEffectLight = { 0 };
//	Objects[1].DEffectLight = { 0 };
//	Objects[2].DEffectLight = { 0 };
//	Objects[3].DEffectLight = { 0 };
//	Objects[4].DEffectLight = { 0 };
//
//	//设置点光影影响的
//	Objects[0].PEffectLight = { 0,1 };
//	Objects[1].PEffectLight = { 0,1 };
//	Objects[2].PEffectLight = { 0 ,1 };
//	Objects[3].PEffectLight = { 0 ,1 };
//	Objects[4].PEffectLight = { 0 ,1 };
//
//	//灯光模型
//	Model lightModel("bin/model/light.obj", GL_RGBA);
//
//
//	//模型初始位置
//	std::vector<glm::vec3> kkkpositon = {
//
//	glm::vec3(0.0f,0.0f,0.0f),
//	glm::vec3(0.0f,0.0f,0.0f),
//	glm::vec3(0.0f,0.0f,0.0f),
//	glm::vec3(0.0f,0.0f,0.0f),
//	glm::vec3(0.0f,0.0f,0.0f),
//	};
//	//模型初始大小
//	std::vector<glm::vec3> kkksize = {
//
//	glm::vec3(1.0f,1.0f,1.0f),
//	glm::vec3(1.0f,1.0f,1.0f),
//	glm::vec3(1.0f,1.0f,1.0f),
//	glm::vec3(1.0f,1.0f,1.0f),
//	glm::vec3(1.0f,1.0f,1.0f),
//	};
//
//	//设置结束----------------------------------------------------------------
//
//
//	//给模型调整位置
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
//	//创建屏幕VAO,VBO
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
//	//创建球体的shader
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
//	//启用模板测试
//	glEnable(GL_STENCIL_TEST);
//	glfwWindowHint(GLFW_STENCIL_BITS, 8); // 启用8位模板缓冲
//
//	//缩放布尔
//	bool resizea = false;
//
//	//创建FBO
//	unsigned int framebuffer;
//	glGenFramebuffers(1, &framebuffer);
//	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//
//	//创建纹理附件
//	unsigned int RTO;
//	glGenTextures(1, &RTO);
//	glBindTexture(GL_TEXTURE_2D, RTO);
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//把纹理附加到buffer
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, RTO, 0);
//
//	//创建RBO
//	unsigned int rbo;
//	glGenRenderbuffers(1, &rbo);
//	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
//	//创建Depth Sencil对象
//	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 600);
//	//把渲染对象附加到buffer
//	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);
//	
//	//检测完整性
//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
//		std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
//	}
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//
//
//	while (!glfwWindowShouldClose(win)) {
//		// 1. 先渲染到帧缓冲
//		glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
//		glEnable(GL_DEPTH_TEST);
//		glClearColor(0.1f, 0.116f, 0.0339f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//		// 计算时间差
//		float currentFrame = glfwGetTime();
//		deltaTimew = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//#pragma region 帧率输出
//		// 更新帧率计数器并尝试获取FPS
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
//#pragma region 绘画物体
//
//		//转动后更新
//		viewMat = camera.GetViewMatrix();
//		for (int i = 0; i < Objects.size(); i++) {
//
//			if (i == 3 || 4) {
//				//启用混合
//				glEnable(GL_BLEND);
//				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//			}
//			else
//			{
//				//禁用混合
//				glDisable(GL_BLEND);
//			}
//			// 初始化模型矩阵为单位矩阵
//			glm::mat4 modelMat2 = glm::mat4(1.0f);
//			// 应用缩放
//			modelMat2 = glm::scale(modelMat2, Objects[i].size); // 缩放为原来的 1%
//			// 应用旋转
//		//	modelMat2 = glm::rotate(modelMat2, glm::radians(Objects[NowChoice].Angle), Objects[i].range);
//			// 应用平移
//			modelMat2 = glm::translate(modelMat2, Objects[i].position);
//
//			testShader->use();
//
//#pragma region uniform内容
//			glUniform1i(glGetUniformLocation(testShader->ID, "DrawLine"), 0);
//			glUniformMatrix4fv(glGetUniformLocation(testShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat2));
//			glUniformMatrix4fv(glGetUniformLocation(testShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
//			glUniformMatrix4fv(glGetUniformLocation(testShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
//
//
//
//
//			//摄像机位置,用于镜面反射
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
//#pragma region 绘画球体
//		qiuShader->use();
//		glBindVertexArray(quadVAO);
//		glUniform3f(glGetUniformLocation(qiuShader->ID, "cameraPos"), camera.Position.x, camera.Position.y, camera.Position.z);
//
//				//传递3D纹理
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
//#pragma region 帧缓冲内容
//		// 3. 切换回默认帧缓冲（屏幕）
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//		glDisable(GL_DEPTH_TEST);  // 禁用深度测试，确保平面在最前面
//		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		//完整检查
//		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
//			std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
//		
//		}
//	
//		// 4. 渲染帧缓冲平面（蓝色效果）
//		frameShader->use();
//		glBindVertexArray(quadVAO);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, RTO);  // 绑定帧缓冲纹理
//		glUniform1i(glGetUniformLocation(frameShader->ID, "screenTexture"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, rbo);  // 深度纹理
//		glUniform1i(glGetUniformLocation(frameShader->ID, "depthTexture"), 1);
//
//		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//#pragma endregion
//
//
//		//光线步进测试器
//
//		glfwPollEvents();
//		glfwSwapBuffers(win);
//		camera.UpdateCameraPos(deltaTimew);
//	}
//
//}