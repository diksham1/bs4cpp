**BS4CPP**

This project aims to translate the Python BeautifulSoup Library to C++. 

``ID: 2000072
Author: Diksha``

I will be using the HTMLCXX parser and the tree.h API. I'll implement the major functions available in BeautifulSoup in the BS4CPP library. 

As of now, the functions completed are :

    PageElement:
        
    - Constructor
    - unwrap
    - attrs
    - text
    - clear
    - setAttr
    - append (both string and Tag)
    - extend
    - isTag
    - name
    - parent
    - next_element
    - previous_element
    - previous_sibling
    - next_sibling
    - descendants
    - last_descendant
    - insert (both string and tag)
    - replace_with (both string and tag)
    
    Soup:   
    
    - constructor
    - new_tag
    - find_all
    - find
    - prettify
    - contents
    - strings
    - get_text
    
