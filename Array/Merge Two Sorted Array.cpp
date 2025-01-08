

//approach1->Borute force
void Merg(vector<int>&arr1,vector<int>&arr2){
     int n1=arr1.size(); int n2=arr2.size();
     vector<int>ans;
     for(int i=0; i<n1; i++){
        ans.push_back(arr1[i]);

     }
     for(int i=0; i<n2; i++){
        ans.push_back(arr2[i]);
     }

     sort(ans.begin(),ans.end());
     for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
     }
  }

// approach2-> Optimal Approach

void MergeArr(vector<int>&arr1,vector<int>&arr2){
    int n=arr1.size(); int m=arr2.size();
    vector<int>ans;
    int i=0; int j=0;
    while(i<n && j<m){
      if(arr1[i]<arr2[j]){
        ans.push_back(arr1[i]);
        i++;
      }
      else{
        ans.push_back(arr2[j]);
        j++;
      }
    }
    while(i<n){
      ans.push_back(arr1[i]);
      i++;
    }
    while(j<m){
      ans.push_back(arr2[j]);
      j++;
    }

    for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
    }
}
