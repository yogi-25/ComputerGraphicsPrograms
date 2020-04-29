/*
Assignment no 10
Problem statement:- Perform rotation on cube about vertical axis passing thrungh its centroid
Name of student: Yogita Tatya Misal
Rollno:27092
Batch:D
*/
#include<iostream>
#include<math.h>
using namespace std;
#include<GL/glut.h>

double rotate_x=0.0;
double rotate_y=0.0;
void init();
void splKeys();
void display();

void splKeys(int key,int x,int y)
    {
       if(key==GLUT_KEY_RIGHT)
	   rotate_y-=4;
	  else if(key==GLUT_KEY_LEFT)
	    rotate_y+=4;
	    else if(key==GLUT_KEY_UP)
	    rotate_x+=4;
	    else if(key==GLUT_KEY_DOWN)
	    rotate_x-=4;
	    
	    glutPostRedisplay();
	 } 
   
   void display()
    {
           glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
           glLoadIdentity();
           glRotatef(rotate_y,0.0,1.0,0.0);
           glRotatef(rotate_x,1.0,0.0,0.0);
           
           //front side
           glBegin(GL_POLYGON);
           glColor3f(1.0,0.0,0.0);
           glVertex3f(0.5,0.5,0.5);
           glVertex3f(-0.5,0.5,0.5);
           glVertex3f(-0.5,-0.5,0.5);
           glVertex3f(0.5,-0.5,0.5);
           glEnd();
           
           //left side
           glBegin(GL_POLYGON);
           glColor3f(1.0,1.0,0.0);
           glVertex3f(-0.5,0.5,0.5);
           glVertex3f(-0.5,0.5,-0.5);
           glVertex3f(-0.5,-0.5,-0.5);
           glVertex3f(-0.5,-0.5,0.5);
           glEnd();
           
           //right side
           glBegin(GL_POLYGON);
           glColor3f(0.0,0.0,1.0);
           glVertex3f(0.5,0.5,0.5);
           glVertex3f(0.5,0.5,-0.5);
           glVertex3f(0.5,-0.5,-0.5);
           glVertex3f(0.5,-0.5,0.5);
            glEnd();
            
            //up side
           glBegin(GL_POLYGON);
           glColor3f(0.0,1.0,1.0);
           glVertex3f(-0.5,0.5,0.5);
           glVertex3f(0.5,0.5,0.5);
           glVertex3f(0.5,0.5,-0.5);
           glVertex3f(-0.5,0.5,-0.5);
           glEnd();
           
           //down side
           glBegin(GL_POLYGON);
           glColor3f(1.0,0.0,1.0);
           glVertex3f(-0.5,-0.5,0.5);
           glVertex3f(0.5,-0.5,0.5);
           glVertex3f(0.5,-0.5,-0.5);
           glVertex3f(-0.5,-0.5,-0.5);
           glEnd();
           
           //back side
           glBegin(GL_POLYGON);
           glColor3f(0.0,1.0,0.0);
           glVertex3f(-0.5,0.5,-0.5);
           glVertex3f(0.5,0.5,-0.5);
            glVertex3f(0.5,-0.5,-0.5);
           glVertex3f(-0.5,-0.5,-0.5);
           glEnd();
           
              glFlush();
   }
   
int main(int argc,char **argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
   glutInitWindowPosition(0,0);
   glutInitWindowSize(1000,1000);
   
   glutCreateWindow(" 3D - TRANSFORMATIONS");
   glEnable(GL_DEPTH_TEST);
   glutDisplayFunc(display);
   glutSpecialFunc(splKeys);
    glutMainLoop();
   
  }
