#ifndef GAME_H
#define GAME_H

#include <Debug.h>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "MyMatrix3D.h"
#include "MyVector3D.h"
#include <fstream>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	void transformation(MyMatrix3 &);
	void translation(double translation, const MyMatrix3::Axis & m_axis);
	void translateCenterPoint(double translateCenterPoint, const MyMatrix3::Axis&m_axis);
	MyVector3D m_cubePoints[8];
	MyVector3D m_cubeCenterPoint = { 0,0,0 };
	MyMatrix3 m_matrix;
	std::string loadShaderFromFile(const std::string & textFile);
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};

#endif