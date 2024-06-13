//https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop

 void print(int N,int i){
          if(i<1) return;
          std::cout<<i<<" ";
          print(N,i-1);
      }
    void printNos(int N) {
          int i=N;
      print(N,i);
    }
