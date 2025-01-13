class Solution:
    def __init__(self):
        self.max = 2**31 - 1
        
    def myAtoi(self, s: str) -> int:
        isPos = True
        isNumStarted = False
        res = 0

        for ch in s:
            if ch.isdigit():
                if not isNumStarted:
                    isNumStarted = True
                res = res * 10 + int(ch)
            elif not isNumStarted and (ch == ' ' or ch == '+'):
                if ch == '+':
                    isNumStarted = True
                continue
            elif ch == '-' and not isNumStarted:
                isNumStarted = True
                isPos = False
            else:
                break

            if res > self.max:
                return self.max if isPos else -1 * (self.max + 1)

        return res if isPos else -1 * res