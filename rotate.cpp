#include <GL/glut.h>
GLfloat angle = 0.0f;
void idle() {
   glutPostRedisplay();   // Post a re-paint request to activate display()
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
   glLoadIdentity();               // Reset the model-view matrix
 
   glPushMatrix();                     // Save model-view matrix setting
   glTranslatef(-0.5f, 0.4f, 0.0f);    // Translate
   glRotatef(angle, 0.0f, 0.0f, 1.0f); // rotate by angle in degrees
   glBegin(GL_QUADS);                  // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex2f(-0.3f, -0.3f);
      glVertex2f( 0.3f, -0.3f);
      glVertex2f( 0.3f,  0.3f);
      glVertex2f(-0.3f,  0.3f);
   glEnd();
   glPopMatrix();

    glPushMatrix(); 
    glTranslatef(0.5f, 0.4f, 0.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    
    glColor3f(0.0,1.0f,0.0);
    
    glVertex2f(0.5f,0.0f);
    glVertex2f(-0.5,0.0f);
    glVertex2f(0.0f,0.5f);

 
    glEnd();
    glPopMatrix(); 

    glPushMatrix(); 
    glTranslatef(0.5f, -0.4f, 0.0f);
    glRotatef(angle, 1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    
    glColor3f(0.0,0.0,1.0f);
    
    glVertex2f(-0.3f,-0.2f);
    glVertex2f(0.3,-0.2f);
    glVertex2f(0.5f,0.3f);
    glVertex2f(0.0f,0.6f);
    glVertex2f(-0.5f,0.3f);

 
    glEnd();
    glPopMatrix(); 

   glutSwapBuffers();   // Double buffered - swap the front and back buffers
 
   // Change the rotational angle after each display()
   angle += 1.0f;    
}
 
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE );
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating shapes!");
    glutDisplayFunc(displayMe);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}