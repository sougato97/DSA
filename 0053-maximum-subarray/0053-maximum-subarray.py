class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = nums[0]
        array_sum = 0
        for i in range(0, len(nums)):
            if (array_sum < 0):
                array_sum = 0 # discard the elements from the subarray
            array_sum += nums[i]
            if (array_sum > max_sum):
                max_sum = array_sum
        return max_sum
