https://leetcode.com/problems/sort-characters-by-frequency/description/
// striver sheet

string frequencySort(string s) {
    // Create an unordered map to store the frequency of each character
    unordered_map<char, int> mp;
    for(int i = 0; i < s.length(); i++) {
        mp[s[i]]++;  // Increment the count for each character
    }

    // Create a vector of pairs to store the frequency and corresponding character
    vector<pair<int, char>> v;
    for(auto it : mp) {
        v.push_back({it.second, it.first});  // Store the frequency and character as a pair
    }

    // Sort the vector in descending order based on frequency
    sort(v.begin(), v.end(), greater<pair<int, char>>());

    // Initialize an empty string to store the result
    string result;
    for(auto it : v) {
        // Append each character 'it.first' times to the result string
        for(int i = 0; i < it.first; i++) {
            result += it.second;
        }
    }

    // Return the final sorted string based on character frequency
    return result;
}
