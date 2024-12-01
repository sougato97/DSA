class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int num: arr){
            // check if 2 * num, or num/2 (when divisible) is present in the set seen
            if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))){
                return true; 
            }
            // if not present yet, then add it into the set 'seen'
            seen.insert(num);
        }
        // No valid pair found
        return false;
    }
};