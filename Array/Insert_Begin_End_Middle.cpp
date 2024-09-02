//striver NQT

#include<bits/stdc++.h>
using namespace std;
void InserAtbegin(int* arr,int n,int value){
   for(int i=n-1;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=value;
}
void insertatEnd(int *arr, int n, int value)
{
    arr[n] = value;
}
void insertatposition(int *arr, int n, int value, int pos)
{
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
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
