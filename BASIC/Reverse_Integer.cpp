int getReverse(int n){
    int ans=0;
    bool isNeg=false;
    if(n<0){
        isNeg=true;
        n=-n;
    }
    while(n>0){
        int digit=n%10;
        ans=ans*10+digit;
       
        n=n/10;
    }
    return isNeg ?-ans:ans;
 }
