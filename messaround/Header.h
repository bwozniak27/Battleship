//
//  Header.h
//  messaround
//
//  Created by Ben Wozniak on 11/27/19.
//  Copyright © 2019 Ben Wozniak. All rights reserved.
//

#ifndef Header_h
#define Header_h


class Boat
{
public:
    
    Boat();
    
    void genBoat(int boatSize, int size);
    
    int getX1();
    
    int getY1();
    
    int getX2();
    
    int getY2();
    
    int getX3();
    
    int getY3();
    
    
private:
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    
};



#endif /* Header_h */
