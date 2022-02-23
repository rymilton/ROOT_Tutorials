# Assignment 3: Graphs and Fitting

1. Read the sections on Graphs, Graphics, and Fitting in ROOT Manual - Functional Parts
2. Generate 1000 random numbers between 0 and 2pi
     - gRandom->Rndm() generates a number between 0 and 1. This range can go from 0 to X by multiplying the output by X.

3. Using these points, generate sin values with 'A sin(x)' and cos values with 'B cos(x) + C' where A, B, and C are values of your choice.
4. Make TGgraphs of these points and draw them together with a TMultiGraph.
      - Make sure you differentiate the curves by making distinct colors/markers.
5. Create TF1s of the same form as your sin and cos functions and fit the graphs.
6. Create a TLegend and label the plots with their formulas, but with the fit parameters substituted for the A, B, and C values. 
     - Can easily do this using TString::Form() or sprintf().
     - Can limit the decimal places using %0.Nf where N is the number of numbers after the decimal.
