#include<windows.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include<gl/glut.h>
#include<math.h>
#include<string.h>
float cloud_move=0;
float cloud1_move=0;
float man_movey=0,man2_movey=0,man4_movey=0;
float man_movex=0,man1_movex=0,man3_movex=0,man4_movex=0;
int time=0;
void writetext(char *text,int length,float x,float y)
{
    glRasterPos2f(x,y);
    for(int i=0;i<length;i++)
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)text[i]);
}
void writetext1(char *text,int length,float x,float y)
{
    glRasterPos2f(x,y);
    for(int i=0;i<length;i++)
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)text[i]);
}
void firstwindow()
{
    glBegin(GL_QUADS);
    glColor3f(0.4,0.7,0.9);
    glVertex3f(0,0,0);
    glVertex3f(0,40,0);
    glVertex3f(40,40,0);
    glVertex3f(40,0,0);
    glEnd();
    glColor3f(0,0,0);
     char college[]="SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT";
     writetext(college,strlen(college),10,38);
     char dept[]="DEPARTENT OF COMPUTER SCIENCE AND ENGINEERING";
     writetext(dept,strlen(dept),10,35);
        char mini[]="A Mini Project on";
     writetext(mini,strlen(mini),17,30);
     glColor3f(1,0,.2);
     char projname[]="\" THE ROAD WARRIOR \"";
     writetext(projname,strlen(projname),16,27);
     glColor3f(0,0,0);
     char guide[]="Under the Guidance of";
     writetext(guide,strlen(guide),16,22);
     char sir[]="Mr.Manjunath S R";
     writetext(sir,strlen(sir),16.8,20);
     char des[]="Professor, Dept. of CSE";
     writetext1(des,strlen(des),16.5,18);
     char proj[]="The Project By";
     writetext(proj,strlen(proj),17,13);
     char kavya[]="1. KAVYA - 4SF17CS069";
     writetext1(kavya,strlen(kavya),7,9);
     char dep1[]="Computer Science and Engineering";
     writetext1(dep1,strlen(dep1),7.4,7);
     char krithi[]="2. KRITHI - 4SF17CS074";
     writetext1(krithi,strlen(krithi),24,9);
     writetext1(dep1,strlen(dep1),24.4,7);

}
void roads()
{
     glBegin(GL_LINES);
    glVertex3f(0,20,0.0);//starting-up
    glVertex3f(10,20,0);
    glVertex3f(0,18,0.0);//starting-down
    glVertex3f(10,18,0);
    glVertex3f(10,20,0.0);//first-up
    glVertex3f(15,30,0);
    glVertex3f(15,30,0.0);//1 to 2
    glVertex3f(27,30,0);
    glVertex3f(27,30,0.0);//2 to 4
    glVertex3f(27,10,0);
    glVertex3f(15,10,0.0);//3 to 4
    glVertex3f(27,10,0);
    glVertex3f(10,18,0.0);//start to 3
    glVertex3f(15,10,0);
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
    glVertex3f(10,20,0);
    glEnd();

}

void circle(float x,float y,float radius)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        float theta=i*3.142/180;
        glVertex2f(x+radius*cos(theta),y+radius*sin(theta));
    }
    glEnd();
}
void man()                          //Man at the beginning
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
    glColor3f(0,0,0);
    circle(8.75,16,0.5);

}
void man1()                                     //man at node A
{
    glBegin(GL_QUADS);//body
    glColor3f(1,.2,1);
    glVertex3f(14.5,32,0.0);
    glVertex3f(14.5,35.5,0.0);
    glVertex3f(16,35.5,0);
    glVertex3f(16,32,0);
    glEnd();
    glBegin(GL_QUADS);//left leg
    glColor3f(0,0,0);
    glVertex3f(14.9,30,0.0);
    glVertex3f(14.9,32,0.0);
    glVertex3f(15.1,32,0);
    glVertex3f(15.1,30,0);
    glEnd();
     glBegin(GL_QUADS);//right leg
    glColor3f(0,0,0);
    glVertex3f(15.4,30,0.0);
    glVertex3f(15.4,32,0.0);
    glVertex3f(15.6,32,0);
    glVertex3f(15.6,30,0);
    glEnd();
    glColor3f(0,0,0);
    circle(15.25,36,.5);
}
void man2()                                 //man at node B
{
    glBegin(GL_QUADS);//body
    glColor3f(1,.2,1);
    glVertex3f(25.5,32,0.0);
    glVertex3f(25.5,35.5,0.0);
    glVertex3f(27,35.5,0);
    glVertex3f(27,32,0);
    glEnd();
    glBegin(GL_QUADS);//left leg
    glColor3f(0,0,0);
    glVertex3f(25.9,30,0.0);
    glVertex3f(25.9,32,0.0);
    glVertex3f(26.1,32,0);
    glVertex3f(26.1,30,0);
    glEnd();
     glBegin(GL_QUADS);//right leg
    glColor3f(0,0,0);
    glVertex3f(26.4,30,0.0);
    glVertex3f(26.4,32,0.0);
    glVertex3f(26.6,32,0);
    glVertex3f(26.6,30,0);
    glEnd();
    glColor3f(0,0,0);
    circle(26.25,36,.5);
}
void man3()                         //man at node D
{
    glBegin(GL_QUADS);//body
    glColor3f(1,.2,1);
    glVertex3f(25,14,0.0);
    glVertex3f(25,17.5,0.0);
    glVertex3f(26.5,17.5,0);
    glVertex3f(26.5,14,0);
    glEnd();
    glBegin(GL_QUADS);//left leg
    glColor3f(0,0,0);
    glVertex3f(25.4,12,0.0);
    glVertex3f(25.4,14,0.0);
    glVertex3f(25.6,14,0);
    glVertex3f(25.6,12,0);
    glEnd();
     glBegin(GL_QUADS);//right leg
    glColor3f(0,0,0);
    glVertex3f(25.9,12,0.0);
    glVertex3f(25.9,14,0.0);
    glVertex3f(26.1,14,0);
    glVertex3f(26.1,12,0);
    glEnd();
    glColor3f(0,0,0);
    circle(25.75,18,.5);
}
void man5()                         //man at source
{
    glBegin(GL_QUADS);//body
    glColor3f(1,.2,1);
    glVertex3f(10.5,22,0.0);
    glVertex3f(10.5,25.5,0.0);
    glVertex3f(12,25.5,0);
    glVertex3f(12,22,0);
    glEnd();
    glBegin(GL_QUADS);//left leg
    glColor3f(0,0,0);
    glVertex3f(10.9,20,0.0);
    glVertex3f(10.9,22,0.0);
    glVertex3f(11.1,22,0);
    glVertex3f(11.1,20,0);
    glEnd();
     glBegin(GL_QUADS);//right leg
    glColor3f(0,0,0);
    glVertex3f(11.4,20,0.0);
    glVertex3f(11.4,22,0.0);
    glVertex3f(11.6,22,0);
    glVertex3f(11.6,20,0);
    glEnd();
    glColor3f(0,0,0);
    circle(11.25,26,.5);
}
void man4()                         //man at node C
{
    glBegin(GL_QUADS);//body
    glColor3f(1,.2,1);
    glVertex3f(13,14,0.0);
    glVertex3f(13,17.5,0.0);
    glVertex3f(14.5,17.5,0);
    glVertex3f(14.5,14,0);
    glEnd();
    glBegin(GL_QUADS);//left leg
    glColor3f(0,0,0);
    glVertex3f(13.4,12,0.0);
    glVertex3f(13.4,14,0.0);
    glVertex3f(13.6,14,0);
    glVertex3f(13.6,12,0);
    glEnd();
     glBegin(GL_QUADS);//right leg
    glColor3f(0,0,0);
    glVertex3f(13.9,12,0.0);
    glVertex3f(13.9,14,0.0);
    glVertex3f(14.1,14,0);
    glVertex3f(14.1,12,0);
    glEnd();
    glColor3f(0,0,0);
    circle(13.75,18,.5);
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

void order()
{
    glBegin(GL_QUADS);//message 1 from node 1
    glVertex3f(5,34.6,0);
    glVertex3f(5,37,0);
    glVertex3f(10,37,0);
    glVertex3f(10,34.6,0);
    glEnd();
    glColor3f(0,0,0);
    char pizza[]="Order:pizza";
    writetext1(pizza,strlen(pizza),5.5,35.5);
    glColor3f(1,1,1);
    circle(9,34,0.3);
    circle(9.6,33.5,0.2);

    glBegin(GL_QUADS);//message 2 from node 2
    glVertex3f(25,32,0);
    glVertex3f(25,33,0);
    glVertex3f(27,33,0);
    glVertex3f(27,32,0);
    glEnd();
     glColor3f(0,0,0);
    char dot[]="...";
    writetext1(dot,strlen(dot),25.8,32.5);
    glColor3f(1,1,1);
    circle(26.6,31.4,0.3);
    circle(27,30.8,0.2);

    glBegin(GL_QUADS);//message 3 from node 3
    glVertex3f(10,12,0);
    glVertex3f(10,13,0);
    glVertex3f(12,13,0);
    glVertex3f(12,12,0);
    glEnd();
     glColor3f(0,0,0);
    writetext1(dot,strlen(dot),10.8,12.5);
    glColor3f(1,1,1);
    circle(11.4,11.6,0.3);
    circle(11.7,11.1,0.2);


    glBegin(GL_QUADS);//message 4 from node 4
    glVertex3f(31,15.5,0);
    glVertex3f(31,17,0);
    glVertex3f(32.5,17,0);
    glVertex3f(32.5,15.5,0);
    glEnd();
     glColor3f(0,0,0);
    writetext1(dot,strlen(dot),31.5,16.3);
    glColor3f(1,1,1);
    circle(31.9,15.1,0.3);
    circle(31.4,14.3,0.2);



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

void cloud()
{
    glColor3f(1,1,1);
    circle(10,37,1);
    circle(11,38,.75);
    circle(12.25,38,1);
    circle(11.5,37,1);
}
void cloud1()
{
    glColor3f(1,1,1);
    circle(30,37,0.75);
    circle(31,38,1);
    circle(32.5,38,1);
    circle(31.5,37,1);
}
void sun()
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

    glColor3f(0.2,1,.3);//plant 1
    circle(1,1,1.5);
    circle(3.5,1,1.5);
    circle(2,3,1.5);
    circle(7,1,1.5);//plant 2
    circle(9.5,1,1.5);
    circle(8.5,3,1.5);
    circle(12.5,1,1);
    circle(13.5,1,1);
    circle(13,2.3,1);

    circle(18,1,1);
    circle(19,1,1);
    circle(18.5,2.3,1);
     circle(21.6,1,1.2);
    circle(24,1,1.2);
    circle(22.7,3,1.5);

     circle(28,1,1);
    circle(29,1,1);
    circle(28.5,2.3,1);
    circle(32,1,1.2);
    circle(34,1,1.2);
    circle(33,3,1.5);
    circle(37,1,1);
    circle(38,1,1);
    circle(37.5,2.3,1);

    //flowers
    glColor3f(1,0,0);
    circle(1.2,1,.2);
    circle(3.5,1,0.2);
    circle(2,3,0.2);
    circle(7,1,.2);//plant 2
    circle(9.5,1,0.2);
    circle(8.5,3,0.2);
    circle(12.5,1,0.2);
    circle(13.5,1,0.2);
    circle(13,2.3,.2);
    circle(18,1,0.2);
    circle(19,1,0.2);
    circle(18.5,2.3,0.2);
     circle(21.6,1,0.2);
    circle(24,1,0.2);
    circle(22.7,3,0.2);

     circle(28,1,0.2);
    circle(29,1,0.2);
    circle(28.5,2.3,0.2);
    circle(32,1,0.2);
    circle(34,1,0.2);
    circle(33,3,0.2);
    circle(37,1,0.2);
    circle(38,1,0.2);
    circle(37.5,2.3,0.2);
}
void graph()
{
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glLineWidth(10);
    glVertex3f(18,15,0);
    glVertex3f(22,19,0);
    glVertex3f(22,19,0);
    glVertex3f(26,19,0);
    glVertex3f(26,19,0);
    glVertex3f(26,11,0);
    glVertex3f(26,11,0);
    glVertex3f(22,11,0);
    glVertex3f(22,11,0);
    glVertex3f(18,15,0);
    glVertex3f(22,19,0);
    glVertex3f(22,11,0);
    glVertex3f(26,19,0);
    glVertex3f(22,11,0);
    glEnd();
    glColor3f(0,0,1);
    char t[]="S";
    writetext(t,1,17.5,15);
    char s1[]="A";
    writetext(s1,1,22,20.2);
    char s2[]="B";
    writetext(s2,1,26,20.2);
    char s3[]="C";
    writetext(s3,1,22,9.3);
    char s4[]="D";
    writetext(s4,1,26,9.3);
    glColor3f(0,0,0);
    char d[]="10";
    writetext1(d,2,19,17);
    char d1[]="12";
    writetext1(d1,2,24,20);
    char d2[]="8";
    writetext1(d2,1,27,15);
    char d3[]="5";
    writetext1(d3,1,24,10);
    char d4[]="15";
    writetext1(d4,2,19,12);
    char d5[]="20";
    writetext1(d5,2,21,14);
    char d6[]="25";
    writetext1(d6,2,24,14);

}
void explainationwindow()
{
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(2,2,0.0);
    glVertex3f(2,38,0);
    glVertex3f(38,38,0);
    glVertex3f(38,2,0.0);
    glEnd();
    glColor3f(0,0,0);
    char order1[]="The restuarant has received four orders at a time.";
    writetext1(order1,strlen(order1),4,36);
    char order2[]="Now the delivery boy has to deliver to these places. He has to find the shortest possible route that visits every house";
    char order3[]=" exactly once and returns to the starting point.";
    writetext1(order2,strlen(order2),4,34);
    writetext1(order3,strlen(order3),4,32);
    char gra[]="He makes a graph and calculates shortest distance";
    writetext1(gra,strlen(gra),4,29);
    man();
    graph();
    char dist[]="He starts from S then goes to A. Because distance to A is less than B.";
    writetext1(dist,strlen(dist),4,27);
    char dist1[]="Thus he moves from S to A, then to B, D, C then returns to source.";
    writetext1(dist1,strlen(dist1),4,25);
    char dist2[]="Thus total minimum distance is: 10 + 12 + 8 + 5 + 15 = 50";
    writetext1(dist2,strlen(dist2),4,23);
}
void sourcetoA()
{
    glPushMatrix();
        glTranslatef(man_movex,man_movey,0);
        man();
        glPopMatrix();
        man_movey+=0.1;
        man_movex+=0.03;
        if( man_movey>8 && man_movex>6.5)
        {
            man_movey=20;
            man_movex=6.5;
        }
}
void fromAtoB()
{
     glPushMatrix();
        glTranslatef(man1_movex,0,0);
        man1();
        glPopMatrix();
        man1_movex+=0.05;
        if( man1_movex>11)
            man1_movex=11;
}
void fromBtoD()
{
    glPushMatrix();
        glTranslatef(0,man2_movey,0);
        man2();
        glPopMatrix();
        man2_movey-=0.05;
        if( man2_movey<-20)
            man2_movey=-20;

}
void fromDtoC()
{
    glPushMatrix();
        glTranslatef(man3_movex,0,0);
        man3();
        glPopMatrix();
        man3_movex-=0.05;
        if( man3_movex<-12)
            man3_movex=-12;

}
void Dtosource()
{
    glPushMatrix();
        glTranslatef(man4_movex,man4_movey,0);
        man4();
        glPopMatrix();
        man4_movey+=0.1;
        man4_movex-=0.03;
        if( man4_movey>8 && man4_movex<-2.7)
        {
            man4_movey=8;
            man4_movex=-2.7;
        }
}
void message1()                         //message a node A
{
   glBegin(GL_QUADS);//message 1 from node 1
    glVertex3f(4,34,0);
    glVertex3f(4,37,0);
    glVertex3f(10,37,0);
    glVertex3f(10,34,0);
    glEnd();
    glColor3f(0,0,0);
    char reach1[]="Reached A";
    writetext1(reach1,strlen(reach1),4.5,36);
    char go1[]="Now goes to B";
    writetext1(go1,strlen(go1),4.5,34.8);
}
void message2()                         //message at node B
{
  glBegin(GL_QUADS);
  glColor3f(1,1,1);
    glVertex3f(28,34,0);
    glVertex3f(28,37,0);
    glVertex3f(34,37,0);
    glVertex3f(34,34,0);
    glEnd();
    glColor3f(0,0,0);
    char reach2[]="Reached B";
    writetext1(reach2,strlen(reach2),28.5,36);
    char go2[]="Now goes to D";
    writetext1(go2,strlen(go2),28.5,34.8);
}
void message3()                 //message at node D
{
  glBegin(GL_QUADS);
  glColor3f(1,1,1);
    glVertex3f(28,15,0);
    glVertex3f(28,19,0);
    glVertex3f(34,19,0);
    glVertex3f(34,15,0);
    glEnd();
    glColor3f(0,0,0);
    char reach3[]="Reached D";
    writetext1(reach3,strlen(reach3),28.5,18);
    char go3[]="Now goes to C";
    writetext1(go3,strlen(go3),28.5,17);
}
void message4()       //message at node c
{
  glBegin(GL_QUADS);
  glColor3f(1,1,1);
    glVertex3f(6,12,0);
    glVertex3f(6,15,0);
    glVertex3f(12,15,0);
    glVertex3f(12,12,0);
    glEnd();
    glColor3f(0,0,0);
    char reach4[]="Visited all houses";
    writetext1(reach4,strlen(reach4),6.5,14);
    char go4[]="Returns to source";
    writetext1(go4,strlen(go4),6.5,13);
}
void message5()
{
  glBegin(GL_QUADS);
  glColor3f(1,1,1);
    glVertex3f(6,26,0);
    glVertex3f(6,28,0);
    glVertex3f(10,28,0);
    glVertex3f(10,26,0);
    glEnd();
    glColor3f(0,0,0);
    char finish[]="Finished !!";
    writetext1(finish,strlen(finish),6.5,27);
}



void update(int value)
{
    time+=1;
    if(time>=1800 && time<1900)
    {
        man_movex=0;
        man_movey=0;
    }
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
    sun();
    //cloud to move
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

    //man movement
    if(time<300)
    {
        firstwindow();
    }
    else if (time>300 && time<600)
    {
        man();

    }
    else if (time>600 && time<800)
    {
        order();
        man();
    }
    else if(time>=800 && time<1500)
    {
        explainationwindow();
    }
    else if(time>=1500 && time<1800)
    {
       sourcetoA();
    }
    else if(time>=1800 && time<1900)
    {
        message1();
        man1();
    }
    else if(time>=1900 && time<2200)
    {
        fromAtoB();
    }
    else if(time>=2200 && time<2400)
    {
        man2();
        message2();
    }
    else if(time>=2400 && time<2800)
    {
        fromBtoD();
    }
    else if(time>=2800 && time<2900)
    {
        man3();
        message3();
    }
    else if(time>=2900 && time<3300)
    {
        fromDtoC();
    }
    else if(time>=3300 && time<3400)
    {
        message4();
        man4();
    }
    else if(time>=3400 && time<3700)
    {
        Dtosource();
    }
    else if(time>=3800 && time<3900)
    {
        message5();
        man5();
    }
    else
        man5();

    glutSwapBuffers();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(1200,700);
    glutCreateWindow("THE ROAD WARRIOR");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(25,update,0);
    glutMainLoop();
    return 0;
}
