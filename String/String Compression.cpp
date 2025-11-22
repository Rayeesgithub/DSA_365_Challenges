Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3"


   int compress(vector<char>& nums) {
        int n=nums.size();
        string s="";
        nums.push_back('*'); // for not getting the error as we will check for nums[i+1] in the loop
        int freq=1;
        for(int i=0;i<n;i++){
            
            if(nums[i+1]==nums[i]){ //checking if current character is equal to the next character
                freq++;
            }
            else{
                s+=nums[i];
                if(freq>1){ //if freq=1 then no need to append the frequency
                    s+=to_string(freq);
                    freq=1;
                }
            }
        }
        for(int i=0;i<s.length();i++){
            nums[i]=s[i]; // for copying back
        }
        return s.length();
    }
