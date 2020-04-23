/* 
Draw the polygons by using the mouse. Choose colors by clicking on the designed color pane. 
Use window port to draw. (Use DDA algorithm for line drawing) 
*/ 
#include<iostream> 
using namespace std; 
#include<math.h> 
#include<GL/glut.h> 
 
double x1,yy1,x2,y2; 
void myInit(); 
void display(); 
void keyboard(unsigned char key,int x,int y); 
void menu(int choice); 
void ddaLine(double x1,double yy1,double x2,double y2); 
 
int main(int argc,char **argv) 
{ 
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition(0,0); 
	glutInitWindowSize(640,480); 
	 
	cout<<"\n--------------------Line--------------------"; 
	cout<<"\n\tEnter (x1,yy1) >> "; 
	cin>>x1>>yy1; 
	cout<<"\n\tEnter (x2,y2) >> "; 
	cin>>x2>>y2; 
	 
	glutCreateWindow("Line"); 
	myInit(); 
	 
	glutDisplayFunc(display); 
	 
	glutKeyboardFunc(keyboard); 
	 
	glutCreateMenu(menu); 
		glutAddMenuEntry("HI",1); 
		glutAddMenuEntry("Hello",2); 
		glutAddMenuEntry("EXIT",0); 
		glutAttachMenu(GLUT_RIGHT_BUTTON); 
		 
	glutMainLoop(); 
} 
 
//	FUNCTION : 
 
void myInit() 
{ 
	glClearColor(1,1,1,0); 
	glColor3f(0,0,0); 
	glPointSize(2.0); 
	glLineWidth(2.0); 
	gluOrtho2D(0,640,0,480); 
} 
void display() 
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	 
	ddaLine(x1,yy1,x1,y2); 
	ddaLine(x1,y2,x2,y2); 
	ddaLine(x2,y2,x2,yy1); 
	ddaLine(x2,yy1,x1,yy1); 
	 
	ddaLine((x1+x2)/2,yy1,x1,(yy1+y2)/2); 
	ddaLine(x1,(yy1+y2)/2,(x1+x2)/2,y2); 
	ddaLine((x1+x2)/2,y2,x2,(yy1+y2)/2); 
	ddaLine(x2,(yy1+y2)/2,(x1+x2)/2,yy1); 
	 
	ddaLine(x1+(x2-x1)/4,yy1+(y2-yy1)/4,x1+(x2-x1)/4,y2-(y2-yy1)/4); 
	ddaLine(x1+(x2-x1)/4,y2-(y2-yy1)/4,x2-(x2-x1)/4,y2-(y2-yy1)/4); 
	ddaLine(x2-(x2-x1)/4,y2-(y2-yy1)/4,x2-(x2-x1)/4,yy1+(y2-yy1)/4); 
	ddaLine(x2-(x2-x1)/4,yy1+(y2-yy1)/4,x1+(x2-x1)/4,yy1+(y2-yy1)/4); 
	 
} 
void keyboard(unsigned char key,int x,int y) 
{ 
	if(key == 101) 
	{ 
		cout<<"\n"; 
		exit(0); 
	} 
	else  
		cout<<"\n\tPress 'e' to Exit\n"; 
} 
void menu(int choice) 
{ 
	switch(choice) 
	{ 
		case 1: 
			cout<<"\n\t>>HI"; 
			break; 
		case 2: 
			cout<<"\n\t>>Hello"; 
			break; 
		case 0: 
			cout<<"\n"; 
			exit(0); 
	} 
} 
void ddaLine(double x1,double yy1,double x2,double y2) 
{ 
	double dx=(x2-x1),dy=(y2-yy1),steps,xInc,yInc; 
	 
	if(abs(dx)>=abs(dy)) 
		steps=abs(dx); 
	else  
		steps=abs(dy); 
		 
	xInc=dx/steps; 
	yInc=dy/steps; 
	 
	glBegin(GL_POINTS); 
	 
	for(int k=0 ; k<=steps ; k++,x1=x1+xInc,yy1=yy1+yInc) 
		glVertex2d(x1,yy1); 
	 
	glEnd(); 
	glFlush(); 
} 
/* 
Draw the polygons by using the mouse. Choose colors by clicking on the designed color pane. 
Use window port to draw. (Use DDA algorithm for line drawing) 
*/ 
#include<iostream> 
using namespace std; 
#include<math.h> 
#include<GL/glut.h> 
 
double x1,yy1,x2,y2; 
void myInit(); 
void display(); 
void keyboard(unsigned char key,int x,int y); 
void menu(int choice); 
void ddaLine(double x1,double yy1,double x2,double y2); 
 
int main(int argc,char **argv) 
{ 
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition(0,0); 
	glutInitWindowSize(640,480); 
	 
	cout<<"\n--------------------Line--------------------"; 
	cout<<"\n\tEnter (x1,yy1) >> "; 
	cin>>x1>>yy1; 
	cout<<"\n\tEnter (x2,y2) >> "; 
	cin>>x2>>y2; 
	 
	glutCreateWindow("Line"); 
	myInit(); 
	 
	glutDisplayFunc(display); 
	 
	glutKeyboardFunc(keyboard); 
	 
	glutCreateMenu(menu); 
		glutAddMenuEntry("HI",1); 
		glutAddMenuEntry("Hello",2); 
		glutAddMenuEntry("EXIT",0); 
		glutAttachMenu(GLUT_RIGHT_BUTTON); 
		 
	glutMainLoop(); 
} 
 
//	FUNCTION : 
 
void myInit() 
{ 
	glClearColor(1,1,1,0); 
	glColor3f(0,0,0); 
	glPointSize(2.0); 
	glLineWidth(2.0); 
	gluOrtho2D(0,640,0,480); 
} 
void display() 
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	 
	ddaLine(x1,yy1,x1,y2); 
	ddaLine(x1,y2,x2,y2); 
	ddaLine(x2,y2,x2,yy1); 
	ddaLine(x2,yy1,x1,yy1); 
	 
	ddaLine((x1+x2)/2,yy1,x1,(yy1+y2)/2); 
	ddaLine(x1,(yy1+y2)/2,(x1+x2)/2,y2); 
	ddaLine((x1+x2)/2,y2,x2,(yy1+y2)/2); 
	ddaLine(x2,(yy1+y2)/2,(x1+x2)/2,yy1); 
	 
	ddaLine(x1+(x2-x1)/4,yy1+(y2-yy1)/4,x1+(x2-x1)/4,y2-(y2-yy1)/4); 
	ddaLine(x1+(x2-x1)/4,y2-(y2-yy1)/4,x2-(x2-x1)/4,y2-(y2-yy1)/4); 
	ddaLine(x2-(x2-x1)/4,y2-(y2-yy1)/4,x2-(x2-x1)/4,yy1+(y2-yy1)/4); 
	ddaLine(x2-(x2-x1)/4,yy1+(y2-yy1)/4,x1+(x2-x1)/4,yy1+(y2-yy1)/4); 
	 
} 
void keyboard(unsigned char key,int x,int y) 
{ 
	if(key == 101) 
	{ 
		cout<<"\n"; 
		exit(0); 
	} 
	else  
		cout<<"\n\tPress 'e' to Exit\n"; 
} 
void menu(int choice) 
{ 
	switch(choice) 
	{ 
		case 1: 
			cout<<"\n\t>>HI"; 
			break; 
		case 2: 
			cout<<"\n\t>>Hello"; 
			break; 
		case 0: 
			cout<<"\n"; 
			exit(0); 
	} 
} 
void ddaLine(double x1,double yy1,double x2,double y2) 
{ 
	double dx=(x2-x1),dy=(y2-yy1),steps,xInc,yInc; 
	 
	if(abs(dx)>=abs(dy)) 
		steps=abs(dx); 
	else  
		steps=abs(dy); 
		 
	xInc=dx/steps; 
	yInc=dy/steps; 
	 
	glBegin(GL_POINTS); 
	 
	for(int k=0 ; k<=steps ; k++,x1=x1+xInc,yy1=yy1+yInc) 
		glVertex2d(x1,yy1); 
	 
	glEnd(); 
	glFlush(); 
} 
