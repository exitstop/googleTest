#include "ya0.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <codecvt>
#include <locale>

using std::cout;
using std::wcout;
using std::endl;
using std::string;
using std::wstring;

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
    //setlocale(LC_ALL, "Russian");
    std::locale::global(std::locale(""));

    // запись в файл
    std::wofstream outFile;

    //S{L"камни"}, J{L"драгоценности"};
    wstring S, J;

    std::wifstream inFile;

    inFile.open("in.txt", std::wofstream::in);

    if(inFile.is_open()) {
        //std::getline(inFile, S);
        inFile >> J;
        inFile >> S;

        std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_conv;
        cout << "line: " << utf8_conv.to_bytes(S) << endl;
        cout << "line: " << utf8_conv.to_bytes(J) << endl;

        size_t count = 0;
        for(const auto ch: S) {
            count += ( J.find(ch) != wstring::npos );
            //cout << "line: " << utf8_conv.to_bytes(ch) << " count: " << J.(ch) << endl;
        }
        cout << "count: " << count << endl;
        inFile.close();

        outFile.open("out.txt", std::wofstream::out);
        if(outFile.is_open()) {
            outFile << count << endl;
            outFile.close();
        }
    } else {
        cout << "file in.txt not open" << endl;
    }

}
