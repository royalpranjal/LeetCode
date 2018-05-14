class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        
        for rowIndex, row in enumerate(A):
            start = 0
            end = len(row) - 1
            
            while start < end:
                A[rowIndex][start], A[rowIndex][end] = A[rowIndex][end], A[rowIndex][start]
                A[rowIndex][start] = int(not A[rowIndex][start])
                A[rowIndex][end] = int(not A[rowIndex][end])
                start += 1
                end -= 1
            
            if start == end:
                A[rowIndex][end] = int(not A[rowIndex][end])
            
        return A
