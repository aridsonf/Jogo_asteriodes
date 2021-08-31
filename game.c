#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.141592654

GLint flag = 0;

int andar = 0, andarv = 0, andarx = 0, andary = 0;
int ang = 0, ang_g = 0, proj = 0;


void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void tiro(int passo);

/*
struct Bullet {
    Vector3 Position;
    Vector3 Rotation;
}
struct {
    struct { 
        Vector3 Position;
        Vector3 Rotation;
    } Ship;
    Vector<Bullet*> Bullets;
} Scene;


void Update(void) {
    if (Key.IsPressed(Space)) {
        CreateNewBullet();
    }
}

void UpdateBullets(void) {
    for (Bullet bullet in Scene.Bullets)
    {
        // Delete bullets here if not longer used
        // and move all others
    }
}

void DrawShip(void) {
    glPushMatrix();
    
        glTranslatef(325.0, 325.0, 0.0);
    	glRotatef((GLfloat) ang, 0.0, 0.0, 1.0);
    	glTranslatef(-325.0, -325.0, 0.0);

	glColor3f(1.0, 0.0, 0.7);
	glBegin(GL_LINE_LOOP);  
	glVertex3i(315, 310, 0);
	glVertex3i(325, 340, 0); 
	glVertex3i(335, 310, 0); 
	glVertex3i(325, 315, 0);
	glEnd();   
    glPopMatrix();
    // Draw bullets
    for (Bullet bullet in Scene.Bullets) {
        DrawBullet(bullet);
    }
}

*/


void init(void) {  
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho (0, 650, 0, 650, -1 ,1);
}

void display(void) {  
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
        glTranslatef(325.0, 325.0, 0.0);
    	glRotatef((GLfloat) ang, 0.0, 0.0, 1.0);
    	glTranslatef(-325.0, -325.0, 0.0);

	glColor3f(1.0, 0.0, 0.7);
	glBegin(GL_LINE_LOOP);  
	glVertex3i(315, 310, 0);
	glVertex3i(325, 340, 0); 
	glVertex3i(335, 310, 0); 
	glVertex3i(325, 315, 0);
	glEnd();   
    glPopMatrix();
    
    
    
    
    if (andar == 1){
	    glPushMatrix();
	    	glTranslatef(325.0, 325.0, 0.0);
	    	glRotatef((GLfloat) ang, 0.0, 0.0, 1.0);
	    	glTranslatef(0.0, proj, 0.0);
	    	glTranslatef(-325.0, -325.0, 0.0);
	    	glColor3f(0.0, 0.0, 0.0);
	    	glPointSize(3);
	    	glLineWidth(3);
	    	glBegin(GL_LINES);
	    	glVertex3i (325, 350, 0);
	    	glVertex3i (325, 340, 0);
	    	glEnd ();
	    glPopMatrix();
	    	   

	    if (proj >= 650) {
	    	proj = 0;
	    	andar = 0;
	    }
	    
   	}
    glutSwapBuffers();

}
    
void tiro(int passo){
	if (andar == 1){
		proj = proj + 5;
		glutPostRedisplay();
		glutTimerFunc(10,tiro,1); 
	}
	else {
		andar = 0;
		proj = 0;
	}
}

void keyboard(unsigned char key, int x, int y) {
    switch (key)  { 
        case 'd':
        	ang = (ang - 10) % 360;
        	andar = 0;
        	glutPostRedisplay();
        	break;
        case 'D':
        	ang = (ang - 10) % 360;
        	andar = 0;
        	glutPostRedisplay();
        	break;
        case 'a':
        	ang = (ang + 10) % 360;
        	andar = 0;
        	glutPostRedisplay();
        	break;
        case 'A':
        	ang = (ang + 10) % 360;
        	andar = 0;
        	glutPostRedisplay();
        	break;
        case 27: 
        	exit(0); 
        	break;
        case ' ': 
        	andar = 1; 
        	glutTimerFunc(10,tiro,1);
        	glutPostRedisplay(); 
        	break;
  
    }
}

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
