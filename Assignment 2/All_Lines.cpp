#include <GL/freeglut.h>
#include <GL/gl.h>


void displayfunc(int x,int y,int i){
	glColor3f(0,1,0);
		glBegin(GL_POINTS);
			glVertex2f(x,y);
		
		glEnd();
}

void displaydottedfunc(int x,int y,int i){
	if(i%4!=0){
	   return;
	}
	glColor3f(0,1,0);
		glBegin(GL_POINTS);
			glVertex2f(x,y);
		
		glEnd();
}

void displaydashedfunc(int x,int y,int i){
	if(((i/4)&1)){
	   return;
	}
	glColor3f(0,1,0);
		glBegin(GL_POINTS);
			glVertex2f(x,y);
		
		glEnd();
}

void displaydarkfunc(int x,int y,int i){
	
	glColor3f(1,1,1);
	glPointSize(7);
		glBegin(GL_POINTS);
			glVertex2f(x,y);
		
		glEnd();
}


void simpleline(float x, float y, float x1,float y1,int choice){
	
    
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
    
    if(choice==0){
    	for(int i=0;i<=steps;i++){
    	displayfunc(x,y,i);
    	x+=xincre;
    	y+=yincre;
   	 }
    }
    else if(choice==1){
    	for(int i=0;i<=steps;i++){
    	displaydarkfunc(x,y,i);
    	x+=xincre;
    	y+=yincre;
   	 }
    }
    else{
    	for(int i=0;i<=steps;i++){
    	displaydashedfunc(x,y,i);
    	x+=xincre;
    	y+=yincre;
    	}
    }
    
    	
    glFlush();

}
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0,800,0,800);
   /* glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();*/
    
    simpleline(1,1,1,799,1);
    simpleline(1,1,799,1,1);
    simpleline(1,799,799,799,1);
    simpleline(799,799,799,1,1);
    int cnt =0;
    bool flag =1;
    for(int i=0;i<=700;i+=100){
    	simpleline(i,1,i,799,1);
    	if(flag){
    		for(int j=0;j<=8;j+=2){
    			
    			for(int k = i+1;k<= i+99;k++){
    				simpleline(k,j*100,k,j*100 +100,1);
    			}
    		}
    		flag =0;
    	}
    	else{
    		flag =1;
    		for(int j=1;j<=8;j+=2){
    			for(int k = i+1;k<= i+99;k++){
    				simpleline(k,j*100,k,j*100 +100,1);
    			}
    		}
    	}
    }
    for(int i=100;i<=799;i+=100){
    	simpleline(1,i,799,i,1);
    }
    
    
    
    
    
    glFlush();
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}

