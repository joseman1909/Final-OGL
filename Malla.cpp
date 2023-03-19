#include "Malla.h"

Malla::Malla() {}

void Malla::AbrirMalla(char* malla) {
	objmodel_ptr = NULL;
	if (!objmodel_ptr)
	{
		objmodel_ptr = glmReadOBJ(malla);
		if (!objmodel_ptr)
			exit(0);

		glmUnitize(objmodel_ptr);
		glmFacetNormals(objmodel_ptr);
		glmVertexNormals(objmodel_ptr, 90.0);
	}

}

void Malla::DibujarMalla(float x, float y, float z, float tam, float rot, float rx, float ry, float rz) {
	if (objmodel_ptr) {
		glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(rot, rx, ry, rz);
		glScalef(tam, tam, tam);
		glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL);
		glPopMatrix();
	}
}

void Malla::DibujarMallaTextura(float x, float y, float z, float tam, GLuint& texid) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(tam, tam, tam);
	glBindTexture(GL_TEXTURE_2D, texid);
	glmDraw(objmodel_ptr, GLM_SMOOTH | GLM_MATERIAL | GLM_TEXTURE);
	glPopMatrix();
}