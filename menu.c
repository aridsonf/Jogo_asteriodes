#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SIM 1
#define NAO 0

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void desenhaTextoBmp(int x, int y, void *fonte, char *string);
void reshape (int w, int h);

char txt[99];
int manual = NAO;

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

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    if(manual == NAO){
	    strcpy(txt, "ASTEROIDS");
        	desenhaTextoBmp(130 * correcaowid, 380 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt);

	    strcpy(txt, "START");
        	desenhaTextoBmp(160 * correcaowid, 120 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt);
        
	    strcpy(txt, "MANUAL");
        	desenhaTextoBmp(145 * correcaowid, 100 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt);

	    strcpy(txt, "QUIT");
        	desenhaTextoBmp(168 * correcaowid, 80 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt); 
        	
    }else {
    	strcpy(txt, "Como jogar?");
        	desenhaTextoBmp(10 * correcaowid, 380 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt);
        strcpy(txt, "*QUANTO A NAVE*");
        	desenhaTextoBmp(10 * correcaowid, 350 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt);
        strcpy(txt, "- Pressione D para rotacionar para direita");
        	desenhaTextoBmp(10 * correcaowid, 330 * correcaohei, GLUT_BITMAP_HELVETICA_18, txt);
        strcpy(txt, "- Pressione A para rotacionar para esquerda");
        	desenhaTextoBmp(10 * correcaowid, 310 * correcaohei, GLUT_BITMAP_HELVETICA_18, txt);
      	strcpy(txt, "- Pressione ESPACO para atirar");
        	desenhaTextoBmp(10 * correcaowid, 290 * correcaohei, GLUT_BITMAP_HELVETICA_18, txt);
        strcpy(txt, "*QUANTO AOS INIMIGOS*");
        	desenhaTextoBmp(10 * correcaowid, 250 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt);
        strcpy(txt, "- Se o inimigo e acertado pelo tiro");
        	desenhaTextoBmp(10 * correcaowid, 230 * correcaohei, GLUT_BITMAP_HELVETICA_18, txt);
        strcpy(txt, "ele e destruido");
        	desenhaTextoBmp(10 * correcaowid, 210 * correcaohei, GLUT_BITMAP_HELVETICA_18, txt);
       strcpy(txt, "- Se o inimigo e atingir o quadrado o qual");
        	desenhaTextoBmp(10 * correcaowid, 190 * correcaohei, GLUT_BITMAP_HELVETICA_18, txt);
        strcpy(txt, "a nave esta contida, ela e destruida");
        	desenhaTextoBmp(10 * correcaowid, 170 * correcaohei, GLUT_BITMAP_HELVETICA_18, txt);
        	
    strcpy(txt, "VOLTAR");
        	desenhaTextoBmp(145 * correcaowid, 80 * correcaohei, GLUT_BITMAP_TIMES_ROMAN_24, txt); 
    }
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
	if(manual == NAO){
        	if( (x  > (160 * correcaowid) && x < (240 * correcaowid)) && (y  < (280 * correcaohei) && y > (260 * correcaohei)) ) {
        	    system("g++ -o game game.c -lglut -lGL -lGLU -lm");
        	    system("./game"); 
        	    break;

        	}
        	if( (x > (144 * correcaowid) && x < (255 * correcaowid)) && (y < (300 * correcaohei) && y > (280 * correcaohei)) ) {
        	    manual = SIM;
        	    glutPostRedisplay();
        	    break;
        	}
        	if( (x > (168 * correcaowid) && x < (228 * correcaowid)) && (y < (320 * correcaohei) && y > (300 * correcaohei)) ) {
        	    exit(0);
        	    break;
        	}
	}else{
		if( (x > (168 * correcaowid) && x < (228 * correcaowid)) && (y < (320 * correcaohei) && y > (300 * correcaohei)) ) {
        	    manual = NAO;
        	    glutPostRedisplay();
        	    break;
	}
	}
	printf("(%d %d)\n", x,y);
	break;
  }
}
}
void keyboard(unsigned char key, int x, int y) {
    switch (key)  { 

        case 27:
            exit(0);
            break;
    }
}



