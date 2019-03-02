#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>


void displayWindow(float x, float y) {

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glBegin(GL_LINES);


    glVertex2f(x, y);
    glVertex2f(x + 1.5,y);

    glVertex2f(x, y);
    glVertex2f(x,y - 1.5);

    glVertex2f(x,y - 1.5);
    glVertex2f(x + 1.5,y - 1.5);

    glVertex2f(x + 1.5,y);
    glVertex2f(x + 1.5,y - 1.5);


}


void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glBegin(GL_LINES);
    /// For X
//    glVertex2f(-10,0);
//    glVertex2f(10,0);
//    /// Y Axix
//    glVertex2f(0,10);
//    glVertex2f(0,-10);

    glColor3d(0,1,0);

    /// A
    glVertex2f(-4.5,3);
    glVertex2f(2,3);
    /// B
    glVertex2f(-4.5,3);
    glVertex2f(-6,1);

    /// C
    glVertex2f(2,3);
    glVertex2f(1,1);
    /// D
    glVertex2f(2,3);
    glVertex2f(3,1);

    /// E
    glVertex2f(3,1);
    glVertex2f(-6,1);

    /// F
    glVertex2f(-6,1);
    glVertex2f(-6,-3);

    /// G
    glVertex2f(-6,-3);
    glVertex2f(3,-3);

    /// H
    glVertex2f(3,1);
    glVertex2f(3,-3);

    /// I
    glVertex2f(1,1);
    glVertex2f(1,-3);


    /// Now Door
    glVertex2f(-1.5,-2.9);
    glVertex2f(-1.5,-0.1);

    glVertex2f(-3,-2.9);
    glVertex2f(-3,-0.1);

    glVertex2f(-1.5,-0.1);
    glVertex2f(-3,-0.1);

    glVertex2f(-3,-2.9);
    glVertex2f(-1.5,-2.9);


    /// Now Windows
    displayWindow(-5.2, -0.3);
    displayWindow(-1, -0.3);
    displayWindow(1.3, -0.3);



    glEnd();
    glRotatef(45,0,1,0);



    /*glBegin(GL_LINES);
      glVertex2f (1 , 1);
      glVertex2f (-1, 1);
      glVertex2f (1, 1);
      glVertex2f (2, 2);
      glVertex2f (-1, 1);
      glVertex2f (2, 2);
      glEnd();*/
    glFlush();

}



int main()
{

    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Sweet Home :)");

    glOrtho(-8, 8, -4, 4, -4, 4);
    glutDisplayFunc(display);


    glClearColor(0,0,0,1);

    glutMainLoop();

    return 0;
}
