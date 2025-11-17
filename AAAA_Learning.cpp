(1) sub array
    for(int i=0; i<n; i++){
for(int j=i; j<n; j++){
  
}
}

(2) Sub array sum 
Wrong way
for(int i=0; i<arr.size(); i++){
      int sum=0; ✅ correct way intialize sum
    for(int j=i; j<arr.size(); j++){
        int sum=0;       // ❌ sum re-initialized in EVERY j iteration
        sum+=arr[j];     // only adds current element arr[j], Each time j increases, you reset sum=0.
        
        if(sum==0){
            int len=(j-i)+1;
            maxi=max(maxi,len);
        }
    }
} return maxi;}
dry run-> arr = [1, -1, 2, -2]
  Outer loop → i=0
It just checks single element every time.
j=0 → sum=0+arr[0]=1 → not zero

j=1 → sum=0+arr[1]=-1 → not zero

j=2 → sum=0+arr[2]=2 → not zero

j=3 → sum=0+arr[3]=-2 → not zero


(3) What is -'0' ?
  num1[p1] - '0' ->  It converts the character digit into an integer.
  char c = '5';
int x = c - '0';  // x = 5

✅  What is +'0' ?
Meaning: It converts an integer digit  into a character .
  int digit = 7;
char c = digit + '0';  // c = '7'
