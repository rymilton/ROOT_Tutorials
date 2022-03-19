#include "TF1.h"
#include "TH1.h"
#include "TRandom.h"
#include "TFile.h"
#include "TStyle.h"

void save_histogram()
{
    // Create histogram with range including both Gaussians
    TH1D *h1 = new TH1D("h1","", 100, -10, 10);
    for(Int_t i = 0; i < 1000000; i++)
    {   
        h1->Fill(gRandom->Gaus(0., 1.));

        // Fill the histogram every other time with Gaus(2, 3)
        // i.e. half as many times as Gaus(0, 1)
        if(i % 2 == 0)
        {
            h1->Fill(gRandom->Gaus(2., 3.));
        }
    }
    // Creating new TFile
    // "RECREATE" overwrites any existing file named "hist.root"
    TFile *outfile = new TFile("hist.root", "RECREATE");
    h1->Write();
    outfile->Close();
    h1->Draw();
}

void read_histogram()
{
    // Reading in the saved file
    TFile *infile = new TFile("hist.root");
    TH1D *read_hist;
    // Accessing stored histogram
    infile->GetObject(
        "h1", // Saved histogram name
        read_hist); // New histogram
    TF1* fit_func = new TF1("fit_func", "gaus(0)+gaus(3)", -10., 10.);

    /*
        Initializing fit parameters
        Of course, we know the values exactly so this is cheating a bit
        But in general, you won't know what the fit parameters should be
        Initializing can help improve the fit
    */
    fit_func->SetParName(0, "A_{1}");
    fit_func->SetParameter(1, 0);
    fit_func->SetParName(1, "#mu_{1}");
    fit_func->SetParameter(2, 1.);
    fit_func->SetParName(2, "#sigma_{1}");
    
    fit_func->SetParName(3, "A_{2}");
    fit_func->SetParameter(4, 2.);
    fit_func->SetParName(4, "#mu_{2}");
    fit_func->SetParameter(5, 3.);
    fit_func->SetParName(5, "#sigma_{2}");

    read_hist->Fit(fit_func);
    read_hist->SetTitle("Double Gaussian Fit");
    read_hist->Draw();
    gStyle->SetOptFit(111); // Writing the fit parameters in the stats box
}
