#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
double tx=0,ty=0;
double X2=200,Y2=100,X1=100,Y1=100,X3=200,Y3=200,X4=100,Y4=200,fx1,fx2,fy1,fy2,fx3,fy3,fx4,fy4;
int c;
void reflectx(){
    fx1=-X1;
    fx2=-X2;
    fx3=-X3;
    fx4=-X4;
}
void reflecty(){
    fy1=-Y1;
    fy2=-Y2;
    fy3=-Y3;
    fy4=-Y4;
}
void draw(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex2i(X1,Y1);
    glVertex2i(X2,Y2);
    glVertex2i(X3,Y3);
    glVertex2i(X4,Y4);
    glEnd();
    

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(fx1,fy1);
    glVertex2i(fx2,fy2);
    glVertex2i(fx3,fy3);
    glVertex2i(fx4,fy4);

    glEnd();    
    glFlush();
}
void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
}
int main(int argc, char **argv)
{
  printf("\n1.x axis 2.y-axis:\n");
  scanf("%d",&c);
  if(c==1)reflectx();
  else reflecty();
  /* Initialise GLUT librarY */
  glutInit(&argc,argv);
  /* Set the initial displaY mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  gluOrtho2D(-250,250,-250,250);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Bresenham-Circle");
  /* Initialize drawing colors */
  Init();
  /* Call the displaYing function */
  glutDisplayFunc(draw);
  /* Keep displaYing untill the program is closed */
  glutMainLoop();
  return 0;
}
