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
	Spheroid(float radius, unsigned int rings, unsigned int sectors);
	void draw(GLfloat x, GLfloat y, GLfloat z);
	
protected:
    std::vector<GLfloat> vertices;
    std::vector<GLfloat> normals;
    std::vector<GLfloat> texcoords;
    std::vector<GLushort> indices;
};

#endif
