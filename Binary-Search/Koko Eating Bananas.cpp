https://leetcode.com/problems/koko-eating-bananas/description/
// striver sheet

class Solution {
public:
int findMax(vector<int> &piles) {
    int maxi = INT_MIN;
    int n = piles.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}


    int minEatingSpeed(vector<int>& piles, int h) {
           int low = 1, high = findMax(piles);

    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(piles, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
    }
};
