from collections import Counter

def checkInclusion(s1: str, s2: str) -> bool:
    if len(s1) > len(s2):
        return False
    
    s1Counter = Counter(s1)
    currCounter = Counter()
    size = len(s1)
    for i, c in enumerate(s2):
        currCounter[c] += 1

        if i >= size:
            left = s2[i - size]

            if currCounter[left] == 1:
                del currCounter[left]
            else:
                currCounter[left] -= 1
        if currCounter == s1Counter:
            return True
        
    return False