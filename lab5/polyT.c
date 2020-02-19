#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
double tx=0,ty=0;
void poly(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(-0.3,-0.2);
    glVertex2f(0.3,-0.2);
    glVertex2f(0.5,0.3);
    glVertex2f(0.0,0.6);
    glVertex2f(-0.5,0.3);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-0.3+tx,-0.2+ty);
    glVertex2f(0.3+tx,-0.2+ty);
    glVertex2f(0.5+tx,0.3+ty);
    glVertex2f(0.0+tx,0.6+ty);
    glVertex2f(-0.5+tx,0.3+ty);

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
  printf("\nEnter translation factor tx,ty:\n");
  scanf("%lf%lf",&tx,&ty);
  /* Initialise GLUT librarY */
  glutInit(&argc,argv);
  /* Set the initial displaY mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Poly Transalte");
  /* Initialize drawing colors */
  Init();
  /* Call the displaYing function */
  glutDisplayFunc(poly);
  /* Keep displaYing untill the program is closed */
  glutMainLoop();
  return 0;
}
