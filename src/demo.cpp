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

    auto secondptag = allPtags[1];

    auto descendantList = secondptag.descendants();      
    cout << "descendants are " << endl;

    for (auto x: descendantList) {
        cout << x << endl;
    }

    auto newtag = soup.new_tag("br");
    
    cout <<"Created a new tag: " << newtag << endl;
  
    auto bodyTag = soup.find("body");
    cout << "Appending the tag: " << endl;

    bodyTag.append(newtag);

    soup.prettify();    

    return 0;
}
