class Solution:
    def minOperations(self, nums: List[int]) -> int:
        result = 0
        
        for i in range(1, len(nums)):
            tmp = nums[i - 1] - nums[i] + 1
            if tmp > 0:
                result += tmp
                nums[i] += tmp
            
        return result