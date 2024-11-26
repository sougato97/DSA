class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        int max_product = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            // refresh prefix and suffix, after a 0 encounter
            if (prefix == 0){
                prefix = 1;
            }
            if (suffix == 0){
                suffix = 1;
            }
            // we are trying to find products from two separate directions
            // prefix: group which consists product of all the elments before nums[i].
            prefix = prefix * nums[i];
            // suffix: group which consists product of all the elments after nums[i].
            suffix = suffix * nums[nums.size()-i-1];
            max_product = max(max_product, max(prefix, suffix));
        }
        return max_product;
    }
};