//https://www.geeksforgeeks.org/problems/print-gfg-n-times
 void print(int N,int i){
      if(i>N) return;
      std::cout<<"GFG"<<" ";
      print(N,i+1);
  }
    void printGfg(int N) {
        // Code here
        int i=1;
        print(N,i);
    }
