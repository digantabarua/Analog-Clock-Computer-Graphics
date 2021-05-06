#include <windows.h>
#include <GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;

GLfloat a = 0.0f;
GLfloat b = 0.0f;
GLfloat c = 0.0f;
void Idle()
{
    glutPostRedisplay();
}
void Clock()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.6,30,15);
    glPopMatrix();
    glPushMatrix();
    glRotatef(b,0.0,0.0,0.1);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 0.0f, 0.5f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glRotatef(c,0.0,0.0,0.1);
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(120, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f( 0.0f, 0.4f);
    glEnd();
    glPopMatrix();

    a-=10.0f;
    if(a<=-360)
        {
            if(b<=-360)
            {
                c-=10.0f;
                a=0.0f;
                b=0.0f;
            }
            else
                {
                    b-=6.0f;
                    a=0.0f;
            }

         }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutCreateWindow("Analog Clock");
    glutDisplayFunc(Clock);
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;}
