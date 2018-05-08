class Solution:
    def getLastIndex(self, S, c, index):
        while index < len(S) and S[index] == c:
            index += 1
            
        return index
    
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        
        ans = []
        index = 0
        
        while index < len(S):
            start = index
            end = self.getLastIndex(S, S[index], index)
            
            if end - start >= 3:
                ans.append([start, end - 1])
                
            index = end
        
        return ans
        
