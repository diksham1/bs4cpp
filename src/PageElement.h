class PageElement { 
    htmlcxx::HTML::Node nodeElement;   
    tree<htmlcxx::HTML::Node>::iterator myIterator;
    tree<htmlcxx::HTML::Node> myDom;

    public:    
        std::map<std::string, std::string> attrs;  
        
        PageElement(htmlcxx::HTML::Node & node, auto myIterator, auto myDom) {
            this -> nodeElement = node;
            this -> myIterator = myIterator;
            this -> myDom = myDom;
            nodeElement.parseAttributes();
            attrs = (nodeElement).attributes();
        }
        
        std::string name() {
            return (std::string)(nodeElement);
        }
        
        PageElement parent() {
            auto parent_iterator = myDom.parent(myIterator);
            if (parent_iterator == NULL) 
                parent_iterator = myIterator;
            return PageElement(*parent_iterator, parent_iterator, myDom);
        }
        
};

std::ostream& operator<<(std::ostream& out, PageElement element) {
    std::string name = element.name();
    out << name;
    return out;
}
