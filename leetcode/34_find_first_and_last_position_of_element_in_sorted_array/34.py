class Solution:
    def binary_search(self, nums: List[int], target: int, left: int, right: int):
        start, end = -1, -1
        
        if left == right:
            if nums[left] == target:
                start, end = left, left
        else:
            mid = (left + right) // 2
            if nums[mid] >= target:
                start, end = self.binary_search(nums, target, left, mid)

            if nums[mid] <= target:
                right_start, right_end = self.binary_search(nums, target, mid + 1, right)
                if start < 0 or (0 <= right_start < start):
                    start = right_start
                if right_end > end:
                    end = right_end
        return [start, end]
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]
        return self.binary_search(nums, target, 0, len(nums) - 1)
