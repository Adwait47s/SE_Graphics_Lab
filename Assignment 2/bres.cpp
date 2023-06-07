#include<GL/gl.h>
#include<GL/freeglut.h>
#include<iostream>

using namespace std;

void plot(int x, int y){
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
	glFlush();
}
void bresenham(float x1,float y1, float x2, float y2){
	float dx= abs(x2-x1);
	float dy = abs(y2-y1);
	float m = (dx==0) ? dy : dy/dx;
	if(abs(m)<1){
		if(x1>x2){
			swap(x1,x2);
			swap(y1,y2);
		}
		float dx1=x2-x1;
		float dy1=y2-y1;
		float m1 = dy1/dx1;
		cout<<m1;
		float p = 2*dy - dx;
		
		while(x1<=x2){
			plot(x1,y1);
			x1++;
			if(p>=0){
				if(m1>0){
					y1++;
					
				}
				else if (m1<=0){
					y1--;
				}
				
				p += 2*dy - 2*dx;
			}
			else{
				p += 2*dy;
			}
		}
	}
	else{
		if(y1>y2){
			swap(x1,x2);
			swap(y1,y2);
		}
		float dx2=x2-x1;
		float dy2=y2-y1;
		float m2 = dy2/dx2;
		float p = 2*dx - dy;
		
		while(y1<=y2){
			plot(x1,y1);
			y1++;
			if(p>=0){
				if(m2<0)x1--;
				else
				x1++;
				p += 2*dx - 2*dy;
			}
			else{
				p += 2*dx;
			}
		}
	}
}
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	bresenham(130,500-450,330,500-450);
	bresenham(330,500-450,275,500-385);
	bresenham(130,50,185,115);
	bresenham(10,115,185,115);
	bresenham(275,115,450,115);
	bresenham(450,115,450,400);
	bresenham(10,115,10,400);
	bresenham(10,400,450,400);
	bresenham(20,390,440,390);
	bresenham(20,125,20,390);
	bresenham(20,125,440,125);
	bresenham(440,390,440,125);
	bresenham(200,300,55,125);
	bresenham(200,300,350,125);
	bresenham(380,300,310,170);
	bresenham(440,215,380,300);
	glFlush();
}


int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("bresenham");
	gluOrtho2D(0,500,0,500);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(draw);
	//bresenham(10,70,80,10);
	
	glutMainLoop();
	return 0;
}
