#include "ya0.hpp"

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

void func0()
{
    string j = "abcabcab";
    string s = "ab";
    int result = 0;
    for (const char ch : s) {
        result += j.find(ch) != string::npos;
    }
    cout << result << endl;
}

void func1()
{
    std::ofstream outFile;
    std::ifstream inFile;

    inFile.open("in.txt", std::ifstream::in);

    if(inFile.is_open()) {
        string J, S;
        std::getline(inFile, S);
        std::getline(inFile, J);
        cout << "line : " << S << endl;
        cout << "line : " << J << endl;
    } else {
        cout << "file in.txt not open" << endl;
    }
}
