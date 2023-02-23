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
    simpleline(50, 100, 650,100);
    simpleline(50, 100, 50,300);
    simpleline(50, 300, 250,300);
    simpleline(250, 300, 250,500);
    simpleline(250, 500, 450,500);
    simpleline(450, 500, 450,699);
    simpleline(450, 699, 650,699);
    simpleline(650, 699, 650,100);
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

