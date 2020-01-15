#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double X2,Y2,X1,Y1;
int abs (int n) {
    return (n>0) ? n : n*-1;
}

void bresenham(void)
{ 
   int m_new = 2 * (Y2 - Y1); 
   int slope_error_new = m_new - (X2 - X1); 
   glClear(GL_COLOR_BUFFER_BIT);

    /* Plot the points */
    glBegin(GL_POINTS);

   for (int X = X1, Y = Y1; X <= X2; X++) 
   { 
       glVertex2d(X,Y);
  
      // Add slope to increment angle formed 
      slope_error_new += m_new; 
  
      // Slope error reached limit, time to 
      // increment y and update slope error. 
      if (slope_error_new >= 0) 
      { 
         Y++; 
         slope_error_new  -= 2 * (X2 - X1); 
      } 
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
  scanf("%lf%lf",&X1,&Y1);
  printf("\n************************************");
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%lf%lf",&X2,&Y2);
  
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
  glutDisplayFunc(bresenham);
  /* Keep displaYing untill the program is closed */
  glutMainLoop();
  return 0;
}


