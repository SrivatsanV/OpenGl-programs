#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>

using namespace std;

int n;
void square(float *a, float *b, float *c,float *d){
    glBegin(GL_QUADS); 
        glColor3f(0.0,0.0,0.0);   
        glVertex2fv(a);      
        glVertex2fv(b);      
        glVertex2fv(c);
        glVertex2fv(d);
    glEnd();
}
void recurseSquare(float *a, float *b, float *c, float *d, int n)
{
    float ab1[2], ab2[2], bc1[2], bc2[2], cd1[2], cd2[2], da1[2], da2[2];
    int i;

    if(n>0)		
    {
        for(i=0;i<2;i++){
            ab1[i] = a[i] + ((b[i] - a[i])/3.0);	
            ab2[i] = a[i] + (2*((b[i] - a[i])/3.0));
        }
        for(i=0;i<2;i++){
            bc1[i] = b[i] + ((c[i] - b[i])/3.0);	
            bc2[i] = b[i] + (2*((c[i] - b[i])/3.0));
        }
        for(i=0;i<2;i++){
            cd1[i] = c[i] + ((d[i] - c[i])/3.0);	
            cd2[i] = c[i] + (2*((d[i] - c[i])/3.0));
        }
        for(i=0;i<2;i++){
            da1[i] = d[i] + ((a[i] - d[i])/3.0);	
            da2[i] = d[i] + (2*((a[i] - d[i])/3.0));
        }

		float p1[2], p2[2], p3[2], p4[2];
        p1[0] = ab1[0]; p1[1] = da2[1];
        p2[0] = ab2[0]; p2[1] = da2[1];
        p3[0] = ab2[0]; p3[1] = da1[1];
        p4[0] = ab1[0]; p4[1] = da1[1];
        recurseSquare(a, ab1, p1 ,da2, n-1);
        recurseSquare(ab2, b, bc1 ,p2, n-1);
        recurseSquare(p3, bc2, c ,cd1, n-1);
        recurseSquare(da1, p4, cd2 ,d, n-1);
    }
    else
    {
       square(a,b,c,d);	
    }
}

void display(void){

glClear(GL_COLOR_BUFFER_BIT);

    float a[2] = {0.0, 0.0};	
    float b[2] = {200.0, 0.0};
    float c[2] = {200.0, 200.0};
    float d[2] = {0.0, 200.0};	

    recurseSquare(a, b, c, d, n);		
    glFlush();
}
void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
    gluOrtho2D(-250 , 250, -250 , 250);

}
int main(int argc, char** argv) {  
printf("Enter n\n");
scanf("%d", &n);
/* Initialise GLUT librarY */
  glutInit(&argc,argv);
  /* Set the initial displaY mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Poly Transalte");
  /* Initialize drawing colors */
  Init();
  /* Call the displaYing function */
  glutDisplayFunc(display);
  /* Keep displaYing untill the program is closed */
  glutMainLoop();
  return 0;
}
