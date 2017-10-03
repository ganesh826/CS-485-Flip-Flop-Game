// main.cpp
//  Flip-Flop-Game
//
//  Created by Ganesh Koripalli on 10/3/17.
//  Copyright © 2017 Ganesh Koripalli. All rights reserved.

#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#include <GLUT/glut.h>
#include <iostream>

#define LIMIT 10.0
#define X  2.0
#define Y  2.0
#define WIDTH  2.0
#define HEIGHT  2.0

// Create a blue square to be placed in the window
void drawSquare(double x1, double y1, double length)
{
    double halfLength = length / 2;
    
    glColor3d(0.2, 0.5, 1);
    glBegin(GL_POLYGON);
    glVertex2d(x1 + halfLength, y1 + halfLength);
    glVertex2d(x1 + halfLength, y1 - halfLength);
    glVertex2d(x1 - halfLength, y1 - halfLength);
    glVertex2d(x1 - halfLength, y1 + halfLength);
    glEnd();
}

// Display a 4x4 grid of blue squares
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    
    //Array of 4 x 4 squares
    drawSquare(1, 1, 2);
    drawSquare(1, 3.2, 2);
    drawSquare(1, 5.4, 2);
    drawSquare(1, 7.6, 2);
    drawSquare(3.2, 1, 2);
    drawSquare(3.2, 3.2, 2);
    drawSquare(3.2, 5.4, 2);
    drawSquare(3.2, 7.6, 2);
    drawSquare(5.4, 1, 2);
    drawSquare(5.4, 3.2, 2);
    drawSquare(5.4, 5.4, 2);
    drawSquare(5.4, 7.6, 2);
    drawSquare(7.6, 1, 2);
    drawSquare(7.6, 3.2, 2);
    drawSquare(7.6, 5.4, 2);
    drawSquare(7.6, 7.6, 2);
    
    glFlush();
}

// Clip the scene
void setup() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(LIMIT - 11, LIMIT, LIMIT - 11, LIMIT);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Flip Flop Matching Game");
    glutDisplayFunc(display);
    setup();
    glutMainLoop();
    
    return 0;
}
