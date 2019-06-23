# `navigable string`

    - inherited from pageElement
    - type(self) - <class.str>
    - type(self)(self) - <class.str>(self) => copy of object
---

# `__copy__`
    
    - returns type(self)(self) -> copy

---

# `__getattr__`

    - for backward compatibility
    - returns the string attribute of the NavigableString
    - else raises exception
   **returns**: self if the attribute asked is 'string'

---


