#include <iostream>
#include <htmlcxx/html/ParserDom.h>

using namespace std;
using namespace htmlcxx;

int main() {
    HTML::ParserDom parser;   
    string html = "<html><body><br><a href='sikha'>hey i am a girl</a></body></html>"; 
    tree<HTML::Node> dom = parser.parseTree(html);
    auto start = dom.begin();
    auto end = dom.end();
    cout << typeid(start).name() << endl;
    while(start != end) {
        if (start -> isTag()) {
            cout <<"Tag found \n";
            cout <<"Tag text :\t" << start->text() << endl;
            cout <<"Tag closing Text: "<< start->closingText() <<endl;
            cout <<"Tag offset \t"<< start -> offset() << endl;
            cout<<"Length \t "<<start->length() << endl;
            cout<<"tagname \t"<<start->tagName() <<endl;
            cout <<"isTag \t"<<start -> isTag() << endl;
            cout <<"is Comment "<<start->isComment()<<endl;
            start -> parseAttributes();
            cout <<"attribute href "<<(start->attribute("href")).second<<endl;
            map<string, string> mp = start->attributes();
            
            for (auto x: mp) {
                cout << x.first << ": "<< x.second <<endl;
            }
        }
        cout << endl;   
        start++;
    }

    return 0;
}
