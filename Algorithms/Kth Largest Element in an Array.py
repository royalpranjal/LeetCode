class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        heap = []
        
        for i in range (0, k):
            heapq.heappush(heap, nums[i])
        
        for i in range(k, len(nums)):
            heapq.heappush(heap, nums[i])
            heapq.heappop(heap)
        
        return heap[0]
        
