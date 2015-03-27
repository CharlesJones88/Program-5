//
//  Hash.cpp
//  Program 5
//
//  Created by Charles Jones on 10/25/14.
//  Copyright (c) 2014 Charles Jones. All rights reserved.
//

#include "Hash.h"

Hash::Hash()
{
    for(int i = 0; i < MAX; i++)
        hashTable[i] = DEFAULT_VAL;
}

int Hash::getHashValue(int key)
{
    return key % MAX;
}

bool Hash::insert(int key, int location)
{
    if(hashTable[location] != DEFAULT_VAL)
    {
        cout << "Collision detected at location " << location << ", for value " << key << ". Attempting to resolve." << endl;
        return true;
    }
    hashTable[location] = key;
    return false;
}

bool Hash::resolveCollision(int key, int location)
{
    int changeLocation = location;
    while(hashTable[changeLocation] != DEFAULT_VAL)
    {
        changeLocation++;
        if(changeLocation == MAX)
            changeLocation = 0;
        
        if(changeLocation == location)
        {
            cout << "Table is full." << endl;
            return false;
        }
    }
    hashTable[changeLocation] = key;
    return true;
}

void Hash::show()
{
    cout << "Element\tValue" << endl;
    for(int i = 0; i < MAX; i++)
        cout << i << "\t\t" << hashTable[i] << endl;
}