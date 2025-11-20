input arr[]={8,3,4,1,20,50,30}
0output= i,3,4,8,20,30,50

  ## QuickSort say just choose a any number place at right postion , rest of thing recursion will handel.
  here we choose 8 and place at right postion in such way left part is smaller & right part is greater than 8

  arr=1,3,4,8,20,50,30

  ## QuickSort = partiation logic + recursive call



  #include<bits/stdc++.h>
using namespace std;

// ---------------------------------------------------
// PARTITION FUNCTION
// ---------------------------------------------------
int partiation(vector<int>& arr, int s, int e) {

    // Step 1: Choose first element as the pivot
    int pivotElemnt = arr[s];
    int pivotIndex = s;

    // Step 2: Count how many elements are <= pivot in the remaining array
    int count = 0;
    for(int i = s+1; i <= e; i++) {
        if(arr[i] <= pivotElemnt) {
            count++;
        }
    }

    // Step 3: Place pivot at its correct position
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);

    // Update pivotIndex
    pivotIndex = rightIndex;

    // Step 4: Arrange smaller on left & larger on right using 2 pointers
    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex) {

        // Move left pointer until we find an element > pivot
        while(arr[i] <= pivotElemnt) {
            i++;
        }

        // Move right pointer until we find an element <= pivot
        while(arr[j] > pivotElemnt) {
            j--;
        }

        // If both pointers are in correct range, swap
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Return the correct pivot position
    return pivotIndex;
}

// ---------------------------------------------------
// QUICK SORT FUNCTION
// ---------------------------------------------------
void quickSort(vector<int>& arr, int s, int e) {
    // Base case: if single element or invalid range
    if(s >= e) {
        return;
    }

    // Partition the array → get pivot index
    int p = partiation(arr, s, e);

    // Recursively sort left part
    quickSort(arr, s, p - 1);

    // Recursively sort right part
    quickSort(arr, p + 1, e);
}

// ---------------------------------------------------
// MAIN FUNCTION
// ---------------------------------------------------
int main() {
    vector<int> arr = {4, 1, 7, 9, 3};
    int n = arr.size();
    int s = 0, e = n-1;

    quickSort(arr, s, e);

    // Print sorted array
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}



// 2nd Appraoch
void quickSort(int a[], int start, int end)
{
    // Base condition: if array part has 0 or 1 element → already sorted
    if(start >= end) return;

    // Taking pivot at the end index
    int pivot = end;

    // i will mark the boundary of elements < pivot
    int i = start - 1;

    // j will scan the array from start to pivot-1
    int j = start;

    // Partition logic: move all elements < pivot to the left side
    while(j < pivot){
        
        // If current element is smaller than pivot element
        if(a[j] < a[pivot]){
            ++i;                          // Move i ahead
            swap(a[i], a[j]);             // Put smaller element to left side
        }
        ++j;                              // Move j forward
    }

    // Now place pivot at its correct sorted position: i+1
    ++i;
    swap(a[i], a[pivot]);

    // Now pivot is fixed at position i
    // Recursively sort left side (elements < pivot)
    quickSort(a, start, i - 1);

    // Recursively sort right side (elements > pivot)
    quickSort(a, i + 1, end);
}
