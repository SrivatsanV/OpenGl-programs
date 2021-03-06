#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

typedef float Matrix4 [4][4];

Matrix4 matrix;
static GLfloat input[5][3]=
{
    {40,40,-50},{90,40,-50},
    {30,30,0},{80,30,0},{55,80,-25}

};

float output[5][3];
float tx,ty,tz;
float sx,sy,sz;
float angle;

int choice,choiceRot;

void setIdentityM(Matrix4 m)
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            m[i][j]=(i==j);
}

void translate(int tx,int ty,int tz)
{

    for(int i=0;i<5;i++)
    {
    output[i][0]=input[i][0]+tx;
    output[i][1]=input[i][1]+ty;
    output[i][2]=input[i][2]+tz;
    }
}
void scale(int sx,int sy,int sz)
{
    matrix[0][0]=sx;
    matrix[1][1]=sy;
    matrix[2][2]=sz;
}
void RotateX(float angle) 
{

    angle = angle*3.142/180;
    matrix[1][1] = cos(angle);
    matrix[1][2] = -sin(angle);
    matrix[2][1] = sin(angle);
    matrix[2][2] = cos(angle);

}
void RotateY(float angle) 
{

    angle = angle*3.14/180;
    matrix[0][0] = cos(angle);
    matrix[0][2] = -sin(angle);
    matrix[2][0] = sin(angle);
    matrix[2][2] = cos(angle);

}
void RotateZ(float angle) 
{

    angle = angle*3.14/180;
    matrix[0][0] = cos(angle);
    matrix[0][1] = sin(angle);
    matrix[1][0] = -sin(angle);
    matrix[1][1] = cos(angle);

}

void multiplyMatrix()
{

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            output[i][j]=0;
            for(int k=0;k<3;k++)
            {
                output[i][j]=output[i][j]+input[i][k]*matrix[k][j];
            }
        }
    }

}
void Axes(void)
{
    glColor3f (0.0, 0.0, 0.0);               
    glBegin(GL_LINES);                       
    glVertex2s(-1000 ,0);
    glVertex2s( 1000 ,0);
    glEnd();
    glBegin(GL_LINES);                       
    glVertex2s(0 ,-1000);
    glVertex2s(0 , 1000);
    glEnd();
}
void draw(float a[5][3])
{


    glBegin(GL_QUADS);
    glColor3f(0.7,0.4,0.5); //bottom
    glVertex3fv(a[0]);
    glVertex3fv(a[1]);
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0.1);  //behind
    glVertex3fv(a[4]);
    glVertex3fv(a[0]);
    glVertex3fv(a[1]);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0.5); //left
    glVertex3fv(a[4]);
    glVertex3fv(a[0]);
    glVertex3fv(a[2]);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,1,0);  //right
    glVertex3fv(a[4]);
    glVertex3fv(a[1]);
    glVertex3fv(a[3]);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0,0,0); //front
    glVertex3fv(a[4]);
    glVertex3fv(a[2]);
    glVertex3fv(a[3]);
    glEnd();


}

void init()
{
    glClearColor(1.0,1.0,1.0,1.0); //set backgrond color to white
    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
    // Set the no. of Co-ordinates along X & Y axes and their gappings
    glEnable(GL_DEPTH_TEST);
     // To Render the surfaces Properly according to their depths
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    Axes();
    glColor3f(1.0,0.0,0.0);
    draw(input);
    setIdentityM(matrix);
    switch(choice)
    {
    case 1:
    translate(tx,ty,tz);
    break;
    case 2:
    scale(sx,sy,sz);
    multiplyMatrix();
    break;
    case 3:
    switch (choiceRot) {
    case 1:
        RotateX(angle);
        break;
    case 2: RotateY(angle);
        break;
    case 3:
        RotateZ(angle);
        break;
    default:
        break;
    }
    multiplyMatrix();
    break;
    }

    draw(output);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1362,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("3D TRANSFORMATIONS");
    init();
    cout<<"Enter your choice number:\n1.Translation\n2.Scaling\n3.Rotation\n=>";
    cin>>choice;
    switch (choice) {
    case 1:
        cout<<"\nEnter Tx,Ty &Tz: \n";
        cin>>tx>>ty>>tz;
        break;
    case 2:
        cout<<"\nEnter Sx,Sy & Sz: \n";
        cin>>sx>>sy>>sz;
        break;
    case 3:
        cout<<"Enter your choice for Rotation about axis:\n1.X-axis."
             <<"(y& z)\n2.Y-axis.(x& z)\n3.Z-axis."
              <<"(x& y)\n:";
        cin>>choiceRot;
        cout<<"\nEnter Rotation angle: ";
            cin>>angle;
        break;
    default:
        break;
    }
    glutDisplayFunc(display);
    glutMainLoop();
return 0;
}