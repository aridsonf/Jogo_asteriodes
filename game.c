#include <GL/glut.h>
#include <stdlib.h>


GLint flag = 0;

int ang = 0;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);


int main(int argc, char ** argv) {  
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);  
    glutInitWindowSize (650, 650);
    glutInitWindowPosition (400, 50);
    glutCreateWindow ("ASTEROIDS");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0; 
}

void init(void) {  
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho (0, 650, 0, 650, -1 ,1);
}

void display(void) {  
    glClear(GL_COLOR_BUFFER_BIT);
 
    glPushMatrix();
    

        glTranslatef (325.0, 325.0, 0.0);
    	glRotatef ((GLfloat) ang, 0.0, 0.0, 1.0);
    	glTranslatef (-325.0, -325.0, 0.0);
    	glColor3f (1.0, 0.0, 0.7);
        glBegin(GL_LINE_LOOP);  
        glVertex3i(315, 310, 0);
        glVertex3i(325, 340, 0); 
        glVertex3i(335, 310, 0); 
        glVertex3i(325, 315, 0);
        glEnd();   

    glPopMatrix();
    

    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y) {
    switch (key)  { 
        case 'd':
        	ang = (ang - 5) % 360;
        	glutPostRedisplay();
        	break;
        case 'D':
        	ang = (ang - 5) % 360;
        	glutPostRedisplay();
        	break;
        case 'a':
        	ang = (ang + 5) % 360;
        	glutPostRedisplay();
        	break;
        case 'A':
        	ang = (ang + 5) % 360;
        	glutPostRedisplay();
        	break;
        case 27: 
        	exit(0); 
        	break;
    }
}
