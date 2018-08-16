class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        
        track = dict()
        result = list()
        
        for word in A.split(' '):
            if track.get(word):
                track[word]['first'] += 1
            else:
                track[word] = dict()
                track[word]['first'] = 1
                track[word]['second'] = 0
        
        for word in B.split(' '):
            if track.get(word):
                track[word]['second'] += 1
            else:
                track[word] = dict()
                track[word]['second'] = 1
                track[word]['first'] = 0
                
        for key, value in track.items():
            if value['first'] == 0 and value['second'] == 1:
                result.append(key)
            elif value['second'] == 0 and value['first'] == 1:
                result.append(key)
            
        return result
        
