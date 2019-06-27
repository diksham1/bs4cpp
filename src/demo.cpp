#include <sstream>
#include <fstream>
#include <iostream>
#include "soup.h"

using namespace std;

string readFile(string fileName) {
    stringstream strStream;
    ifstream fhand(fileName);
    strStream << fhand.rdbuf(); 
    std::string str = strStream.str(); 
    return str;
}

int main(int argc, char *argv[]) {
    string fileName;
    if (argc >= 2)
        fileName = argv[1];
    else
        cin >> fileName;
    
    string fileData = readFile(fileName);
    
    auto soup = Bs4cpp(fileData);
        
    auto allContents = soup.contents();

    for (auto element: allContents) {
        cout << element << endl; 
    }

    soup.prettify();

    auto allPtags = soup.find_all("p");

    for (auto ptag: allPtags) {
        cout << ptag.name() << endl;
    } 

    auto body = soup.find("body");
    
    cout << body.parent() << endl;

    auto descendantList = body.descendants();      

    for (auto x: descendantList) {
        cout << x << endl;
    }

    return 0;
}
