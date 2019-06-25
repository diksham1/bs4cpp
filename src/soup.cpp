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
            tree <Node> domtree = this -> dom;
            auto datatypeptr = make_pair(dom.begin(), dom.begin());
            vector<decltype(datatypeptr)> filteredNodes;
    //      dfs2(domtree);
            dfs(domtree, requiredTagName, filteredNodes);
     /*       for (auto p: filteredNodes) {
                auto start = p.first; 
                auto last = p.second;
                cout << start -> text() <<' ' << last ->text() << endl;
            }
       */     return filteredNodes;
        }

        void dfs (tree<Node>  domtree, string requiredTagName, auto & filteredNodes) {
                auto start = domtree.begin();
                auto last = domtree.begin();
                if (start -> tagName() == requiredTagName) {
                    last = domtree.next_sibling(start);
            //        last--;
                    filteredNodes.push_back(make_pair(start, last));
            //        cout << start -> text() << ' ' << last->text() << endl;
                    cout << filteredNodes.size() << endl;
                    
                    for (auto p: filteredNodes) {
                        auto start = p.first; 
                        auto last = p.second;
                      cout << start -> text() <<' ' << last ->text() << endl;
                    }
                }
                for (int i = 0; i < domtree.number_of_children(start); i++) {
                    dfs(domtree.child(start, i), requiredTagName, filteredNodes);
                }
        }
  
        void prettify() {
            int space = 0;
            this -> prettyprint(space, this -> dom);
        }     
        
        void prettyprint(int space, tree<Node> dom);
};

  
int main() {
 string html = "<html><head><title>Hi</title></head><body><p>I</p>  \
    <p>ok<p><b>Hate</b></p></p><p>you so much</p><br><a href='test' col='6'>S</a></body></html>";
    bs4cpp obj(html);
    obj.prettify();

    auto pitems = obj.find_all("p");

    for (auto it : pitems) {
        auto start = it.first;
        auto last = it.second;
        while (start != last) {
            cout << start -> text();;
            start++;
        }
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
