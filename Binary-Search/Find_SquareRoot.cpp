//https://www.geeksforgeeks.org/problems/square-root/
// striver Sheet


// broute force
  long long int floorSqrt(long long int x) 
    {
       int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= x; i++) {
        long long val = i * i;
        if (val <= x) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;

    }


//optimal approach 1
 long long int floorSqrt(long long int x) 
    {
        // Your code goes here  
        int ans=sqrt(x);
        return ans;
    }

// optimal approach2
long long int floorSqrt(long long int x) 
{
    // Set the initial search range
    int s = 1;
    int e = x;

    // Perform binary search
    while (s <= e) {
        // Calculate the middle of the current search range
        long long mid = s + (e - s) / 2;

        // If mid*mid is less than or equal to x,
        // it means mid could be the potential floor square root of x
        // and we need to search in the right half
        if (mid * mid <= x) {
            // Move the search range to the right half
            s = mid + 1;
        }
        // If mid*mid is greater than x, it means mid is too large
        // and we need to search in the left half
        else {
            e = mid - 1;
        }
    } // Return the floor value of the square root
    return e;
}
