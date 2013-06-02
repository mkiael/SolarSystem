#ifndef SPHEROID_H_
#define SPHEROID_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <cmath>

// Class for drawing a spheroid (http://en.wikipedia.org/wiki/Spheroid)
// Right now only a sphere:P
class Spheroid
{
public:
	Spheroid(double size);
	void draw(GLfloat x, GLfloat y, GLfloat z);
	
	void resize(double size);

protected:
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normals;
    std::vector<GLfloat> texcoords;
    std::vector<GLushort> indices;
};

#endif
