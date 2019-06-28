#include "htmlcxx/html/ParserDom.h"
#include <iostream> 
#include <regex> 
#include "helperfunc.h"
#include "PageElement.h"


using namespace std;
using namespace htmlcxx::HTML;


class Bs4cpp {
    public:
        tree <Node> dom;

        Bs4cpp(string html) {
            html = rmWhitespace(html);
            ParserDom parser;
            this -> dom = parser.parseTree(html);
            auto start = dom.begin();
            auto end = dom.end();
            while (start != dom.end()) {
                if (start -> isTag()) {
                    start -> text(lower(trimWhitespace(start -> text())));
                    start -> tagName(lower(trimWhitespace(start -> tagName())));
                } else { 
                    start -> text(trimWhitespace(start -> text()));
                    start -> tagName(trimWhitespace(start -> tagName()));
                }
                start -> closingText(lower(start -> closingText()));
                start++;
            }
        }

        PageElement new_tag (string tagname) {
            tagname = lower(tagname);
            Node newNode;
            newNode.tagName(tagname);
            newNode.text("<" + tagname + ">");
            newNode.closingText("");
            vector <string> emptyTags = {"area", "base", "br", "col", "command", "embed", "hr", "img", "input","keygen", "link", "meta", "param", "source", "track", "wbr"};
            if (std::find(emptyTags.begin(), emptyTags.end(), tagname) == emptyTags.end()) {
                string closetext = "</" + tagname + ">";
                newNode.closingText(closetext);
            }
            newNode.isTag(true);
            
            return PageElement(newNode, dom.end(), &dom);
        } 
            
        auto find_all (string requiredTagName, int limit = -1) {
            requiredTagName = lower(requiredTagName);
            vector<PageElement> filteredNodes;
            filterNodes(requiredTagName, filteredNodes, limit);
            return filteredNodes;
        }
        
        auto find (string requiredTagName) {
            requiredTagName = lower(requiredTagName);
            return find_all(requiredTagName, 1)[0];
        }

        auto find (string requiredTagName, int limit) {
            requiredTagName = lower(requiredTagName);
            return find_all(requiredTagName, limit);
        }

        void filterNodes(string requiredTagName, auto & filteredNodes, int limit) {
            requiredTagName = lower(requiredTagName);
            for (auto element: contents()) {
                if (element.name() == requiredTagName) {
                    filteredNodes.push_back(element);
                }
            }
        }
  
        void prettify() {
            int space = 0;
            this -> prettyprint(space, this -> dom);
        }     
 
        vector<PageElement> contents () {
            vector<PageElement> allElements;
            auto startptr = dom.begin();
            auto endptr = dom.end();
            while (startptr != endptr) {
                string tagText = trimWhitespace(startptr -> text());
                if (tagText != "") {
                    auto my_iterator = startptr;        
                    allElements.push_back(PageElement(*startptr, my_iterator, &dom));
                }
                startptr++;
            }
            return allElements;
        }
 
        vector <string> strings () {
            vector <string> stringList;
            for (auto element: contents()) {
                if (element.isTag())    continue;
                stringList.push_back(element.name());
            }
            return stringList;
        }

        string get_text() {
            string allText = "";
            for (auto str: strings()) {
                allText += str;
            } 
            return allText;
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
