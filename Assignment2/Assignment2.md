# Assignment 2
1. Read “Histograms” under the ROOT Manual - Functional parts section.
2. Within a new macro, create and fill a histogram with 10,000 random Gaussian (Mean = 0, Sigma = 1) points using TH1::FillRandom().
3. Create and fill another histogram with 10,000 random Gaussian points (Mean = 1, Sigma = 1) using TH1::Fill() and gRandom->Gaus().
4. Create a third histogram that is a clone of the histogram in (2). Then scale this new histogram by a factor of 2 using TH1::Scale().
5. Draw all three histograms. You can draw multiple histograms by using TH1::Draw(“same”) after the first histogram.
6. Change the colors of the histograms using TH1::SetLineColor(). Colors are kBlue, kRed, etc.
7. Change the y-axis range using TH1::SetAxisRange() to see the entirety of all three histograms. Hint: The first histogram drawn should do this.
