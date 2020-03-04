#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
int n;
float a[2],b[2],c[2],d[2];
void square(float *a, float *b, float *c,float *d){
    glBegin(GL_QUADS); 
        glColor3f(0.0,0.0,0.0);   
        glVertex2fv(a);      
        glVertex2fv(b);      
        glVertex2fv(c);
        glVertex2fv(d);
    glEnd();
}

void divide_square(float *a,float *b,float *c,float *d,int k){
    float ab[2],cd[2],bc[2],ad[2];
    int i;
    if(k>0){
        //midpoints
       

        ab[0] = (a[0]+b[0])/3.0;
        ab[1] = (a[1]+d[1])/3.0;
        bc[0] = 2*ab[0];
        bc[1] = (a[1]+d[1])/3.0;
        cd[0] = bc[0];
        cd[1] = 2*bc[1];
        ad[0] = ab[0];
        ad[1] = 2*ab[1];
        float p1[2],p2[2],p3[2],p4[2],p5[2],p6[2],p7[2],p8[2];
        p1[0]=ab[0];
        p1[1]=0.0;

        p2[0]=0.0;
        p2[1]=ab[1];

        p3[0]=bc[0];
        p3[1]=0;

        p4[0]=b[0];
        p4[1]=bc[1];

        p5[0]=b[0];
        p5[1]=cd[1];

        p6[0]=cd[0];
        p6[1]=c[1];

        p7[0]=ad[0];
        p7[1]=c[1];

        p8[0]=0;
        p8[1]=ad[1];
        printf("%f %f\n",bc[0],bc[1]);
        //recurse
        divide_square(a,p1,ab,p2,k-1);
        divide_square(p1,p3,bc,ab,k-1);
        divide_square(p3,b,p4,bc,k-1);
        divide_square(bc,p4,p5,cd,k-1);
        divide_square(cd,p5,c,p6,k-1);
        divide_square(ad,cd,p6,p7,k-1);
        divide_square(p8,ad,p7,d,k-1);
        divide_square(p2,ab,ad,p8,k-1);
        
    }
    else
    square(a,b,c,d);
}

void display(void){
        
        glClear(GL_COLOR_BUFFER_BIT);
        // float a[] = {100,100};
        // float b[] = {200,0.0};
        // float c[] = {0.0,0.0};
        divide_square( a, b, c, d, n);

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
  printf("Enter x,y coordinates of point D: ");
  scanf("%f%f",&d[0],&d[1]);
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
