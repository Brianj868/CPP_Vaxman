//
//  ghost.cpp
//  VaxMan
//
//  Created by Brian Johnston on 9/23/21.
//
#include <math.h>
#include <vector>
#include <GLUT/glut.h>
#include "ghost.hpp"

Ghost::Ghost(float x, float y, float dir)
{
    posX = x;
    posY = y;
    direction = dir;
}

void Ghost::updateMonster(std::vector<std::vector<bool>> bitmap){
    float squareSize = 50.0;
        //find the current position of the monster
        int x1Quadrant = (int)((posX - (2/squareSize)) - (16.0 *cos(360 * M_PI / 180.0)) / squareSize);
        int x2Quadrant = (int)((posX + (2/squareSize)) + (16.0 *cos(360 * M_PI / 180.0)) / squareSize);
        int y1Quadrant = (int)((posY - (2/squareSize)) - (16.0 *cos(360 * M_PI / 180.0)) / squareSize);
        int y2Quadrant = (int)((posY + (2/squareSize)) + (16.0 *cos(360 * M_PI / 180.0)) / squareSize);
        //move him acording to its direction until he hits an obstacle
        switch ((int)direction){
        case 1:
            if (!bitmap.at(x1Quadrant).at((int)posY)){
                posX -= 2 / squareSize;
            }else {
                int current = direction;
                do{
                    direction =  (rand() % 4) + 1;
                } while (current == (int) direction);
            }
            break;
        case 2:
            if (!bitmap.at(x2Quadrant).at((int)posY)){
                posX += 2 / squareSize;
            }
            else {
                int current = direction;
                do{
                    direction = (rand() % 4) + 1;
                } while (current == (int)direction);
            }
            break;
        case 3:
            if (!bitmap.at((int)posX).at(y1Quadrant)){
                posY -= 2 / squareSize;
            }
            else {
                int current = direction;
                do{
                    direction = (rand() % 4) + 1;
                } while (current == (int)direction);
            }
            break;
        case 4:
            if (!bitmap.at((int)posX).at(y2Quadrant)){
                posY += 2 / squareSize;
            }
            else {
                int current = direction;
                do{
                    direction = (rand() % 4) + 1;
                } while (current == (int)direction);
            }
            break;
        default:
            break;
        }
}

void Ghost::drawMonster(float r, float g, float b){
    float squareSize = 50.0;
    int x, y;
    glBegin(GL_LINES);
    glColor3f(r, g, b);
    //draw the head
    for (int k = 0; k < 32; k++){
        x = (float)k / 2.0 * cos(360 * M_PI / 180.0) + (posX*squareSize);
        y = (float)k / 2.0* sin(360 * M_PI / 180.0) + (posY*squareSize);
        for (int i = 180; i <= 360; i++){
            glVertex2f(x, y);
            x = (float)k / 2.0 * cos(i * M_PI / 180.0) + (posX*squareSize);
            y = (float)k / 2.0* sin(i * M_PI / 180.0) + (posY*squareSize);
            glVertex2f(x, y);
        }
    }
    glEnd();
    //draw body
    glRectf((posX*squareSize) - 17, posY*squareSize, (posX*squareSize) + 15, (posY*squareSize) + 15);
    glBegin(GL_POINTS);
    glColor3f(0, 0.2, 0.4);
    //draw eyes and legs
    glVertex2f((posX*squareSize) - 11, (posY*squareSize) + 14); //legs
    glVertex2f((posX*squareSize) - 1, (posY*squareSize) + 14); //legs
    glVertex2f((posX*squareSize) + 8, (posY*squareSize) + 14); //legs
    glVertex2f((posX*squareSize) + 4, (posY*squareSize) - 3); //eyes
    glVertex2f((posX*squareSize) - 7, (posY*squareSize) - 3); //eyes
    glEnd();
}

