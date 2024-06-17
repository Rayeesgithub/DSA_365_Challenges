void selection_sort(int arr[], int n) {
  // selection sort
  for (int i = 0; i < n - 1; i++) {
    int mini = i;
      //inner Loop -> index of minimum element in range i->n
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j; // new minimum element
      }
    }
    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }
//printing
  cout << "After selection sort: " << "\n";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";

}
