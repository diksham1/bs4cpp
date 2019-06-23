# `__eq__`

    - a tag is equal to another if name, attributes and contents (recursively) are same
   **returns**: boolean value True or False

--- 

# `has_attr(key)`
    
    - return true if the key is in the self.attrs dictionary
   **returns**: boolean value obtained above 
    
---

# `get_attribute_list`
    
    - same as get(), but always returns a list
    - instead of returning the value directly
        wrap into a list and then return
   **returns**: list containing the value  

---

# `get(key)`

    - self.attrs gives the dictionary of the object attributes
    - use the dictionary method get to get the key value
   **returns**: the key value

---

# `index(element)`

    - enumerate over self.contents
    - if child is the element needed, return i
   **returns**: i if the element if found, else Exception

---

# `clear`
    
    - if decompose is true, decompose
    - else extract all the children
   **returns**: nothing

---

# `decompose()`

    - extract the tag first
    - iterate over the next elements (i)
    - assign null to them and clear their dictionaries
    - do this till i is not None
   **returns**: nothing 

---

# `get_text`

    - get all child strings concatenated using the given separator
    - get all strings using the \_all_strings method 
    - concatenate them using ''.join()
   **returns** - the concatenated string

---

# `string`

    - if the child is a string, return the child
    - else recursively return the child.string
   **returns**: returns the string recursively
 
---

# `_all_strings`

    - by default yields only strings of navigable string class and CData class
    - loop through self.descendants and continue if not navigable string
    - strip them (to take care of '\n')
    - yield the descendant if still not null
   **returns**: yields the next string 

---

# `__copy__`
    
    - makes a clone using type(self)(self)
    - copy all the children from the original to the clone
   **returns**: the clone

---

# `is_empty_element`
    
    - aka self closing tags, like *<br>* , *<img>* etc
    - a tag is empty if it has no contents and it can be an empty tag  
   **returns**: len(self.contents) == 0 and self.can_be_empty
