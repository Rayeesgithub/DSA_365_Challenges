// striver sheet
Example 1:
Input:
 nums = [3, 5, 4, 1, 1]  
Output:
 [1, 2]  
Explanation:
 1 appears twice in the array, and 2 is missing from the array. So the output is [1, 2].



   //Broute force
vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        
        // Size of the array
        int n = nums.size(); 
        int repeating = -1, missing = -1;

        // Find the repeating and missing number:
        for (int i = 1; i <= n; i++) {
            
            // Count the occurrences:
            int cnt = 0;
            
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) cnt++;
            }

            // Check if i is repeating or missing
            if (cnt == 2) repeating = i;
            else if (cnt == 0) missing = i;

            /* If both repeating and missing
            are found, break out of loop*/
            if (repeating != -1 && missing != -1)
                break;
        }
        
        // Return {repeating, missing}
        return {repeating, missing};
    }
};




// Better approach using HASHMAP

vector<int> findErrorNums(vector<int>& nums){

    unordered_map<int,int> freq;

    int duplicate = -1;
    int missing = -1;

    // count frequency

    for(int num : nums){

        freq[num]++;
    }

    // find duplicate and missing

    for(int i=1; i<=nums.size(); i++){

        if(freq[i] == 2){

            duplicate = i;
        }

        else if(freq[i] == 0){

            missing = i;
        }
    }

    return {duplicate, missing};
}





int main(){
vector<int>arr={3,1,2,5,3};
cout<<"finding and repeating Element is:"<<endl;
 vector<int>ans=solve(arr);
 
 for(int i=0; i<ans.size(); i++){
  cout<<ans[i]<<" ";
 }
}



// optimal
// Function to find repeating and missing numbers
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        
        // Size of the array
        long long n = nums.size(); 

        // Sum of first n natural numbers
        long long SN = (n * (n + 1)) / 2;
        
        // Sum of squares of first n natural numbers
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        /*Calculate actual sum (S) and sum 
        of squares (S2) of array elements*/
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        //Compute the difference values
        long long val1 = S - SN; 
        
        // S2 - S2n = X^2 - Y^2
        long long val2 = S2 - S2N; 

        //Calculate X + Y using X + Y = (X^2 - Y^2) / (X - Y)
        val2 = val2 / val1;

        /* Calculate X and Y from X + Y and X - Y
         X = ((X + Y) + (X - Y)) / 2
         Y = X - (X - Y)*/
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        // Return the results as {repeating, missing}
        return {(int)x, (int)y};
    }
};

