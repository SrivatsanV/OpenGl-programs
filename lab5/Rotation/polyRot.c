#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.14
double X2=300,Y2=100,X1=100,Y1=100,X3=200,Y3=300,fx1,fx2,fy1,fy2,fx3,fy3,theta,cx,cy;
void draw(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(X1,Y1);
    glVertex2f(X2,Y2);
    glVertex2f(X3,Y3);
    glEnd();
  
   
        // actual calculations.. 
        fx1 = cx + (int)((float)(X1 - cx) * cos(theta)) 
             - ((float)(Y1 - cy) * sin(theta)); 
        fy1 = cy + (int)((float)(X1 - cx) * sin(theta)) 
             + ((float)(Y1 - cy) * cos(theta));

        fx2 = cx + (int)((float)(X2 - cx) * cos(theta)) 
             - ((float)(Y2 - cy) * sin(theta)); 
        fy2 = cy + (int)((float)(X2 - cx) * sin(theta)) 
             + ((float)(Y2 - cy) * cos(theta));

        fx3 = cx + (int)((float)(X3 - cx) * cos(theta)) 
             - ((float)(Y3 - cy) * sin(theta)); 
        fy3 = cy + (int)((float)(X3 - cx) * sin(theta)) 
             + ((float)(Y3 - cy) * cos(theta)); 
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(fx1,fy1);
    glVertex2f(fx2,fy2);
    glVertex2f(fx3,fy3);
    glEnd();

    glFlush();
}

void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
  gluOrtho2D(0 , 640 , 0 , 480);
}
int main(int argc, char **argv)
{
  printf("Enter two end points of the line to be drawn:\n");
  printf("\n************************************");
  

  printf("\nEnter rotation point cx cy:\n");
  scanf("%lf%lf",&cx,&cy);
    printf("\nEnter rotation angle:\n");
  scanf("%lf",&theta);

  /* Initialise GLUT librarY */
  glutInit(&argc,argv);
  /* Set the initial displaY mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
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
