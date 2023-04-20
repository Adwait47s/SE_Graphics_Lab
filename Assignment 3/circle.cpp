#include<GL/glut.h>
#include<stdio.h>
int xc,yc,radius;
void input(){
  printf("enter xc ,yc");
  scanf("%d%d",&xc,&yc);
  printf("enter radius");
  scanf("%d",&radius);
  xc+=320;
  yc+=240;
  }
void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}
void circle(int r)
{
  int x=0,y=r;
  float pk=3-2*r;
  plot_point(0,0);
  plot_point(x,y);
  while(x < y)
  {
    if(pk<0){
      x++;
      plot_point(x,y);
      pk = pk + 4*x -1;
    }
    else{
      x++;
      y--;
      plot_point(x,y);
      pk = pk + 4*x - 4*y +10;
    }
  }
  glFlush();
}
void dda(float x1, float y1, float x2, float y2)
{
  float dx = x2 - x1, x, y;
  float dy = y2 - y1;
  float steps;
  if (abs(dx) > abs(dy))
  {
    steps = abs(dx);
  }
  else
  {
    steps = abs(dy);
  }
  float x_in = dx / steps;
  float y_in = dy / steps;
  x = x1;
  y = y1;
  glBegin(GL_POINTS);
  glVertex2i(abs(x), abs(y));
  glEnd();
  int m = 0;
  for (int i = 1; i < steps; i++)
  {
      x = x + abs(x_in);
      y = y + abs(y_in);
      m += 1;
      glBegin(GL_POINTS);
      glVertex2i(abs(x), abs(y));
      glEnd();
    
  }
  glFlush();
}
void plotline(){
   glBegin(GL_POINTS);
  glVertex2i(340,5);
  glEnd();
  glFlush();

}
void Init()
{
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{ 
  input();
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(640,480);
  glutCreateWindow("circle");
  Init();
  glClear(GL_COLOR_BUFFER_BIT);
  //plotline();
  dda(0,240,680,240);
  circle(radius);
  glutMainLoop();
}