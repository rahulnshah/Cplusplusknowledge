// backspaceSimulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stack> 
#include <cctype> 
using namespace std;
int main(int argc, char* argv[])
{
    if(argc < 2)
    { 
        cerr << "No file is found." << endl;
        exit(1);
    }
    fstream inFile;
    string fileName = argv[1];
    inFile.open(fileName, ios::in);
    if (!inFile.is_open()) 
    {
        cerr << "File cannot be opened: " << fileName << endl;
    }
    else if (inFile.peek() == fstream::traits_type::eof())
    {
        cerr << "File is empty." << endl;
    }
    else
    {
        char ch;
        // init a stack of strings 
        stack<char> mystack;
        while (inFile.get(ch)) 
        {
            if (isalnum(ch) || isspace(ch) || ch == '.' || ch == '\n') {
                mystack.push(ch);
            }
            else
            {
                if (!mystack.empty())
                {
                    mystack.pop();
                }
            }
            
        }
        // create a string fill it up with contents of the stack
        string backspacedStr = "";
        while (!mystack.empty())
        {
            backspacedStr += mystack.top();
            mystack.pop();
        }
        // cout << "backspaced str: " << endl << backspacedStr << endl;
        //reverse the string 
        reverse(backspacedStr.begin(), backspacedStr.end());
        // cout << "reversed backspaced str: " << endl << backspacedStr << endl;
        // close the file 
        inFile.close();
        //reopen the file in writing mode 
        string outputFileName = argv[2];
        inFile.open(outputFileName, ios::out);
        if (!inFile.is_open())
        {
            cerr << "File cannot be opened: " << fileName << endl;
        }
        else
        {
            //rewrite the file with the reversed string 
            inFile << backspacedStr;
            inFile.close();
        }
    }
    return 0;
}


