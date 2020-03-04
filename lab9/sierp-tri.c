#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
int n;
float a[2],b[2],c[2];
void triangle(float *a, float *b, float *c){
    glBegin(GL_TRIANGLES); 
        glColor3f(0.0,0.0,0.0);   
        glVertex2fv(a);      
        glVertex2fv(b);      
        glVertex2fv(c);
    glEnd();
}

void divide_triangle(float *a,float *b,float *c,int k){
    float ab[2],ac[2],bc[2];
    int i;
    if(k>0){
        //midpoints
        for(i=0;i<2;i++) ab[i] = (a[i]+b[i])/2.0;
        for(i=0;i<2;i++) ac[i] = (a[i]+c[i])/2.0;
        for(i=0;i<2;i++) bc[i] = (c[i]+b[i])/2.0;

        //recurse
        divide_triangle(a,ab,ac,k-1);
        divide_triangle(ab,b,bc,k-1);
        divide_triangle(ac,c,bc,k-1);
    }
    else
    triangle(a,b,c);
}

void display(void){
        
        glClear(GL_COLOR_BUFFER_BIT);
        // float a[] = {100,100};
        // float b[] = {200,0.0};
        // float c[] = {0.0,0.0};
        divide_triangle( a, b, c, n);

        glFlush();
}

void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
    gluOrtho2D(-250 , 250, -250 , 250);

}
int main(int argc, char **argv)
{
  printf("\nEnter recursion factor:\n");
  scanf("%d",&n);
  printf("Enter x,y coordinates of point A: ");
  scanf("%f%f",&a[0],&a[1]);
  printf("Enter x,y coordinates of point B: ");
  scanf("%f%f",&b[0],&b[1]);
  printf("Enter x,y coordinates of point C: ");
  scanf("%f%f",&c[0],&c[1]);
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
