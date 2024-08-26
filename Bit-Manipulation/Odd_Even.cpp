//striver sheet

// apprach1
  string oddEven(int n) {
       if(n%2==0){
           return "even";
       }
       else{
           return "odd";
       }
    }

// aprroach 2
string oddEven(int n) {
        // code here
          if(n&1){
            return "odd";
        }
        else{
            return "even";
        }
        
    }
