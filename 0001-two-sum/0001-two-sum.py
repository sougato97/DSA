class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        storage_map = {}
        for i in range(0, len(nums)):
            if nums[i] in storage_map:
                # Element present
                return [i, storage_map[nums[i]]]
            complement = target - nums[i] 
            # We need to store the index with the complement key
            storage_map[complement] = i