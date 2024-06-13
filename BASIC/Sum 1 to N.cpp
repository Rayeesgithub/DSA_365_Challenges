// Apprach1=by looping  Time Complexity: O(N)  , Space Complexity: O(1)
void solve(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += i;
    }
    cout<<"The sum of the first "<<n<<" numbers is: "<<sum<<endl;
  }
 int main() {

    solve(5);
    }
// apprach2-> by Formula   Time Complexity: O(1),  Space Complexity: O(1)
 void solve(int N) {
    int sum = N * (N + 1) / 2;
    cout<<"The sum of the first "<<N<<" numbers is: "<<sum<<endl;
  }
//apprach3-by recursion   Time Complexity: O(N)      ,     Space Complexity: O(N)
void func(int i, int sum){
   
   // Base Condition.
   if(i<1)
   {
       cout<<sum<<endl;
       return;
   }

   // Function call to increment sum by i till i decrements to 1.
   func(i-1,sum+i);

}
