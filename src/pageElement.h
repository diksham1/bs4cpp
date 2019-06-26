class PageElement {
    Node nodeElement;
    
    public:
        std::string operator <<() {
            return nodeElement.text();
        }
};
