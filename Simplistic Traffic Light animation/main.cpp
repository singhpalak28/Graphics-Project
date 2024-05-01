#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

const int windowWidth = 400;
const int windowHeight = 600;
const int centerX = windowWidth / 2;
const int centerY = windowHeight / 2;
const int boxWidth = 120;
const int boxHeight = 360;

// Traffic light states
enum TrafficLightState {
    RED,
    YELLOW,
    GREEN
};

TrafficLightState currentState = RED; // Initial state is RED
int countdown = 5; // Initial countdown value

void drawCircle(float x, float y, float radius) {
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float dx = radius * std::cos(theta);
        float dy = radius * std::sin(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawTrafficLight() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw rectangle for traffic light box
    glColor3f(0.0f, 0.0f, 0.0f); // Gray color for box
    glBegin(GL_POLYGON);
    glVertex2f(centerX - boxWidth / 2, centerY - boxHeight / 2);
    glVertex2f(centerX + boxWidth / 2, centerY - boxHeight / 2);
    glVertex2f(centerX + boxWidth / 2, centerY + boxHeight / 2);
    glVertex2f(centerX - boxWidth / 2, centerY + boxHeight / 2);
    glEnd();

    // Draw traffic lights and text based on current state
    if (currentState == RED) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        drawCircle(centerX, centerY + 100, 40);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glRasterPos2f(centerX - 20, centerY + 90);
        std::string stopText = "STOP";
        for (const char &c : stopText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    } else if (currentState == YELLOW) {
        glColor3f(1.0f, 1.0f, 0.0f); // Yellow
        drawCircle(centerX, centerY, 40);
        glColor3f(0.0f, 0.0f, 0.0f); // Black
        glRasterPos2f(centerX - 25, centerY - 10);
        std::string waitText = "WAIT";
        for (const char &c : waitText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    } else if (currentState == GREEN) {
        glColor3f(0.0f, 1.0f, 0.0f); // Green
        drawCircle(centerX, centerY - 100, 40);
        glColor3f(1.0f, 1.0f, 1.0f); // White
        glRasterPos2f(centerX - 20, centerY - 110);
        std::string goText = "GO";
        for (const char &c : goText) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }

    // Draw countdown number
    glColor3f(1.0f, 1.0f, 1.0f); // Black
    glRasterPos2f(centerX - 10, centerY + 160);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0' + countdown);

    glFlush();
}

void updateTrafficLightState(int value) {
    // Decrement countdown
    countdown--;

    // Check if countdown reached zero
    if (countdown == 0) {
        // Update traffic light state based on current state
        if (currentState == RED) {
            currentState = YELLOW;
            countdown = 5; // Reset countdown for GREEN state
        } else if (currentState == YELLOW) {
            currentState = GREEN;
            countdown = 5; // Reset countdown for RED state
        } else if (currentState == GREEN) {
            currentState = RED;
            countdown = 5; // Reset countdown for YELLOW state
        }
    }

    glutPostRedisplay(); // Request redisplay to update countdown and state
    glutTimerFunc(1000, updateTrafficLightState, 0); // Schedule next timer tick after 1 second (1000 milliseconds)
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set clear color to white
    glutTimerFunc(0, updateTrafficLightState, 0); // Start timer for state updates
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Traffic Light Simulation");

    init();
    glutDisplayFunc(drawTrafficLight);
    glutReshapeFunc(reshape);

    currentState = RED; // Start with RED light
    countdown = 5; // Reset countdown for initial state

    glutMainLoop();

    return 0;
}
