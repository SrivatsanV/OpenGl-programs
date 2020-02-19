#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
double X2,Y2,X1,Y1,X3,Y3,fx1,fx2,fy1,fy2,fx3,fy3,sf,R;
int c;
void scaling(){
    fx1 = X1 * sf;
    fx2 = X2 * sf;
    fx3 = X3 * sf;
    fy1 = Y1 * sf;
    fy2 = Y2 * sf;
    fy3 = Y3 * sf;
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
void draw(void){
    glClear(GL_COLOR_BUFFER_BIT);
    if(c==3){
    glColor3f(0.0,0.0,0.0);

    glBegin(GL_POINTS);
     glVertex2i(320,240);
    glEnd();
    circle(320,240,R);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(320,240);
    glEnd();
    circle(320,240,R*sf);
    glFlush();
    }
    else if(c==2){
        X2=300;Y2=100;X1=100;Y1=100;X3=200;Y3=300;
        scaling();
         glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(X1,Y1);
    glVertex2f(X2,Y2);
    glVertex2f(X3,Y3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(fx1,fy1);
    glVertex2f(fx2,fy2);
    glVertex2f(fx3,fy3);
    glEnd();
    glFlush();
    }
    else if(c==1){
        scaling();
        glColor3f(0.0,0.0,0.0);
        line(X1,Y1,X2,Y2);
        glEnd();
        glColor3f(1.0,0.0,0.0);
        line(fx1+100,fy1,fx2+100,fy2);
        glEnd();
    }
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
  printf("Sale : 1.Line 2.Polygon 3. Circle");
  scanf("%d",&c);
   switch(c){
       case 1:
       printf("Enter X1 Y1 :");
       scanf("%lf%lf",&X1,&Y1);
       printf("Enter X1 Y1 :");
       scanf("%lf%lf",&X2,&Y2);
       printf("Enter scaling factor : ");
       scanf("%lf",&sf);
       break;
       case 2:
       printf("Enter scaling factor : ");
       scanf("%lf",&sf);
       break;
       case 3:
       printf("Radius : ");
       scanf("%lf",&R);
       printf("Enter scaling factor : ");
       scanf("%lf",&sf);
       break;
       default :
       printf("Wrong option");
   }

  /* Initialise GLUT librarY */
  glutInit(&argc,argv);
  /* Set the initial displaY mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Scaling");
  /* Initialize drawing colors */
  Init();
  /* Call the displaYing function */
  glutDisplayFunc(draw);
  /* Keep displaYing untill the program is closed */
  glutMainLoop();
  return 0;
}