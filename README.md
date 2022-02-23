# ROOT Tutorial

## Installation

To install ROOT locally, go to:
https://root.cern/install/

Download the latest version for your operating system and follow the isntallation instructions.

## First use

Once everything is installed, try it out by typing root into the terminal. If everything is installed correctly you should see: `root[0]`

ROOT is now waiting for user input. **To exit: Type `.q`**

Typically, ROOT (similar to Python) is an interpreted language and reads code line-by-line instead of compiling it all together. So you can program within the terminal by passing in lines of code:

`root[0] int x = 1`

`root[1] int y = 5`

`root[2] x + y`

ROOT should have outputted `(int) 6`. This is pretty tedious to do though and is only useful when doing quick things. Instead, ROOT typically uses “macros”, which are just files of C++ code read in line-by-line. 

 
## Learning the details of ROOT

The most direct way of learning ROOT is looking through the [manual](https://root.cern/manual/).


A helpful resource that you’ll likely need frequently is the [ROOT reference guide](https://root.cern/doc/master/index.html). Easier though is to just Google the class you’re looking for (e.g. “[th1 root](https://root.cern.ch/doc/master/classTH1.html)”). These pages give a description of classes and their member functions. 

This tutorial gives some practice assignments that increase in complexity and difficulty. Solutions are also provided -- .cpp files for code and .txt files for answering questions. If you have any questions, please feel free to contact me or shoot me an email at rmilton@ucla.edu .
