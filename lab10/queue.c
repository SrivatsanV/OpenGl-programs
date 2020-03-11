#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <string.h>
#define EMPTY 100
#define FULL 101
#define ENT 102
#define DEL 103
int status = EMPTY;
char stack[7][3],n=7,top=0,rear=0,x,i;
char val[7][3] = {"10","20","30","40","50","60","70"};
int val_int[] = {10,20,30,40,50,60,70};
float yfarr = 0.0;
float yrarr = 0.0;

void textPt(float x, float y, char* text)
{
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(x, y, 0);
    glScalef(1/10.5, 1/10.5, 1/10.5);
    for( char* p = text; *p; p++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    }
    glPopMatrix();
}
void drawText(){
    char w[40];
    if(status==EMPTY)
    strcpy(w,"Queue Empty");
    else if(status==FULL)
        strcpy(w,"Queue FUll");
    else
        strcpy(w,"Queue operating");

    textPt(-100,-100,w);
}
void push()
{
    if(rear>n-1)
    {
        status = FULL;
        rear=7;
    }
    else
    {
        rear++;
        yrarr+=40;
        //stack[top]=val_int[top];
        printf("%s",val[top]);
        status = ENT;
    }
}
void pop()
{
    if(top==rear-1)
    {
         status = EMPTY;
         top=0;
         rear=0;
         yfarr=0;
         yrarr=0;
         return;
    }
    else
    {
        top++;
        yfarr+=40;
        status = DEL;
    }
}
void fill(){
    float X=20.0;
float Y=20.0+top*40;
    for(int i =top;i<rear;i++){
        textPt(X,Y,val[i]);
        Y+=40;
    }
}
void keyboard(unsigned char key,int x,int y){
        switch(key)
        {
            case 'i':
            {
                push();
                printf("i");
                break;
            }
            case 'd':
            {
                pop();
                break;
            }
            case 'e':
            {
                printf("\n\t EXIT POINT ");
                break;
            }
        }
    glutPostRedisplay();
}
void square(float *a, float *b, float *c,float *d){
    glBegin(GL_LINE_LOOP); 
        glColor3f(0.0,0.0,0.0);   
        glVertex2fv(a);      
        glVertex2fv(b);      
        glVertex2fv(c);
        glVertex2fv(d);
    glEnd();
}
void disFrArr(){
    char w[10]="->";
    textPt(-25.0,yfarr,w);
}
void disRrArr(){
    char w[10]="->";
    textPt(-25.0,yrarr,w);
}
void display(void){
        
	glClear(GL_COLOR_BUFFER_BIT);
    drawText();
    float a[]={0.0,0.0},b[]={40,0.0},c[]={40,40},d[]={0.0,40};
    for(int j=0;j<7;j++){
        square(a,b,c,d);
       
        // glRasterPos2f(100, c[1]/2);
        // glColor3f(1,1,1);
        // int len = strlen(val[i]);
        // for (i = 0; i < len; i++) {
        //     glutBitmapCharacter(GLUT_BITMAP_8_BY_13, val[i]);
        // }

        //textPt(100,c[1]/2,val[i]);
        a[1]+=40;
        b[1]+=40;
        c[1]+=40;
        d[1]+=40;
    }
    fill();
    disFrArr();
    disRrArr();
    glFlush();
}

void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
    gluOrtho2D(-400 , 400, -400 , 400);

}

int main(int argc, char **argv)
{
    //clrscr();

    
    /* Initialise GLUT librarY */
    glutInit(&argc,argv);
    /* Set the initial displaY mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0,0);
    glutInitWindowSize(800,800);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Poly Transalte");
  /* Initialize drawing colors */
  Init();
  /* Call the displaYing function */
  glutDisplayFunc(display);
  /* Keep displaYing untill the program is closed */

  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}