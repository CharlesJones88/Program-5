//
//  main.cpp
//  Program 5
//
//  Created by Charles Jones on 10/25/14.
//  Copyright (c) 2014 Charles Jones. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include "Hash.h"

using namespace std;

int main() {
    Hash hashData;
    ifstream fileRead;
    string fileName;
    int key;
    cout << "Charles Jones\nCS2420 Section 002\nProgram 5 - Hashing" << endl;
    cout << "Enter in a file name: ";
	cin >> fileName;
    fileRead.open(fileName);
    if (fileRead.fail())
    {
        cout << "Failed to open file " << fileName << ". Terminating program." << endl;
        fileRead.close();
        system("pause");
        exit(EXIT_FAILURE);
    }
    while (fileRead >> key)
    {
        int location = hashData.getHashValue(key);
        bool collision = hashData.insert(key, location);
        if(collision)
        {
            bool resolved = hashData.resolveCollision(key, location);
            if(!resolved)
            {
                hashData.show();
                system("pause");
                return 0;
            }
        }
    }
    hashData.show();
    system("pause");
    return 0;
}
