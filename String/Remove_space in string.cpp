Problem->GFG
Input: s = "geeks  for geeks"
Output: "geeksforgeeks"
Explanation: All the spaces have been removed.
Input: s = "    g f g"
Output: "gfg"
Explanation: All the spaces including the leading ones have been removed.


// APPROACH 1
string modify(string s)
{
    // create an empty string to store result
    string ans = "";

    // loop over each character in the string
    for(int i = 0; i < s.length(); i++) {

        // if current character is NOT a space
        if(s[i] != ' ') {

            // add that character to ans
            ans += s[i];    // same as ans.push_back(s[i]);
        }
    }

    // return final string with no spaces
    return ans;
}


// APPROACH 2
string modify(string& s) {

    // result string
    string ans;

    for(int i = 0; i < s.length(); i++) {

        // if current character is space, skip it
        if(s[i] == ' ') {
            continue;       // move to next character
        }
        else {
            // add non-space character
            ans += s[i];
        }
    }

    return ans;
}



int main(){
    string str="My Name is Rayees Alam";
    cout<<"Before Replace string:"<<str<<endl;
    string ans=RemoveSpace(str);
    cout<<"after replace string:"<<ans<<endl;
}


