class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        duplicate = set()
        for i in range(0, len(nums)):
            if nums[i] in duplicate:
                return True
            else:
                duplicate.add(nums[i])
        return False