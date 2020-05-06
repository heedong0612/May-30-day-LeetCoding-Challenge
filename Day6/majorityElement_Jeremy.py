from collections import defaultdict as dd
from typing import List

def majorityElement(nums: List[int]) -> int:
    '''
    O(n)
    we iterate through nums at most once
    '''
    d = dd(lambda : 0)
    for i in nums:
        d[i] += 1
        if d[i] > len(nums)//2:
            return i

if __name__ == "__main__":
    majorityElement([1,1,1,3,4])