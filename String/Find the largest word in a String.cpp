Example 1:
Input:
 string s = "Google Doc"  
Output:
 "Google"  
Explanation:
  "Google" is the largest word in the given string.



  void solve(string &str){
 
    string temp = "";
    int count = 0;
    string ans = "";
    int maxi = 0;

    for(int i = 0; i < str.size(); i++){

        if(str[i] != ' '){
            count++;
            temp += str[i];
        }
        else{
            if(count > maxi){
                maxi = count;
                ans = temp;
            }

            count = 0;
            temp = "";
        }
    }

    // check last word
    if(count > maxi){
        ans = temp;
    }

    cout << ans;
}
