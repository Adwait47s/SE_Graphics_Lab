#include<GL/gl.h>
#include<iostream>
#include<GL/freeglut.h>

struct color
{
	GLubyte r,g,b;
};
void plot(int xc,int yc,int x, int y){
	glColor3ub(0,0,0);
	glBegin(GL_POINTS);
		glVertex2i(xc + x,yc + y);
		glVertex2i(xc + x,yc - y);
		glVertex2i(xc + y,yc + x);
		glVertex2i(xc + y,yc - x);
		glVertex2i(xc - x,yc + y);
		glVertex2i(xc - x,yc - y);
		glVertex2i(xc - y,yc + x);
		glVertex2i(xc - y,yc - x);
	glEnd();
	glFlush();
}

void circle(int xc,int yc,int r){
	int x=0,y=r;
	xc+=250;yc+=250;
	int p=3-2*r;
	
	plot(xc,yc,x,y);
	while(x<=y){
		x++;
		if(p<0){
			p = p + 4*x + 6;
			
		}
		else{
			p= p+ 4*(x-y) + 10;
			y--;
		}
		plot(xc,yc,x,y);
	}
	
}
void putpixel(int x,int y, color c){
    glColor3ub(c.r,c.g,c.b);
    glBegin(GL_POINTS);
    	glVertex2i(x,y);
    glEnd();
    glFlush();
}

void seedfill(int x, int y, color o, color n)
{
	color c;
	glReadPixels(x,y,1,1,GL_RGB, GL_UNSIGNED_BYTE, &c);
	
	if(c.r== o.r && c.g==o.g && c.b==o.b){
		putpixel(x,y,n);
		
		seedfill(x,y+1,o,n);
		seedfill(x+1,y,o,n);
		seedfill(x-1,y,o,n);
		seedfill(x,y-1,o,n);
		glFlush();
	}
}
void plotcircle(int x, int y, int radius){
	circle(x,y,radius);
	circle(-x,y,radius);
}
void mouse(int button, int state, int x, int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		plotcircle(x-250,-(y-250),20);
		std::cout<<x<<" "<<y<<std::endl;
	}
}

void drawlace(){

plotcircle(312-250,-249+250-15,20);
plotcircle(340-250, -220+250-15,20);
plotcircle(366-250, -191+250-15,20);
plotcircle(388-250, -157+250-15,20);
plotcircle(412-250, -115+250-12-15,20);
plotcircle(427-250, -79+250-13-15,20);
glFlush();

}


int main(int argv, char **argc){
	glutInit(&argv,argc);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Necklace");
	gluOrtho2D(0,500,0,500);
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	color old={255,255,255};
	color red = {255,0,0};
	color green = {0,255,0};
	color blue = {0,0,255};
	color n ={255,255,0};
	
	circle(0,-50,50);
	
	circle(0,-50,25);
	circle(249-250,-380+250,30);
	circle(-1,-380+250,15);
	circle(-55,-105,30);
	circle(55,-105,30);
	glutDisplayFunc(drawlace);
	
	//seedfill(250,200,old,red);
	//seedfill(250,230,old,n);
	//seedfill(249,120,old,green);
	
	
	glutMouseFunc(mouse);
	glFlush();
	glutMainLoop();
	return 0;
}
