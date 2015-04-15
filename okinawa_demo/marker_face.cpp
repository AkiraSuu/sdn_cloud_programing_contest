/* 
 * marker_face.cpp
 */

#include <stdexcept>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <FTGL/ftgl.h>
#include "marker_face.hpp"
#include "artkglut_marker.hpp"
//#include "draw_utils.hpp"

extern void draw_panel_map(float x, float y, float w, float h);
extern void draw_panel_xywh_3(float x, float y, float w, float h);
extern void draw_panel_xywh_2(float x, float y, float w, float h);
extern void draw_panel_xywh(float x, float y, float w, float h);

Marker_Face::Marker_Face()
	: ARTKGLUT_Marker("data/patt.face", 15)
{
	_font1 = new FTGLTextureFont("Aller_Bd.ttf");
	if (_font1->Error()) {
		throw runtime_error("FTGLTextureFont()");
	}
	_font1->FaceSize(8);

	_panelList = glGenLists(1);
	glNewList(_panelList, GL_COMPILE);
		draw_panel_xywh(-15, 15, 30, 30);
		glTranslatef(0, 0, 3);
	glEndList();

}

Marker_Face::~Marker_Face()
{
}

int
Marker_Face::process(bool b)
{
	return 0;
}

int
Marker_Face::draw()
{

	glPushMatrix(); // Save world coordinate system.

	glPushMatrix();
	//glTranslatef(0, -30, 0);
	
	static int interval = 0;
	if (++interval > 30) {
		glLineWidth(10);
		glColor3f(0, 0.3, 0);
		glBegin(GL_LINES);
			glVertex2d(0, 50);
			glVertex2d(0, 20);
		glEnd();

		glBegin(GL_LINES);
			glVertex2d(0, -20);
			glVertex2d(0, -50);
		glEnd();

		if (interval > 35) {
			interval = 0;
		}
	}

	glPopMatrix();

	//glTranslatef(-3, -3, 0);

	glCallList(_panelList);
	glTranslatef(-3, 0, 0);
	_font1->Render("42");


	glPopMatrix();	// Restore world coordinate system.

	return 0;
}

