class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); // initialization condition. as lis for the lement in itself is also 1. 

        for (int i = 1; i<nums.size(); i++){
            // j is for the previous element
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1); // this part is important.
                }
            }
        }

        int longest = 0; 
        for (int c: dp){
            // find the longest LIS in the vector dp
            longest = max(longest, c); 
        }

        return longest;
    }
};