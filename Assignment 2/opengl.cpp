#include <GL/freeglut.h>
#include <GL/gl.h>


void displayfunc(int x,int y){
	glColor3f(0,1,0);
		glBegin(GL_POINTS);
			glVertex2f(x,y);
		
		glEnd();
}

void simpleline(float x, float y, float x1,float y1){
	
    
    float dy,dx ;
    dy = y1-y;
    dx = x1-x;
    int steps;
    if(abs(dy) <abs(dx)){
    	steps = abs(dx);
    }
    else{
    	steps = abs(dy);
    }
    
    float xincre,yincre;
    xincre = dx/(float)steps;
    yincre = dy/(float)steps;
    
    for(int i=0;i<=steps;i++){
    	displayfunc(x,y);
    	x+=xincre;
    	y+=yincre;
    }
    	
    glFlush();

}

void BSA_Algo(int xi, int yi, int xf, int yf)
{
/*
* Input : Initial (xi, yi) and final co-ordinates of line segment.
* Utility : Plot line on the window using Bresenham's line drawing algorithm.
* Output : Line.
*/
int P;
int dx = xf - xi;
int dy = yf - yi;
int x = xi, y = yi;
//Consider absolute value of dx and dy.
if (dx < 0)
{
dx = -dx;
}
if (dy < 0)
{
dy = -dy;
}
//Change of x and y values depends on initial and final points defined by the user.
int x_change = 1, y_change = 1;
if(xi > xf)
{
x_change = -1;
}
if (yi > yf)
{
y_change = -1;
}
//plot initial point.
glVertex2i(x, y);
//For horizontal line, increment y value. Plot the line and return.
if (dx == 0)
{
glBegin(GL_POINTS);
for (int i = 1; i<dy; i++)
{
y = y + y_change;
glVertex2i(x, y);
}
glEnd();
return;
}
//For vertical line, increment x value. Plot the line and return.
if (dy == 0)
{
glBegin(GL_POINTS);
for (int i = 1; i<dx; i++)
{
x = x + x_change;
glVertex2i(x, y);
}
glEnd();
return;
}
//Calculate vertex position based on descision parameter.
glBegin(GL_POINTS);
if (dx > dy)
{
P = 2*dy -dx;
for(int i = 0; i < dx; i++)
{
if (P > 0)
{
y += y_change;
P = P + 2*(dy - dx);
}
else
{
P = P + 2*dy;
}
x += x_change;
glVertex2i(x, y);
}
}
else
{
P = 2*dx -dy;
for(int i = 0; i < dy; i++)
{
if (P > 0)
{
x += x_change;
P = P + 2*(dx - dy);
}
else
{
P = P + 2*dx;
}
y += y_change;
glVertex2i(x, y);
}
}
glEnd();
}
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0,700,0,700);
   /* glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();*/
    BSA_Algo(50, 100, 650,100);
    BSA_Algo(50, 100, 50,300);
    BSA_Algo(50, 300, 250,300);
    BSA_Algo(250, 300, 250,500);
    BSA_Algo(250, 500, 450,500);
    BSA_Algo(450, 500, 450,699);
    BSA_Algo(450, 699, 650,699);
    BSA_Algo(650, 699, 650,100);
    glFlush();
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
