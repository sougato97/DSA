class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        std::vector<int> sub;
        sub.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > sub.back()) {
                sub.push_back(nums[i]);
            } else {
                // Find the first element in sub that is greater than or equal to nums[i]
                // Equivalent of writing a loop
                auto it = std::lower_bound(sub.begin(), sub.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return sub.size();
    }
};
