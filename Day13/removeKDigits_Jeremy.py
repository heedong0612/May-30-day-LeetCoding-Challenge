def removeKdigits(num: str, k: int) -> str:
    '''
    Got this solution from
    https://www.youtube.com/watch?v=HXvxIth510g
    '''
    if len(num) == k:
        return "0"
    
    # init stack
    stack = []
    popCount = k

    for i in num:
        while popCount and stack and stack[-1] > i:
            stack.pop()
            popCount -= 1
        stack.append(i)
    ans = ''.join(stack[:len(stack)-popCount]).lstrip('0')
    
    if len(ans):
        return ans
    else:
        return '0'

if __name__ == "__main__":
    pass