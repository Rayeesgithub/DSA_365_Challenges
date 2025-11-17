Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

  class Solution {
public:
bool solve(string &s,int si,string &p,int pi){
 // Case 1: Both strings finished
    if (si == s.size() && pi == p.size())
        return true;
// Case 2: s finished but p still has characters
  if(si==s.size() && pi<p.size()){
  while(pi<p.size()){
    if(p[pi]!='*') return false;
    pi++;

  }
  return true;
  }
    // singleChar Matching current characters match OR pattern has '?'
    if(s[si]==p[pi] || '?'==p[pi]){
     return solve(s,si+1,p,pi+1);
    }
    if(p[pi]=='*'){
        bool caseA=solve(s,si,p,pi+1);// '*' matches empty
        bool caseB=solve(s,si+1,p,pi);   // '*' matches one or more chars
        return caseA || caseB;
    }

    return false;
}
    bool isMatch(string s, string p) {
       int si=0; int pi=0;
       return solve(s,si,p,pi);  
    }
};
