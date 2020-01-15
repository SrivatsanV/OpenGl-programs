#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double x2,Y2,x1,Y1;
int abs (int n) {
    return (n>0) ? n : n*-1;
}

void dda (void){
    //difference between the oridnates
    double dx = x2 - x1;
    double dY = Y2 - Y1;

    //calculating steps
    double steps = (abs(dx) > abs(dY)) ? abs(dx) : abs(dY);

    //X increment and Y increment
    double xi = dx / (float) steps;
    double Yi = dY / (float) steps;

    double x = x1, Y = Y1;
    glClear(GL_COLOR_BUFFER_BIT);

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

void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}
int main(int argc, char **argv)
{
  printf("Enter two end points of the line to be drawn:\n");
  printf("\n************************************");
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%lf%lf",&x1,&Y1);
  printf("\n************************************");
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%lf%lf",&x2,&Y2);
  
  /* Initialise GLUT librarY */
  glutInit(&argc,argv);
  /* Set the initial displaY mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("DDA_Line");
  /* Initialize drawing colors */
  Init();
  /* Call the displaYing function */
  glutDisplayFunc(dda);
  /* Keep displaYing untill the program is closed */
  glutMainLoop();
  return 0;
}


