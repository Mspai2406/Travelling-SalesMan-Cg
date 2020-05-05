#include<windows.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include<gl/glut.h>
#include<math.h>
float cloud_move=0;
float cloud1_move=0;
void roads()
{
     glBegin(GL_LINES);
    glVertex3f(0,20,0.0);//starting-up
    glVertex3f(10,20,0);
    glVertex3f(0,18,0.0);//starting-down
    glVertex3f(10,18,0);
    glVertex3f(10,20,0.0);//first-up
    glVertex3f(15,30,0);
    //glVertex3f(11,19,0.0);//first-down
    //glVertex3f(15,28,0);
    glVertex3f(15,30,0.0);//1 to 2
    glVertex3f(27,30,0);
    glVertex3f(27,30,0.0);//2 to 4
    glVertex3f(27,10,0);
    glVertex3f(15,10,0.0);//3 to 4
    glVertex3f(27,10,0);
    glVertex3f(10,18,0.0);//start to 3
    glVertex3f(15,10,0);
    //glVertex3f(11,19,0.0);//start to 3
    //glVertex3f(15,12,0);
    //glVertex3f(15,28,0.0);//1 to 3
    //glVertex3f(15,12,0);
    glVertex3f(15,0,0.0);//3 to ground
    glVertex3f(15,10,0);
    glVertex3f(27,10,0.0);//4 to ground
    glVertex3f(27,0,0);

    glEnd();
}
void surroundings()
{
   glBegin(GL_TRIANGLES);
    glColor3f(0,.8,.3);
    glVertex3f(16,28,0.0);//TRIANGLE 2
    glVertex3f(25,28,0);
    glVertex3f(16,12,0.0);
    glVertex3f(26,28,0.0);//triangle 3
    glVertex3f(26,12,0);
    glVertex3f(17,12,0.0);
    glVertex3f(15,28,0.0);//triangle 1
    glVertex3f(11,19,0.0);
    glVertex3f(15,12,0);

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,.8,.3);//bottom square
    glVertex3f(16,0,0.0);
    glVertex3f(16,10,0.0);
    glVertex3f(26,10,0.0);
    glVertex3f(26,0,0);
    glVertex3f(27,0,0.0);//bottom right corner
    glVertex3f(27,18,0);
    glVertex3f(45,18,0.0);
    glVertex3f(45,0,0);
    glVertex3f(27,20,0.0);//top right corner
    glVertex3f(27,40,0);
    glVertex3f(45,40,0.0);
    glVertex3f(45,20,0);
    glVertex3f(15,30,0.0);//top-middle
    glVertex3f(15,35,0.0);
    glVertex3f(27,35,0.0);
    glVertex3f(27,30,0);

    glVertex3f(0,0,0.0);//bottom left
    glVertex3f(0,18,0.0);
    glVertex3f(10,18,0.0);
    glVertex3f(10,0,0);

    glVertex3f(10,0,0);
    glVertex3f(10,18,0.0);//bottom left
    glVertex3f(15,10,0);
    glVertex3f(15,0,0);



    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0,.8,.3);//top-left
    glVertex3f(0,20,0.0);
    glVertex3f(0,35,0.0);
    glVertex3f(15,35,0.0);
    glVertex3f(15,30,0);
    //glVertex3f(15,30,0);
    glVertex3f(10,20,0);


    glEnd();

}


void man()
{


    glBegin(GL_QUADS);//body
    glColor3f(1,.2,1);
    glVertex3f(8,12,0.0);
    glVertex3f(8,15.5,0.0);
    glVertex3f(9.5,15.5,0);
    glVertex3f(9.5,12,0);
    glEnd();
    glBegin(GL_QUADS);//left leg
    glColor3f(0,0,0);
    glVertex3f(8.4,10,0.0);
    glVertex3f(8.4,12,0.0);
    glVertex3f(8.6,12,0);
    glVertex3f(8.6,10,0);
    glEnd();
     glBegin(GL_QUADS);//right leg
    glColor3f(0,0,0);
    glVertex3f(8.9,10,0.0);
    glVertex3f(8.9,12,0.0);
    glVertex3f(9.1,12,0);
    glVertex3f(9.1,10,0);
    glEnd();

    glBegin(GL_POLYGON);//head
    glColor3f(0,0,0);
    for(int i=0;i<360;i++)
    {
        float theta=i*3.142/180;
        glVertex2f(8.75+.5*cos(theta),16+0.5*sin(theta));
    }
    glEnd();


}
void houses()
{
    //source
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
     glVertex3f(8,21,0.0);
    glVertex3f(8,24,0.0);
    glVertex3f(9.5,24,0);
    glVertex3f(9.5,21,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
     glVertex3f(7.5,24,0.0);
     glVertex3f(7.5,25.5,0.0);
    glVertex3f(10,25.5,0.0);
    glVertex3f(10,24,0);
    glEnd();
//node 1
    glBegin(GL_QUADS);
    glColor3f(0,1,1);
     glVertex3f(10,30,0.0);
    glVertex3f(10,33,0.0);
    glVertex3f(12,33,0);
    glVertex3f(12,30,0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(.7,0.5,0);
     glVertex3f(10,33,0.0);
    glVertex3f(11,34.5,0.0);
    glVertex3f(12,33,0);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(1,.5,0);
     glVertex3f(11,34.5,0.0);
    glVertex3f(13.5,34.5,0.0);
    glVertex3f(14.5,33,0);
    glVertex3f(12,33,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.8,.7,0.2);
     glVertex3f(12,33,0.0);
    glVertex3f(14.5,33,0.0);
    glVertex3f(14.5,30,0);
    glVertex3f(12,30,0);
    glEnd();
    //node 2
    glBegin(GL_QUADS);
    glColor3f(.7,0,.5);
     glVertex3f(27.5,28,0.0);
    glVertex3f(27.5,31,0.0);
    glVertex3f(29,31,0);
    glVertex3f(29,28,0);
    glEnd();
    glBegin(GL_QUADS);//roof
    glColor3f(.7,0.4,.3);
     glVertex3f(28.25,32.5,0.0);
    glVertex3f(31.25,32.5,0.0);
    glVertex3f(32,31,0);
    glVertex3f(29,31,0);
    glEnd();
    glBegin(GL_QUADS);//ground
    glColor3f(0,1,1);
     glVertex3f(29,31,0.0);
    glVertex3f(32,31,0.0);
    glVertex3f(32,28,0);
    glVertex3f(29,28,0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
     glVertex3f(27.5,31,0.0);
    glVertex3f(28.25,32.5,0.0);
    glVertex3f(29,31,0);
    glEnd();
    //node 3
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
     glVertex3f(12.5,7,0.0);
    glVertex3f(12.5,10,0.0);
    glVertex3f(14,10,0);
    glVertex3f(14,7,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,.4,.5);
     glVertex3f(12.25,10,0.0);
    glVertex3f(12.25,11,0.0);
     glVertex3f(14.25,11,0.0);
    glVertex3f(14.25,10,0);
    glEnd();
    //node 4
    glBegin(GL_QUADS);
    glColor3f(.5,.3,.9);
     glVertex3f(27.5,10,0.0);
    glVertex3f(27.5,13,0.0);
    glVertex3f(29,13,0);
    glVertex3f(29,10,0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,.5);
     glVertex3f(27.5,13,0.0);
    glVertex3f(28.25,14.5,0.0);
    glVertex3f(29,13,0);
    glEnd();
     glBegin(GL_QUADS);//roof
    glColor3f(.5,.2,.7);
     glVertex3f(28.25,14.5,0.0);
    glVertex3f(30.5,14.5,0.0);
    glVertex3f(31.5,13,0);
    glVertex3f(29,13,0);
    glEnd();
     glBegin(GL_QUADS);//ground
    glColor3f(1,1,0);
     glVertex3f(29,13,0.0);
    glVertex3f(31.5,13,0.0);
    glVertex3f(31.5,10,0);
    glVertex3f(29,10,0);
    glEnd();


    //last1
    glBegin(GL_QUADS);//ground
    glColor3f(.5,.3,0);
     glVertex3f(33.5,20.5,0.0);
    glVertex3f(33.5,23.5,0.0);
    glVertex3f(35.5,23.5,0);
    glVertex3f(35.5,20.5,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.2,0,.8);
     glVertex3f(33.5,23.5,0.0);
    glVertex3f(33.5,24.25,0.0);
    glVertex3f(35.5,24.25,0.0);
    glVertex3f(35.5,23.5,0);
    glEnd();
    glBegin(GL_QUADS);//first floor
    glColor3f(.5,.3,0);
     glVertex3f(33.5,24.25,0.0);
    glVertex3f(33.5,27,0.0);
    glVertex3f(35.5,27,0);
    glVertex3f(35.5,24.25,0);
    glEnd();
    //last2
    glBegin(GL_QUADS);//ground
    glColor3f(.8,.5,0.4);
    glVertex3f(36,20.5,0.0);
    glVertex3f(36,23.5,0.0);
    glVertex3f(37.5,23.5,0);
    glVertex3f(37.5,20.5,0);
    glEnd();
    glBegin(GL_QUADS);//roof
    glColor3f(1,0,0.5);
     glVertex3f(36,23.5,0.0);
    glVertex3f(36,25,0.0);
    glVertex3f(37.5,25,0);
    glVertex3f(37.5,23.5,0);
    glEnd();
}
void sky()
{
    glBegin(GL_QUADS);
    glColor3f(0.110,.545,1);//sky
    glVertex3f(0,35,0.0);
    glVertex3f(0,40,0.0);
    glVertex3f(45,40,0.0);
    glVertex3f(45,35,0);

    glEnd();
}
void whiteroadmarks()
{
     //roads white line
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    //glLineWidth(100);
    glVertex3f(0,19,0.0);//starting
    glVertex3f(2,19,0);
    glVertex3f(3,19,0.0);//
    glVertex3f(5,19,0);
    glVertex3f(6,19,0.0);//starting
    glVertex3f(8,19,0);
    glVertex3f(9,19,0.0);//
    glVertex3f(10,19,0);

    glVertex3f(11.25,21,0.0);//source to 1
    glVertex3f(12.5,24,0);
    glVertex3f(13,25,0.0);//source to 1
    glVertex3f(14.5,28,0);

    glVertex3f(15.5,29,0.0);//1 to 2
    glVertex3f(17.5,29,0);
    glVertex3f(18.5,29,0.0);//1 to 2
    glVertex3f(20.5,29,0);
    glVertex3f(21.5,29,0.0);//1 to 2
    glVertex3f(23.5,29,0);
    glVertex3f(24.5,29,0.0);//1 to 2
    glVertex3f(26.5,29,0);

    glVertex3f(26.5,28,0.0);//2 to 4
    glVertex3f(26.5,26,0);
     glVertex3f(26.5,25,0.0);//2 to 4
    glVertex3f(26.5,22,0);
     glVertex3f(26.5,21,0.0);//2 to 4
    glVertex3f(26.5,19,0);
     glVertex3f(26.5,18,0.0);//2 to 4
    glVertex3f(26.5,15,0);
     glVertex3f(26.5,14,0.0);//2 to 4
    glVertex3f(26.5,12,0);

    glVertex3f(15.5,11,0.0);//3 to 4
    glVertex3f(17.5,11,0);
    glVertex3f(18,11,0.0);//3 to 4
    glVertex3f(20,11,0);
    glVertex3f(20.5,11,0.0);//3 to 4
    glVertex3f(22.5,11,0);
    glVertex3f(23,11,0.0);//3 to 4
    glVertex3f(25,11,0);
    glVertex3f(25.5,11,0.0);//3 to 4
    glVertex3f(26.8,11,0);

   glVertex3f(11.25,17.25,0.0);//start to 3
    glVertex3f(12.5,15,0);
    glVertex3f(13,14.5,0.0);//start to 3
    glVertex3f(14.75,11.5,0);
    glVertex3f(15.5,28,0.0);//1 to 3
    glVertex3f(15.5,27,0);
    glVertex3f(15.5,26,0.0);//1 to 3
    glVertex3f(15.5,24,0);
    glVertex3f(15.5,23,0.0);//1 to 3
    glVertex3f(15.5,21,0);
    glVertex3f(15.5,20,0.0);//1 to 3
    glVertex3f(15.5,18,0);
    glVertex3f(15.5,17,0.0);//1 to 3
    glVertex3f(15.5,15,0);
    glVertex3f(15.5,14,0.0);//1 to 3
    glVertex3f(15.5,12,0);
    glVertex3f(15.5,10,0.0);//3 to ground
    glVertex3f(15.5,8,0);
     glVertex3f(15.5,7,0.0);//3 to ground
    glVertex3f(15.5,5,0);
     glVertex3f(15.5,4,0.0);//3 to ground
    glVertex3f(15.5,2,0);
    glVertex3f(26.5,10,0.0);//4 to ground
    glVertex3f(26.5,8,0);
    glVertex3f(26.5,7,0.0);//4 to ground
    glVertex3f(26.5,5,0);
    glVertex3f(26.5,4,0.0);//4 to ground
    glVertex3f(26.5,1,0);

    glVertex3f(16.5,12,0.0);//3 to 2
    glVertex3f(18,14.5,0);
    glVertex3f(18.5,15.5,0.0);//3 to 2
    glVertex3f(20.5,19,0);
    glVertex3f(21,20,0.0);//3 to 2
    glVertex3f(23,23.5,0);
    glVertex3f(23.5,24.5,0.0);//3 to 2
    glVertex3f(25,27,0);
    glVertex3f(28,19,0.0);//last road
    glVertex3f(31,19,0);
    glVertex3f(32,19,0.0);//last road
    glVertex3f(35,19,0);
    glVertex3f(36,19,0.0);//last road
    glVertex3f(38,19,0);
    glVertex3f(39,19,0.0);//last road
    glVertex3f(41,19,0);
     glEnd();

}
void circle(float x,float y,float radius)
{
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(int i=0;i<360;i++)
    {
        float theta=i*3.142/180;
        glVertex2f(x+radius*cos(theta),y+radius*sin(theta));
    }
    glEnd();
}
void cloud()
{
    circle(10,37,1);
    circle(11,38,.75);
    circle(12.25,38,1);
    circle(11.5,37,1);
}
void cloud1()
{
    circle(30,37,0.75);
    circle(31,38,1);
    circle(32.5,38,1);
    circle(31.5,37,1);
}
sun()
{
    glBegin(GL_POLYGON);
    glColor3f(1,.5,0);
    for(int i=0;i<360;i++)
    {
        float theta=i*3.142/180;
        glVertex2f(26+1.5*cos(theta),37.5+1.5*sin(theta));
    }
    glEnd();
}
void grass()
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.5,.9,.2);
    glVertex3f(0,0,0);//plant 1
    glVertex3f(1,1.5,0.0);
    glVertex3f(2,0,0);
    glVertex3f(0,0.75,0);//plant 1
    glVertex3f(1,2.25,0.0);
    glVertex3f(2,0.75,0);
    glVertex3f(0,1.75,0);//plant 1
    glVertex3f(1,3.0,0.0);
    glVertex3f(2,1.75,0);

    glVertex3f(2.25,0,0);//plant 2
    glVertex3f(3.25,1.5,0.0);
    glVertex3f(4.25,0,0);
    glVertex3f(2.25,0.75,0);//plant 2
    glVertex3f(3.25,2.25,0.0);
    glVertex3f(4.25,0.75,0);

    glVertex3f(4,0,0);//plant 3
    glVertex3f(5,1.5,0.0);
    glVertex3f(6,0,0);
    glVertex3f(4,0.75,0);//plant 3
    glVertex3f(5,2.5,0.0);
    glVertex3f(6,0.75,0);
    glVertex3f(4,1.75,0);//plant 3
    glVertex3f(5,3.0,0.0);
    glVertex3f(6,1.75,0);
    glVertex3f(4,2.5,0);//plant 3
    glVertex3f(5,3.5,0.0);
    glVertex3f(6,2.55,0);

    glVertex3f(6.25,0,0);//plant 4
    glVertex3f(7.25,1.5,0.0);
    glVertex3f(8.25,0,0);
    glVertex3f(6.25,0.75,0);//plant 4
    glVertex3f(7.25,2.5,0.0);
    glVertex3f(8.25,0.75,0);
    glVertex3f(6.25,1.75,0);//plant 4
    glVertex3f(7.25,3.0,0.0);
    glVertex3f(8.25,1.75,0);


    glVertex3f(8.5,0,0);//plant 5
    glVertex3f(9.5,1.5,0.0);
    glVertex3f(10.25,0,0);
    glVertex3f(8.5,0.75,0);//plant 5
    glVertex3f(9.5,2.5,0.0);
    glVertex3f(10.5,0.75,0);
    glVertex3f(8.5,1.75,0);//plant 5
    glVertex3f(9.5,3.0,0.0);
    glVertex3f(10.5,1.75,0);

     glVertex3f(11,0,0);//plant 6
    glVertex3f(12,1.5,0.0);
    glVertex3f(13,0,0);
    glVertex3f(11,0.75,0);//plant 6
    glVertex3f(12,2.25,0.0);
    glVertex3f(13,0.75,0);

    glVertex3f(16.5,0,0);//plant 7
    glVertex3f(17.5,1.5,0.0);
    glVertex3f(18.5,0,0);
    glVertex3f(16.5,0.75,0);//plant 7
    glVertex3f(17.5,2.5,0.0);
    glVertex3f(18.5,0.75,0);
    glVertex3f(16.5,1.75,0);//plant 7
    glVertex3f(17.5,3.0,0.0);
    glVertex3f(18.5,1.75,0);
    glVertex3f(16.5,2.5,0);//plant 7
    glVertex3f(17.5,3.5,0.0);
    glVertex3f(18.5,2.55,0);

     glVertex3f(19,0,0);//plant 8
    glVertex3f(20,1.5,0.0);
    glVertex3f(21,0,0);
    glVertex3f(19,0.75,0);//plant 8
    glVertex3f(20,2.25,0.0);
    glVertex3f(21,0.75,0);

    glVertex3f(22,0,0);//plant 9
    glVertex3f(23,1.5,0.0);
    glVertex3f(24,0,0);
    glVertex3f(22,0.75,0);//plant 9
    glVertex3f(23,2.5,0.0);
    glVertex3f(24,0.75,0);
    glVertex3f(22,1.75,0);//plant 9
    glVertex3f(23,3.0,0.0);
    glVertex3f(24,1.75,0);
    glVertex3f(22,2.5,0);//plant 9
    glVertex3f(23,3.5,0.0);
    glVertex3f(24,2.55,0);
    glVertex3f(27,0,0);//plant 1
    glVertex3f(28,1.5,0.0);
    glVertex3f(29,0,0);
    glVertex3f(27,0.75,0);//plant 1
    glVertex3f(28,2.25,0.0);
    glVertex3f(29,0.75,0);
    glVertex3f(27,1.75,0);//plant 1
    glVertex3f(28,3.0,0.0);
    glVertex3f(29,1.75,0);

    glVertex3f(29.25,0,0);//plant 2
    glVertex3f(30.25,1.5,0.0);
    glVertex3f(31.25,0,0);
    glVertex3f(29.25,0.75,0);//plant 2
    glVertex3f(30.25,2.25,0.0);
    glVertex3f(31.25,0.75,0);

    glVertex3f(32,0,0);//plant 3
    glVertex3f(33,1.5,0.0);
    glVertex3f(34,0,0);
    glVertex3f(32,0.75,0);//plant 3
    glVertex3f(33,2.5,0.0);
    glVertex3f(34,0.75,0);
    glVertex3f(32,1.75,0);//plant 3
    glVertex3f(33,3.0,0.0);
    glVertex3f(34,1.75,0);
    glVertex3f(32,2.5,0);//plant 3
    glVertex3f(33,3.5,0.0);
    glVertex3f(34,2.55,0);

    glVertex3f(35.25,0,0);//plant 4
    glVertex3f(36.25,1.5,0.0);
    glVertex3f(37.25,0,0);
    glVertex3f(35.25,0.75,0);//plant 4
    glVertex3f(36.25,2.5,0.0);
    glVertex3f(37.25,0.75,0);
    glVertex3f(35.25,1.75,0);//plant 4
    glVertex3f(36.25,3.0,0.0);
    glVertex3f(37.25,1.75,0);
    glEnd();
}
void update(int value)
{
    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,40,0,40,0,20);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    roads();
    whiteroadmarks();
    surroundings();
    grass();
    houses();
    sky();
    glPushMatrix();
    glTranslatef(cloud_move,0,0);
    cloud();
    glPopMatrix();
    cloud_move+=0.1;
    if(cloud_move>40)
        cloud_move=-40;
     glPushMatrix();
    glTranslatef(cloud1_move,0,0);
    cloud1();
    glPopMatrix();
    cloud1_move+=0.1;
    if(cloud1_move>40)
        cloud1_move=-40;
    sun();
    man();
    glutSwapBuffers();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(1200,700);
    glutCreateWindow("TRAVELLING SALES MAN");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(25,update,0);
    glutMainLoop();
    return 0;
}
