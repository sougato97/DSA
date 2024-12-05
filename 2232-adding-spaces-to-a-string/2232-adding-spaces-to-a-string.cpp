class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int j = 0; // to keep track of the space index
        int i = 0; // to keep the start index of the string s 
        while (j < spaces.size()){
            result += s.substr(i, spaces[j]-i);
            result.push_back(' ');
            i = spaces[j];
            j++;
        }
        // Append the remaining part of the string 
        result += s.substr(i);
        return result;
    }
};