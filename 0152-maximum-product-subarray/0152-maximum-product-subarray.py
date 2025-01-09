class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_pdt = nums[0]
        min_pdt = nums[0]
        result = nums[0]
        for i in range(1, len(nums)):
            # refreshing the subarrays
            temp = max_pdt
            max_pdt = max(nums[i], max_pdt * nums[i], min_pdt * nums[i])
            min_pdt = min(nums[i], temp * nums[i], min_pdt * nums[i])
            result = max(result, max_pdt)
        return result
