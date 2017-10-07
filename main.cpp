// main.cpp
//  Flip-Flop-Game
//
//  Created by Ganesh Koripalli on 10/3/17.
//  Copyright © 2017 Ganesh Koripalli. All rights reserved.

#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#include <GLUT/glut.h>
#include <iostream>

/*#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>*/

GLsizei mouseX = 0, mouseY = 0;
GLsizei winWidth = 0, winHeight = 0;
GLfloat side = 50; //size of the square whenever mouse left button is clicked
GLfloat redColor[3] = { 1,0,0 };
GLfloat blueColor[3] = { 0,0,1 };

void drawLines() {
    
    glLineWidth(2.5);
    glColor3fv(redColor);
    
    //For loop for drawing the lines
    for (int i = 0; i <= 800; i += 200) {
        glBegin(GL_LINES);
        glVertex3f(i, 0.0 , 0.0);
        glVertex3f(i, 800, 0.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(800, i , 0.0);
        glVertex3f(0, i, 0);
        glEnd();
    }
}

//void drawCube() {
// //for loop for making the cubes within the board
// for (int i = 0; i <= 800; i += 200) {
//
// }
//}

void drawSquare() { //draw the square in between the grid squares
    glColor3fv(blueColor);
    
    /*glVertex3f(mouseX, mouseY, 0);
     glVertex3f(mouseX + side, mouseY, 0);
     glVertex3f(mouseX + side, mouseY + side, 0);
     glVertex3f(mouseX, mouseY + side, 0);*/
    for (int i = 0; i <= 800; i += 200) {
        glBegin(GL_POLYGON);
        glVertex3f(50 + i, 50, 0);
        glVertex3f(side, 50, 0);
        glVertex3f(side, side, 0);
        glVertex3f(50, side, 0);
        glEnd();
    }
    glFlush();
}

void display(void) {
    glClearColor(1, 1, 1, 1); //changes the background color to white
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawLines();
    drawSquare();
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800, 800, 0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void spindisplay(void) {
    glutPostRedisplay();
}

//Mouse X position
void setX(int x) {
    mouseX = x;
}

//Mouse Y position
void setY(int y) {
    mouseY = y;
}

void mouse(int btn, int state, int x, int y) {
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        setX(x);
        setY(y);
        glutPostRedisplay();
    }
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        exit(1);
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Basic Grid - Mouse Interaction");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutIdleFunc(spindisplay);
    winWidth = glutGet(GLUT_WINDOW_WIDTH);
    winHeight = glutGet(GLUT_WINDOW_WIDTH);
    glutMainLoop();
}


//#define LIMIT 10.0
//#define X  2.0
//#define Y  2.0
//#define WIDTH  2.0
//#define HEIGHT  2.0
//
//// Create a blue square to be placed in the window
//void drawSquare(double x1, double y1, double length)
//{
//    double halfLength = length / 2;
//
//    glColor3d(0.2, 0.5, 1);
//    glBegin(GL_POLYGON);
//    glVertex2d(x1 + halfLength, y1 + halfLength);
//    glVertex2d(x1 + halfLength, y1 - halfLength);
//    glVertex2d(x1 - halfLength, y1 - halfLength);
//    glVertex2d(x1 - halfLength, y1 + halfLength);
//    glEnd();
//}
//
//// Display a 4x4 grid of blue squares
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1.0, 0.0, 0.0);
//
//    //Array of 4 x 4 squares
//    drawSquare(1, 1, 2);
//    drawSquare(1, 3.2, 2);
//    drawSquare(1, 5.4, 2);
//    drawSquare(1, 7.6, 2);
//    drawSquare(3.2, 1, 2);
//    drawSquare(3.2, 3.2, 2);
//    drawSquare(3.2, 5.4, 2);
//    drawSquare(3.2, 7.6, 2);
//    drawSquare(5.4, 1, 2);
//    drawSquare(5.4, 3.2, 2);
//    drawSquare(5.4, 5.4, 2);
//    drawSquare(5.4, 7.6, 2);
//    drawSquare(7.6, 1, 2);
//    drawSquare(7.6, 3.2, 2);
//    drawSquare(7.6, 5.4, 2);
//    drawSquare(7.6, 7.6, 2);
//
//    glFlush();
//}
//
//// Clip the scene
//void setup() {
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//    gluOrtho2D(LIMIT - 11, LIMIT, LIMIT - 11, LIMIT);
//}
//
//int main(int argc, char *argv[]) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowPosition(200, 100);
//    glutInitWindowSize(800, 800);
//    glutCreateWindow("Flip Flop Matching Game");
//    glutDisplayFunc(display);
//    setup();
//    glutMainLoop();
//
//    return 0;
//}

