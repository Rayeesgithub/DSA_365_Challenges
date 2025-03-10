int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;  // current size

    // Insert at the beginning
    int element = 5;
    int pos = 0;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    n++;

    // Insert at the end
    arr[n] = 60;
    n++;

    // Insert at a specific position (say pos = 3)
    element = 25;
    pos = 3;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    n++;

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}




//2nd approach


int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    // Insert at the beginning
    arr.insert(arr.begin(), 5);   // 5 10 20 30 40 50

    // Insert at the end
    arr.push_back(60);            // 5 10 20 30 40 50 60

    // Insert at a specific position (say pos = 3)
    arr.insert(arr.begin() + 3, 25);  // 5 10 20 25 30 40 50 60

    cout << "Vector after insertion: ";
    for (auto num : arr) {
        cout << num << " ";
    }

    return 0;
}
