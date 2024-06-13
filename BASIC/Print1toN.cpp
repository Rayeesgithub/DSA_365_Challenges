//https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-1-to-n-without-using-loops
// approach1-by recursion
 void print(int N,int i){
        // base case
        if(i>N){
            return;
        }
        //one case solve
        std::cout<<i<<" ";
        //Baki recusion saMBHAL LEGA
        print(N,i+1);
    }
    void printNos(int N)
    {
      int i=1;
      print(N,i);
    }

//apprach-2 by looping
void printNos(int N){
  for(int i=1; i<=N; i++){
   cout<<i<<" ";
  }
}
