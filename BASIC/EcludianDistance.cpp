#include<bits/stdc++.h>
using namespace std;
float findDis(int x1,int y1,int x2,int y2 ){
    int dis1=abs(x1-x2);
    int dis2=abs(y1-y2);
    float ans=sqrt(pow(dis1,2)+pow(dis2,2));
  return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int x1,y1;
    cin>>x1>>y1;
    int x2,y2;
    cin>>x2>>y2;
    float distance=findDis(x1,y1,x2,y2);
    cout<<distance<<endl;
    }
}
