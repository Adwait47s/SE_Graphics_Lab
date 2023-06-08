#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>
#define radian (3.14/180)


void drawcurve(float xa , float ya , float xb , float yb , int n){

    float xc ,yc ,xd ,yd , midx ,midy;

    xc = (2*xa + xb )/3;
    yc = (2*ya + yb) / 3;
    xd = (2*xb + xa) / 3;
    yd = (2*yb + ya)/3;

    midx = xc + ((xd - xc)*cos(60*radian)) + ((yd-yc)*sin(60*radian));
    midy = yc - ((xd-xc)*sin(60*radian)) + ((yd-yc)*cos(60*radian));

    if(n > 0){

        drawcurve(xa,ya,xc,yc,n-1);
        drawcurve(xc,yc,midx,midy,n-1);
        drawcurve(midx,midy,xd,yd,n-1);
        drawcurve(xd,yd,xb,yb,n-1);

    }
    else{

        glVertex2f(xa,ya);
        glVertex2f(xc,yc);

        glVertex2f(xc,yc);
        glVertex2f(midx,midy);

        glVertex2f(midx,midy);
        glVertex2f(xd,yd);

        glVertex2f(xd,yd);
        glVertex2f(xb,yb);
    }
}


void myfunc()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1,1,1);
 glBegin(GL_LINES);
 koch(100,100,200,100,02);
 koch(200,100,150,200,02);
 koch(150,200,100,100,02);
 
 glEnd();
 
 glFlush();
 
}
int main(int argc , char ** argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(500,500);
 glutInitWindowPosition(400,150);
 glutInitDisplayMode(GLUT_SINGLE);
 glutCreateWindow("KOCH CURVE");
 gluOrtho2D(0,500,0,500);
 glClearColor(0,0,0,0);
 glutDisplayFunc(myfunc);
 glutMainLoop();
 
 return 0;
 
}
