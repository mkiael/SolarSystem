#ifndef SPHEROID_H_
#define SPHEROID_H_

#include <GL/gl.h>
#include <vector>

#include "Triangle.h"

// Class for drawing a icosahedron (http://en.wikipedia.org/wiki/icosahedron)
// Will be Smoother in the future, and have normals!
class Spheroid
{
public:
	Spheroid(double radius);
	void draw(GLfloat x, GLfloat y, GLfloat z) const;
	
	void resize(double radius);

private:
	 void create();

	 double m_radius;
    std::vector<Triangle> m_triangles;
};

#endif
