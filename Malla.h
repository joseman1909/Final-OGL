#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glApplication.h"
#include "glutWindow.h"
#include <iostream>
#include "glsl.h"
#include <time.h>
#include "glm.h"
#include <FreeImage.h> //*** Para Textura: Incluir librería

class Malla
{
private:
	GLMmodel* objmodel_ptr;
	GLMmodel* malla;

public:
	Malla();
	void AbrirMalla(char*);
	void DibujarMalla(float, float, float, float, float, float, float, float);
	void DibujarMallaTextura(float, float, float, float, GLuint&);

};

