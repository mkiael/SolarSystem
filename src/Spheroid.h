#ifndef SPHEROID_H_
#define SPHEROID_H_

#include <GL/gl.h>
#include <vector>

#include "Triangle.h"

// Class for drawing a icosahedron (http://en.wikipedia.org/wiki/icosahedron)
// Will be EVEN Smoother in the future!
class Spheroid
{
public:
	Spheroid(double radius, unsigned resolution = 0);
	void draw(GLfloat x, GLfloat y, GLfloat z) const;
	
	void resize(double radius);
	void changeResolution(unsigned resolution);

private:
	 void create();

	 double m_radius;
	 double m_resolution;

	 void subDivide(unsigned times, Triangle current);
    std::vector<Triangle> m_triangles;
};

#endif
