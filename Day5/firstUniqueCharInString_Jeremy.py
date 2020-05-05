def firstUniqChar(s: str) -> int:
    '''
    Time complexity O(n)
    '''
    charSet = set()
    countArr = [0 for i in range(len(s))]
    d = dict()
    for i, ch in enumerate(s):
        if ch not in charSet:
            charSet.add(ch)
            countArr[i] += 1
            d[ch] = i
        else:
            countArr[d[ch]] += 1
    try:
        return countArr.index(1)
    except:
        return -1

# ----- Got this from the fastest solution on leetcode (python3)
import string
def firstUniqChar2(s: str) -> int:
    '''
    O(1) wow 
    '''
    # init ans as length of s
    ans = len(s)

    # loop through every alphabet
    for ch in string.ascii_lowercase:
        left = s.find(ch)

        # basically if it's unique
        if left != -1 and left == s.rfind(ch):
            # update ans with lesser val
            ans = min(ans, left)

    # return ans if modified, -1 otherwise (not found)
    return ans if ans != len(s) else -1

    

    
if __name__ == "__main__":
    print(firstUniqChar('loveleetcode'))
