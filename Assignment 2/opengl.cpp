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

void bres(int x,int y, int x1,int y1){
	
	int dy = y1-y;
	int dx = x1-x;
	int p_in = 2*dy - dx;
	
	displayfunc(x,y);
	while(x1>x){
		x++;
		if(p_in>=0){
		y++;
			p_in += 2*dy - 2*dx;
		}
		else{
			p_in += 2*dy;
			
		}
		displayfunc(x,y);
	}
}
void bresenham(int xA,int yA, int xB,int yB)
{


GLint dy = xB - xA;
GLint dx = yB - yA;
GLint p_ini = 2 * dy - dx;
GLint x_plot = xA;
GLint y_plot = yA;
displayfunc(x_plot, y_plot);
while (x_plot < xB)
{
x_plot += 1;
if (p_ini <= 0)
{
p_ini = p_ini + 2 * dy;
}
else
{
y_plot += 1;
p_ini = p_ini + 2 * dy - 2 * dx;
}

glPointSize(1);
displayfunc(x_plot, y_plot);
}
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
    bres(50, 100, 650,100);
    bres(50, 100, 50,300);
    bres(50, 300, 250,300);
    bres(250, 300, 250,500);
    bres(250, 500, 450,500);
    bres(450, 500, 450,699);
    bres(450, 699, 650,699);
    bres(650, 699, 650,100);
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

