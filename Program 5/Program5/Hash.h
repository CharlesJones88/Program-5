//
//  Hash.h
//  Program 5
//
//  Created by Charles Jones on 10/25/14.
//  Copyright (c) 2014 Charles Jones. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 20;
const int DEFAULT_VAL = -999;

class Hash
{
    
private:
    int hashTable[MAX];
    
public:
    Hash();
    int getHashValue(int);
    bool insert(int, int);
    bool resolveCollision(int, int);
    void show();
};