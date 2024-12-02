class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int word_count = 1; // as in the constraints, it's mentioned that the length will be at least 1
        int sentence_length = sentence.length();
        int i = 0; // takes care of the character pointer (starting from 0 to len of sentence)

        while (i < sentence_length) {
            // Skip leading spaces
            while (i < sentence_length && sentence[i] == ' ') {
                i++;
            }

            // Check if the current word starts with searchWord
            // Custom implementation of string.substring()
            int j = 0; // matchCount
            while (i < sentence_length && j < searchWord.length() && sentence[i] == searchWord[j]){
                i++;
                j++;
            }
            // Check whether the substring has matched with the searchWord
            if (j == searchWord.length()){
                return word_count;
            }

            // Move to the end of the current word
            while (i < sentence_length && sentence[i] != ' ') {
                i++;
            }

            // Move to the next word
            word_count++;
        }

        return -1;
    }

};