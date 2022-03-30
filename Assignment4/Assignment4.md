# Assignment 4: File input and ouput

1. Read "ROOT files" under the ROOT Manual - Basics section.
	- If you don't understand the smart pointers in this section, you can try looking at sections 11.1 and 11.2 in the [Users Guide](https://root.cern.ch/root/htmldoc/guides/users-guide/ROOTUsersGuide.html#inputoutput).
2. Fill a histogram many times with 2 Gaussian random numbers. 
	- One Gaussian with mean 0 and RMS 1, the other with mean 2 and RMS 3.
	- Fill the first type of random number (mean 0, RMS 1) twice as many times as the second type.
	- In the end, you will have two overlapping Gaussians in a single histogram.
3. Write this histogram into a ROOT file.
4. Open the previous ROOT file and obtain the saved histogram.
	- You can look at the file in a file browser by opening ROOT and typing `TBrowser b`.
6. Fit the histogram with a defined function and try to retreive the parameters you input in step 2.
	- The fit function is a sum of two Gaussians, of course.
	- Hint: To obtain the fit parameters, it is sometimes helpful to initialize the parameter values.  
