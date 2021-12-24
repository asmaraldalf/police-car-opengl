#include <GL/glut.h>
#include <math.h>

GLint b = 300;
float  counter = 600.0;
int state = 1;
float x_position = 0;
void timer(int);
void wheel(int x, int y);
void car();
void keyboard(unsigned char key, int x, int y);

void init()

{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(0.8, 0.8, 0.8, 0.0);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 800, 0.0, 600);

}



int main(int argc, char** argv)

{
    // Initialize GLUT
    glutInit(&argc, argv);

    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set top - left display window position.
    glutInitWindowPosition(100, 100);

    // Set display window width and height
    glutInitWindowSize(720, 480);

    // Create display window with the given title
    glutCreateWindow("5220600041 TRANSFORMASI 2D");

    // Execute initialization procedure
    init();

    // Send graphics to display window
    glutDisplayFunc(car);

    glutTimerFunc(1000, timer, 0);

    glutKeyboardFunc(keyboard);
    // Display everything and wait.
    glutMainLoop();

}

void wheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 20 * cos(th), y + 20 * sin(th));
    }

    glEnd();

}

void car()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    
    //glScaled(0.1,0.1,0.0);
    glBegin(GL_QUADS);
    glVertex2f(x_position, 100);
    glVertex2f(x_position, 160);
    glVertex2f(x_position + 400, 160);
    glVertex2f(x_position + 400, 100);

    //Top Part
    glVertex2f(x_position + 50, 160);
    glVertex2f(x_position + 100, 200);
    glVertex2f(x_position + 300, 200);
    glVertex2f(x_position + 350, 160);

    //Window
    glColor3f(0, 0, 0);
    glVertex2f(x_position + 80, 170);
    glVertex2f(x_position + 105, 190);
    glVertex2f(x_position + 295, 190);
    glVertex2f(x_position + 320, 170);

    //Sirene
    glColor3f(0, 0, 1);
    glVertex2f(x_position + 175, 200);
    glVertex2f(x_position + 225, 200);
    glVertex2f(x_position + 225, 215);
    glVertex2f(x_position + 175, 215);
    glEnd();

    //Decor
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(x_position + 150, 160);
    glVertex2f(x_position + 135, 130);
    glVertex2f(x_position + 150, 100);
    glVertex2f(x_position + 205, 100);
    glVertex2f(x_position + 190, 130);
    glVertex2f(x_position + 205, 160);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x_position + 210, 160);
    glVertex2f(x_position + 195, 130);
    glVertex2f(x_position + 210, 100);
    glVertex2f(x_position + 230, 100);
    glVertex2f(x_position + 215, 130);
    glVertex2f(x_position + 230, 160);
    glEnd();


    wheel(x_position + 100, 100);
    wheel(x_position + 280, 100);

    glFlush();

}

void keyboard(int key, int x, int y)

{

    /* kontrol tombol pada keyboard:
      "w": up
      "s": down
    */

    switch (key)
    {
    case 'w':
        glTranslatef(0.0, +5.0, 0.0);
        break;

    case 's':
        glTranslatef(0.0, -5.0, 0.0);
        break;
    }

    car();
}

void timer(int) {

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);

    switch (state) {
    case 1:
        if (x_position < 800 - 400)
            x_position += 5;
        else
            state = -1;
        break;
    case -1:
        if (x_position > 0)
            x_position += -5;
        else
            state = 1;
        break;
    }

}