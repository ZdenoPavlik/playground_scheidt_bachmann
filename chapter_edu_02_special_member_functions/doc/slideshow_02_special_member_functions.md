---
title: Special member functions
author: Zdenko Pavlik
lang: en-US
institute: Scheidt&Bachmann Slovakia s.r.o.    
pdf-engine: lualatex
mainfont: "Segoe UI Emoji"
cmd: pandoc slideshow_02_special_member_functions.md -t beamer -o slideshow_02_special_member_functions.pdf
---

# Special member functions


\begin{center}
... done with support of
\end{center}

::: {.center}
![scheidt&bachmann](images/sb_logo.png){ height=64px }
:::

---

# Agenda
- Lessons learned from previous lesson (class introduction)
- Examples from previous lesson
- Special member function
- Compiler generated functions
- Copy semantics 
- Move semantics
- Copy vs move
- Rule of Zero
- Rule of Three
- Rule of Five
- Copy elision & RVO
- Practical examples - How to prevent class from being movable, copyable. Compare with std::unique_ptr
 
---

# Lessons learned from previous lesson (class introduction)

---

# Lessons learned from previous lesson (class introduction)
- Virtual destructor
   - Always declare destructor as `virtual`, otherwise it may not be called at all.
- Uninitialized variables
   - Always initialize your variables, at least with `{}`, otherwise those variables will obtain random values in release version.
- Encapsulation
   - Do not populate your variables as `public` to improve personal comfort. Other users can break functionality of your class.
-  Use keywords like `const`, `override`, `final`
   - It will give a hint to other developers how to behave to your class.

---

# Example of usage from previous lesson

---

# Example of usage from previous lesson
 - Inheritance (`Logger` example)
  - Reusing functionality
 - Polymorphism (`std::vector<Animal> zoo` example)
 - Polymorphism (`foo(Parent class)` example)

---

# Special member function

---

# Special member function
- Constructor (default or parametrized)
- Destructor
- Copy constructor
- Copy assignment operator
- Move constructor
- Move assignment operator

---

# Compiler generated functions

---

# Copy semantics 

---

# Move semantics

---

# Copy vs move

---

# Rule of Zero

---

# Rule of Three

---

# Rule of Five

---

# Copy elision & RVO

---

# Practical examples - How to prevent class from being movable, copyable. Compare with std::unique_ptr

---
