class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        '''
        Credits for the eyeball tests
        https://www.youtube.com/watch?v=3ZnAYjpj6zc
        '''
        # Eyeball tests
        if num == 1 or num == 0:
            return True
        
        digitalRoot = [1, 4, 7, 9]
        squareOneth = [0, 1, 4, 5, 6, 9]
        oneth = num % 10
        tenth = num // 10 % 10
        divBy8 = num % 8
        
        # if oneth is one of the vals in squareOneth
        if oneth not in squareOneth:
            return False
        
        # even oneth
        elif oneth % 2 == 0:
            if oneth == 0:
                # tenth has to be 0
                if tenth != 0:
                    return False 
                       
            elif oneth == 4:
                # tenth has to be even
                if tenth % 2 != 0: 
                    return False
        
            elif oneth == 6:
                print("oneth == 6")
                print(f'tenth : {tenth}')
                # tenth has to be odd
                if tenth % 2 == 0:
                    print('return false?')
                    return False
            
            # check divisible by 8
            
            if divBy8 != 0 and divBy8 != 4:
                return False
            
        # odd
        else:
            if oneth == 1:
                # tenth has to be even
                if tenth % 2 != 0:
                    return False
            elif oneth == 5:
                # tenth has to be '2'
                if tenth != 2:
                    return False
            elif oneth == 9:
                # tenth has to be even
                if tenth % 2 != 0:
                    return False
                
            if divBy8 != 1:
                return False
     
        
        # Digital Root check
        print("Digital Root check")
        number = num
        sumDigit = sum(int(digit) for digit in str(number))
        
        while sumDigit > 9:
            sumDigit = sum(int(digit) for digit in str(sumDigit))
        print(f'Final sumDigit : {sumDigit}')
        
        if sumDigit not in digitalRoot:
            return False
        
        # this is where the fun begins
        l, r = 0, num
        
        while l <= r:
            mid = (l + r)//2
            square = mid * mid
            if square == num:
                return True
            # go left
            elif square > num:
                r = mid - 1
            # go right
            elif square < num:
                l = mid + 1
                
            
        
        # super brute force
        for i in range(num):
            if i * i == num:
                return True
            
        return False
    