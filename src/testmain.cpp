#include "soup.h"
  
int main() {
 string html = "<html><head><title>Hi</title></head><body><p>I</p>  \
    <p>ok<p><b>Hate</b></p></p><p>you so much</p><br><a href='test' col='6'>S</a></body></html>";
    Bs4cpp obj(html);
    obj.prettify();

    auto pitems = obj.find_all("p");

    for (auto start : pitems) {
        cout << start -> text() << endl; 
    }
    
    return 0;
}

