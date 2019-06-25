#include "htmlcxx/html/ParserDom.h"
#include <bits/stdc++.h>  

using namespace std;
using namespace htmlcxx;

#include "helperfunc.h"

class bs4cpp {
    public:
        string title;
        tree<HTML::Node> dom;
      
        bs4cpp(string html) {
            HTML::ParserDom parser;
            this -> dom = parser.parseTree(html);
            this -> setup(); 
        }

        void setup() {
            tree<HTML::Node> dom = this -> dom;
            auto start = dom.begin();
            auto end = dom.end();

            while (start != end) {
                string tag = start -> text();
                cout << *start <<endl;
                if (tag == "<title>") {
                    start++;
                    string s = start -> text();
                    s = trimWhitespace(s);
                    while( s == "") {
                        start++;
                        s = start -> text();
                        s = trimWhitespace(s);
                    }
                    this -> title = s;
                    break;
                }
                start++;
            }
        }
    
    void prettify() {
        int space = 0;
        this -> prettyprint(space, this -> dom);
    }

    void prettyprint(int space, tree<HTML::Node> dom) {
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
            prettyprint(newspace, dom.child(it, i));
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
};

  
int main() {
  //Parse some html code
 string html = "<html><head><title>Hi</title></head><body><p>I</p>  \
    <p><b>Hate</b></p><p>you</p><a href='test' col='6'>S</a></body></html>";
  //Print whole DOM tree
//  std::cout << dom << std::endl;
    int space = 0;    
    bs4cpp obj(html);
    obj.prettify();
    cout <<"Title is "<<obj.title <<endl;
    return 0;
}
