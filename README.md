# ROOT_Tutorials
Installation:

To install ROOT locally, go to:
https://root.cern/install/

Option 1: Download a pre-compiled binary distribution
 
To install on MacOS, the Xcode developer package must be installed using xcode-select --install
Download the latest release (currently 6.24/0.6) for your operating system and unpack the files in your preferred destination
Enable the ROOT libraries by using source root/bin/thisroot.sh
Tip: Add this command to your .bashrc or .profile to avoid typing this every time you start your computer
Option 2: Use Homebrew

Details about halfway down the installation guide under “MacOS package managers”

First use:

Once everything is installed, try it out by typing root into the terminal. If everything is installed correctly you should see: root[0] 
ROOT is now waiting for user input. To exit: Type .q

Typically, ROOT (similar to Python) is an interpreted language and reads code line-by-line instead of compiling it all together. So you can program within the terminal by passing in lines of code:
root[0] int x = 1
root[1] int y = 5
root[2] x + y
ROOT should have outputted (int) 6. This is pretty tedious to do though and is only useful when doing quick things. Instead, ROOT typically uses “macros”, which are just files of C++ code read in line-by-line. 

 
Learning the details of ROOT

The most direct way of learning ROOT is looking through the manual found here: https://root.cern/manual/

First assignment - Creating and running macros:

Read “First Steps with ROOT”, “ROOT architecture and components”, and “ROOT macros and shared libraries” under the ROOT Manual - Basics section
Create your first macro! 
Call it “MyFirstMacro.cpp”. Make the main function “void MyFirstMacro()” and have it print “Hello World!”.
Run the macro in ROOT using “.x”, then exit ROOT
Run the macro in ROOT using “.L”
In the same file, make a new function called “void FunctionTwo()” and have it print “This is my second function.”
Try running the macro file in ROOT using “.x”. What is the output?
Now change the function name of “MyFirstMacro()” to “MyMacro() and try using “.x” again. What happens? (Change function name back afterwards)
Restart ROOT and obtain the correct output of FunctionTwo() using “.L”.
Finally, make a third function called “int Sum(int x, int y)” and have it return the sum of x and y
Try calling the function with any two numbers within the ROOT terminal and verify it’s correct. 

Congrats! You now know how to create and run macros and functions in ROOT.

Second assignment - Histograms:
Read “Histograms” under the ROOT Manual - Functional parts section.
Within a new macro, create and fill a histogram with 10,000 random Gaussian (Mean = 0, Sigma = 1) points using TH1::FillRandom().
Create and fill another histogram with 10,000 random Gaussian points (Mean = 1, Sigma = 1) using TH1::Fill() and gRandom->Gaus().
Create a third histogram that is a clone of the histogram in (2). Then scale this new histogram by a factor of 2 using TH1::Scale().
Draw all three histograms. You can draw multiple histograms by using TH1::Draw(“same”) after the first histogram.
Change the colors of the histograms using TH1::SetLineColor(). Colors are kBlue, kRed, etc.
Change the y-axis range using TH1::SetAxisRange() to see the entirety of all three histograms. Hint: The first histogram drawn should do this.

A helpful resource that you’ll likely need frequently is the ROOT reference guide. You can find it by clicking “Reference” on the ROOT webpage. Easier though is to just google the class you’re looking for (e.g. “th1 root”). These pages give a description of classes and their member functions. 

