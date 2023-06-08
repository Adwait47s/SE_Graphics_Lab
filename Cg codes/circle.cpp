#include <GL/glu.h>
#include<GL/gl.h>
#include <GL/freeglut.h>






void plot(int x,int y,int xc,int yc){

	glColor3f(0,0,0);
	glBegin(GL_POINTS);
	glVertex2f(xc +x , yc +y);
	glVertex2f(xc +x , yc-y);
	glVertex2f(xc +y , yc+x);
	glVertex2f(xc +y , yc-x);
	glVertex2f(xc -x , yc+y);
	glVertex2f(xc -x , yc-y);
	glVertex2f(xc -y , yc+x);
	glVertex2f(xc -y , yc-x);
	glEnd();
	glFlush();
	
}



void bres(int xc,int yc,int r){
	int x=0; int y=r;
	int p =  3 - 2*r;
	xc+=250;
	yc+=250;
	
	plot(x,y,xc,yc);
	
	while(x<=y){
		x++;
		if(p<0){
			p+= 4*x + 6;
		}
		else{
			p+= 4*(x-y)+10;
			y--;
		}
		plot(x,y,xc,yc);
	}
}





void myfunction(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	bres(0,0,20);
	bres(20,20,20);
	bres(20,-20,20);
	bres(-20,20,20);
	bres(-20,-20,20);
}









int main(int argc , char **argv){
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Circle Bres");
	glClearColor(1.0,1.0,1.0,0.0);
	gluOrtho2D(0,500,0,500);
	
	glutDisplayFunc(myfunction);
	
	glutMainLoop();
	return 0;
}
