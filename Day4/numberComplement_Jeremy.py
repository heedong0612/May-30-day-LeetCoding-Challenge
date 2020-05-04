class Solution:
    def findComplement(self, num: int) -> int:
        '''
        There's probably a faster way with bitwise
        but I don't know how to do that yet lol
        '''
        ans = ''
        
        # for each number in the binaryString
        for ch in bin(num).split('b')[1]:
            if ch == '1':
                ans += '0'
            else:
                ans += '1'
        
        # converts the binary string to a decimal integer
        # the second param denotes the source base number
        return int(ans, 2) 