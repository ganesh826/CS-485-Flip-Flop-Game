//  main.cpp
//  Flip-Flop-Game
//  Created by Ganesh Koripalli on 10/3/17.
//  Copyright © 2017 Ganesh Koripalli. All rights reserved.

/*
Headers for Visual Studio
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glfw.h>
#include <SOIL.h>
*/

//Headers for Xcode
#include "OpenGL/gl.h"
#include "OpenGL/glu.h"
#include <GLUT/glut.h>
#include <iostream>

//Variables
GLfloat delta = 0.25;
GLint axis = 2;
GLuint texture[6];
GLuint texture_s[2];
int rotate = -1;
int stop = 0;
int elements = 16;
int width = 200;
int height = 200;

GLfloat theta[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

GLfloat pick_Cube[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                        0.0,  0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

//Vertices of cube about the orgin
GLfloat vertices[][3] = { { 0.0 ,0.0 ,-5.0 },{ 198.0, 0.0, -5.0 },{ 198.0,198.0,-5.0 },{ 0.0,198,-5.0 },{ 0.0, 0.0, 5.0 },{ 198.0,0.0,5.0 },{ 198.0, 198.0, 5.0 },{ 0.0, 198.0, 5.0 } };

GLfloat arrays[16][4] = { { -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0},{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0},{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 } };

//Spin the cube about the axis
void spinCube(int id) {
    
    int success = 0;
    int g = 0;
    int check[2];
    
    pick_Cube[id - 1] += 1;
    check[g] = id - 1;
    g++;
    
    if (g == 2) {
        
        if ((arrays[check[0]][0]) == check[1]) {
            
            success++;
            
        } else {
            
            if (pick_Cube[check[1]] > 0) {
                
                    rotate = check[0];
                
            } else {
                
                     pick_Cube[check[0]] += 1;
                
            }
            pick_Cube[check[1]] += 1;
        }
        g = 0;
    }
    
    if (success == 8) {
        
        stop = 1;
        
    }
}

//draw the grid
void drawLines() {
    int i;
    glLineWidth(2.5);
    glColor3f(0.0, 0, 1.0);
    
        for (i = 0; i <= 800; i += 200) {
            
            glBegin(GL_LINES);
            glVertex3f(i, 0.0, 0.0);
            glVertex3f(i, 800, 0);
            glEnd();
            
            glBegin(GL_LINES);
            glVertex3f(0.0, i, 0.0);
            glVertex3f(800, i, 0);
            glEnd();
            
        }
}

//Drawing a face
void face(int a, int b, int c, int d) {
    
    glBegin(GL_POLYGON);
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
    glEnd();
    
}

//color the cube
void colorcube(void) {
    
    float pixels[] = { 0.0f, 0.0f, 0.0f, 100.0f, 100.0f, 100.0f,
        100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f };
    
    unsigned char* image = SOIL_load_image("image/1.png", &width, &height, 0, SOIL_LOAD_RGB);
    
    glBindTexture(GL_TEXTURE_2D, texture_s[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    
    static int i = 0;
    
    glColor3f(0, 0, 1.0);
    face(0, 3, 2, 1);
    glColor3f(0, 1.0, 0);
    face(2, 3, 7, 6);
    face(0, 4, 7, 3);
    face(1, 2, 6, 5);
    
    glColor3f(arrays[i][1] / 10, arrays[i][2] / 10, arrays[i][3] / 10);
    
    i++;
    if (i > 15) {
        
        i = 0;
    
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
    face(4, 5, 6, 7);
    glColor3f(0, 1.0, 0);
    face(0, 1, 5, 4);
    SOIL_free_image_data(image);
}

//display the cubes
void display(void) {
    
    int z = 0;
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    drawLines();
    glPopMatrix();
    
    glPushMatrix();
    glInitNames();
    glPushName(0);
    
    for (int i = 0; i <= 3; i++)
        
        for (int j = 0; j <= 3; j++) {
            
            glPushMatrix();
            glTranslatef(200 * j, 200.0 * i, 0.0);
            glRotatef(theta[z], 1.0, 1.0, 0.0);
            colorcube();
            glPopMatrix();
            z++;
            
        }
    
    glutSwapBuffers();
    
}

void myReshape(int w, int h) {
    
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 850, 400.0, -400.0);
    glMatrixMode(GL_MODELVIEW);
    
}
//Checks which cube to be rotated with the click of the mouse
void mouseSelection(int x, int y) {
    
    if (y > 50 && y < 250) {
        
        if (x > 0 && x < 200 && theta[12] != 180)
            spinCube(13);
            else if (x > 200 && x < 400 && theta[13] != 180)
                spinCube(14);
                else if (x > 400 && x < 600 && theta[14] != 180)
                    spinCube(15);
                    else if (x > 600 && x < 800 && theta[15] != 180)
                        spinCube(16);
        
    } else if (y > 250 && y < 450) {
            
            if (x > 0 && x < 200 && theta[8] != 180)
                spinCube(9);
                else if (x > 200 && x < 400 && theta[9] != 180)
                    spinCube(10);
                    else if (x > 400 && x < 600 && theta[10] != 180)
                        spinCube(11);
                        else if (x > 600 && x < 800 && theta[11] != 180)
                            spinCube(12);
            
    } else if (y > 450 && y < 650) {
            
                if (x > 0 && x < 200 && theta[4] != 180)
                    spinCube(5);
                    else if (x > 200 && x < 400 && theta[5] != 180)
                        spinCube(6);
                        else if (x > 400 && x < 600 && theta[6] != 180)
                            spinCube(7);
                            else if (x > 600 && x < 800 && theta[7] != 180)
                                spinCube(8);
            
    } else if (y > 650 && y < 850) {
                
                    if (x > 0 && x < 200 && theta[0] != 180)
                        spinCube(1);
                        else if (x > 200 && x < 400 && theta[1] != 180)
                            spinCube(2);
                            else if (x > 400 && x < 600 && theta[2] != 180)
                                spinCube(3);
                                else if (x > 600 && x < 800 && theta[3] != 180)
                                    spinCube(4);
                
    }
}

//Use the mouse mouseSelction function
void mouse(int btn, int state, int x, int y){
    
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        
        mouseSelection(x, y);
        
    }
}

//Keyboard function
void keyboard(unsigned char key, int x, int y) {
    
    if (key == 'q' || key == 'Q') {
        
        exit(0);
        
    }
}

//change the angle of certain cube to rotate the cube
void spinCube2() {
    
    for (int i = 0; i < elements; i++) {
        
        if (pick_Cube[i] > 0) {
            
            theta[i] += delta;
            
            if (theta[i] == 180) {
                
                pick_Cube[i] -= 1;
                
                if (rotate != -1 && rotate != i) {
                    
                    pick_Cube[rotate] += 1;
                    rotate = -1;
                    
                }
            }
            
            if (theta[i] > 360.0) {
                
                theta[i] -= 360.0;
                pick_Cube[i] -= 1;
                
            }
        }
    }
    glutPostRedisplay();
}

//main function
int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 850);
    glutCreateWindow("Flip-Flop-Match-Game");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutIdleFunc(spinCube2);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
    
}
