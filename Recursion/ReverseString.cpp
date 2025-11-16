Input: s = "Geeks"
Output: "skeeG"


// Iterative approach
   string reverseString(string& s) {
        // code here
        string ans;
        for(int i=s.size()-1; i>=0; i--){
          ans.push_back(s[i]);
        }
        
        return ans;
    }

// Two Pointer
 void reverseString(vector<char>& s) {
     int left=0; int right=s.size()-1;
     while(left<right){
        swap(s[left],s[right]);
        left++; right--;
     }
     
    }


// Recursive
 void reverseString(string &s,int left,int right){
      if(left>right){
          return;
      }
      swap(s[left],s[right]);
      
      
      reverseString(s,left+1,right-1);
    
      
  }
    string reverseString(string& s) {
        // code here
     
       int left=0; int right=s.size()-1;
       reverseString(s,left,right);
       
       return s;
    }
