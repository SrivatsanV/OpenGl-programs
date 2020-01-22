#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int R = 0;

void dda (double x2,double Y2,double x1,double Y1){
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

}

void points (int xc,int yc,int x,int y){
  glBegin(GL_POINTS);
  dda(xc+x,yc+y,320,240);
  dda(xc+x,yc-y,320,240);
  dda(xc-x,yc+y,320,240);
  dda(xc-x,yc-y,320,240);
  dda(xc+y,yc+x,320,240);
  dda(xc+y,yc-x,320,240);
  dda(xc-y,yc+x,320,240);
  dda(xc-y,yc-x,320,240);
  glEnd();
}

void circle(int xc,int yc,int r){
  int x = 0, y = r;
  int d = 3 - 2*r;

  while (y>=x){
    x++;

    if(d<0){
      d = d + 4*x + 6;
    }
    else{
      d = d + 4*(x-y) + 10;
      y--;
    }

    points(xc,yc,x,y);   
  }
   glFlush();
}

void drawCircle(void){
  glClear(GL_COLOR_BUFFER_BIT);
//   glBegin(GL_POINTS);
//   glVertex2i(320,240);
//   glEnd();
  circle(320,240,R);
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
  printf("Enter Radius : ");
  scanf("%d",&R);
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
  glutDisplayFunc(drawCircle);
  /* Keep displaYing untill the program is closed */
  glutMainLoop();
  return 0;
}
