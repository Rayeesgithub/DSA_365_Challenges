Example 1:
Input: String str = “zxcbg”
Output: bcgxz
Explanation: After sorting we get string as bcgxz

Approach1-> selection sort

void solve(string & str){
 
   for(int i=0; i<str.size()-1; i++){
    int miniIndex=i;

    for(int j=i+1; j<str.size(); j++){
        if(str[j]<str[miniIndex]){
            miniIndex=j;
        }
    }

    swap(str[i],str[miniIndex]);

   }

  for(auto it:str){
        cout<<it;
    }
}

//2nd approach
string solve(string str) {
  sort(str.begin(), str.end());
  return str;
}

// 2nd 
