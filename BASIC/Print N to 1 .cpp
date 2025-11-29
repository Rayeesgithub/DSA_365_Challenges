//https://www.geeksforgeeks.org/problems/print-n-to-1-without-loop

Input: N = 4
Output: 1, 2, 3, 4
Explanation: All the numbers from 1 to 4 are printed.

 Time=0(n) && 
 void print(int N,int i){
          if(i<1) return;
          std::cout<<i<<" ";
          print(N,i-1);
      }
    void printNos(int N) {
          int i=N;
      print(N,i);
    }
