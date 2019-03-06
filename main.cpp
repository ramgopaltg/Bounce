/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 *
 */
#include<windows.h>
#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

float dx1=-55.0;   //position of demon1
float dy1=34;
float dx2=0;     //position of demon2
float dy2=-11;
float x=-50.0;  //current position of ball
float y=-40.0;  //
int w=10;
int v=0;
int h=0;
int demondirection1=1;   //directiom of demons
int demondirection2=1;
float demoneye=0.0;     //angle of rotation of demon eye once dead
float r=2;              //radius of ball
float sign1=.01;
float dist=0.0;
float height=-40.0;
float lower=-40.0;
float ballspeed=.9;
float yobs1=-60;
float yobs=60;
float cx=0.0;     //position of cap
float cy=20.0;
int won=0;
int ct=0;
int coinangle=0;
float meter=24;
float cr=0.0;
float dr=0.0;
int demonlife1=1;
int demonlife2=0;
int flag1=0;
int flag2=0;
int lose;
int life=3;
int prevlife=3;
int laser=0;
int level=1;
int tx=45;
int ty=0;
int teddydirection=1;
float bullets[10][2];
int bulletindex=0;
void init()
{
	glClearColor(0, 0.7, 1,0);
	glShadeModel(GL_SMOOTH);
}
void drawbullets()
{
    for(int i=0;i<bulletindex;i++)
    {

    glPushMatrix();
    glColor3f(.5,.5,.5);
    glRotatef(180,0,0,1);

    glTranslatef((bullets[i][0]),(bullets[i][1]),0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(1,1);
    glVertex2f(3,1);
    glVertex2f(3,-1);
    glVertex2f(1,-1);
    glEnd();
    glPopMatrix();
    bullets[i][0]-=1;
    }
}
void drawevilteddy()
{

    if(ty>30)
        teddydirection=-1;
    else if(ty<-30)
        teddydirection=1;
    ty+=teddydirection;
    glPushMatrix();
    glTranslatef(tx,ty,0);
    glColor3f(0,0,0);
    glutSolidSphere(7,1000,10000);
    glTranslatef(4.6,4.6,0);
    glutSolidSphere(3.5,1000,10000);
    glTranslatef(-9.2,0,0);
    glutSolidSphere(3.6,1000,10000);
    glTranslatef(4.6,-4.6,0);

    glColor3f(0.8235,0.411,0.11);
    glutSolidSphere(6.5,1000,10000);
    glTranslatef(4.4,4.4,0);
    glutSolidSphere(3.25,1000,10000);
    glTranslatef(-8.8,0,0);
    glutSolidSphere(3.25,1000,10000);
    glTranslatef(4.4,-4.4,0);


    glTranslatef(3,2.5,0);
    glColor3f(0,0,0);
    glutSolidSphere(2,1000,10000);
    glColor3f(1,0,0);
    glutSolidSphere(1.85,1000,1000);
    glColor3f(0,0,0);
    glutSolidSphere(.5,1111,11111);
    glTranslatef(-6,0,0);
    glColor3f(0,0,0);
    glutSolidSphere(2,1000,10000);
    glColor3f(1,0,0);
    glutSolidSphere(1.85,1000,1000);
    glColor3f(0,0,0);
    glutSolidSphere(.5,1111,11111);
    glTranslatef(3,-3,0);

    glTranslatef(0,-1.5,0);
    glColor3f(0,0,0);
    glutSolidSphere(3,111,1111);
    glColor3f(.545,.271,.075);
    glutSolidSphere(2.85,111,1111);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-2,0);
    glVertex2f(2,0);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-2,0);
    glVertex2f(-1.5,-2);
    glVertex2f(-1,0);
    glColor3f(1,1,1);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(-1.75,0);
    glVertex2f(-1.5,-1.75);
    glVertex2f(-1.25,0);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(2,0);
    glVertex2f(1.5,-2);
    glVertex2f(1,0);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(1.75,0);
    glVertex2f(1.5,-1.75);
    glVertex2f(1.25,0);
    glEnd();
    glPopMatrix();
}
void drawcoins(int coinx,int coiny)
{
    glPushMatrix();
    //glRotatef(2*x+60,1,0,0);

    glRotatef(coinangle,0,1,0);
    glTranslatef(4,0,0);
    glColor3f(0,0,0);
    GLUquadricObj *disk=gluNewQuadric();
    gluDisk(disk,0,4,30,30);
    glColor3f(.8,.498039,.196078);
    glTranslatef(0,0,1);
    gluDisk(disk,0,4,30,30);

    glColor3f(1,1,1);
    glTranslatef(0,0,-1);

//    glBegin(GL_POLYGON);
 //   GLUquadricObj *obj=gluNewQuadric();
  //  gluCylinder(obj,4,4,1,30,30);
   // glEnd();

    glPopMatrix();
}
void drawcapmeter()
{
    glPushMatrix();
    glTranslatef(0,55,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-25,-1);
    glVertex2f(23,-1);
    glVertex2f(25,4);
    glVertex2f(-23,4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,55,0);
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-24,0);
    glVertex2f(22,0);
    glVertex2f(24,3);
    glVertex2f(-22,3);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,55,0);
    glColor3f(0,.7,1);
    glBegin(GL_QUADS);
    glVertex2f(meter-2,0);
    glVertex2f(22,0);
    glVertex2f(24,3);
    glVertex2f(meter,3);
    glEnd();
    glPopMatrix();
}
float distance(float x1,float y1,float x2,float y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y2-y1)*(y2-y1));
}

void drawdemon()
{
    glPushMatrix();
    if(demonlife1==1)
    {

    glPushMatrix();
    glTranslatef(dx1,dy1-3,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);           //horns
    glVertex2f(0,0);
    glVertex2f(r,0);
    glVertex2f(r+3,5);
    glVertex2f(0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(dx1-4,dy1-3,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);          //horns
    glVertex2f(0,0);
    glVertex2f(-r,0);
    glVertex2f(-r-3,5);
    glVertex2f(0,0);
    glEnd();
    glPopMatrix();
    }
	glPushMatrix();
		//glTranslatef(-55,-12,0);
		glTranslatef(dx1,dy1,0);
        glColor3f(1,0,0);
		glTranslatef(-2,-5,0);
		glutSolidSphere(2*r+.1,100,1000);            //red ring
		glColor4f(0,0,0,.5);
		glutSolidSphere(2*r,100,1000);             //black ball

        glTranslatef(-2,.5,0);
        glPushMatrix();

        glColor3f(0,0,0);
		glutSolidSphere(1.7,100,1000);             //eye black 1
        glColor3f(1,1,1);
        glutSolidSphere(1.3,100,1000);           //eye white part1
        glPushMatrix();

        if(demonlife1==0)
          {
            glRotatef(coinangle*10,0,0,1);
            glTranslatef(.4,.4,0);
          }
        else if(demondirection1==1)
            glTranslatef(.4,0,0);
        else if(demondirection1==-1)
            glTranslatef(-.4,0,0);
        glColor3f(1,0,0);
        glutSolidSphere(.5,100,1000);

        glPopMatrix();
        glPopMatrix();

        glColor3f(0,0,0);
		glTranslatef(4,0,0);//tyres
		glutSolidSphere(1.7,100,1000);           //eye black 2
        glColor3f(1,1,1);
        glutSolidSphere(1.3,100,1000);

        glPushMatrix();
        if(demonlife1==0)
                  {
            glRotatef(-coinangle*10,0,0,1);
            glTranslatef(.4,.4,0);
          }
        else if(demondirection1==1)
            glTranslatef(.4,0,0);
        else if(demondirection1==-1)
            glTranslatef(-.4,0,0);
        glColor3f(1,0,0);
        glutSolidSphere(.5,100,1000);
/*        if(demondirection==1)
            glTranslatef(.4,0,0);
        else if(demondirection==-1)
            glTranslatef(-.4,0,0);

        glColor3f(1,0,0);
        if(demonlife==1)
		glutSolidSphere(.5,100,1000);*/
        glPopMatrix();
		glPopMatrix();
		glPopMatrix();

            if(level!=1)
    {
    glPushMatrix();
    //glTranslatef(55,-45,0);
    glPushMatrix();
    glTranslatef(dx2,dy2-3,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);           //horns
    glVertex2f(0,0);
    glVertex2f(r,0);
    glVertex2f(r+3,5);
    glVertex2f(0,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(dx2-4,dy2-3,0);
    glColor3f(0,0,0);
    glBegin(GL_QUADS);          //horns
    glVertex2f(0,0);
    glVertex2f(-r,0);
    glVertex2f(-r-3,5);
    glVertex2f(0,0);
    glEnd();
    glPopMatrix();

	glPushMatrix();
		//glTranslatef(-55,-12,0);
		glTranslatef(dx2,dy2,0);
        glColor3f(1,0,0);
		glTranslatef(-2,-5,0);
		glPushMatrix();
		glColor3f(1,0,0);
		glBegin(GL_LINES);
		glVertex2f(0,0);
		glVertex2f(laser,0);
		glEnd();
		glPopMatrix();
		glutSolidSphere(2*r+.1,100,1000);            //red ring
		glColor4f(0,0,0,.5);
		glutSolidSphere(2*r,100,1000);             //black ball

        glTranslatef(-2,.5,0);
        glPushMatrix();

        glColor3f(0,0,0);
		glutSolidSphere(1.7,100,1000);             //eye black 1
        glColor3f(1,1,1);
        glutSolidSphere(1.3,100,1000);           //eye white part1
        glPushMatrix();

        if(demonlife2==0)
          {
            glRotatef(coinangle*10,0,0,1);
            glTranslatef(.4,.4,0);
          }
        else if(demondirection2==1)
            glTranslatef(.4,0,0);
        else if(demondirection2==-1)
            glTranslatef(-.4,0,0);
        glColor3f(1,0,0);
        glutSolidSphere(.5,100,1000);

        glPopMatrix();
        glPopMatrix();

        glColor3f(0,0,0);
		glTranslatef(4,0,0);//tyres
		glutSolidSphere(1.7,100,1000);           //eye black 2
        glColor3f(1,1,1);
        glutSolidSphere(1.3,100,1000);

        glPushMatrix();
        if(demonlife2==0)
                  {
            glRotatef(-coinangle*10,0,0,1);
            glTranslatef(.4,.4,0);
          }
        else if(demondirection2==1)
            glTranslatef(.4,0,0);
        else if(demondirection2==-1)
            glTranslatef(-.4,0,0);
        glColor3f(1,0,0);
        glutSolidSphere(.5,100,1000);
/*        if(demondirection==1)
            glTranslatef(.4,0,0);
        else if(demondirection==-1)
            glTranslatef(-.4,0,0);

        glColor3f(1,0,0);
        if(demonlife==1)
		glutSolidSphere(.5,100,1000);*/
        glPopMatrix();
		glPopMatrix();
		glPopMatrix();
    }




}
void takecap()
{
    if(demonlife1==0 && distance(x,y,cx,cy)<5)
    {
        ct=1;
    }
}
void kill()
{
    if(distance(x,y,dx1,dy1)<5 && y-2>dy1)
   {

    demonlife1=0;
   }

       if(distance(x,y,dx2,dy2)<5 && y-2>dy2)
   {

    demonlife2=0;
   }
}
void lifereduce()
{
    if(life==0)
        {
//        GLvoid *font_style1=GL_BITMAP_TIMES_ROMAN_24;
  //      glRasterPos3f(0,0,0);
    //    glutBitmapCharacter(font_style1,'a');
        }
    else if(life<prevlife && life>0)
    {
        prevlife=life;
        x=-50;
        y=-40;
        lower=y;
    }
}
void drawcap()
{


    glPushMatrix();
    if(ct==1)
    glTranslatef(x-1,y+2,0);
    else
    glTranslatef(cx,cy,0);
    glColor3f(0,0,0);
    glRotatef(-30,1,0,0);
    glRotatef(cr,0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(-5,0,1);
    glVertex3f(-5,0,-1);
    glVertex3f(0,0,0);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(5,0,1);
    glVertex3f(5,0,-1);
    glVertex3f(0,0,0);
    glEnd();
    glPopMatrix();
}
void drawlife()
{
    glPushMatrix();
    glTranslatef(-55,55,0);
    if(life >2)
{
    glPushMatrix();
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,-3);
    glVertex2f(-3,0);
    glVertex2f(0,3);
    glVertex2f(3,0);
    glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5,1.5,0);
	glutSolidSphere(2,100,100);
	glTranslatef(-3.0,0,0);
	glutSolidSphere(2,100,100);
    glPopMatrix();
    //glTranslatef(15,0,0);

	glPushMatrix();
	glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,-2.5);
    glVertex2f(-2.5,0);
    glVertex2f(0,2.5);
    glVertex2f(2.5,0);
    glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(1.25,1.25,0);
	glutSolidSphere(1.75,100,100);
	glTranslatef(-2.5,0,0);
	glutSolidSphere(1.75,100,100);
    glPopMatrix();
    glTranslatef(7.5,0,0);
    }
    if(life>1)
 {
    glPushMatrix();
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,-3);
    glVertex2f(-3,0);
    glVertex2f(0,3);
    glVertex2f(3,0);
    glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5,1.5,0);
	glutSolidSphere(2,100,100);
	glTranslatef(-3.0,0,0);
	glutSolidSphere(2,100,100);
    glPopMatrix();
    //glTranslatef(15,0,0);

	glPushMatrix();
	glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,-2.5);
    glVertex2f(-2.5,0);
    glVertex2f(0,2.5);
    glVertex2f(2.5,0);
    glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(1.25,1.25,0);
	glutSolidSphere(1.75,100,100);
	glTranslatef(-2.5,0,0);
	glutSolidSphere(1.75,100,100);
    glPopMatrix();
    glTranslatef(7.5,0,0);
    }
    if(life>0)
    {
    glPushMatrix();
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,-3);
    glVertex2f(-3,0);
    glVertex2f(0,3);
    glVertex2f(3,0);
    glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5,1.5,0);
	glutSolidSphere(2,100,100);
	glTranslatef(-3.0,0,0);
	glutSolidSphere(2,100,100);
    glPopMatrix();
    //glTranslatef(15,0,0);

	glPushMatrix();
	glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,-2.5);
    glVertex2f(-2.5,0);
    glVertex2f(0,2.5);
    glVertex2f(2.5,0);
    glEnd();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(1.25,1.25,0);
	glutSolidSphere(1.75,100,100);
	glTranslatef(-2.5,0,0);
	glutSolidSphere(1.75,100,100);
    glPopMatrix();
    glTranslatef(7.5,0,0);
    }
    glPopMatrix();
}

void check(void)
{
    if(x+r>0 && y<=-25-r)
        yobs=-25-r;
        else yobs=60;
    if(distance(x,y,dx1,dy1)<2 && y-1<=dy1 && demonlife1==1)
    {
        life--;
        flag1=0;
        flag2=0;
        lifereduce();
    }
    if(distance(x,y,dx2,dy2)<2 && y-1<=dy2 && demonlife2==1)
    {
        life--;
        flag1=0;
        flag2=0;
        lifereduce();
    }
    if(demondirection2==1 && demonlife2==1)
    {
        if(x<laser && x>dx2 && ((y+r)>=dy2 && (y-r)<=dy2))
        {
        life--;
        flag1=0;
        flag2=0;
        lifereduce();
        }
    }
        if(demondirection2==-1 && demonlife2==1)
    {
        if(x>laser && x<dx2 && ((y+2)>=dy2 && (y-2)<=dy2))
        {
        life--;
        flag1=0;
        flag2=0;
        lifereduce();
        }
    }
    if(x>40.0 && y>40.0)
    {
        x=-50;
        y=-40;
        life=3;
        height=-40;
        lower=y;
        prevlife=3;
        demonlife1=1;
        demonlife2=1;
        dr=0;
        ct=0;
        meter=24;
        cx=0.0;
        cy=20.0;
        level++;


    }
    if(y<-60 && x>0)
      {
          life--;
          flag1=0;
          flag2=0;
          lifereduce();
      }
    else if(x>=0 && x<30)
    {
        if(y>-11.0)
        {
            lower=-10;
        }
        else if(y != -10.0)
        {
            lower=-100;
        }
    }else if(x>=35)
            lower=-100;
    else if(x>-20)
    {
        if(y>=4)
            lower=15;
        else
            lower=-40;
        }else
        {
            if(y>=24)
                lower=35;
            else
                lower=-40;
        }
}
void moveball(void)
{
    takecap();
    kill();

    if(demonlife1==0)
    {
        if(demoneye>360)
            demoneye=0;
        else
            demoneye++;
    }

        check();
        if(height>yobs)
            height=yobs;
        if(flag1==1)
        {
            y=y+ballspeed;
            if(y>height)
                flag1=-1;
        }
        else if(flag1==-1)
        {
        if(y<=lower)
                flag1=0;
            else
            y=y-ballspeed;

        }
        else if((y)>lower)
        {
            cout<<endl<<"y"<<y<<" lower  "<<lower<<endl;
            y-=ballspeed;
        }

        if(flag2==1)
        {

            if(x<dist)
                x=x+ballspeed;
            else
                flag2=0;
        }
        if(flag2==-1)
        {
            if(x>dist)
                x=x-ballspeed;
            else
                flag2=0;

        }

		glutPostRedisplay();


/*	angle=angle+1.0;
	if(angle>360.0)
	angle=angle-360.0;
	move++;
	glutPostRedisplay(); */
}
void door()
{
    glPushMatrix();
    glTranslatef(40,40,0);


    glBegin(GL_QUADS);	//h1
	glColor3f(0,0,0);
	glVertex2f(-1,-1);
	glVertex2f(20,-1);
	glVertex2f(20,20);
	glVertex2f(-1,20);
	glEnd();

    glColor3f(0,0,1);
    glBegin(GL_QUADS);
	glVertex2f(0,0);
	glVertex2f(20,0);
	glVertex2f(20,20);
	glVertex2f(0,20);
	glEnd();

    glPushMatrix();
    glRotatef(-3,1,0,0);
    glRotatef(dr,0,1,0);
    glBegin(GL_QUADS);	//h1
	glColor3f(0,0,0);
	glVertex2f(10,20);
	glVertex2f(0,20);
	glVertex2f(0,0);
	glVertex2f(10,0);
	glEnd();

    glBegin(GL_QUADS);	//h1
	glColor3f(0.8235,0.411,0.11);
	glVertex2f(9,19);
	glVertex2f(1,19);
	glVertex2f(1,1);
	glVertex2f(9,1);
	glEnd();
	glPopMatrix();

    glPushMatrix();
    glTranslatef(20,0,0);
    glRotatef(-3,1,0,0);
    glRotatef(-dr,0,1,0);
    glBegin(GL_QUADS);	//h1
	glColor3f(0,0,0);
	glVertex2f(-10,20);
	glVertex2f(0,20);
	glVertex2f(0,0);
	glVertex2f(-10,0);
	glEnd();

    glBegin(GL_QUADS);	//h1
	glColor3f(0.8235,0.411,0.11);
	glVertex2f(-9,19);
	glVertex2f(-1,19);
	glVertex2f(-1,1);
	glVertex2f(-9,1);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void ball()
{
	glPushMatrix();
		glTranslatef(x,y,0);
        glColor3f(0,0,0);
		glTranslatef(-2,-5,0);
		glutSolidSphere(2*r+1,100,1000);            //black ring
		glColor4f(1,0,0,.5);
		glutSolidSphere(2*r,100,1000);             //red ball

        glTranslatef(-2,.5,0);
        glColor3f(0,0,0);
		glutSolidSphere(1.7,100,1000);             //eye black 1
        glColor3f(1,1,1);
        glutSolidSphere(1.3,100,1000);

        glPushMatrix();

        if(flag2==1)
            glTranslatef(.4,0,0);
        else if(flag2==-1)
            glTranslatef(-.4,0,0);

        if(flag1==1)
            glTranslatef(0,.4,0);
        glColor3f(0,0,0);
		glutSolidSphere(.5,100,1000);
        glPopMatrix();

        glColor3f(0,0,0);
		glTranslatef(4,0,0);//tyres
		glutSolidSphere(1.7,100,1000);           //eye black 2
        glColor3f(1,1,1);
        glutSolidSphere(1.3,100,1000);

        glPushMatrix();
        if(flag2==1)
            glTranslatef(.4,0,0);
        else if(flag2==-1)
            glTranslatef(-.4,0,0);

        if(flag1==1)
            glTranslatef(0,.4,0);

        glColor3f(0,0,0);
		glutSolidSphere(.5,100,1000);
        glPopMatrix();
		glPopMatrix();


}


void display()
{
    if(demondirection2==1 && laser<0)
        laser=0;
    if(demondirection2==1 && laser>=0)
        laser++;
     if(demondirection2==-1 && laser>0)
        laser=0;
    if(demondirection2==-1 && laser<=0)
        laser--;
    if(coinangle>360)
        coinangle=0;
    else
        coinangle++;
        if(ct==1 && meter>-22)
            meter-=.5;
        //if(meter==-22)
            //ct=0;

        if(dr<45 && demonlife1==0)
        dr+=1;

    //glutPostRedisplay();
        if(ct)
            cr+=10;
        if(demondirection1==1 && demonlife1==1)
    {
        if(dx1>-20)
            demondirection1=-1;
        else
            dx1+=.5;
    }
    else if(demonlife1==1)
    {
        if(dx1<-55)
            demondirection1=1;
        else
            dx1-=.5;
    }

        if(demondirection2==1 && demonlife2==1)
    {
        if(dx2>35)
            demondirection2=-1;
        else
            dx2+=.5;
    }
    else if(demonlife2==1)
    {
        if(dx2<5)
            demondirection2=1;
        else
            dx2-=.5;
    }

glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
	glBegin(GL_QUADS);	//h1
	glColor3f(0,1,0);
	glVertex2f(0,-20);
	glVertex2f(35,-20);
	glVertex2f(35,-25);
	glVertex2f(0,-25);
	glEnd();
    glTranslatef(0,5,0);
    glBegin(GL_QUADS);	//h1
	glColor3f(0,1,0);
	glVertex2f(-60,-60);
	glVertex2f(-60,-55);
	glVertex2f(0,-55);
	glVertex2f(0,-60);
	glEnd();
    glTranslatef(0,-5,0);
	glBegin(GL_QUADS);	//h1
	glColor3f(0,1,0);
	glVertex2f(0,0);
	glVertex2f(-20,0);
	glVertex2f(-20,5);
	glVertex2f(0,5);
	glEnd();

	glBegin(GL_QUADS);	//h1
	glColor3f(0,1,0);
	glVertex2f(-60,20);
	glVertex2f(-20,20);
	glVertex2f(-20,25);
	glVertex2f(-60,25);
	glEnd();
	glPopMatrix();


    if(won==1)
    {

        level++;
    }
    drawlife();
	ball();
	door();

	//Sleep(30);
		drawcap();
		drawdemon();
		drawcapmeter();
		drawbullets();
		//drawcoins(0,0);
//        drawevilteddy();
	glutSwapBuffers();
}



void reshape(int w, int h)
{
glViewport(0, 0, (GLsizei)w, (GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-60.0,60.0,-60.0,60.0,-1.0,20.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}


void keyboard(unsigned char key, int x1, int y1)
{
  switch (key)
  {
    case 27:
		exit(0);
      break;
    case 'w':
        {
            if(ct==1)
            {
                check();
                glutIdleFunc(display);
                y++;
                //cr+=90;
                glutPostRedisplay();
            }
            else if(flag1==0)
           {
            height=lower+35;
            flag1=1;
            glutIdleFunc(moveball);
			moveball();
			glutPostRedisplay();
           }
			break;
        }
    case 'd':
        {
            if(ct==1)
            {
                check();
                glutIdleFunc(display);
                x++;
                //cr+=90;
                glutPostRedisplay();
            }
            else {
            flag2=1;
            dist=x+5.0;
            glutIdleFunc(moveball);
			moveball();
			glutPostRedisplay();
            }
			break;
        }
    case 'a':
        {
            if(ct==1)
            {
                check();
                glutIdleFunc(display);
                x--;
                //cr+=90;
                glutPostRedisplay();
            }
            else {
            flag2=-1;
            dist=x-5.0;
            glutIdleFunc(moveball);
			moveball();
			glutPostRedisplay();
            }
			break;
        }
    case 'b':
        {
            bulletindex++;
            bullets[bulletindex-1][0]=-1*x;
            bullets[bulletindex-1][1]=-1*y;
            break;
        }
}

}
/*void mouse(int button, int state, int x, int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
		    cout<<distance(4.0,6.0,28.0,13.0);
            glutIdleFunc(opendoor);
            opendoor();
            glutPostRedisplay();
		}
	break;
	case GLUT_RIGHT_BUTTON:
           {cr=0;
			glutIdleFunc(NULL);}
			break;
	}
} */
int main(int argc, char* argv[])
{
    bulletindex=0;
    for(int i=0;i<10;i++)
    {
        bullets[i][0]=0.0;
        bullets[i][1]=0.0;
    }
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
glEnable(GL_BLEND);
glutInitWindowSize(900,900);
glutInitWindowPosition(0,0);
glutCreateWindow(argv[0]);
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
//glutMouseFunc(mouse);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}
