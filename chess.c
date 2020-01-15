#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void Init()
{
    glClearColor(0.0,1.0,1.0,0);     // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer (background)
    glColor3f(0.0,0.0,1.0);
 glViewport(0 , 0 , 640 , 480);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0 , 640 , 0 , 480);
}
int abs (int n) {
    return (n>0) ? n : n*-1;
}

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

  glFlush(); 
}

void ChessBoard()
{
            Init();
            int i,  k = 0,j;
            float cbvalue;  
            cbvalue = 1.0;

            int row=0;
            for(i=0; i<8; i++)
            {
                int col = 0; row +=50;
                for(j=0; j<8; j++)
                {
                    glColor3f(cbvalue, cbvalue,cbvalue);
                    for(int r=0; r<50; r++)
                        dda(50 + col,row+r,100 + col,row+r);
                    col = col+50;
                    if (j<7)
                        if (cbvalue == 1.0)
                                cbvalue =0.0;
                        else
                                cbvalue =1.0;
                }
             }
            glFlush();
}


int main(int argc, char **argv)
{
  
  /* Initialise GLUT librarY */
  glutInit(&argc,argv);
  /* Set the initial displaY mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Chess");
  /* Initialize drawing colors */
  Init();
  /* Call the displaYing function */
  glutDisplayFunc(ChessBoard);
  /* Keep displaYing untill the program is closed */
  glutMainLoop();
  return 0;
}


