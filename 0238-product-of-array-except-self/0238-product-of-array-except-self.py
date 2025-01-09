class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1] * len(nums)
        # calculate the prefix
        for i in range(1, len(nums)):
            result[i] = result[i-1] * nums[i-1]
        
        # calculate the postfix
        i = len(nums) - 2
        product = 1
        while(i>=0):
            product *= nums[i+1]
            result[i] = result[i] * product
            i = i-1
        
        return result

