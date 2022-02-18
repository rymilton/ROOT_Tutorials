#include "TRandom.h"
#include "TMath.h"
#include "TGraph.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TF1.h"
#include "TLegend.h"
#include "TString.h"

void Assignment3()
{
    Int_t n = 1000; // Number of points to generate
    Double_t x[n], y_sin[n], y_cos[n]; // Arrays to hold the data

    for(Int_t i = 0; i < n; i++)
    {
        // Rndm() generates a random number between 0 and 1
        // Multiplying by 2pi changes that range to between 0 and 2pi
        Double_t x_point = gRandom->Rndm() * 2.0 * TMath::Pi();
        
        // Generating y-points
        Double_t sin_point = 3.*TMath::Sin(x_point);
        Double_t cos_point = 2.*TMath::Cos(x_point) + 2;

        // Adding points to arrays
        x[i] = x_point;
        y_sin[i] = sin_point;
        y_cos[i] = cos_point;
    }

    // Adding points to a TGraph
    // Could also use a TGraphErrors and set the errors to 0
    TGraph *gr_sin = new TGraph(n, x, y_sin);
    TGraph *gr_cos = new TGraph(n, x, y_cos);

    // TMultiGraph is a convenient container for drawing multiple graphs
    TMultiGraph *mg_trig = new TMultiGraph();
    mg_trig->Add(gr_sin);
    mg_trig->Add(gr_cos);

    /*
        TCanvas is where the plots are drawn. 
        One is automatically defined when calling Draw()
        Alternatively, can make your own to control its size and how it looks
        Last two parameters are width and height in pixels
    */
    TCanvas *c_trig = new TCanvas("c_trig", "", 1200, 800);

    mg_trig->Draw("ap"); // Option a draws axes 
                         // Option p draws points without connecting them 
    mg_trig->GetYaxis()->SetTitle("y");
    mg_trig->GetXaxis()->SetTitle("x");

    /* 
        Adjusting appearance of graphs
        Can see markers in View->Marker Types. 
        Names like kFullCircle can be found in the TAttMarker class documentation
    */
    gr_sin->SetMarkerStyle(kFullCircle); 
    gr_sin->SetMarkerColor(kBlue);

    gr_cos->SetMarkerStyle(kFullSquare);
    gr_cos->SetMarkerColor(kGreen);


    /*  
        Defining fit functions and fitting
        The parameters we want to fit are denoted with [X] where X is the number
        of the parameter
    */

    TF1 *f_sin = new TF1(
        "f_sin", // Variable name
        "[0]*sin(x)", // Function mathematical definition
        0, // Lower range
        2. * TMath::Pi()); // Upper range
    gr_sin->Fit(f_sin, "R"); // Option R limits fit to range of function 
                             // (0 to 2pi in this case) 
    TF1 *f_cos = new TF1(
        "f_cos", 
        "[0]*cos(x)+[1]", 
        0, 
        2. * TMath::Pi());
    gr_cos->Fit(f_cos, "R");

    /*
        Creating the TLegend
        The TLegend paramaters are the relative locations on the canvas
        e.g. x1 = 0.2, x2 = 0.4: 
            Legend horizontally stretches from 20% mark of canvas to 40% mark 
        
        Can add numbers to text using TString::Form() (seen below) 
        Can also use a cstring and use sprintf()

        Function parameter numbers used in GetParameter() are the same parameter
        numbers in your definition (the [X]).
    */
    TLegend *leg_trig = new TLegend(0.2, 0.1, 0.4, 0.3);
    leg_trig->AddEntry(
        gr_sin,
        Form(
            "y = %0.2f sin(x)",
            f_sin->GetParameter(0)));
    leg_trig->AddEntry(
        gr_cos, 
        Form(
            "y = %0.2f cos(x) + %0.2f", 
            f_cos->GetParameter(0), 
            f_cos->GetParameter(1)));
    leg_trig->SetTextSize(0.04);
    leg_trig->SetBorderSize(0); // Removes box around TLegend
    leg_trig->Draw();
}