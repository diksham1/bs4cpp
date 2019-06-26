#include "htmlcxx/html/ParserDom.h"
#include <iostream> 
#include <regex> 
#include "helperfunc.h"


using namespace std;
using namespace htmlcxx::HTML;


class Bs4cpp {
    public:
        tree<Node> dom;
        vector<decltype(dom.begin())> contents;
      
        Bs4cpp(string html) {
            ParserDom parser;
            this -> dom = parser.parseTree(html);
            this -> contents = getContents();
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
            for (auto elementPtr: contents) {
                if (elementPtr -> tagName() == requiredTagName) {
                    filteredNodes.push_back(elementPtr);
                }
            }
        }
  
        void prettify() {
            int space = 0;
            this -> prettyprint(space, this -> dom);
        }     
 
        vector<decltype(dom.begin())> getContents() {
            vector<decltype(dom.begin())> allElements;
            auto startptr = dom.begin();
            auto endptr = dom.end();
            while (startptr != endptr) {
                string tagText = trimWhitespace(startptr -> text());
                if (tagText != "")
                    allElements.push_back(startptr);
                startptr++;
            }
            return allElements;
        }       
        void prettyprint(int space, tree<Node> dom);
};

void Bs4cpp::prettyprint(int space, tree<Node> dom) {
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
