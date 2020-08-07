//
//  main.cpp
//  messaround
//
//  Created by Ben Wozniak on 11/25/19.
//  Copyright © 2019 Ben Wozniak. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Header.h"
using namespace std;

const int MAX_SIZE = 100;

void genBoard(int size, int numBoats);

void printBoard(int size);

void genBoard(int size);

void makeAMove(int size);

bool areBoatsSunk(int size);

bool boardIsFull(int size);

string board[MAX_SIZE][MAX_SIZE];
string userBoard[MAX_SIZE][MAX_SIZE];

//creates instance of Boat for boats
Boat a;
Boat b;
Boat c;
Boat d;
Boat e;
Boat f;


int main() {
    cout << "Welcome to Battleship!" << endl;
    cout << "The goal is to sink all of the ships in the least amount of moves" << endl;
    cout << "Enter a board size 4 or larger: ";
    
    //user inputted board size
    int size;
    cin >> size;
    if (size < 4) {
        size = 4;
    }
    cout << endl << "Boats are either of length 2 or 3 and you can generate up to 6";
    cout << endl << "Enter a number of boats: ";
    
    //user inputted number of boats
    int numBoats;
    cin >> numBoats;
    int x;
    cout << endl << endl;
    srand(time(NULL));
    x = rand() % 100;
    
    int moves = 0;
    genBoard(size, numBoats);
    while (areBoatsSunk(size) == false) {
        printBoard(size);
        makeAMove(size);
        moves++;
        if (boardIsFull(size) == true) {
            break;
        }
    }
    
    printBoard(size);
    cout << endl;
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "You finished in " << moves << " moves!" << endl;
    
    
    return 0;
}

void genBoard(int size, int numBoats) {
    
        
        if (numBoats == 1) {
            a.genBoat(rand(), size);
        } else if (numBoats == 2) {
            a.genBoat(rand(), size);
            b.genBoat(rand(), size);
        } else if (numBoats == 3) {
            a.genBoat(rand(), size);
            b.genBoat(rand(), size);
            c.genBoat(rand(), size);
        } else if (numBoats == 4) {
            a.genBoat(rand(), size);
            b.genBoat(rand(), size);
            c.genBoat(rand(), size);
            d.genBoat(rand(), size);
        } else if (numBoats == 5) {
            a.genBoat(rand(), size);
            b.genBoat(rand(), size);
            c.genBoat(rand(), size);
            d.genBoat(rand(), size);
            e.genBoat(rand(), size);
        } else if (numBoats == 6) {
            a.genBoat(rand(), size);
            b.genBoat(rand(), size);
            c.genBoat(rand(), size);
            d.genBoat(rand(), size);
            e.genBoat(rand(), size);
            f.genBoat(rand(), size);
        }
    
    for (int row = size - 1; row >= 0; row--) {
        for (int col = 0; col < size; col++) {
            if (row == a.getY1() && col == a.getX1()) {
                board[row][col] = "X";
            } else if (row == a.getY2() && col == a.getX2()){
                board[row][col] = "X";
            } else if (row == a.getY3() && col == a.getX3()){
                board[row][col] = "X";
            } else if (row == b.getY1() && col == b.getX1()) {
                board[row][col] = "X";
            } else if (row == b.getY2() && col == b.getX2()){
                board[row][col] = "X";
            } else if (row == b.getY3() && col == b.getX3()){
                board[row][col] = "X";
            } else if (row == c.getY1() && col == c.getX1()) {
                board[row][col] = "X";
            } else if (row == c.getY2() && col == c.getX2()){
                board[row][col] = "X";
            } else if (row == c.getY3() && col == c.getX3()){
                board[row][col] = "X";
            } else if (row == d.getY1() && col == d.getX1()) {
                board[row][col] = "X";
            } else if (row == d.getY2() && col == d.getX2()){
                board[row][col] = "X";
            } else if (row == d.getY3() && col == d.getX3()){
                board[row][col] = "X";
            } else if (row == e.getY1() && col == e.getX1()) {
                board[row][col] = "X";
            } else if (row == e.getY2() && col == e.getX2()){
                board[row][col] = "X";
            } else if (row == e.getY3() && col == e.getX3()){
                board[row][col] = "X";
            } else if (row == f.getY1() && col == f.getX1()) {
                board[row][col] = "X";
            } else if (row == f.getY2() && col == f.getX2()){
                board[row][col] = "X";
            } else if (row == f.getY3() && col == f.getX3()){
                board[row][col] = "X";
            } else {
                board[row][col] = "-";
            }
        }
    }
}

void printBoard(int size) {
    for (int row = size - 1; row >= 0; row--) {
        for (int col = 0; col < size; col++) {
            if (userBoard[row][col] != "X" && userBoard[row][col] != "O") {
                userBoard[row][col] = "-";
            }
            if (col == 0) {
                cout << row << " |" << userBoard[row][col] << " ";
            } else {
                cout << userBoard[row][col] << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < size + 2; j++) {
            if (i == 0 && j == 0) {
                cout << "  ";
            } else if (i == 0 && j == 1) {
                cout << " ";
            } else if (i == 0) {
                cout << "--";
            } else if (i == 1 && j == 0) {
                cout << "  ";
            } else if (i == 1 && j == 1) {
                cout << " ";
            } else if (i == 1) {
                cout << j - 2 << " ";
            }
        }
        cout << endl;
    }
}


void makeAMove(int size) {
    int x;
    int y;
    char a;
    char b;
    cout << "Make a move in format x, y in range 0 - " << size - 1 << ": ";
    cin >> x >> a;
    if (isdigit(a)) {
        y = a - 48;

    } else {
        cin >> y;
    }
    cout << endl << endl;
    if (cin.fail()) {
        cout << "Invalid Format" << endl;
        cin.clear();
        cin >> b;
    } else if (x > size - 1 || y > size - 1) {
        cout << "Out of Range" << endl << endl;
    } else if (board[y][x] == "X") {
        userBoard[y][x] = "X";
        cout << "(" << x << ", " << y << ")" << endl;
        cout << "Hit" << endl << endl;
    } else if (board[y][x] != "X") {
        userBoard[y][x] = "O";
        cout << "(" << x << ", " << y << ")" << endl;
        cout << "Miss" << endl << endl;
    }
}

bool areBoatsSunk(int size) {
    int count = 0;
    int countX = 0;
 
    
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == "X") {
                count++;
            }
        }
    }
   
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (userBoard[i][j] == "X") {
                countX++;
            }
        }
    }
    if (countX == count) {
        return true;
    } else {
        return false;
    }
}

bool boardIsFull(int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (userBoard[i][j] == "-") {
                count ++;
            }
        }
    }
    if (count > 0) {
        return false;
    } else {
        return true;
    }
}
