#include "TH1.h"
#include "TRandom.h" // Used to generate random numbers

void Assignment2()
{
    TH1D *h_gaus1 = new TH1D(
        "h_gaus1", // histogram name -- should be unique
        "Histogram from a Gaussian", // histogram title -- does not need to be unique
        100, // number of bins
        -3., // lower x range
        3.); // upper x range

    // Filling with random Gaussian of mean 0 and sigma 1
    h_gaus1->FillRandom("gaus", 10000); 

    TH1D *h_gaus2 = new TH1D(
        "h_gaus2",
        "",
        100,
        -3,
        3.);

    for (Int_t i = 0; i < 10000; i++)
    {
        // Filling with Gaussian of mean 1 and sigma 1
        h_gaus2->Fill(gRandom->Gaus(1., 1.)); 
    }

    // Creating a clone of original histogram
    // (TH1D*) tells compiler what type of object h_gaus3 should be
    TH1D *h_gaus3 = (TH1D*) h_gaus1->Clone();
    h_gaus3->Scale(2.);

    // Drawing the histograms
    h_gaus1->Draw();
    h_gaus2->Draw("same"); // The "same" option draws on top of the first hist.
    h_gaus3->Draw("same");

    // To see available colors, go to View->Colors in the pop-up window
    h_gaus1->SetLineColor(kBlack);
    h_gaus2->SetLineColor(kRed);
    h_gaus3->SetLineColor(kBlue);

    h_gaus1->SetAxisRange(0, 600., "y");
}