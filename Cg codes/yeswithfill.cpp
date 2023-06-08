#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;
int angle = 0; // Rotation angle
float vertices[][2] = {
        {250 - 25, 250 + 25},
        {250 - 25, 250 + 75},
        {250 + 25, 250 + 75},
        {250 + 25, 250 + 25},
        {250 + 75, 250 + 25},
        {250 + 75, 250 - 25},
        {250 + 25, 250 - 25},
        {250 + 25, 250 - 75},
        {250 - 25, 250 - 75},
        {250 - 25, 250 - 25},
        {250 - 75, 250 - 25},
        {250 - 75, 250 + 25},
        {250 - 25, 250 + 25},
        {250 - 25, 250 + 75},
        {250 + 25, 250 + 75},
        {250 + 25, 250 + 25},
        {250 + 75, 250 + 25},
        {250 + 75, 250 - 25},
        {250 + 25, 250 - 25},
        {250 + 25, 250 - 75},
        {250 - 25, 250 - 75},
        {250 - 25, 250 - 25},
        {250 - 75, 250 - 25},
        {250 - 75, 250 + 25},
        {250 - 25, 250 + 25}
    };
    
void drawLines()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1.0);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<25;i++){
    	glVertex2i(vertices[i][0],vertices[i][1]);
    }
    glEnd();
    glFlush();
}

void rotateLines()
{
    angle += 45;
    if (angle >= 360){
    	angle= 0;
    }
    if(angle%90==0){
    	angle+=45;
    }
    
    float radianAngle = angle * 3.1416 / 180.0;
    float sinAngle = sin(radianAngle);
    float cosAngle = cos(radianAngle);

    int numVertices = sizeof(vertices) / sizeof(vertices[0]);

    for (int i = 0; i < numVertices; i++)
    {
        float x = vertices[i][0] - 250;
        float y = vertices[i][1] - 250;

        float newX = (x * cosAngle) - (y * sinAngle);
        float newY = (x * sinAngle) + (y * cosAngle);

        vertices[i][0] = newX + 250;
        vertices[i][1] = newY + 250;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numVertices; i++)
    {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
    glFlush();
}

struct color{
	GLubyte r,g,b;
};

color old = {255,255,255};
color green = {0,255,0};


void putp(int x, int y, color c){
	glColor3ub(c.r,c.g,c.b);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	glFlush();
}
void seedfill(int x, int y, color o, color n){
	color c;
	glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&c);
	
	if(c.r == o.r && c.g==o.g && c.b==o.b){
		putp(x,y,n);
		seedfill(x+1,y,o,n);
		seedfill(x,y+1,o,n);
		seedfill(x-1,y,o,n);
		seedfill(x,y-1,o,n);
	}
}
color red = {255,0,0};
void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        rotateLines();
        seedfill(250,250,old,red)   ;     
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotate Lines by 45 Degrees");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
    drawLines();
    seedfill(250,250,old,green);
    glutMouseFunc(mouseClick);
    glutMainLoop();
    return 0;
}
