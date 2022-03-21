#include <iostream>
#include "TRandom.h"
#include "TH1.h"
#include "TProfile.h"
#include "TString.h"
#include "TStyle.h"

// Function that outputs the content of an array
void print_array(Double_t array[], Int_t size)
{
    std::cout<<"{";
    for(Int_t i = 0; i < size; i++)
    {
        std::cout<<array[i];
        if(i != size - 1) 
        {
            std::cout<<", ";
        }
    }
    std::cout<<"}."<<std::endl;
}

// Returns Nc
//Included Nc in selection_sort in case you're curious about the value
Int_t selection_sort(Double_t array[], Int_t size)
{
    Int_t Nc = 0;
    for (Int_t i = 0; i < size; i++)
    {
        // Initialize the minimum value as the front of the array
        Int_t minimum_index = i;
        // Loop through the elements after the initial value
        for(Int_t j = i + 1; j < size; j++)
        {
            // Finding the minimum value
            Nc++;
            // std::cout << Nc << std::endl;
            if (array[j] < array[minimum_index])
            {
                minimum_index = j;
            }
        }
        // Swap element at index i with minimum value
        Double_t temp = array[i];
        array[i] = array[minimum_index];
        array[minimum_index] = temp;
    }
    return Nc;
}

// Returns Nc
Int_t bubble_sort(Double_t array[], Int_t size)
{
    Int_t Nc = 0;
    Bool_t is_sorted = kFALSE; // Keeps track of if the array is sorted
    Int_t num_iterations = 0;

    while(!is_sorted)
    {
        Bool_t swap_occurred = kFALSE;
        // Pushing maximum value to the back of array
        for(Int_t i = 0; i < size - 1; i++)
        {
            Nc++; // Counts number of total comparisons
            if(array[i+1] < array[i])
            {
                Double_t temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swap_occurred = kTRUE;
            }
        }
        // If there was no swap, we know the array is sorted
        if(!swap_occurred) 
            is_sorted = kTRUE;
    }
    return Nc;
}

void problem1()
{
    const Int_t N = 20;
    // Generating array of 20 random numbers between 0 and 1
    Double_t random_array[N];
    gRandom->RndmArray(N, random_array);

    // Printing the initial values
    std::cout<<"Before sorting: ";
    print_array(random_array, N);

    // The sorting functions permanently alter the array
    // Make a copy to try both sorting methods
    auto random_array_selection_sort = random_array;

    selection_sort(random_array_selection_sort, N);
    bubble_sort(random_array, N);

    // Printing array after selection sort
    std::cout<<"Selection sorting: ";
    print_array(random_array_selection_sort, N);

    // Printing array after bubble sort
    std::cout<<"Bubble sorting: ";
    print_array(random_array, N);
}
void problem2()
{
    const Int_t N = 20;
    // Histogram to hold Nc values
    TH1I *h_Nc = new TH1I(
    "h_Nc",
    // Can set hist title and axes titles using "hist title; x title; ytitle"
    Form("Bubble Sort, %d random numbers;Number of Comparisons (Nc)", N),
    50,
    0.,
    N*N); 

    // Trying bubble sort 10,000 times
    for(Int_t i = 0; i < 100000; i++)
    {
        Double_t random_array[N];
        gRandom->RndmArray(N, random_array);
        Int_t Nc = bubble_sort(random_array, N);
        h_Nc->Fill(Nc);
    }

    h_Nc->Draw(); 
}
void problem3()
{
    const Int_t num_runs = 1000;
    // Profile to average the Nc values for each N
    TProfile *p_bubble_sort = new TProfile(
        "p_bubble_sort", 
        Form("Bubble Sort: %d Runs with Changing N; Array Size (N); Nc", num_runs), 
        110,
        0.5, 
        110.5); 
    // Using this binning makes Fill(X) center at value X.

    // For each value of N, try sorting 1000 times to generate decent statistics
    for(Int_t i = 0; i < num_runs; i++)
    {
        for(Int_t j = 10; j <= 100; j += 10)
        {
            Double_t random_array[j];
            // Return an array of j random numbers between 0 and 1 
            gRandom->RndmArray(j, random_array);
            Int_t num = bubble_sort(random_array, j);
            p_bubble_sort->Fill(j, num);
        }
    }

    p_bubble_sort->Draw();
    p_bubble_sort->SetMarkerStyle(21);
    p_bubble_sort->SetMarkerColor(kBlue);
    p_bubble_sort->Fit("pol2"); // Bubble sort has average comparisons of N^2
    // Moving title further off axis to remove clutter
    p_bubble_sort->GetYaxis()->SetTitleOffset(1.3);
    gStyle->SetOptFit(111);
}