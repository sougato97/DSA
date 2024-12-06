class Solution {
public:
    bool canChange(string start, string target) {
        int length = start.size(); // length of both the strings should be the same 
        // pointers for both the strings 
        int start_pointer = 0;
        int target_pointer = 0;
        while(start_pointer < length || target_pointer < length){
            // 1. skip underscore 
            // 1a. for start
            while (start_pointer < length && start[start_pointer] == '_'){
                start_pointer++;
            }
            // 1b. for target
            while (target_pointer < length && target[target_pointer] == '_'){
                target_pointer++;
            }
            // 2. If one string is exhausted, both should be exhausted
            if (start_pointer == length || target_pointer == length) {
                return start_pointer == length && target_pointer == length;
            }

            // 3. Follow the negation of the movement rules (easier to write the code)
            if (start[start_pointer] != target[target_pointer] ||
                start[start_pointer] == 'L' && start_pointer < target_pointer ||
                start[start_pointer] == 'R' && start_pointer > target_pointer){
                    return false;
                }

            // Normal conditions, no edge case. (after encountering characters)
            start_pointer++;
            target_pointer++;
        }

        // If all conditions are satisfied, return true
        return true;
    }
};