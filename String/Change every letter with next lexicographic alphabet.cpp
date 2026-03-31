Input: string str = “abcdxyz”
Output: bcdeyza


void solve(string & str){
 
  string asn="";

  for(int i=0; i<str.size(); i++){
   if(str[i]=='z'){
    str[i]='a';
   }
   else if(str[i]=='Z'){
    str[i]='A';
   }

   else{
    str[i]=str[i]+1;
   }
  }

  cout<<str;
}

