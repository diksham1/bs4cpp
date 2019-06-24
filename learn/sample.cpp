#include "htmlcxx/html/ParserDom.h"
#include <bits/stdc++.h>  

using namespace std;
using namespace htmlcxx;

string trimWhitespace(string s) {
    s = std::regex_replace(s, std::regex("\\s+"), "");
    return s;
}

void dfs(int space, tree<HTML::Node> const & dom) {
    auto it = dom.begin();

    string line = "";

    for (int i = 0; i < space; i++) {
        line += "  ";
    }

    string s = it -> text();
    s = trimWhitespace(s);
    int newspace = space;

    if(s != "") {
        cout << line + it->text() << endl;
        newspace+=2;        
    }
    
    for (int i =0; i < dom.number_of_children(it); i++) {
        dfs(newspace, dom.child(it, i));
    }

    line = "";

    for (int i = 0; i < space; i++) {
        line += "  ";
    }

    s = it -> closingText();
    s = trimWhitespace(s);
    
    if(s != "") {
        cout <<line +  it->closingText() << endl;
    }
}
  
int main() {
  //Parse some html code
  std::string html = "<html>\n<body><p>hey</p><p>2nd</p></body></html>";
  HTML::ParserDom parser;
  tree<HTML::Node> dom = parser.parseTree(html);
  
  //Print whole DOM tree
//  std::cout << dom << std::endl;
    int space = 0;    
    dfs(space, dom); 
    cout << dom.size() << endl;
    return 0;
}
