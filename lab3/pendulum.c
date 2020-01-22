#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int R = 0;
int abs (int n) {
    return (n>0) ? n : n*-1;
}

void bresenham(int X1,int Y1,int X2,int Y2)
{ 
    //calculating range for line between start and end point
    int dx = X2 - X1;
    int dy = Y2 - Y1;

    int x = X1;
    int y = Y1;

    //this is the case when slope(m) < 1
    if(abs(dx) > abs(dy))
    {
        glBegin(GL_POINTS);
        glVertex2i(x,y);   
   //this putpixel is for very first pixel of the line
        int pk = (2 * abs(dy)) - abs(dx);

        for(int i = 0; i < abs(dx) ; i++)
        {
            x = x + 1;
            if(pk < 0)
                pk = pk + (2 * abs(dy));
            else
            {
                y = y + 1;
                pk = pk + (2 * abs(dy)) - (2 * abs(dx));
            }
            glVertex2i(x,y);
        }
        glEnd();
    }
    else
    {
        glBegin(GL_POINTS);
        //this is the case when slope is greater than or equal to 1  i.e: m>=1
        glVertex2i(x,y);    //this putpixel is for very first pixel of the line
        int pk = (2 * abs(dx)) - abs(dy);

        for(int i = 0; i < abs(dy) ; i++)
        {
            y = y + 1;
            if(pk < 0)
                pk = pk + (2 * abs(dx));
            else
            {
                x = x + 1;
                pk = pk + (2 * abs(dx)) - (2 *abs(dy));
            }

            glVertex2i(x,y);    // display pixel at coordinate (x, y)
        }
        glEnd();
    }
    glFlush();
}
 

void points (int xc,int yc,int x,int y){
  glBegin(GL_POINTS);
  glVertex2i(xc+x,yc+y);
  glVertex2i(xc+x,yc-y);
  glVertex2i(xc-x,yc+y);
  glVertex2i(xc-x,yc-y);
  glVertex2i(xc+y,yc+x);
  glVertex2i(xc+y,yc-x);
  glVertex2i(xc-y,yc+x);
  glVertex2i(xc-y,yc-x);
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
  glBegin(GL_POINTS);
  glVertex2i(320,240);
  glEnd();
  bresenham(320,R+240,320,R+240+100);
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
