#include <GL/glut.h>
#include <iostream>

// Dimensions of the cuboid
float length, width, height;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
    glTranslatef(-length / 2, -height / 2, -width / 2);
    
    glBegin(GL_QUADS);
    
    // Front face
    glVertex3f(0.0, 0.0, width);
    glVertex3f(length, 0.0, width);
    glVertex3f(length, height, width);
    glVertex3f(0.0, height, width);
    
    // Back face
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, height, 0.0);
    glVertex3f(length, height, 0.0);
    glVertex3f(length, 0.0, 0.0);
    
    // Top face
    glVertex3f(0.0, height, 0.0);
    glVertex3f(0.0, height, width);
    glVertex3f(length, height, width);
    glVertex3f(length, height, 0.0);
    
    // Bottom face
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(length, 0.0, 0.0);
    glVertex3f(length, 0.0, width);
    glVertex3f(0.0, 0.0, width);
    
    // Left face
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, width);
    glVertex3f(0.0, height, width);
    glVertex3f(0.0, height, 0.0);
    
    // Right face
    glVertex3f(length, 0.0, 0.0);
    glVertex3f(length, height, 0.0);
    glVertex3f(length, height, width);
    glVertex3f(length, 0.0, width);
    
    glEnd();
    
    glPopMatrix();
    
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    std::cout << "Enter the length of the cuboid: ";
    std::cin >> length;
    std::cout << "Enter the width of the cuboid: ";
    std::cin >> width;
    std::cout << "Enter the height of the cuboid: ";
    std::cin >> height;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Cuboid");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
