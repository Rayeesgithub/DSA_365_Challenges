//https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1
//Approach1-Broute force
#include<bits/stdc++.h>
using namespace std;
int findGCD(int n1,int n2){
    int ans=1;
    for(int i=1; i<=min(n1,n2); i++){
    if(n1%i==0 && n2%i==0){
        ans=i;
    }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n1,n2;
        cin>>n1; cin>>n2;
        int gcd=findGCD(n1,n2);
        int lcm=n1*n2/gcd;
        cout<<gcd<<":"<<lcm<<endl;
    }
}

//Approach2-optimal
 long long gcd(long long A, long long B) {
        if (A == 0)
            return B;
        return gcd(B%A, A);
    }

    vector<long long> lcmAndGcd(long long A, long long B) {
        long long hcf = gcd(A, B);
        long long lcm = (A * B) / hcf;
        return {lcm, hcf};
    }
