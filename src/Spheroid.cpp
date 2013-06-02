#include "Spheroid.h"

#include "Triangle.h"
#include "Vertex.h"

double icos_r[12][3] = {   {  1.0,              0.0,              0.0            },
                           {  0.447213595500,   0.894427191000,   0.0            },
                           {  0.447213595500,   0.276393202252,   0.850650808354 },
                           {  0.447213595500,  -0.723606797748,   0.525731112119 },
                           {  0.447213595500,  -0.723606797748,  -0.525731112119 },
                           {  0.447213595500,   0.276393202252,  -0.850650808354 },
                           { -0.447213595500,  -0.894427191000,   0.0            },
                           { -0.447213595500,  -0.276393202252,   0.850650808354 },
                           { -0.447213595500,   0.723606797748,   0.525731112119 },
                           { -0.447213595500,   0.723606797748,  -0.525731112119 },
                           { -0.447213595500,  -0.276393202252, - 0.850650808354 },
                           { -1.0,              0.0,              0.0            }} ;

int icos_v [20][3] = { { 0, 1, 2 }, { 0, 2, 3 }, { 0, 3, 4 }, { 0, 4, 5 }, { 0, 5, 1 },
                       { 1, 8, 2 }, { 2, 7, 3 }, { 3, 6, 4 }, { 4, 10, 5 }, { 5, 9, 1 },
                       { 1, 9, 8 }, { 2, 8, 7 }, { 3, 7, 6 }, { 4, 6, 10 }, { 5, 10, 9 },
                       { 11, 9, 10 }, { 11, 8, 9 }, { 11, 7, 8 }, { 11, 6, 7 }, { 11, 10, 6 } } ;


Spheroid::Spheroid(double radius)
{
   resize(radius);
}

void Spheroid::resize(double size)
{
   for(int i = 0; i < 12; ++i)
   {
      for(int j = 0; j < 3; ++j)
      {
         icos_r[i][j] *= size;
      }
   }
}

void Spheroid::draw(GLfloat x, GLfloat y, GLfloat z)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x,y,z);

    int i ;

    glBegin ( GL_TRIANGLES ) ;
    for ( i = 0; i < 20; i++ )
    {
      double length = sqrt(   pow(*icos_r[icos_v[i][2]], 2)
                            + pow(*icos_r[icos_v[i][1]], 2)
                            + pow(*icos_r[icos_v[i][0]], 2));
      double normal[3] = { *icos_r[icos_v[i][2]]/length,
                           *icos_r[icos_v[i][1]]/length,
                           *icos_r[icos_v[i][0]]/length};
      /*
      normal[0] = ( icos_r[icos_v[i][1]][1] - icos_r[icos_v[i][0]][1] ) * ( icos_r[icos_v[i][2]][2] - icos_r[icos_v[i][0]][2] ) - ( icos_r[icos_v[i][1]][2] - icos_r[icos_v[i][0]][2] ) * ( icos_r[icos_v[i][2]][1] - icos_r[icos_v[i][0]][1] ) ;
      normal[1] = ( icos_r[icos_v[i][1]][2] - icos_r[icos_v[i][0]][2] ) * ( icos_r[icos_v[i][2]][0] - icos_r[icos_v[i][0]][0] ) - ( icos_r[icos_v[i][1]][0] - icos_r[icos_v[i][0]][0] ) * ( icos_r[icos_v[i][2]][2] - icos_r[icos_v[i][0]][2] ) ;
      normal[2] = ( icos_r[icos_v[i][1]][0] - icos_r[icos_v[i][0]][0] ) * ( icos_r[icos_v[i][2]][1] - icos_r[icos_v[i][0]][1] ) - ( icos_r[icos_v[i][1]][1] - icos_r[icos_v[i][0]][1] ) * ( icos_r[icos_v[i][2]][0] - icos_r[icos_v[i][0]][0] ) ;
        */
        glNormal3dv ( normal ) ;
        glVertex3dv ( icos_r[icos_v[i][2]] ) ;
        glVertex3dv ( icos_r[icos_v[i][1]] ) ;
        glVertex3dv ( icos_r[icos_v[i][0]] ) ;
    }

    glEnd () ;

}
