/*
Assignment no 10
Problem statement:-Generate fractal patterns by using koch curve
Name of student: Yogita Tatya Misal
Rollno:27092
Batch:D
*/
#include <iostream>
using namespace std;
#include <math.h>
#include <GL/glut.h>
# define SIN 0.866

int X1=100 , Y1=200, X2=500 ,Y2=200;
int n;
void myInit()
{
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0 , 640 , 0 , 480);

}

void koch(int X1,int Y1,int X2,int Y2,int n)
{
	int x2 , y2 ,lx, ly, x[5], y[5];
	lx=(X2-X1)/3;
	ly=(Y2-Y1)/3;
	x[0]=X1;		//point 0
	y[0]=Y1;
	x[4]=X2;		//point 4
	y[4]=Y2;
	x[1]=x[0]+lx;	//point 1
	y[1]=y[0]+ly;
	x[3]=x[0]+2*lx;	//point 3
	y[3]=y[0]+2*ly;
	x2=x[3]-x[1];		// point 2 to origin
	y2=y[3]-y[1];
	x[2]=x2*(0.5)+y2*(SIN);	//rotation
	y[2]=-x2*(SIN)+y2*(0.5);
	x[2]=x[2]+x[1];	//inverse transformation
	y[2]=y[2]+y[1];
	
	if(n > 0)
	{
			koch(x[0] , y[0] , x[1] , y[1] ,n-1);    // koch curve is called 4 times because line is divided in 4 parts ...iteration is passed in 'n' ...
			
			koch(x[1] , y[1] , x[2] , y[2] ,n-1);
						
			koch(x[2] , y[2] , x[3] , y[3] ,n-1);

			koch(x[3] , y[3] , x[4] , y[4] ,n-1);

	}
	else
	{
		glBegin(GL_LINES);
	 	glVertex2d(x[0], y[0]);
		glVertex2d(x[1] , y[1] );
		glEnd();
		
		glBegin(GL_LINES);
	 	glVertex2d(x[1], y[1]);
		glVertex2d(x[2] , y[2] );
		glEnd();
		
		glBegin(GL_LINES);
	 	glVertex2d(x[2], y[2]);
		glVertex2d(x[3] , y[3] );
		glEnd();
		
		glBegin(GL_LINES);
	 	glVertex2d(x[3], y[3]);
		glVertex2d(x[4] , y[4] );
		glEnd();
	}

}

void MyDisplay()
{
	int x,y;
  	glClear(GL_COLOR_BUFFER_BIT);
  	glColor3f(0.0 ,0.0 ,0.0);
	//koch(X1,Y1,X2,Y2,8);
	koch(100,100,100,300,1);		//call line function to draw triangle
	koch(100,300,400,300,1);
	koch(400,300,400,100,1);
	koch(400,100,100,100,1);

	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("KOCH CURVE");
	myInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
} 
