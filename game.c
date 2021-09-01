//Bibliotecas e pavalras-chave
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.141592654
#define VIVO 1
#define MORTO 0


//Variaveis
GLint flag = 0;
GLint direcao = 1;

static int xe = 45, ye = 60, tame = 50; 
int status_Nave = VIVO, status_Enemy = VIVO;
int andar = 0, fim = 0;
int ang, ang_g = ang + 90, proj = 0;
static int x2 = 325, y2 = 350, xr, yr;

void movEnemy(int passo);
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void tiro(int passo);
void drawShip(void);
void drawEnemy(int x, int y, int lado);
void drawBorda(void);
void idle(void);

//Funcao que desenha nave e seu tiro
void drawShip(void){
    //Nave
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
    
    //Tiro
    if (andar == 1){
	    glPushMatrix();
	    	glTranslatef(325.0, 325.0, 0.0);
	    	glRotatef((GLfloat) ang, 0.0, 0.0, 1.0);
	    	glTranslatef(-325.0, -325.0, 0.0);
	    	glColor3f(0.0, 0.0, 0.0);
	    	glLineWidth(3);
	    	glBegin(GL_LINES);
	    	glVertex3i (325, 350 + proj, 0);
	    	glVertex3i (325, 340 + proj, 0);
	    	glEnd ();
	    glPopMatrix();	    
   	}
}

//Funcao da animacao do tiro
void tiro(int passo){
	if (andar == 1){
		proj = proj + 10;
		glutPostRedisplay();
		glutTimerFunc(50,tiro,1); 
		//Colisao entre tiro e parede
	        if (x2 <= 0 || y2 <= 0 || x2 >= 650 || y2 >= 650) {
	    		proj = 0;
	    		andar = 0;
	        }
	}
	else {
		andar = 0;
		proj = 0;
	
	}
}

//Funcao que desenha inimigo
void drawEnemy(int x, int y, int lado){
	if (status_Enemy == VIVO){
		glPointSize(40);
		glColor3f(0.5, 1.0, 0.0);
		glBegin(GL_POINTS);  
		glVertex3i(x, y, 0); 
		glEnd();   
	}else{
	}

}

//Movimentacao do inimigo
void movEnemy(int passo) {
        if (direcao == 1) {
            ye += passo;
            if (ye == 630)
                direcao = 0;
        } else {
            ye -= passo;
            if (ye == -90)
                direcao = 1;
        }
        if (!fim)glutPostRedisplay();
        glutTimerFunc(10, movEnemy, 1);
    }

//Funcao para desenha a borda do cenario
void drawBorda(){
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);   
	glVertex3i(0, 0, 0);
	glVertex3i(0, 650, 0);
	glVertex3i(650, 650, 0);
	glVertex3i(650, 0, 0);
	glEnd();  
}

void init(void) {  
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glOrtho (0, 650, 0, 650, -1 ,1);
}

//Janela do jogo
void display(void) { 
    
    glClear(GL_COLOR_BUFFER_BIT);
    drawBorda();
    drawEnemy(xe, ye, tame = 50);
    drawShip();
    glutSwapBuffers();

}

//Colisao    
void idle(void){

	//Calculo da posicao do tiro
	x2 = 325;
        y2 = 325 + proj;
        x2 = x2 - 325;
        y2 = y2 - 325;
        xr = (x2*cos(ang*PI/180) - (y2)*sin(ang*PI/180));
        yr = (x2*sin(ang*PI/180) + (y2)*cos(ang*PI/180));
        x2 = xr + 325;
        y2 = yr + 325;
	//Colisao entre tiro e inimigo
	if(status_Enemy == VIVO){
		if((x2 - xe <= 40) && (y2 - ye <= 40)){
			printf("x2 = %d, y2 = %d, xe = %d, ye = %d\n", x2,y2,xe,ye);
			
			status_Enemy = MORTO;
			proj = 0;
			
		}else{
		}
	}
}

//Definicao das teclas utilizadas no jogo
void keyboard(unsigned char key, int x, int y) {
    switch (key)  { 
        case 'd':
        	ang = (ang - 5) % 360;
        	andar = 0;
        	glutPostRedisplay();
        	break;
        case 'D':
        	ang = (ang - 5) % 360;
        	andar = 0;
        	glutPostRedisplay();
        	break;
        case 'a':
        	ang = (ang + 5) % 360;
        	andar = 0;
        	glutPostRedisplay();
        	break;
        case 'A':
        	ang = (ang + 5) % 360;
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
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(10, movEnemy, 1);
    glutMainLoop();
    return 0; 
}
