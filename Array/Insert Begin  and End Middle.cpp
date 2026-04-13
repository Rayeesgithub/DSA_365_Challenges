//striver NQT

 vector<int> insertAtBeginning(vector<int>& arr, int x) {
        // Insert x at index 0
        arr.insert(arr.begin(), x);
        return arr;
    }

  vector<int> insertAtEnd(vector<int>& arr, int x) {
        // Push element at the back
        arr.push_back(x);
        return arr;
    }

  vector<int> insertAtPosition(vector<int>& arr, int pos, int x) {
        // Insert x at index = pos
        arr.insert(arr.begin() + pos, x);
        return arr;
    }






int main() {
   int n=8;
   int arr[n]={2,3,1,9,3,1,3,9};
 
   int value=40;  int pos = 5;
      InserAtbegin(arr,n,value);
    cout<<"After inserting the value at beginning:"<<endl;
    insertatEnd(arr,n,value);
    cout<<" after Inserting at End"<<endl;
     insertatposition(arr,n,value,pos);
    cout<<"After inserting the value at beginning:"<<endl;
  for(int i=0; i<=n; i++){
    cout<<arr[i]<<" ";
  }

}
