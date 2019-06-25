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

        bool hasClosingTag(Node node) {
            return (node.closingText()).size();
        }

        string closingTag(Node node) {
            return node.closingText();
        }
            
        auto find_all (string requiredTagName) {
            tree <Node> dom = this -> dom;
            auto start = dom.begin();
            
            vector<decltype(start)> filteredNodes;
            dfs(start, requiredTagName, filteredNodes);
            return filteredNodes;
        }

        void dfs (auto source, string requiredTagName, auto & filteredNodes) {
                auto start = source;
                auto end = source;
                if (source->tagName() == requiredTagName) {
                    end = dom.next_sibling(source);
                    filteredNodes.push_back(start);
                }
                for (int i = 0; i < dom.number_of_children(start); i++) {
                    dfs(dom.child(source, i), requiredTagName, filteredNodes);
                }
        }
   
        void prettify() {
            int space = 0;
            this -> prettyprint(space, this -> dom);
        }     
        
        void prettyprint(int space, tree<Node> dom);
};

  
int main() {
  //Parse some html code
 string html = "<html><head><title>Hi</title></head><body><p>I</p>  \
    <p><b>Hate</b></p><p>you so much</p><br><a href='test' col='6'>S</a></body></html>";
  //Print whole DOM tree
//  std::cout << dom << std::endl;
    int space = 0;    
    bs4cpp obj(html);
    obj.prettify();
//    auto aitems = obj.find_all("a");
    auto pitems = obj.find_all("p");

    for (auto it : pitems) {
        cout << *it << endl;
        auto next_sibl = obj.dom.next_sibling(it);
        while (it != next_sibl) {
            cout << it->text() << endl;
            it++;
        }
    }

  /*  for (auto nodelist : pitems) {
        for (auto node: nodelist) {
            cout << node <<endl;
        }
        cout << endl;
    }

*/
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
