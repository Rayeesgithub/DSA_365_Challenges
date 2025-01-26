https://www.geeksforgeeks.org/problems/primes-sum5827/1

bool isPrime(int n){
       for(int i=2; i<=sqrt(n); i++){
           if(n%i==0){
               return false;
           }
       }
       return true;
   }
    string isSumOfTwo(int N){
      for(int i=2; i<=N/2; i++){
          if(isPrime(i) && isPrime(N-i)){
              return "Yes";
          }
      }
      return "No";
    }
