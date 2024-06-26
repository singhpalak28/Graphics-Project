#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<GL/glut.h>

#define pi 3.14
#define rand_max 600


int cflag=0;
int flag=0;
char str1[]="START";
char str2[]="Project by Divyanshu . ";
int xmin=0,xmax=500,ymin=0,ymax=500;
int dx=5,dir=1;

void myinit()
{
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w>h)
	{
		gluOrtho2D(xmin*float(w)/float(h),xmax*float(w)/float(h),ymin,ymax);
	}
	else
	{
		gluOrtho2D(xmin,xmax,ymin*float(h)/float(w),ymax*float(h)/float(w));
	}
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void start_screen()
{
	int i;
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,1);

	glRasterPos2f(230,250);
	for(i=0;i<strlen(str1);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,str1[i]);
		glFlush();
	}
	glRasterPos2f(10,30);
	for(i=0;i<strlen(str2);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,str2[i]);
		glFlush();
	}

}

void rain()
{
	int x1,y1;

	glClear(GL_COLOR_BUFFER_BIT);

	for(long int i=0;i<rand_max;i++)
	{
		x1=rand()%1000;
		y1=rand()%1000;


		glColor3f(1,1,1);
		glBegin(GL_POINTS);
			glVertex2f(x1,y1);

		glEnd();

		glFlush();
	}

}

void draw_bod()
{

		glBegin(GL_LINES);
			glVertex2f(10,0);
			glVertex2f(20,50);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(30,0);
			glVertex2f(20,50);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(20,50);
			glVertex2f(20,90);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(20,90);
			glVertex2f(10,70);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(20,90);
			glVertex2f(30,70);
		glEnd();
		glBegin(GL_LINES);
			glVertex2f(30,70);
			glVertex2f(30,120);
		glEnd();
		glFlush();
}

void draw_head(double dx,double dy)
{

		double x,y,t;
		double r=7;
		glBegin(GL_POINTS);
		for(t=0;t<=1000;t++)
		{
				x=r*cos(t*pi/180)+dx;
				y=r*sin(t*pi/180)+dy;
				glVertex2f(x,y);
		}

		glEnd();
		glFlush();
}

void draw_um()
{
    // Canopy parameters
    double centerX = 30.0; // X-coordinate of the canopy center
    double centerY = 120.0; // Y-coordinate of the canopy center
    double radius = 40.0; // Larger radius for the canopy

    // Draw the semi-circle canopy
    glColor3f(1.0, 1.0, 1.0); // Red color for the canopy
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY); // Center of the semi-circle (top of the canopy)

    int numSegments = 100; // Number of segments to approximate the semi-circle
    for (int i = 0; i <= numSegments; ++i)
    {
        double angle = i * (pi / numSegments);
        double x = centerX + radius * cos(angle);
        double y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}
/*void draw_um()
{
		double x,y,t;
		double r=5;
		glBegin(GL_TRIANGLES);
			glVertex2f(10,110);
			glVertex2f(30,150);
			glVertex2f(50,110);
			glEnd();
		glBegin(GL_LINES);
			glVertex2f(30,150);
			glVertex2f(30,153);
		glEnd();

		glFlush();
*/
void mt(int v)
{
		if(dir==1)
			dx=dx+5;
		else
			dx=dx-5;
		if(dx==800)
			dir=-1;
		else if(dx==0)
			dir=1;


		glutPostRedisplay();
		glutTimerFunc(200,mt,v);
}

void mouse_func(int button,int status,int x,int y)
{
	y=500-y;
	if((button==GLUT_LEFT_BUTTON)&&(status==GLUT_DOWN))
	{
		if(((x>230)&&(x<270))&&((y>230)&&(y<270)))
			flag=1;
	}
	glutPostRedisplay();
}

void menufunc(int id)
{
		if(id==5)
			exit(0);
}

void ifunc()
{
	dx=dx+5;
	glutPostRedisplay();
}
void disp()
{
		//function call to display start screen
		start_screen();


		if(flag==1)
		{
			glClearColor(0,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);

			glLoadIdentity();

			rain();
			glTranslatef(dx,0,0);

			//selection of color of man , based on menu selection
			switch(cflag)
			{
			case 1:glColor3f(1,0,0);
						break;
			case 2:glColor3f(0,1,0);
						break;
			case 3:glColor3f(0,0,1);
						break;
			case 4:glColor3f(1,1,1);


			}

			draw_bod();
			draw_head(20,97);
			draw_um();


		}

		glutSwapBuffers();
		glFlush();

}
int main(int argc, char* argv[])
{

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB );
	// Set the window size
	glutInitWindowSize(500,500);
	//set window position
	glutInitWindowPosition(0,0);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Project");
	//calling myinit functionn

	myinit();


	//registering call back functions

	//registering display function
	glutDisplayFunc(disp);

	//registering mouse function
	glutMouseFunc(mouse_func);

	//registering timmer func
	glutTimerFunc(200,mt,60);


	//registering reshape func
	glutReshapeFunc(reshape);

	glutMainLoop();

	return 0;
}
