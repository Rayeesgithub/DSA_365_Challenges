input s="6384 thisNmuber"
output=6348


#include<bits/stdc++.h>
using namespace std;
 void solve(string &s,vector<int>&ans,int i){
    if(i>=s.size()){
        return;
    }
    if(isdigit(s[i])){
       ans.push_back(s[i]-'0');
    }
    solve(s,ans,i+1);
 }
int main(){
    string s="4193 with words";
    vector<int>ans;
    solve(s,ans,0);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }
}




// optimal approach
int myAtoi(string s) 
{
    int i = 0;          // Pointer to traverse the string
    int sign = 1;       // Default sign = positive
    long ans = 0;       // Store the converted number (use long to handle overflow)

    // 1️⃣ Skip all leading spaces
    while (i < s.length() && s[i] == ' ')
        i++;

    // 2️⃣ Check for sign (+ or -)
    if (s[i] == '-')
    {
        sign = -1;      // Number is negative
        i++;
    }
    else if (s[i] == '+')
        i++;            // Number is positive, just skip the '+'

    // 3️⃣ Convert characters to number
    while (i < s.length())
    {
        // If current char is a digit
        if (s[i] >= '0' && s[i] <= '9')
        {
            // Build the number: ans = ans * 10 + (current digit)
            ans = ans * 10 + (s[i] - '0');

            // 4️⃣ Check overflow
            // If ans > INT_MAX and sign is negative → return INT_MIN
            if (ans > INT_MAX && sign == -1)
                return INT_MIN;

            // If ans > INT_MAX and sign is positive → return INT_MAX
            else if (ans > INT_MAX && sign == 1)
                return INT_MAX;

            i++;        // Move to next character
        }
        else
            // If character is not digit → stop and return result
            return ans * sign;
    }

    // 5️⃣ Return final number with sign
    return ans * sign;
}
