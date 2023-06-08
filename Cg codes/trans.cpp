#include <GL/glu.h>
#include<GL/freeglut.h>
#include <iostream>
#include <math.h>
using namespace std;

float centerX=100;
float centerY=100;

int transx=0;
int transy=0;

int scalex=1;
int scaley=1;

int angle=0;

float vertices[][2] = {
	{centerX +100,centerY+100},
	{centerX +100,centerY-100},
	{centerX-100,centerY-100},
	{centerX-100,centerY+100}
};

void draw(){
	glColor3f(0,0,1);
	glBegin(GL_LINES);
		glVertex2i(0,500);
		glVertex2i(0,-500);
		glVertex2i(-500,0);
		glVertex2i(500,0);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		for(int i=0;i<4;i++){
			glVertex2f(vertices[i][0],vertices[i][1]);
		}
	glEnd();
	glFlush();
}

void drawpolyt(){
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		for(int i=0;i<4;i++){
			glVertex2i(vertices[i][0]+transx,vertices[i][1]+transy);
		}
	glEnd();
	glFlush();
}

void drawpolyr(){
	glColor3f(0,1,0);
	
	float radianangle = angle*3.14/180;
	float sinangle = sin(radianangle);
	float cosangle = cos(radianangle);
	
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<4;i++){
		float x = vertices[i][0] - centerX;
		float y = vertices[i][1] - centerY;
		
		float newx = x*cosangle - y*sinangle;
		float newy = x*sinangle + y*cosangle;
		
		newx+=centerX;
		newy+=centerY;
		glVertex2f(newx,newy);
	}
	glEnd();
	glFlush();
}
void drawpolys(){
	glColor3f(0,1,1);
	glBegin(GL_LINE_LOOP);
		for(int i=0;i<4;i++){
			float x = vertices[i][0] - centerX;
			float y = vertices[i][1] - centerY;
		
			float newx = x*scalex;
			float newy = y*scaley;
		
			newx+=centerX;
			newy+=centerY;
			glVertex2f(newx,newy);
		}
	glEnd();
	glFlush();
}
void renderfunc(){
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	
	int choice;
	while(1){
		cout << "MENU" << endl;
		cout << "1.Translation" << endl;
		cout << "2.Rotation" << endl;
		cout << "3.Scaling" << endl;
		cout << "4.Exit" << endl;
		cin>>choice;
		if(choice==1){
			cout << "Please enter x traslation factor : ";
			cin>>transx;
			cout << endl;
			cout << "Please enter y traslation factor : ";
			cin>>transy;
			cout << endl;
			drawpolyt();
		}
		else if(choice==2){
			cout << "Please enter the angle of rotation : ";
			cin>>angle;
			cout << endl;
			drawpolyr();
		}
		else if(choice==3){
			cout << "Please enter the x scaling factor : ";
			cin>>scalex;
			cout << endl;
			cout << "Please enter the y scaling factor : ";
			cin>>scaley;
			cout << endl;
			drawpolys();
		}
		else if(choice==4){
			return;
			break;
		}
		else{
		cout << "FUCK OFF" << endl;
		}
	}
	glFlush();
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Trans");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-500, 500, -500, 500);
    glutDisplayFunc(renderfunc);

    glutMainLoop();
    return 0;
}
