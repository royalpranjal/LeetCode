class Solution:
    def check(self, S, index, target_string):
        for i in range(0, len(target_string)):
            if index + i == len(S):
                return False
            elif S[index + i] != target_string[i]:
                return False
        
        return True
    
    def makeString(self, tracker):
        ans = ""
        
        for i in range(0, len(tracker)):
            ans += tracker[i]
            
        return ans
    
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        
        tracker = dict()
        
        for index, char in enumerate(S):
            tracker[index] = char
            
        for index in range(0, len(indexes)):
            if self.check(S, indexes[index], sources[index]):
                tracker[indexes[index]] = targets[index]    
                for temp_index in range(indexes[index] + 1, indexes[index] + len(sources[index])):
                    tracker[temp_index] = ''
        
        return self.makeString(tracker)
        
