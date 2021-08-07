#include <stdarg.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

double x1 = 0.0;	 //X direction movement
double y1 = 0.0;	 //Y direction movement
double x2 = 0.0;	 //Propeller Rotation
double r1 = 0.0;	 //Tilt Plane
double r2 = 0.0;	 //Tilt Plane
double move_x = 0.0; //Plane movement in X direction
double move_y = 0.0; //Plane movement in Y direction
bool over = false;   //To check if game is over

void stroke(float x, float y, char *format, float a, float b, float c, ...)
{
	va_list args;
	char buffer[200], *p;
	vsprintf(buffer, format, args);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(a / 1000, b / 1000, c / 1000);
	for (p = buffer; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}

void renderPlane()
{

	glPushMatrix();

	//Main Body

	glPushMatrix();
	glScalef(0.3, 0.3, 1.5);
	glColor3f(1, 0, 0);
	glutSolidSphere(2.0, 50, 50);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, 0.1, -1.8);
	glScalef(1.0, 1, 1.5);
	glColor3f(0, 0, 1);
	glutSolidSphere(0.5, 25, 25);
	glPopMatrix();

	//Left Fin

	glPushMatrix();
	glTranslatef(-1.0, 0, 0);
	glScalef(1.5, 0.1, 0.5);
	glColor3f(0.1, 0.1, 0.1);
	glutSolidSphere(1.0, 50, 50);
	glPopMatrix();

	// Right Fin

	glPushMatrix();

	glTranslatef(1.0, 0, 0);
	glScalef(1.5, 0.1, 0.5);
	glColor3f(0.1, 0.1, 0.1);
	glutSolidSphere(1.0, 50, 50);
	glPopMatrix();

	//Rear Fin

	glPushMatrix();
	glTranslatef(0, 0.5, 2.4);
	glScalef(0.1, 1.1, 0.5);
	glColor3f(0.1, 0.1, 0.1);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

	//Propeller

	glPushMatrix();
	glRotatef(x2, 0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -3.0);
	glScalef(2.5, 0.3, 0.3);
	glColor3f(0.1, 0.1, 0.1);
	glutSolidSphere(0.3, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0.0, 0.0, 1.0);
	glTranslatef(0, 0.0, -3.0);
	glScalef(2.5, 0.3, 0.3);
	glColor3f(0.1, 0.1, 0.1);
	glutSolidSphere(0.3, 50, 50);
	glPopMatrix();

	glPopMatrix();

	//Front Wheel

	glPushMatrix();
	glTranslatef(0.0, -0.8, -1.5);
	glRotatef(90, 0.0, 1, 0);
	glScalef(0.3, 0.3, 0.3);
	glColor3f(0, 0, 0);
	glutSolidTorus(0.18, 0.5, 25, 25);
	glColor3f(1, 1, 1);
	glutSolidTorus(0.2, 0.1, 25, 25);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.4, -1.5);
	glRotatef(20, 0.0, 1, 0);
	glScalef(0.05, 0.3, 0.05);
	glutSolidSphere(1.0, 25, 25);
	glPopMatrix();

	//Rear Right Wheel

	glPushMatrix();
	glTranslatef(0.3, -0.8, 0.7);
	glRotatef(90, 0.0, 1, 0);
	glScalef(0.3, 0.3, 0.3);
	glColor3f(0, 0, 0);
	glutSolidTorus(0.18, 0.5, 25, 25);
	glColor3f(1, 1, 1);
	glutSolidTorus(0.2, 0.1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, -0.4, 0.7);
	glRotatef(20, 0.0, 1, 0);
	glScalef(0.05, 0.3, 0.05);
	glutSolidSphere(1.0, 25, 25);
	glPopMatrix();

	//Rear Left Wheel

	glPushMatrix();
	glTranslatef(-0.3, -0.8, 0.7);
	glRotatef(90, 0.0, 1, 0);
	glScalef(0.3, 0.3, 0.3);
	glColor3f(0, 0, 0);
	glutSolidTorus(0.18, 0.5, 25, 25);
	glColor3f(1, 1, 1);
	glutSolidTorus(0.2, 0.1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, -0.4, 0.7);
	glRotatef(20, 0.0, 1, 0);
	glScalef(0.05, 0.3, 0.05);
	glutSolidSphere(1.0, 25, 25);
	glPopMatrix();

	glPopMatrix();
}

void planeStructure()
{
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(1.0, 0.0, -13.0);
	glColor3f(1.0, 1.0, 1.0);
	stroke(-2.1, 2.0, "The Plane", 4, 5, 5);
	glTranslatef(-1.0, -1.0, 0.0);
	glPushMatrix();
	glRotatef(x1, 0.0, 1.0, 0.0);
	glRotatef(y1, 1.0, 0.0, 0.0);
	renderPlane();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void gameOver()
{
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -13.0);
	glColor3f(0.0, 0.0, 0.0);
	stroke(-2.8, -0.2, "The plane crashed", 5, 7, 10);
	glFlush();
}

void backdrop()
{
	glClearColor(0.3, 0.6, 0.9, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -13.0);
	if (move_y <= -4)
	{
		over = true;
		gameOver();
	}
	else
	{
		//Ground

		glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-10, -5, 10);
		glVertex3f(10, -5, 10);
		glVertex3f(10, -5, -10);
		glVertex3f(-10, -5, -10);
		glEnd();

		//Initializing plane

		glPushMatrix();
		glTranslatef(move_x, -1.0 + move_y, 0);
		glRotatef(r1, 0.0, 0.0, 1.0);
		glRotatef(r2, 1.0, 0.0, 0.0);
		renderPlane();
		glPopMatrix();
	}
	glFlush();
	glutSwapBuffers();
}

void start()
{
	x2 += 5.0;
	backdrop();
}

void process()
{
	x2 = 0.0;
	planeStructure();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (float)640 / (float)480, 0.1, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -13.0);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.7, 0.7, 0.7);
	stroke(-2.0, 1.7, "Stunt Plane", 5, 7, 9);
	stroke(-6.5, -2.8, "By: ", 3, 5, 5);
	stroke(-6.0, -3.8, "Arjun Khanduri (1CR18CS029)", 3, 5, 5);
	stroke(-6.0, -4.5, "Aswini Kalyan (1CR18CS034)", 3, 5, 5);
	stroke(1.8, -2.8, "Under the guidance of: ", 3, 5, 5);
	stroke(3.0, -3.8, "Mr. Shivraj B", 3.5, 5, 5);
	glPopMatrix();
	float mat_ambient[] = {0.2, 0.2, 0.2, 1.0};
	float mat_diffuse[] = {0.8, 0.8, 0.8, 1.0};
	float mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	float mat_shininess[] = {64.0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	float lightIntensity[] = {1.7, 1.7, 1.7, 1.0};
	float light_position[] = {0.0, 5.0, 5.0, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
	glFlush();
	glutSwapBuffers();
}

void planeViewControls(unsigned char key, int x, int y)
{
	if (key == 'h' || key == 'H')
	{
		r1 = 0;
		r2 = 0;
	}
	if (key == 'a' || key == 'A')
		x1 += 1.5;
	if (key == 'd' || key == 'D')
		x1 -= 1.5;
	if (key == 's' || key == 'S')
		y1 += 1.5;
	if (key == 'w' || key == 'W')
		y1 -= 1.5;
	if (key == 'q' || key == 'Q')
		exit(0);
}

static void planeMovementControls(int key, int x, int y)
{
	if (!over)
	{

		if (key == GLUT_KEY_UP)
		{
			r1 = 0;
			r2 = -10;
			move_y -= 0.5;
		}

		if (key == GLUT_KEY_DOWN)
		{
			r1 = 0;
			r2 = 10;
			move_y += 0.5;
		}
		if (key == GLUT_KEY_LEFT)
		{
			r1 = 45;
			r2 = 10;
			move_x -= 0.5;
		}
		if (key == GLUT_KEY_RIGHT)
		{
			r1 = -45;
			r2 = 10;
			move_x += 0.5;
		}
	}
}

void menu(int num)
{
	if (num == 1)
		glutIdleFunc(start);
	if (num == 2)
	{
		x1 = 0.0;
		y1 = 0.0;
		glutIdleFunc(process);
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("Stunt Plane");
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutKeyboardFunc(planeViewControls);
	glutSpecialFunc(planeMovementControls);
	glutCreateMenu(menu);
	glutAddMenuEntry("Backdrop", 1);
	glutAddMenuEntry("Plane Structure", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
	glutMainLoop();
	return 0;
}
