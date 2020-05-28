// Donghee Lee
// 5/28/2020

class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        arr = []
        
        arr.append(0)
        if num == 0:
            return arr
        
        arr.append(1)
        if num == 1:
            return arr
        
        currNum = 2
        nextNum = currNum * 2
        i = 2
        
        while i <= num:
            arr.append(1 + arr[i - currNum])
            i += 1
            
            if i == nextNum:
                currNum = nextNum
                nextNum *= 2
                
        return arr
        