class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        result = '' # for storing the final result
        count_parenthesis = 0 # 0 means, outer. Anything +ve means inner
        for c in s:
            if c == '(':
                if count_parenthesis != 0:
                    result += c
                count_parenthesis += 1
            if c == ')':
                if count_parenthesis - 1 != 0:
                    result += c 
                count_parenthesis -= 1    
                               
        return result

        