# Assignment 5: Sorting algorithms and TProfiles

1. Randomly generate 20 numbers, store them in an array, and sort them in an ascending order using two approaches.
	- Approach 1 (Selection sort): Start with the first element and compare its value with the other elements. If another element is smaller than it, swap the two numbers. Then compare this new smallest value to the remaining elements. If no other element is smaller than the element of interest, move to the next element and do it again.
	- Approach 2 (Bubble sort): This approach compares elements pairwise. Look at the first pair of numbers (elements 0 and 1). If they obey ascending order, leave them, otherwise swap them. Then try the next pair (elements 1 and 2) and keep going until the end of the array. At the end, restart from the beginning and repeat the process until no more swapping is needed.

2. Using approach 2, count the number of comparisons, Nc, done when dealing with 20 random numbers. When you have another set of 20 random numbers, you get another Nc. Fill a histogram with Nc after trying many sets of 20 random numbers.

3. Similar to step 2, but this time we are not limited to 20 random numbers. Try 10, 20, 30, ..., 100 random numbers, and each time you get an Nc value. Fill a TProfile of Nc vs N, where N is the number of random numbers (10, 20, ...). Try to fit the profile with a functional form. TProfile is found in the "Histograms" section of the manual. 
