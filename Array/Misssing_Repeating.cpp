// gfg->Missing And Repeating
// striver sheet

//broute force
int hash[n+1] = {0}; // Initialize a hash array of size n+1 with all elements set to 0

// Loop through each element in the input array
for(int i = 0; i < n; i++) {
    hash[arr[i]]++; // Increment the count of the element in the hash array
}
int repeating = -1, missing = -1;
// Loop through the hash array to find the repeating and missing numbers
for(int i = 1; i <= n; i++) {
    if(hash[i] == 2) { // If the count of an element is 2, it means this element is repeating
        repeating = i;
    } else if(hash[i] == 0) { // If the count of an element is 0, it means this element is missing
        missing = i;
    }
    
    // If both repeating and missing numbers are found, break out of the loop
    if (repeating != -1 && missing != -1) {
        break;
    }
}
// At this point, 'repeating' contains the repeating number and 'missing' contains the missing number
return (repeating, missing};

// optimal approach-
vector<int> findTwoElement(vector<int> arr, int n) {
    long long sumN = n * (n + 1) / 2; // Sum of first n natural numbers
    long long sumNSquare = n * (n + 1) * (2 * n + 1) / 6; // Sum of squares of first n natural numbers

    long long sum = 0, sumSquare = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Sum of elements in the array
        sumSquare += (long long)arr[i] * arr[i]; // Sum of squares of elements in the array
    }

    long long diff = sumN - sum; // Difference between expected sum and actual sum (missing - repeating)
    long long sumDiff = sumNSquare - sumSquare; // Difference between expected sum of squares and actual sum of squares (missing^2 - repeating^2)

    long long sumPlusDiff = sumDiff / diff; // (missing + repeating)

    int missing = (diff + sumPlusDiff) / 2; // Calculate missing number
    int repeating = sumPlusDiff - missing; // Calculate repeating number

    return {repeating, missing}; // Return the repeating and missing numbers
}
 
