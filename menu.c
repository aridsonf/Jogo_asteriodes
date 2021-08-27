#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void desenhaTextoBmp(int x, int y, void *fonte, char *string);
void reshape (int w, int h);

char txt[99];


// Largura e altura da janela
GLfloat windowWidth = 400;
GLfloat windowHeight = 400;
GLfloat correcaowid = 1;
GLfloat correcaohei = 1;


int main(int argc, char ** argv) {  
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize (windowWidth, windowHeight);
    glutInitWindowPosition (500, 100);
    glutCreateWindow("ASTEROIDS");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    	glutReshapeFunc(reshape);
    glutMainLoop();
    return 0; 
}

void init(void) {  
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void desenhaTextoBmp(int x, int y, void *fonte, char *string){
  glRasterPos2f(x, y);
  while(*string) 
    glutBitmapCharacter(fonte, *string++);
}

void display(void) {  
    int i;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    strcpy(txt, "ASTEROIDS");
        desenhaTextoBmp(130 * correcaowid, 380 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt);

    strcpy(txt, "START");
        desenhaTextoBmp(155 * correcaowid, 100 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt);

    strcpy(txt, "QUIT");
        desenhaTextoBmp(165 * correcaowid, 80 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt);
    
    glFlush();
    glutSwapBuffers();
}




void reshape (int w, int h){

    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // novos tamanhos
    windowHeight = h;
    windowWidth = w;

    // fator de correcao
    correcaowid = windowWidth / 400;
    correcaohei = windowHeight / 400;

    glOrtho (0, windowWidth, 0, windowHeight, -1 ,1);
}

void mouse(int button, int state, int x, int y){
  switch (button) {

  case GLUT_LEFT_BUTTON:
	if (state == GLUT_DOWN) {

        if( (x  > (155 * correcaowid) && x < (235 * correcaowid)) && (y  < (300 * correcaohei) && y > (285 * correcaohei)) ) {
            system("g++ -o game game.c -lglut -lGL -lGLU -lm");
            system("./game"); 
            break;

        }
        if( (x > (165 * correcaowid) && x < (225 * correcaowid)) && (y < (320 * correcaohei) && y > (300 * correcaohei)) ) {
            exit(0);
            break;
        }
	}
	printf("(%d %d)\n", x,y);
	break;
  }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key)  { 

        case 27:
            exit(0);
            break;
    }
}



