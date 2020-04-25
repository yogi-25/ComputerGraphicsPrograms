/*
Assignment no 4
Problem statement:-Draw inscribed and Circumscribed circles in the triangle as shown as an example below (Use any Circle drawing and Line drawing algorithms)
Name of student:Yogita Tatya Misal
Rollno:27092
Batch:D
*/
#include <iostream>
using namespace std;
#include <math.h>
#include <GL/glut.h>
int Rad1, Rad2,xc=150,yc=130;

void Symmetry(int x, int y)			//to plot points using octant symmetry
{
	glVertex2d(xc+x,yc+y);
            glVertex2d(xc+x,yc-y);
            glVertex2d(xc-x,yc+y);
             glVertex2d(xc-x,yc-y);
            glVertex2d(xc+y,yc+x);
            glVertex2d(xc+y,yc-x);
            glVertex2d(xc-y,yc+x);
           glVertex2d(xc-y,yc-x);
}
	
void CircleMid(int Rad, int xc, int yc)		//midpoint circle algorithm
{
	int x,y,dp;
	
	x=0; y=Rad;
	dp=1-Rad;
	glVertex2d(x+xc,y+yc);			//plot the 1st point
	while(x<=y)
             {
                        if(dp<=0)
                        {
                                 x++;
                                 dp+=(2*x)+1;
                        }
                        else
                        {
                            x++;
                            y--;
                            dp+=2*(x-y)+1;
                        }
                        Symmetry(x,y);	//plot the remaining ponits using octant symmetry
             }
}
	
void LineDDA(double X1,double Y1,double X2,double Y2)    //DDA  line algorithm
{
  double dx=(X2-X1);
  double dy=(Y2-Y1);
  double steps;
  float xInc,yInc,x=X1,y=Y1;
  
  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)steps;
  yInc=dy/(float)steps;
 
  glVertex2d(x,y);						//plot 1st point of triangle
  int k;
  
  for(k=0;k<steps;k++)
  {
    x+=xInc;
    y+=yInc;
    
    glVertex2d(x,y);						//plot remaining points of triangle
  }
}

	
void myInit()
{
    glClearColor(1.0,1.0,1.0,0);					//set window colour
    glColor3f(0.0,0.0,0.0);						//set font colour
    glPointSize(2.0);							//set pixel size
    gluOrtho2D(0 , 640 , 0 , 480);					//initialize window size

}

void MyDisplay()
{
	int x,y;
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POINTS);
	CircleMid(60,xc,yc);				//call circle function to draw outer 									//circle
	CircleMid(31,xc,yc);				//call circle function to draw inner 								//circle
	LineDDA(100,100,200,100);		//call line function to draw triangle
	LineDDA(200,100,150,188);
	LineDDA(150,188,100,100);
	glEnd();
	glFlush();					//clears window
}

int main(int argc, char **argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);		//set window to to left corner
	glutInitWindowSize(640,480);
	glutCreateWindow("Triangle");		//window name
	myInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
}

OUTPUT:-

