/*
Assignment no 6
Problem statement:-Draw a 4X4 chessboard rotated 45 ° with the horizontal axis. Use Bresenham algorithm to draw
all the lines. Use seed fill algorithm to fill black squares of the rotated chessboard
Name of student:Yogita Tatya Misal
Rollno:27092
Batch:D
*/

#include <windows.h>
#include<iostream>
using namespace std;
#include<GL/glut.h>
#include<math.h>
float readpixel[3],interiorcolor[3]={1,1,1};
int x,y,menu_id,submenu_id;
int h=600;

void myInit()
{
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,0.0,0.0);
    //glPointSize(3.0);
    gluOrtho2D(0,800,0,600);
}

int plot(int x1,int y1)
{
    glBegin(GL_POINTS);
    glVertex2f(x1,y1);
    glEnd();
    glFlush();
}

int sign(int arg)
{
    if(arg>1)
        return 1;
    if(arg<1)
        return -1;
    if(arg==0)
        return 0;
}

int Bresenham(int x1,int y1, int x2,int y2 )
{
    int x,y,dx,dy,G,temp;
    x=x1;
    y=y1;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    int s1,s2,exchange,i;

    s1=sign(x2-x1);
    s2=sign(y2-y1);

	glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();
    
    if((dy)>(dx))
    {
        temp=dy;
        dy=dx;
        dx=temp;
        exchange=1;
    }
    else
        exchange=0;
    G=(2*dy)-dx;
    i=1;
    while(i<=dx)
    {
        glBegin(GL_POINTS);
        glVertex2d(x,y);
        glEnd();
        while(G>=0)
        {
            if(exchange==1)
            x=x+s1;
            else
            y=y+s2;
            G=G-(2*dx);
        }
        if(exchange==1)
            y=y+s2;
        else
            x=x+s1;
        G=G+(2*dy);
        i++;
    }
}

void getPixelColor(int x,int y,float *color)
{
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}

void setPixelColor(float x,float y)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void floodfill(int x,int y)
{
    getPixelColor(x,y,readpixel);
    if(readpixel[0]==interiorcolor[0] && readpixel[1]==interiorcolor[1] && readpixel[2]==interiorcolor[2])
    {
        setPixelColor(x,y);
        floodfill(x,y+1);
        floodfill(x,y-1);
        floodfill(x+1,y);
        floodfill(x-1,y);
    }
}

void rotate(float x1,float y1,float x2,float y2)
{
    float angle=0.01745*45;
    float p1,p2,p3,p4;
    float s=sin(angle),c=cos(angle);
    p1=x1*c+y1*s;
    p2=-x1*s+y1*c;
    p3=x2*c+y2*s;
    p4=-x2*s+y2*c;
   
    Bresenham(p1,p2,p3,p4);
}

void mouse(int button,int state,int x,int y)
{
    int X,Y;
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        X=x;
        Y=h-y;
        floodfill(X,Y);
    }
}

void menu(int z)
{
    switch(z)
    {
    	case 1:
    	Bresenham(50,250,250,250);
		Bresenham(250,250,250,450);
		Bresenham(250,450,50,450);
		Bresenham(50,450,50,250);
		Bresenham(100,250,100,450);
		Bresenham(150,250,150,450);
		Bresenham(200,250,200,450);
		Bresenham(50,300,250,300);
		Bresenham(50,350,250,350);
		Bresenham(50,400,250,400);
		
		rotate(50,250,250,250);
		rotate(250,250,250,450);
		rotate(250,450,50,450);
		rotate(50,450,50,250);
		rotate(100,250,100,450);
		rotate(150,250,150,450);
		rotate(200,250,200,450);
		rotate(50,300,250,300);
		rotate(50,350,250,350);
		rotate(50,400,250,400);
		
		/*with for loop
		for(int i=50;i<=250;i+=50)
		{
			Bresenham(i,250,i,450);
			rotate(i,250,i,450);
		}
		
		for(int i=250;i<=450;i+=50)
		{
			Bresenham(50,i,250,i);
			rotate(50,i,250,i);
		}*/
    }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,600);
    glutCreateWindow("Chessboard");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouse);
    submenu_id = glutCreateMenu(menu);
    glutAddMenuEntry("-----Menu----",0);
    glutAddMenuEntry("1.Draw & Rotate",1);
    glutAddMenuEntry("3.Exit",2);
    menu_id = glutCreateMenu(menu);
    glutAddSubMenu("Draw",submenu_id);
    glutAddMenuEntry("Exit",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}



