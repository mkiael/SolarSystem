#include "Spheroid.h"
#include "Vertex.h"
#include <iostream>

Spheroid::Spheroid(double radius, unsigned resolution)
: m_radius(radius)
, m_resolution(resolution)
{

   setAmbient(Vector3(0.7, 0.7, 0.7));
   setEmissive(Vector3(0.0, 0.0, 0.0));
   setSpecular(Vector3(0.2, 0.2, 0.2));

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

void Spheroid::setEmissive(Vector3 emissive)
{
   m_emissive[0] = emissive.getX(); //red
   m_emissive[1] = emissive.getY(); //green
   m_emissive[2] = emissive.getZ(); //blue
   m_emissive[3] = 1.0; //alfa
}

void Spheroid::setSpecular(Vector3 emissive)
{
   m_specular[0] = emissive.getX(); //red
   m_specular[1] = emissive.getY(); //green
   m_specular[2] = emissive.getZ(); //blue
   m_specular[3] = 1.0; //alfa
}

void Spheroid::setAmbient(Vector3 ambient)
{
   m_ambient[0] = ambient.getX(); //red
   m_ambient[1] = ambient.getY(); //green
   m_ambient[2] = ambient.getZ(); //blue
   m_ambient[3] = 1.0; //alfa
}

void Spheroid::create()
{
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
   std::vector<Triangle> baseTriangles;
   baseTriangles.push_back(Triangle(vertices[1], vertices[4], vertices[0]));
   baseTriangles.push_back(Triangle(vertices[4], vertices[9], vertices[0]));
   baseTriangles.push_back(Triangle(vertices[4], vertices[5], vertices[9]));
   baseTriangles.push_back(Triangle(vertices[8], vertices[5], vertices[4]));
   baseTriangles.push_back(Triangle(vertices[1], vertices[8], vertices[4]));

   baseTriangles.push_back(Triangle(vertices[1], vertices[10], vertices[8]));
   baseTriangles.push_back(Triangle(vertices[10], vertices[3], vertices[8]));
   baseTriangles.push_back(Triangle(vertices[8], vertices[3], vertices[5]));
   baseTriangles.push_back(Triangle(vertices[3], vertices[2], vertices[5]));
   baseTriangles.push_back(Triangle(vertices[3], vertices[7], vertices[2]));

   baseTriangles.push_back(Triangle(vertices[3], vertices[10], vertices[7]));
   baseTriangles.push_back(Triangle(vertices[10], vertices[6], vertices[7]));
   baseTriangles.push_back(Triangle(vertices[6], vertices[11], vertices[7]));
   baseTriangles.push_back(Triangle(vertices[6], vertices[0], vertices[11]));
   baseTriangles.push_back(Triangle(vertices[6], vertices[1], vertices[0]));

   baseTriangles.push_back(Triangle(vertices[10], vertices[1], vertices[6]));
   baseTriangles.push_back(Triangle(vertices[11], vertices[0], vertices[9]));
   baseTriangles.push_back(Triangle(vertices[2], vertices[11], vertices[9]));
   baseTriangles.push_back(Triangle(vertices[2], vertices[5], vertices[9]));
   baseTriangles.push_back(Triangle(vertices[11], vertices[2], vertices[7]));

   m_triangles.clear();

   // Subdivide the triangles to make it smoother
   for(auto T : baseTriangles)
   {
      subDivide(m_resolution, T);
   }
}


void Spheroid::subDivide(unsigned times, Triangle current)
{
   // If recursion bottom is reached
   if (times == 0) {
      m_triangles.push_back(current);
      return;
   }

   // Create 3 new vectors between all the others
   Vector3 p1 = (current.getV1().getPos() + current.getV2().getPos()) / 2.0;
   Vector3 p2 = (current.getV2().getPos() + current.getV3().getPos()) / 2.0;
   Vector3 p3 = (current.getV3().getPos() + current.getV1().getPos()) / 2.0 ;

   //normalize them
   p1.normalize();
   p2.normalize();
   p3.normalize();

   p1 = p1 * m_radius;
   p2 = p2 * m_radius;
   p3 = p3 * m_radius;

   //Send the 4 new triangles into Recursion hell
   subDivide(times-1, Triangle( Vertex(current.getV1()), Vertex(p1), Vertex(p3)));
   subDivide(times-1, Triangle( Vertex(current.getV2()), Vertex(p2), Vertex(p1)));
   subDivide(times-1, Triangle( Vertex(current.getV3()), Vertex(p3), Vertex(p2)));
   subDivide(times-1, Triangle( Vertex(p1)  , Vertex(p2), Vertex(p3)));
}

void Spheroid::draw(GLfloat x, GLfloat y, GLfloat z) const
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, m_ambient);
    //glMaterialfv(GL.GL_FRONT, GL.GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
    glMaterialfv(GL_FRONT, GL_EMISSION, m_emissive);

    // Begin drawing 20 sided icosahedron
    glBegin(GL_TRIANGLES);

    for(auto T : m_triangles)
    {
       T.draw();
    }
    glEnd();
}
