---
title: Unit tests 01 - Introduction
author: Zdenko Pavlik
lang: en-US
institute: Scheidt&Bachmann Slovakia s.r.o.    
pdf-engine: lualatex
mainfont: "Segoe UI Emoji"
cmd: pandoc chapter_edu_unittests_01_intro.md -t beamer -o chapter_edu_unittests_01_intro.pdf
classoption:
  - t
  - aspectratio=169
---

# Unit tests 01 - Introduction


\begin{center}
... done with support of
\end{center}

::: {.center}
![scheidt&bachmann](images/sb_logo.png){ height=64px }
:::

---

# Agenda
- Lessons learned from previous lesson (Rule of 5)
- Intro into containers
- Establishing containers for demonstration 

 
---

# Lessons learned from previous lesson (Rule of 5)
Class has several function, that are used when we alter lifecycle of class (either by new creation, assigning of copying from already existing classes). Each of them can be default, user defined or deleted.
