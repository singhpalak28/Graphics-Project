#include <stdio.h>
#include <GL/glut.h>
#include<math.h>

GLfloat rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;
float move_unit = 3;
float rate = 1.0f;
float angle = -0.0f;
float RotateX = 0.f, RotateY = 45.f;

void Timer(int value)
{
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(16, Timer, 0); // next Timer call milliseconds later
}

void stand()
{
	// windmill stand
	glBegin(GL_QUADS);
	glColor3f(0.69, 0.43, 0.314);
	glVertex2i(106, 298);
	glVertex2i(199, 296);
	glVertex2i(160, 420);
	glVertex2i(140, 420);
	glEnd();
	glFlush();

}

void windmill()
{

	//left 1st wing
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.176, 0.070);
	glVertex2i(200, 400);
	glVertex2i(180, 450);
	glVertex2i(20, 570);
	glVertex2i(40, 520);
	//glEnd();
	glFlush();
	//2nd wing
	glColor3f(0.4, 0.176, 0.070);
	glVertex2i(0, 400);
	glVertex2i(190, 520);
	glVertex2i(210, 570);
	glVertex2i(20, 450);
	glEnd();
	glFlush();


}

void drawCircle(int x1, int y1, int radius)

{
	float x2, y2;
	float angle;
	glBegin(GL_POLYGON);
	for (angle = .1f; angle<361.0f; angle += 1.0f)

	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}

	glEnd();
}

void megh()

{
	glColor3f(0.94, 1.0, 0.94);
	drawCircle(45, 680, 20);
	drawCircle(75, 680, 40);
	drawCircle(90, 680, 45);
	drawCircle(120, 680, 35);
	drawCircle(140, 680, 20);

	drawCircle(200, 670, 25);
	drawCircle(220, 670, 35);
	drawCircle(260, 670, 50);
	drawCircle(290, 670, 35);
	drawCircle(320, 670, 20);

}

void tree()
{
	//right leaf
	glColor3f(0, 0.098, 0);
	drawCircle(1170, 288, 25);
	drawCircle(1190, 344, 45);
	drawCircle(1185, 320, 30);
	drawCircle(1245, 380, 55);
	drawCircle(1238, 310, 25);
	drawCircle(1259, 315, 30);
	drawCircle(1200, 295, 25);

	//left leaf

	glColor3f(0, 0.098, 0);
	drawCircle(956, 364, 20);
	drawCircle(990, 361, 25);
	drawCircle(1046, 361, 25);
	drawCircle(1070, 360, 20);

	glColor3f(0, 0.098, 0);
	drawCircle(980, 400, 25);
	drawCircle(1020, 387, 35);
	drawCircle(1065, 392, 25);

	glColor3f(0, 0.098, 0);
	drawCircle(999, 440, 30);
	drawCircle(1030, 435, 35);



}

void background()
{
	//backgrounds******
	//back sky ash background
	glBegin(GL_QUADS);
	glColor3f(0.70, 0.96, 0.96);
	glVertex2i(0, 420);
	glVertex2i(1277, 420);
	glVertex2i(1277, 780);
	glVertex2i(0, 780);
	glEnd();
	glFlush();

	//back grass left
	glBegin(GL_QUADS);
	glColor3f(0.30, 0.701, 0.235);
	glVertex2i(0, 420);
	glVertex2i(0, 80);
	glVertex2i(1236, 80);
	glVertex2i(625, 420);
	glEnd();
	glFlush();

	//road black middle
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2i(1236, 80);
	glVertex2i(1277, 117);
	glVertex2i(700, 420);
	glVertex2i(625, 370);
	glEnd();
	glFlush();

	//road black middle
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 0);
	glVertex2i(1277, 117);
	glVertex2i(1236, 80);
	glVertex2i(1277, 80);

	glEnd();
	glFlush();

	//back grass right
	glBegin(GL_TRIANGLES);
	glColor3f(0.30, 0.701, 0.235);
	glVertex2i(1277, 117);
	glVertex2i(1277, 420);
	glVertex2i(600, 420);
	glEnd();
	glFlush();
}


void powerHouse()
{
	//**power house *********

	//phouse base left
	glBegin(GL_POLYGON);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(559, 331);
	glVertex2i(559, 320);
	glVertex2i(660, 318);
	glVertex2i(660, 330);
	glVertex2i(565, 333);
	glEnd();
	glFlush();

	glBegin(GL_POLYGON);
	glColor3f(0.21, 0.15, 0.12);
	glVertex2i(554, 389);
	glVertex2i(564, 386);
	glVertex2i(565, 395);
	glVertex2i(607, 444);
	glVertex2i(607, 446);
	glEnd();
	glFlush();

	//phouse base ri8
	glBegin(GL_POLYGON);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(660, 330);
	glVertex2i(660, 318);
	glVertex2i(685, 327);
	glVertex2i(685, 336);
	glVertex2i(678, 336);
	glEnd();
	glFlush();


	//phouse wall right side
	glBegin(GL_POLYGON);
	glColor3f(0.69, 0.407, 0.34);
	glVertex2i(659, 397);
	glVertex2i(659, 329);
	glVertex2i(679, 336);
	glVertex2i(679, 386);
	glVertex2i(669, 389);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0, 0.01, 0.02);
	glVertex2i(660, 329);
	glVertex2i(660, 400);
	glEnd();
	glFlush();

	//phouse wall front
	glBegin(GL_POLYGON);
	glColor3f(0.69, 0.407, 0.34);
	glVertex2i(607, 443);
	glVertex2i(564, 396);
	glVertex2i(565, 333);
	glVertex2i(659, 329);
	glVertex2i(659, 397);
	glEnd();
	glFlush();

	//phouse door
	glBegin(GL_QUADS);
	glColor3f(0.37, 0.250, 0.12);
	glVertex2i(620, 391);
	glVertex2i(620, 331);
	glVertex2i(650, 331);
	glVertex2i(650, 390);
	glEnd();
	glFlush();

	//phouse window
	glBegin(GL_QUADS);
	glColor3f(0.909, 0.780, 0.486);
	glVertex2i(572, 390);
	glVertex2i(572, 354);
	glVertex2i(607, 354);
	glVertex2i(607, 390);
	glEnd();
	glFlush();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(578, 390);
	glVertex2i(578, 354);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(584, 390);
	glVertex2i(584, 353);
	glEnd();
	glFlush();


	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(590, 389);
	glVertex2i(590, 353);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2i(598, 389);
	glVertex2i(598, 353);
	glEnd();
	glFlush();

	//phouse top left
	glBegin(GL_QUADS);
	glColor3f(0.31, 0.31, 0.39);
	glVertex2i(545, 397);
	glVertex2i(554, 388);
	glVertex2i(607, 443);
	glVertex2i(607, 466);
	glEnd();
	glFlush();

	//phouse top right
	glBegin(GL_QUADS);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(643, 447);
	glVertex2i(607, 466);
	glVertex2i(677, 401);
	glVertex2i(695, 394);
	glEnd();
	glFlush();

	//phouse top right
	glBegin(GL_QUADS);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(607, 466);
	glVertex2i(607, 443);
	glVertex2i(668, 389);
	glVertex2i(677, 401);
	glEnd();
	glFlush();


	//phouse top right
	glBegin(GL_QUADS);
	glColor3f(0.28, 0.29, 0.34);
	glVertex2i(695, 394);
	glVertex2i(677, 401);
	glVertex2i(668, 389);
	glVertex2i(687, 386);
	glEnd();
	glFlush();
}

void treeBase()
{
	//tree base

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex2i(1230, 304);
	glVertex2i(1230, 169);
	glVertex2i(1260, 169);
	glVertex2i(1260, 304);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex2i(1230, 180);
	glVertex2i(1225, 170);
	glVertex2i(1265, 170);
	glVertex2i(1260, 180);
	glEnd();
	glFlush();


	//tree base 2

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex2i(1004, 360);
	glVertex2i(1004, 267);
	glVertex2i(1027, 267);
	glVertex2i(1027, 360);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex2i(1004, 267);
	glVertex2i(1000, 265);
	glVertex2i(1029, 265);
	glVertex2i(1027, 267);
	glEnd();
	glFlush();

	tree();
}


void Display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.5);
	glPointSize(4.0);

	background();

	stand();
	/////////rotatoin
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(150.0, 420.0f, 1);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	angle = angle - rate;
	glTranslatef(-100.0f, -500.0f, -2.0f);


	windmill();
	glPopMatrix();
	glFlush();


	powerHouse();
	treeBase();




	//megh box
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	megh();
	glPopMatrix();
	glutSwapBuffers();

}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1280.0, 0.0, 768.0);
}

void update(int value)
{
	posX += move_unit;
	if (posX>1000)
	{
		posX -= 1000;
	}
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1300, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("wind");
	glutDisplayFunc(Display1);
	myInit();
	glutTimerFunc(1000, update, 0);
	glutMainLoop();
}
