#include "soup.h"

int main() {
 string html = "<html><head><title>Hi</title></head><body><p>I</p><p>ok<p><b>Hate</b></p></p><p>you so much</p><br><a href='test' col='6'>S</a></body></html>";
    Bs4cpp obj(html);
    obj.prettify();
//    Node test;
 //   test.text("diksha");
//    pair<int,int> p(1,2);
  //  cout << p << endl;
//
//    PageElement p(test);
  //  cout << p; 
    auto pitems = obj.contents;

    for (auto start : pitems) {
        cout <<"\ntag, parent is "<<start <<" " << start.parent() << endl; 
        cout <<"Next element is "<<start.next_element() << endl;
    }
    
    return 0;
}

