class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0; // str1 iterator
        int j = 0; // str2 iterator
        while (i<str1.size() && j < str2.size()){
            if(str1[i] == str2[j] || str1[i] + 1 == str2[j] || str1[i] - 25 == str2[j]){
                j++;
                i++;
            }
            else
                i++;
        }
        if (j == str2.size()){
            return true;
        }
        return false;
    }
};