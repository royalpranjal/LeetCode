class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        indexed_list = []
        answer = []
        
        for index, value in enumerate(nums):
            indexed_list.append((value, index))
        
        indexed_list.sort(key=lambda x: x[0], reverse=False)
        
        start = 0
        end = len(nums) - 1
        
        while start < end:
            sum = indexed_list[start][0] + indexed_list[end][0]
            if sum == target:
                answer = [min(indexed_list[start][1], indexed_list[end][1]), max(indexed_list[start][1], indexed_list[end][1])]
                break
            elif sum < target:
                start += 1
            else:
                end -= 1
        
        return answer
