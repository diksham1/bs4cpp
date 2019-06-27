class PageElement { 
    htmlcxx::HTML::Node nodeElement;   
    tree<htmlcxx::HTML::Node>::iterator myIterator;
    tree<htmlcxx::HTML::Node>* myDom;

    public:    
       
        PageElement(htmlcxx::HTML::Node & node, auto myIterator, auto myDom) {
            this -> nodeElement = node;
            this -> myIterator = myIterator;
            this -> myDom = myDom;
            node.parseAttributes(); 
        }

        std::map<std::string, std::string> attrs() {
            return  myIterator -> attributes();
        }
        
        void setAttr(std::string key, std::string value) {
            auto attrs = myIterator -> attributes();
            attrs[key] = value;
        }

        void append (PageElement myNewTag) {
            auto it = myDom -> append_child (myIterator, myNewTag.nodeElement);
            myNewTag.myIterator = it;
        }

        void append (std::string myNewChild) {
            htmlcxx::HTML::Node newnode;
            newnode.text(myNewChild);
            newnode.closingText("");
            newnode.tagName(myNewChild);
            newnode.isTag(false);
            myDom -> append_child (myIterator, newnode);
        }
        
        void extend (std::vector <std::string> children) {
            for (auto child: children) {
                append(child);
            }
        }

        void extend (std::vector <PageElement> children) {
            for (auto child: children) {
                append(child);
            }
        }

        bool isTag() {
            return nodeElement.isTag();
        }
        
        std::string name() {
            return (std::string)(nodeElement);
        }
        
        PageElement parent() {
            auto parent_iterator = myDom->parent(myIterator);
            if (parent_iterator == NULL) 
                parent_iterator = myIterator;
            return PageElement(*parent_iterator, parent_iterator, myDom);
        }

        PageElement next_element() {
            auto iteratorCurrentNode = myIterator;
            std::string textCurrentNode  = "";      
            auto endIterator = myDom -> end();

            while (textCurrentNode == "" && ++iteratorCurrentNode != endIterator) {
               textCurrentNode = trimWhitespace(iteratorCurrentNode -> text());
            }        
            if(iteratorCurrentNode == endIterator) {
                iteratorCurrentNode = myIterator;
            }   
            return PageElement(*iteratorCurrentNode, iteratorCurrentNode, myDom);
        }
        
        PageElement previous_element() {
            auto iteratorCurrentNode = myIterator;
            std::string textCurrentNode  = "";      
            auto endIterator = myDom -> begin();
            endIterator--;

            while (textCurrentNode == "" && --iteratorCurrentNode != endIterator) {
               textCurrentNode = trimWhitespace(iteratorCurrentNode -> text());
            }        
            if(iteratorCurrentNode == endIterator) {
                iteratorCurrentNode = myIterator;
            }   
            return PageElement(*iteratorCurrentNode, iteratorCurrentNode, myDom);
        }

        PageElement previous_sibling() {
            auto prevSiblIterator = myDom -> previous_sibling(myIterator);
            if (prevSiblIterator == NULL) {
                prevSiblIterator = myIterator;
            }
            return PageElement(*prevSiblIterator, prevSiblIterator, myDom);
        }
        
        PageElement next_sibling() {
            auto nextSiblIterator = myDom -> next_sibling(myIterator);
            if (nextSiblIterator == NULL) {
                nextSiblIterator = myIterator;
            }
            return PageElement(*nextSiblIterator, nextSiblIterator, myDom);
        }

        std::vector <PageElement> descendants() {
            std::vector <PageElement> descendantList;
            int num = myDom -> size(myIterator) - 1;
            auto currentIterator = myIterator;
            currentIterator++;
            
            while (num--) {
               descendantList.push_back(PageElement(*currentIterator, currentIterator, myDom));
               currentIterator++;
            }
            return descendantList;
        } 
        
        PageElement last_descendant() {
            auto descendantList = descendants();
            if (descendantList.size()) {
                return descendantList.back();
            }
            return PageElement(nodeElement, myIterator, myDom);
        }      

        void insert (auto position, std::string myNewChild) {
            auto newChildPosition = myDom -> child(myIterator, position);
            htmlcxx::HTML::Node newnode;
            newnode.text(myNewChild);
            newnode.closingText("");
            newnode.tagName(myNewChild);
            myDom -> insert( newChildPosition, newnode);
        }    
        
};

std::ostream& operator<<(std::ostream& out, PageElement element) {
    std::string name = element.name();
    out << name;
    return out;
}
