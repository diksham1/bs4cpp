# `parents`
    
    - loop through changing i = i.parent as long i is not None
    - keep yielding the i's obtained
   **returns**: yields the i at each step

---

# `next_elements`, `previous_siblings` and `next_siblings` 

    - loop through changing i to i.next_sibling as long as i is not None
    - keep yielding the i's obtained
   **returns**: yeilds the i at each step 

---

# `insert_after(arguments)`

    - same as inserting the list of arguments at the index of self + 1
    - iteratively insert all the elements + offset
   **returns**: nothing

---

# `insert_before(arguments)`

    - same as inserting the list of arguments at the index of self. 
    - iteratively insert the elements at the index of self
   **returns**: nothing 

---
# `Extend`
    
    - appends a set of tags to the object
    - calls append internally for each tag in the taglist
   **returns**:  nothing 

---

# `Append`
    
    - Insertion at the last position
    - last position = len(self.contents)
   **returns**: nothing

---
# `insert `

    - Just like insertion in a linked list
    - change previous and next siblings and elements
   **returns**: nothing

---
# ` replace_with `

    - Store the index of the the object
    - Extract the child
    - Insert new one at the same index
   **returns**: the object (self)

---

# ` unwrap `

    1. Store object's index
    2. Find parent
    3. Extract the object(self)
    4. Insert the object's children at the index of object
   **returns**: the object (self)

---
# `wrap`

    1. Replace myself with the wrapper
    2. Append myself to the wrapper
   **returns**: the wrapper

---
# `extract`

    1. Just like node deletion in a linked list
    2. next_element to be changed
    3. previous_element to be changed
    4. previous_sibling and next_sibling to be changed
   **returns**: self

---

# `_last_descendant`

    1. if next_sibling is not none, last child is the previous element of the next_sibling
    2. else keep on replacing last child with the last element in the list of last.contents, it will always replace last child with last of it's children
    3. When no longer possible to do so, we have found the last descendant.
   **returns**: last child

---


