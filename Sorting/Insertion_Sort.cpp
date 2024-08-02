// Striver-sheet

 void insertionSort(int arr[], int n)
    {
        //code here
        for(int i=1; i<n; i++){
            //step1- fetch
            int key=arr[i];
            int j=i-1;
            for(;j>=0;j--){
                //compare
                if(arr[j]>key){
                    //shift
                    arr[j+1]=arr[j];
                }
                else{
                    break;
                }
            }
            // copy
            arr[j+1]=key;
        }

//aproach2
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    insertionSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
