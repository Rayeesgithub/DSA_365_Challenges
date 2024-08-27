//striver sheet
//
//broute force
  void print_divisors(int n) {
      for(int i=1; i<=n; i++){
          if(n%i==0){
              std::cout<<i<<" ";
            
          }
      }
    }

//optimal approach
 void print_divisors(int n) {
       std::vector<int> divisors;  // Vector to store divisors

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);  // Store the divisor `i`
            if (i != n / i) {  // If it's not the same as `n/i`, store `n/i`
                divisors.push_back(n / i);
            }
        }
    }

    // Sort divisors in ascending order
    std::sort(divisors.begin(), divisors.end());

    // Print all divisors
    for (int divisor : divisors) {
        std::cout << divisor << " ";
    }
    }
