
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


// optimal approach

int pagecount(int n, int arr[], int pages) {
    int pagesum = 0;  // Sum of pages currently assigned to a student.
    int student = 1;  // Number of students required, starting with the first student.

    for(int i = 0; i < n; i++) {
        // If adding the current book to the current student's allocation does not exceed the limit.
        if(pagesum + arr[i] <= pages) {
            pagesum += arr[i];  // Add the current book to the current student's allocation.
        }
        else {
            // If the current book cannot be allocated to the current student without exceeding the limit,
            // allocate it to the next student.
            student++;
            pagesum = arr[i];  // Start the new student's allocation with the current book.
        }
    }

    return student;  // Return the total number of students required.
}

// Function to find the minimum number of pages that each student needs to read.
long long findPages(int n, int arr[], int m) {
    // If the number of students is greater than the number of books, return -1.
    if(m > n) return -1;

    int pagsum = 0;  // Total sum of all pages.
    int maxi = INT_MIN;  // Maximum number of pages in a single book.

    // Calculate the total sum of pages and find the book with the maximum pages.
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
        pagsum += arr[i];
    }

    int low = maxi;  // The minimum possible value for the highest number of pages a student can read.
    int high = pagsum;  // The maximum possible value for the highest number of pages a student can read.

    // Perform binary search to find the minimum number of pages.
    while(low <= high) {
        int mid = (low + high) / 2;  // Midpoint of the current range.
        int student = pagecount(n, arr, mid);  // Number of students required if each student reads up to 'mid' pages.

        // If more students are required than available, increase the lower bound.
        if(student > m) {
            low = mid + 1;
        }
        else {
            // If fewer or equal students are required, decrease the upper bound.
            high = mid - 1;
        }
    }

    return low;  // The minimum number of pages that each student needs to read.
}
