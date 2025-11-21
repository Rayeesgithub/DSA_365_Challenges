You are given a string s. You need to find the length of the string and return it.
Examples:
Input: s = Geeks
Output: 5

   int lengthString(string &s) {
       if(s.size()==0){
           return 0;
       }
       
       int len=0;
       for(int i=0; i<s.length();i++){
           len++;
       }
       
       return len; 
    }
};
