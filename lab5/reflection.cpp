#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>
#define PI 3.14159265

using namespace std;

int numpoints;
double angle;
vector<int> xpoints;
vector<int> ypoints;
vector<int> xpointsn;
vector<int> ypointsn;

void reflectY(){
    for(int i=0; i<numpoints; i++){
        xpointsn[i] = xpoints[i] * -1;
        ypointsn[i] = ypoints[i];
    }
}

void reflectX(){
    for(int i=0; i<numpoints; i++){
        ypointsn[i] = ypoints[i] * -1;
        xpointsn[i] = xpoints[i];
    }
}

void displayPolygon(){

    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0; i<numpoints; i++){
        	glVertex2i(xpoints[i],ypoints[i]);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,1,1);
    for(int i=0; i<numpoints; i++){
        	glVertex2i(xpointsn[i],ypointsn[i]);
    }
    glEnd();

    glFlush();
}

void display(void){
	
	glClear(GL_COLOR_BUFFER_BIT);

    displayPolygon();
}

int main(int argc, char** argv) {
char input;  
int x,y;
numpoints=4;
cout<<"Enter number of end points\n";
        cin>>numpoints;
        cout<<"Enter end points\n";
        for(int i=0; i<numpoints; i++){
            cin>>x>>y;
            xpoints.push_back(x);
            ypoints.push_back(y);
            xpointsn.push_back(x);
            ypointsn.push_back(y);
        }
printf("Enter reflextion axis\n");
cin>>input;
switch(input){
    case 'x': 
        reflectX();
        break;
    case 'y': 
        reflectY();
        break;
}
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100,100);
glutCreateWindow ("Reflection");
gluOrtho2D(-250,250,-250,250);
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}
