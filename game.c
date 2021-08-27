#include <GL/glut.h>
#include <stdlib.h>


GLint flag = 0;

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);




int main(int argc, char ** argv) {  
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize (650, 650);
    glutInitWindowPosition (400, 50);
    glutCreateWindow ("Introducao");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0; 
}

void init(void) {  
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho (0, 700, 0, 700, -1 ,1);
}

void display(void) {  
    int i;
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f (1.0, 0.0, 0.7);
    glBegin(GL_LINE_LOOP);  
        glVertex2i(30, 170);
        glVertex2i(40, 200); 
        glVertex2i(50, 170); 
        glVertex2i(40, 175);
    glEnd();  
 
    
    glFlush(); 
}


void keyboard(unsigned char key, int x, int y) {
    switch (key)  { 
        case 27: exit(0); break;
    }
}



