/* 
Draw the following pattern using any Line drawing algorithms. 
*/ 
#include<iostream> 
using namespace std; 
#include<GL/glut.h> 
#include<math.h> 
 
double Xmin,Xmax,Ymin,Ymax,A1,A2,B1,B2; 
const int Top=8,Bottom=4,Right=2,Left=1; 
 
int calcode(double A,double B); 
void clipping(); 
 
void myInit() 
{ 
    glClearColor(1,1,1,0); 
    glColor3f(0,0,0); 
    glPointSize(2); 
    gluOrtho2D(0,640,0,480); 
} 
void Display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
     
    glColor3f(1,0,0); 
    glBegin(GL_LINE_LOOP); 
    glVertex2d(Xmin,Ymin); 
    glVertex2d(Xmin,Ymax); 
    glVertex2d(Xmax,Ymax); 
    glVertex2d(Xmax,Ymin); 
    glEnd(); 
     
    glColor3f(0,0,1); 
    glBegin(GL_LINES); 
    glVertex2d(A1,B1); 
    glVertex2d(A2,B2); 
    glEnd(); 
     
    glFlush(); 
} 
void menu(int choice) 
{ 
    switch(choice) 
    { 
        case 1: 
            cout<<"\n\tEnter the window size ::"; 
            cout<<"\n\t(Xmin,Ymin) >> "; 
            cin>>Xmin>>Ymin; 
            cout<<"\n\t(Xmin,Ymin) >> "; 
            cin>>Xmax>>Ymax; 
            break; 
        case 2: 
            cout<<"\n\tEnter the Line Co-ordinates ::"; 
            cout<<"\n\t(A1,B1) >> "; 
            cin>>A1>>B1; 
            cout<<"\n\t(A2,B2) >> "; 
            cin>>A2>>B2; 
            break; 
        case 3: 
            clipping(); 
            break; 
        case 0: 
            exit(0); 
    } 
} 
 
int main(int argc,char **argv) 
{ 
    glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowPosition(0,0); 
    glutInitWindowSize(640,480); 
     
    cout<<"\n\t\t//CLIPPING//\n";     
    glutCreateWindow("Clipping"); 
    myInit(); 
     
    glutDisplayFunc(Display); 
  
    glutCreateMenu(menu); 
        glutAddMenuEntry("Create Window",1); 
        glutAddMenuEntry("Generate Line",2); 
        glutAddMenuEntry("Clip",3); 
        glutAddMenuEntry("EXIT",0); 
        glutAttachMenu(GLUT_RIGHT_BUTTON); 
     
    glutMainLoop(); 
} 
 
//  //  //  //  //  //  //  //  //  // 
 
int calcode(double A,double B) 
{ 
    int code=0; 
    if(A<Xmin) 
        code+=Left; 
    else if(A>Xmax) 
        code+=Right; 
    if(B<Ymin) 
        code+=Bottom; 
    else if(B>Ymax) 
        code+=Top; 
    return code; 
} 
void clipping() 
{ 
    unsigned int rcode1,rcode2,temp; 
    double  m=(B2-B1)/(A2-A1),x,y; 
         
    rcode1=calcode(A1,B1); 
    rcode2=calcode(A2,B2); 
     
    while(1) 
    { 
        if( rcode1==0 && rcode2==0 ) 
            break; 
        else if( (rcode1 & rcode2)!=0 ) 
        { 
            A1=A2=B1=B2=0; 
            return; 
        } 
        else 
        { 
            if(rcode1==0) 
                temp=rcode2; 
            else  
                temp=rcode1; 
             
            if(temp & Top) 
            { 
                x=A1+(Ymax-B1)/m; 
                y=Ymax; 
            } 
            else if(temp & Bottom) 
            { 
                x=A1+(Ymin-B1)/m; 
                y=Ymin;          
            } 
            else if(temp & Right) 
            { 
                x=Xmax; 
                y=B1+(Ymax-A1)*m; 
            } 
            else if(temp & Left) 
            { 
                x=Xmin; 
                y=B1+(Ymin-A1)*m;             
            } 
             
            if(temp==rcode1) 
            { 
                A1=x; 
                B1=y; 
                rcode1=calcode(A1,B1); 
            } 
            else if(temp==rcode2) 
            { 
                A2=x; 
                B2=y; 
                rcode2=calcode(A2,B2); 
            } 
        } 
    } 
} 
 
