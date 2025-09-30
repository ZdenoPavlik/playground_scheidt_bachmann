﻿---
title: Sample Presentation
author: Zdenko Pavlik
lang: en-US
institute: Scheidt&Bachmann Slovakia s.r.o.    
pdf-engine: lualatex
mainfont: "Segoe UI Emoji"
cmd: pandoc slideshow_02_special_member_functions.md -t beamer -o slideshow_02_special_member_functions.pdf
---

# Introduction

![SB logo](images/sb_logo.png){ height=64px }

Welcome to this sample presentation.

- Point 1
- Point 2
- Point 3

---

# Some emojis

-  Warning message
-  High performance
-  Secure design
-  Innovative

Another emojis
https://emojipedia.org/en/search?q=programming

---

# Goals

1. Show Markdown-based slides
2. Convert to PDF using Pandoc
3. Stay productive

---

# Code Sample

```cpp
#include <iostream>
int main() {
    std::cout << "Hello, world!" << std::endl;
}
```

---

# My Presentation
- Point 1
- Point 2
    - **Bold**
    - _Italic_
    - `code`

---

use following command in order to generate pdf
```pandoc presentation.md -t beamer -o presentation.pdf```