#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.14
double X2,Y2,X1,Y1,fx1,fx2,fy1,fy2,theta,cx,cy;
#define thetaSpeed 0.05 
void rotateAroundPt() 
{ 
        theta = (theta*PI)/180;
        // actual calculations.. 
        fx1 = cx + (int)((float)(X1 - cx) * cos(theta)) 
             - ((float)(Y1 - cy) * sin(theta)); 
        fy1 = cy + (int)((float)(X1 - cx) * sin(theta)) 
             + ((float)(Y1 - cy) * cos(theta));

        fx2 = cx + (int)((float)(X2 - cx) * cos(theta)) 
             - ((float)(Y2 - cy) * sin(theta)); 
        fy2 = cy + (int)((float)(X2 - cx) * sin(theta)) 
             + ((float)(Y2 - cy) * cos(theta)); 
  
    
} 
void line(int x1,int Y1,int x2,int Y2)
{ 
       //difference between the oridnates
    double dx = x2 - x1;
    double dY = Y2 - Y1;

    //calculating steps
    double steps = (abs(dx) > abs(dY)) ? abs(dx) : abs(dY);

    //X increment and Y increment
    double xi = dx / (float) steps;
    double Yi = dY / (float) steps;

    double x = x1, Y = Y1;

    /* Plot the points */
    glBegin(GL_POINTS);
    for(int i=0; i<=steps; i++){
        glVertex2d(x,Y);
        x += xi;
        Y += Yi;
    }
    glEnd();

  glFlush(); 
}
void draw(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
   line(X1,Y1,X2,Y2);
   glEnd();
   glColor3f(1.0,0.0,0.0);
   line(fx1,fy1,fx2,fy2);
   glEnd();
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
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%lf%lf",&X1,&Y1);
  printf("\n************************************");
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%lf%lf",&X2,&Y2);

  printf("\nEnter rotation point cx cy:\n");
  scanf("%lf%lf",&cx,&cy);
    printf("\nEnter rotation angle:\n");
  scanf("%lf",&theta);
      rotateAroundPt();

  /* Initialise GLUT librarY */
  glutInit(&argc,argv);
  /* Set the initial displaY mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Rotation");
  /* Initialize drawing colors */
  Init();
  /* Call the displaYing function */
  glutDisplayFunc(draw);
  /* Keep displaYing untill the program is closed */
  glutMainLoop();
  return 0;
}
