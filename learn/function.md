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
    2. next\_element to be changed
    3. previous\_element to be changed
    4. previous\_sibling and next\_sibling to be changed
   **returns**: self

---
