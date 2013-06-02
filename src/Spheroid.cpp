#include "Spheroid.h"
#include "Vertex.h"
#include <iostream>

Spheroid::Spheroid(double radius, unsigned resolution)
: m_radius(radius)
, m_resolution(resolution)
{
   create();
}

void Spheroid::resize(double radius)
{
   m_radius = radius;
   create();
}

void Spheroid::changeResolution(unsigned resolution)
{
   m_resolution = resolution;
   create();
}

void Spheroid::create()
{
   m_triangles.clear();

   // Constants for making a basic icosahedron with radius 1.
   double X = 0.525731112119133606 * m_radius;
   double Z = 0.850650808352039932 * m_radius;

   // 12 vertices for all corners
   std::vector<Vertex> vertices;
   vertices.push_back(Vertex(-X,    0.0,  Z ));
   vertices.push_back(Vertex( X,    0.0,  Z ));
   vertices.push_back(Vertex(-X,    0.0, -Z));
   vertices.push_back(Vertex( X,    0.0, -Z));
   vertices.push_back(Vertex( 0.0,  Z,    X));
   vertices.push_back(Vertex( 0.0,  Z,   -X));
   vertices.push_back(Vertex( 0.0, -Z,    X));
   vertices.push_back(Vertex( 0.0, -Z,   -X));
   vertices.push_back(Vertex( Z,    X,    0.0));
   vertices.push_back(Vertex(-Z,    X,    0.0));
   vertices.push_back(Vertex( Z,   -X,    0.0));
   vertices.push_back(Vertex(-Z,   -X,    0.0));

   //20 Triangles (Make a bit less....MASSIVE?)
   m_triangles.push_back(Triangle(vertices[1], vertices[4], vertices[0]));
   m_triangles.push_back(Triangle(vertices[4], vertices[9], vertices[0]));
   m_triangles.push_back(Triangle(vertices[4], vertices[5], vertices[9]));
   m_triangles.push_back(Triangle(vertices[8], vertices[5], vertices[4]));
   m_triangles.push_back(Triangle(vertices[1], vertices[8], vertices[4]));

   m_triangles.push_back(Triangle(vertices[1], vertices[10], vertices[8]));
   m_triangles.push_back(Triangle(vertices[10], vertices[3], vertices[8]));
   m_triangles.push_back(Triangle(vertices[8], vertices[3], vertices[5]));
   m_triangles.push_back(Triangle(vertices[3], vertices[2], vertices[5]));
   m_triangles.push_back(Triangle(vertices[3], vertices[7], vertices[2]));

   m_triangles.push_back(Triangle(vertices[3], vertices[10], vertices[7]));
   m_triangles.push_back(Triangle(vertices[10], vertices[6], vertices[7]));
   m_triangles.push_back(Triangle(vertices[6], vertices[11], vertices[7]));
   m_triangles.push_back(Triangle(vertices[6], vertices[0], vertices[11]));
   m_triangles.push_back(Triangle(vertices[6], vertices[1], vertices[0]));

   m_triangles.push_back(Triangle(vertices[10], vertices[1], vertices[6]));
   m_triangles.push_back(Triangle(vertices[11], vertices[0], vertices[9]));
   m_triangles.push_back(Triangle(vertices[2], vertices[11], vertices[9]));
   m_triangles.push_back(Triangle(vertices[2], vertices[5], vertices[9]));
   m_triangles.push_back(Triangle(vertices[11], vertices[2], vertices[7]));

   std::vector<Triangle> tmp, result;
   // Subdivide the triangles to make it smoother
   for(auto T : m_triangles)
   {
      tmp = T.subDivide(m_resolution);
      result.insert(result.end(), tmp.begin(), tmp.end());
   }


   std::cout << "Sides: " << result.size() << std::endl;

   m_triangles.clear();
   m_triangles = result;

}

void Spheroid::draw(GLfloat x, GLfloat y, GLfloat z) const
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    // Begin drawing 20 sided icosahedron
    glBegin(GL_TRIANGLES);
    for(auto T : m_triangles)
    {
       T.draw();
    }
    glEnd();
}
