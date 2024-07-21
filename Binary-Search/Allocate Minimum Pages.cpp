https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// striver file

// broute force
  int pagecount(int n,int arr[],int pages){
        int pagesum=0; int student=1;
        for(int i=0; i<n; i++){
            if(pagesum+arr[i]<=pages){
                pagesum+=arr[i];
            }
            else{
               student++;
               pagesum=arr[i];
            }
        }
        return student;
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        if(m>n) return -1;
        int pagsum=0; int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            maxi=max(maxi,arr[i]);
           pagsum=pagsum+arr[i];
        }
        for(int page=maxi; page<=pagsum; page++){
            if(pagecount(n,arr,page)==m){
                return page;
            }
        }
        maxi;
    }
