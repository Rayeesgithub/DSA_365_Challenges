Input: Numerator1 = 3, Denominator1 = 4, Numerator2 = 1, Denominator2 = 7
Output: Numerator = 25, Denominator = 28 
Explanation: 3/4 + 1/7 = 25/28


#include<bits/stdc++.h>
using namespace std;
int findGCD(int n,int m){
  int ans=1;
  for(int i=1; i<=min(n,m); i++){
    if(n%i==0 && m%i==0){
      ans=i;
    }
  }
  return ans;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1 = 3, d1 = 4;   // Fraction 1 = 3/4
    int n2 = 1, d2 = 7;   // Fraction 2 = 1/7

    // Step 1: LCM of denominators
    int lcm = (d1 * d2) / FindGCD(d1, d2);

    // Step 2: Convert both numerators to same denominator
    int num1 = n1 * (lcm / d1);
    int num2 = n2 * (lcm / d2);

    // Step 3: Add numerators
    int final_num = num1 + num2;
    int final_den = lcm;

    cout << "Numerator = " << final_num << ", Denominator = " << final_den;
}

int main(){
  int t;
  cin>>t;
  while(t--){
  int num1,den1; int num2,den2;
  cout<<"Enter the numerator or denometer of first fraction:";
  cin>>num1>>den1;
  cout<<"enter the numrator and denometr of seond fraction:";
  cin>>num2>>den2;
  solveFraction(num1,den1,num2,den2);
  cout<<endl;
  }
}
