// striver sheet
// gfg ->Longest Sub-Array with Sum K
int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       // using 3 loop Time Complexity: O(N^3)
       int len=0;
    //   for(int i=0; i<N; i++){
    //       for(int  j=i; j<N; j++){
    //           long long int sum=0;
    //           for(int k=i; k<=j; k++){
    //               sum=sum+A[k];
    //           }
    //           if(sum==K){
    //             len=max(len,j-i+1);   
    //           }
    //       }
    //       return len;
    //   }
    
    
    // using twqo loops Time Complexity: O(N^2)
    
    //   for(int i=0; i<N; i++){
    //       long long sum=0;
    //       for(int j=i; j<N; j++){
    //           sum=sum+A[j];
    //           if(sum==K){
    //              len=max(len,j-i+1);
    //           }
    //       }
          
    //   }
    //   return len;
    
    //third approach-> Time Complexity: O(N) or O(N*logN)  Space-complexity=0(n)
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < N; i++) {
        //calculate the prefix sum till index i:
        sum += A[i];

        // if the sum = k, update the maxLen:
        if (sum == K) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - K;
   
        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
    } 
int main() {
    int A[] = {10, 5, 2, 7, 1, 9};
    int N = sizeof(A) / sizeof(A[0]);
    int K = 15;
    cout << "Length of the longest subarray with sum " << K << " is: " << lenOfLongSubarr(A, N, K) << endl;

    return 0;
}
