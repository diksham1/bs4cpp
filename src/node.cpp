#include "htmlcxx/html/ParserDom.h"
#include <bits/stdc++.h>  

using namespace std;
using namespace htmlcxx::HTML;

#include "helperfunc.h"

class bs4cpp {
    public:
        tree<Node> dom;
      
        bs4cpp(string html) {
            ParserDom parser;
            this -> dom = parser.parseTree(html);
        } 
            
        auto find_all (string requiredTagName, int limit = -1) {
            vector<decltype(dom.begin())> filteredNodes;
            filterNodes(requiredTagName, filteredNodes, limit);
            return filteredNodes;
        }

        auto find (string requiredTagName, int limit = 1) {
            return find_all(requiredTagName, limit);
        }

        void filterNodes(string requiredTagName, auto & filteredNodes, int limit) {
            auto currentNode = dom.begin();
            auto lastNode = dom.end();
            while (currentNode != lastNode  &&  limit) {
                if (currentNode -> tagName() == requiredTagName) {
                    filteredNodes.push_back(currentNode);
                    limit--;
                }
                currentNode++;
            }
        }
        
        auto getAllElements() {
            vector<decltype(dom.begin())> allElements;
            auto first = dom.begin();
            auto last = dom.end();

            while (first != last) {
                cout << "at tag "<<first -> text() << endl;
                allElements.push_back(first);
                first++;
            }
            return allElements;
        }
  
        void prettify() {
            int space = 0;
            this -> prettyprint(space, this -> dom);
        }     
        
        void prettyprint(int space, tree<Node> dom);

 /*       auto contents() {
            auto
        }*/
};

  
int main() {
 string html = "<html><head><title>Hi</title></head><body><p>I</p>  \
    <p>ok<p><b>Hate</b></p></p><p>you so much</p><br><a href='test' col='6'>S</a></body></html>";
    bs4cpp obj(html);
    obj.prettify();

    auto pitems = obj.getAllElements();

    for (auto start : pitems) {
        cout << start -> text() << endl;
        cout << endl;;       
    }
    return 0;
}


void bs4cpp::prettyprint(int space, tree<Node> dom) {
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