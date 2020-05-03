from collections import defaultdict as dd

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        '''
        m = len(ransomNote)
        n = len(magazine)

        Loops through magazine and ransomNote once each
        Time complexity O(m+n)
        '''
        # make dict from magazine
        d = dd(lambda: 0)
        for ch in magazine:
            d[ch] += 1
        
        # loop through ransomNote
        for ch in ransomNote:
            if d[ch] == 0: # all instanse of that char has been used or doesn't exist
                return False
            else:
                d[ch] -= 1
        return True

'''
A more convinient solutions would be using 'Counter' from the
collections module which does the exact thing we're doing up there

For some 
'''