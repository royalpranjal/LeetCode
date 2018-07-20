class Solution:
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        
        max_power_of_2 = 1
        
        while max_power_of_2 <= N:
            max_power_of_2 *= 2
            
        max_power_of_2 /= 2
        
        last = 0
        curr = 0
        ans = 0
        
        while N:
            curr += 1
            
            if N - max_power_of_2 >= 0: 
                N -= max_power_of_2
                if last:
                    ans = max(ans, curr - last)

                last = curr
            
            max_power_of_2 /= 2    
            
        return ans
        
