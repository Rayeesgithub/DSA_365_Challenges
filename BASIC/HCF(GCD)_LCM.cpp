//https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1
//Approach1-Broute force
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        long long hcf=1; long long lcm=1;
      for(int i=1;i<=min(A,B);i++){
          if(A%i==0 && B%i==0)
          hcf=i;
      }
      lcm=(A*B)/hcf;
      return {lcm, hcf};
    }
//Approach2-optimal
 long long gcd(long long A, long long B) {
        if (B == 0)
            return A;
        return gcd(B, A % B);
    }

    vector<long long> lcmAndGcd(long long A, long long B) {
        long long hcf = gcd(A, B);
        long long lcm = (A * B) / hcf;
        return {lcm, hcf};
    }
