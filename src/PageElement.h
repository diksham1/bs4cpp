class PageElement { 
    htmlcxx::HTML::Node nodeElement;   
    htmlcxx::HTML::Node parentNode;
    
    public:
        PageElement(htmlcxx::HTML::Node node) {
            this -> nodeElement = node;
        }
        std::string name() {
            return (std::string)(nodeElement);
        }
        std::string tagName() {
            return nodeElement.tagName();
        }
        PageElement parent() {
            return parentNode;
        }
        PageElement setParent(htmlcxx::HTML::Node myParent) {
            parentNode = myParent;
        }
};

std::ostream& operator<<(std::ostream& out, PageElement element) {
    std::string name = element.name();
    out << name;
    return out;
}
