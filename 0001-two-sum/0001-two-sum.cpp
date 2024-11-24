class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i=0; i<nums.size(); i++){
            int temp = target - nums[i];
            // checks for the complement
            if (mp.find(temp) != mp.end()){
                // mp[temp] is the index of the complement element int he original array
                // temp is the complement element
                return {mp[temp], i};
            }
            // key:element, value:index
            mp.insert({nums[i],i});
        }
        return {};
        }
};