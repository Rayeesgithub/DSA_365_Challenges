Example 1:
Input:x = 2, n = 5
Output:32
Explanation: Calculate pow(2, 5) = 25 = 2*2*2*2*2 = 32 

Example 2:
Input:x = 21, n = 2                
Output: 441    
Explanation:  Calculate pow(21, 2) = 212 = 21*21 = 441  


  Time=0(n) && space=0(1)

  int main()
{
    int x= 5, n = 3;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * x; //Simply multiply the ans with x
    }
    cout <<x<<" raised to the power "<<n<<" is "<< ans;
}


//2nd way

double myPow(double x, int n) {
    // Initialize the result
    double ans = 1;
    // Store the original value of 'n'
    double oriNum = n;
    
    // If the base is 0 or 1, return the base itself
    if(x==0 || x==1){
        return x;
    }

    // If 'n' is negative, make 'x' its reciprocal and change 'n' to its absolute value minus 1
    if(n<0){
        x = 1/x;
        n = -(n+1);
        ans = ans*x;
    }
    
    while(n>0){
        // If 'n' is odd, multiply 'ans' by 'x' and decrement 'n' by 1
        if(n%2==1){
            ans = ans*x;
            n = n-1;
        }

        else{
            n = n/2;
            x = x*x;
        }
    }
    // Return the final result
    return ans;
}
