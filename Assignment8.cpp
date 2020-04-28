/*
Assignment no 8
Problem statement:-Perform 2D transformation on Equilateral triangle
Name of student:Yogita Tatya Misal
Rollno:27092
Batch:D
*/
#include <iostream>
using namespace std;
#include <math.h>
#include <GL/glut.h>

float p1[3][3],p2[3][3],t[3][3],p3[3][3],p4[3][3];

void drawpoly(float p1[3][3])	//draw traingle
{
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<3;i++)	
		glVertex2f(p1[i][0],p1[i][1]);	//plot vertex
	glEnd();
}

void multiply(float p1[3][3],float t[3][3] ,float p2[3][3])
{ 									//matrix multiplication
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			int sum=0;
			for(int k=0;k<3;k++)
				sum=sum+p1[i][k]*t[k][j];
			p2[i][j]=sum;
		}
	}
}

void scale()			//to scale polygon
{
	float sx,sy;
	cout<<"Enter value of sx and sy";
	cin>>sx>>sy;
	t[0][0]=sx;
	t[0][1]=0;
	t[0][2]=0;
	t[1][0]=0;
	t[1][1]=sy;
	t[1][2]=0;
	t[2][0]=0;
	t[2][1]=0;
	t[2][2]=1;
	multiply(p1,t,p2);
	drawpoly(p2);
}
void translate(float tx,float ty,float p1[3][3] ,float p2[3][3]) //to translate polygon
{
	t[0][0]=1;
	t[0][1]=0;
	t[0][2]=0;
	t[1][0]=0;
	t[1][1]=1;
	t[1][2]=0;	
	t[2][0]=tx;
	t[2][1]=ty;
	t[2][2]=1;
	multiply(p1,t,p2);
}

void rot_clock(float p1[3][3],float p2[3][3]) 		//rotate polygon clockwise
{
	float angle,ang;
	cout<<"\n Enter angle of rotation in degree";
	cin>>ang;
	angle=((3.14*ang)/180);
	cout<<angle;
	t[0][0]=cos(angle);
	t[0][1]=-sin(angle);
	t[0][2]=0;
	t[1][0]=sin(angle);
	t[1][1]=cos(angle);
	t[1][2]=0;	
	t[2][0]=0;
	t[2][1]=0;
	t[2][2]=1;
	multiply(p1,t,p2);
}

void rot_anticlock(float p1[3][3],float p2[3][3]) //rotate polygon anticlockwise
{
	float angle,ang;
	cout<<"\n Enter angle of rotation in degree";
	cin>>ang;
	angle=((3.14*ang)/180);
	t[0][0]=cos(angle);
	t[0][1]=sin(angle);
	t[0][2]=0;
	t[1][0]=-sin(angle);
	t[1][1]=cos(angle);
	t[1][2]=0;	
	t[2][0]=0;
	t[2][1]=0;
	t[2][2]=1;
	multiply(p1,t,p2);
	drawpoly(p2); 	}
void shear_x()	//shear for x-axis on polygon
{
	float value;
	cout<<"\n Enter value for shear operation";
	cin>>value;
	t[0][0]=1;
	t[0][1]=0;
	t[0][2]=0;
	t[1][0]=value;
	t[1][1]=1;
	t[1][2]=0;	
	t[2][0]=0;
	t[2][1]=0;
	t[2][2]=1;
	multiply(p1,t,p2);
	drawpoly(p2);
}

void shear_y()	//shear for y-axis on polygon
{
	float value;
	cout<<"\n Enter value for shear operation";
	cin>>value;
	t[0][0]=1;
	t[0][1]=value;
	t[0][2]=0;
	t[1][0]=0;
	t[1][1]=1;
	t[1][2]=0;	
	t[2][0]=0;
	t[2][1]=0;
	t[2][2]=1;
	multiply(p1,t,p2);
	drawpoly(p2);
}

void rot_arbitary() //rotation about arbitary point
{
	cout<<"\nEnter x and y value of arbitary point";
	float x,y;
	cin>>x>>y;

	cout<<"\n Choose type of rotation";
	cout<<"\n1.Clockwise \n2.Anticlockwise";
	int c2;
	cin>>c2;
	translate(-x,-y,p1,p2);
	if(c2==1)
		rot_clock(p2,p3);
	if(c2==2)
	rot_anticlock(p2,p3);
	translate(x,y,p3,p4);
	drawpoly(p4);
}

void reflect_x()	//reflection about x-axis
{
	t[0][0]=1;
	t[0][1]=0;
	t[0][2]=0;
	t[1][0]=0;
	t[1][1]=-1;
	t[1][2]=0;	
	t[2][0]=0;
	t[2][1]=0;
	t[2][2]=1;
	multiply(p1,t,p2);
	drawpoly(p2);
}

void reflect_O()	//reflection about origin
{
	t[0][0]=-1;
	t[0][1]=0;
	t[0][2]=0;
	t[1][0]=0;
	t[1][1]=-1;
	t[1][2]=0;	
	t[2][0]=0;
	t[2][1]=0;
	t[2][2]=1;
	multiply(p1,t,p2);
	drawpoly(p2);
}

void reflect_y()	//reflection about y-axis
{
	t[0][0]=-1;
	t[0][1]=0;
	t[0][2]=0;
	t[1][0]=0;
	t[1][1]=1;
	t[1][2]=0;	
	t[2][0]=0;
	t[2][1]=0;
	t[2][2]=1;
	multiply(p1,t,p2);
	drawpoly(p2);
}
void Menu(int ch)	//function call for different options according to choice
{
	cout<<ch;
	switch(ch)
	{
		case 1:
		scale();
		break;
		
		case 2:
		float tx,ty;
		cout<<"Enter value of tx and ty";
		cin>>tx>>ty;
		translate(tx,ty,p1,p2);
		drawpoly(p2);
		break;
		
		case 3:
		cout<<"\n Choose type of rotation";
		cout<<"\n1.Clockwise \n2.Anticlockwise";
		int c;
		cin>>c;
		if(c==1)
		{
			rot_clock(p1,p2);
			drawpoly(p2);
		}
		if(c==2)
		{
			rot_anticlock(p1,p2);
			drawpoly(p2);
		}
		break;	
		
		case 4:
		rot_arbitary();
		break;
	
		case 5:
		cout<<"\n Choose type of Shear";
		cout<<"\n1.X-axis \n2.Y-axis";
		int c1;
		cin>>c1;
		if(c1==1)
			shear_x();
		if(c1==2)
			shear_y();
		break;	
		
		case 6:
		cout<<"\n Choose reflection about :";
		cout<<"\n1.X-axis \n2.Y-axis \n3.Origin";
		int r;
		cin>>r;
		if(r==1)
			reflect_x();
		if(r==2)
			reflect_y();
		if(r==3)
			reflect_O();

		break;
		
		case 7:
		break;
	}
}

void myInit()	//for window
{
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,0.0,0.0);
    glPointSize(2.0);
    gluOrtho2D(-320 , 320 , -240 , 240);
}

void MyDisplay()
{
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2d(-320,0);	//to divide screen
	glVertex2d(320,0);
	glVertex2d(0,-240);
	glVertex2d(0,240);
	glEnd();
	drawpoly(p1);	//function call
	glFlush();
}

int main(int argc, char **argv)
{
	p1[0][0]= 0;	//polygon co-ordinates
	p1[0][1]= 0;
	p1[0][2]= 1;
	p1[1][0]= 60;
	p1[1][1]= 0;
	p1[1][2]= 1;
	p1[2][0]= 30;
	p1[2][1]= 52;
	p1[2][2]= 1;
		
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	glutCreateWindow("Sample");
	myInit();
	glutDisplayFunc(MyDisplay);
	
	glutCreateMenu(Menu);	//Attaching menu to program on right click of mouse
	glutAddMenuEntry("Scaling",1);
	glutAddMenuEntry("Translation",2);
	glutAddMenuEntry("Rotation",3);
	glutAddMenuEntry("Rotation about any point",4);
	glutAddMenuEntry("Shear",5);
	glutAddMenuEntry("Reflection",6);
	glutAddMenuEntry("Exit",7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
