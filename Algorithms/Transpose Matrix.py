class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        
        transpose = list()
        
        for col in range(0, len(A[0])):
            new_row = list()
            
            for row in range(0, len(A)):
                new_row.append(A[row][col])
            
            transpose.append(new_row)
            
        return transpose
        
