// gfg-> floor in sorted array
// striver
  int findFloor(vector<long long> v, long long n, long long x) {
        
         // brute force
     long long maxi = LLONG_MIN;
    //   for(int i=0; i<n; i++){
    //       if(v[i]<=x){
    //           maxi=max(maxi,v[i]);
               
    //       }
           
    //   }
    //  optimal approach
    
    int s=0; int e=n-1;
     int floorIndex = -1; // Index to store the position of the floor

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (v[mid] <= x) {
            if (v[mid] > maxi) {
                maxi = v[mid];
                floorIndex = mid; // Update the floor index
            }
            s = mid + 1; // Move to the right half to find a larger floor
        } else {
            e = mid - 1; // Move to the left half
        }
    }

    return floorIndex; // Return the index of the floor
}
