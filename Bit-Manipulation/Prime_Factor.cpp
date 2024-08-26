//striver sheet

//broute force
	bool checkPrime(int n){
	 for(int i=2; i<n; i++){
	     if(n%i==0) return false;
	    
	 }
	 return true;
	}
	
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int>ans;
	    for(int i=2; i<=N;i++){
	        if(checkPrime(i)){
	           ans.push_back(i);
	        }
	    }
	    vector<int>res;
	    for(int i=0; i<ans.size(); i++){
	        if(N%ans[i]==0){
	            res.push_back(ans[i]);
	        }
	    }
	    set<int>st;
	    for(int i=0; i<res.size();i++){
	        st.insert(res[i]);
	    }
	   vector<int>er;
	   for(auto i:st){
	     er.push_back(i);
	   }
	   return er;
	}

//optimal approach
#include <iostream>
#include <vector>
using namespace std;

void findUniquePrimeFactors(int N) {
    vector<int> primeFactors;

    // Check for number of 2s that divide N
    if (N % 2 == 0) {
        primeFactors.push_back(2);
        while (N % 2 == 0) {
            N = N / 2;
        }
    }

    // Check for odd factors from 3 to sqrt(N)
    for (int i = 3; i * i <= N; i += 2) {
        if (N % i == 0) {
            primeFactors.push_back(i);
            while (N % i == 0) {
                N = N / i;
            }
        }
    }

    // This condition is to check if N is a prime number greater than 2
    if (N > 2) {
        primeFactors.push_back(N);
    }

    // Print the prime factors
    for (int i = 0; i < primeFactors.size(); i++) {
        cout << primeFactors[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    findUniquePrimeFactors(N);
    return 0;
}
