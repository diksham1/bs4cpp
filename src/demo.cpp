#include <sstream>
#include <fstream>
#include <iostream>

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
    
    
    return 0;
}
