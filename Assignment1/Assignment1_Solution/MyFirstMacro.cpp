#include <iostream> // Included to print things in C++

// Number 2
void MyFirstMacro()
{
    std::cout << "Hello World!" << std::endl;
}

// Number 3
void FunctionTwo()
{
    std::cout << "This is my second function." << std::endl;
}

// Number 4
int Sum(int x, int y)
{
    int sum = x + y;
    return sum;
    
    /* 
        Can use int or Int_t here.
        I typically use Int_t since it helps me know that I'm looking at a ROOT
        macro when I open a file.
    */
}