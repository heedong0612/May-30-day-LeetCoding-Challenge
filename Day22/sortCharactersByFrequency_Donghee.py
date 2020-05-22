import sys

class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        counts = [0 for x in range(256)]

        for c in s:
            counts[ord(c)] += 1

        mp = dict() # mp = { 'a' : 4, 'b' : 2 }

        maxCount = 0
        minCount = sys.maxsize # INT_MAX

        for i in range(256) :
            if counts[i] > 0 :
                if counts[i] not in mp :
                    mp[counts[i]] = ""
                
                mp[counts[i]] += chr(i)
                
                maxCount = max(maxCount, counts[i])
                minCount = min(minCount, counts[i])
        
        ans = ""
        
        # range(start, stop, step)
        for i in range(maxCount, minCount - 1, -1) :
            # if (mp.find(i) != mp.end()) {
            if i in mp : 
                for ch in mp[i] :
                    for j in range(i) :
                        ans += ch

        return ans

            
    # from collections import defaultdict as dd
    # a["a"]; error
    # a['a']; give you a fallback
    # c = Counter('Jeremy')
    # c['e'] -> 2
    # c['a'] -> 0
    # contacts = {}
    # contacts['Donghee'] -> Person()

        


