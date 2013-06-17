#pragma once

#include <GL/gl.h>
#include <vector>
#include "Vector3.h"
#include "Triangle.h"

// Class for drawing a icosahedron (http://en.wikipedia.org/wiki/icosahedron)
class Spheroid
{
public:

	Spheroid(double radius, unsigned resolution = 0);

	void draw(GLfloat x, GLfloat y, GLfloat z) const;
	
	void resize(double radius);

	void changeResolution(unsigned resolution);

	void setAmbient(Vector3 ambient);

	void setSpecular(Vector3 specular);

	void setEmissive(Vector3 emissive);

private:

	 void create();

	 void subDivide(unsigned times, Triangle current);

	 double m_radius;

	 double m_resolution;

	 GLfloat m_ambient[4]; //should be a vector3 i guess...

	 GLfloat m_diffuse[4]; //should be a vector3 i guess...

	 GLfloat m_emissive[4]; //should be a vector3 i guess...

	 GLfloat m_specular[4]; // but it was a pain!

    std::vector<Triangle> m_triangles;

};
