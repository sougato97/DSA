class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        std::vector<int> sub;
        
        for (int num : nums) {
            // low_bound is using binary search. T(N) = O(log(n))
            auto it = std::lower_bound(sub.begin(), sub.end(), num);
            
            // If num is greater than any element in sub
            if (it == sub.end()) {
                sub.push_back(num);
            } 
            // Otherwise, replace the first element in sub greater than or equal to num
            else {
                *it = num;
            }
        }
        
        return sub.size();
    }
};
