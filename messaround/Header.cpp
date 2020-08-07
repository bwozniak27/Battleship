//
//  Header.cpp
//  messaround
//
//  Created by Ben Wozniak on 11/27/19.
//  Copyright © 2019 Ben Wozniak. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Header.h"
using namespace std;

Boat::Boat() {
    x1 = 1000000;
    y1 = 1000000;
    x2 = 1000000;
    y2 = 1000000;
    x3 = 1000000;
    y3 = 1000000;
}

void Boat::genBoat(int boatSize, int size) {
    int boatS = boatSize % 3;
    if (boatS == 0 || boatS == 1) {
        boatS += 2;
    } else if (boatS == 2) {
        boatS += 1;
    }
    x1 = 1000000;
    y1 = 1000000;
    x2 = 1000000;
    y2 = 1000000;
    x3 = 1000000;
    y3 = 1000000;
    int direction = rand() % 4;
    
    if (boatS >= 1) {
        x1 = rand() % size;
        y1 = rand() % size;
    }
    if (boatS >= 2) {
        if (direction == 0) {
            if (y1 + 1 > size - 1) {
                x2 = x1;
                y2 = y1 - 1;
            } else {
                x2 = x1;
                y2 = y1 + 1;
            }
        } else if (direction == 1) {
            if (x1 + 1 > size - 1) {
                x2 = x1 - 1;
                y2 = y1;
            } else {
                x2 = x1 + 1;
                y2 = y1;
            }
        } else if (direction == 2) {
            if (y1 - 1 < 0) {
                x2 = x1;
                y2 = y1 + 1;
            } else {
                x2 = x1;
                y2 = y1 - 1;
            }
        } else if (direction == 3) {
            if (x1 - 1 < 0) {
                x2 = x1 + 1;
                y2 = y1;
            } else {
                x2 = x1 - 1;
                y2 = y1;
            }
        }
    }
    if (boatS >= 3) {
        if (direction == 1) {
            if (y2 + 1 > size - 1) {
                x3 = x2;
                y3 = y2 - 2;
            } else {
                x3 = x2;
                y3 = y2 + 1;
            }
        } else if (direction == 2) {
            if (x2 + 1 > size - 1) {
                x3 = x2 - 2;
                y3 = y2;
            } else {
                x3 = x2 + 1;
                y3 = y2;
            }
        } else if (direction == 3) {
            if (y2 - 1 < 0) {
                x3 = x2;
                y3 = y2 + 2;
            } else {
                x3 = x2;
                y3 = y2 - 1;
            }
        } else if (direction == 2) {
            if (x2 - 1 < 0) {
                x3 = x2 + 2;
                y3 = y2;
            } else {
                x3 = x2 - 1;
                y3 = y2;
            }
        }
    }
}

int Boat::getX1() {
    return x1;
}

int Boat::getY1() {
    return y1;
}

int Boat::getX2() {
    return x2;
}

int Boat::getY2() {
    return y2;
}

int Boat::getX3() {
    return x3;
}

int Boat::getY3() {
    return y3;
}

