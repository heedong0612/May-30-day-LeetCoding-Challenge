from collections import defaultdict as dd 
from typing import List

def findJudge(self, N: int, trust: List[List[int]]) -> int:
    '''
    1. The town judge trusts nobody.
    2. Everybody (except for the town judge) trusts the town judge.
    3. There is exactly one person that satisfies properties 1 and 2.

    Runtime : 824ms lol

    This solution is honestly lowkey brute force 
    '''
    # special cases
    if N == 0:
        return -1
    if N == 1 and len(trust) == 0:
        return 1
    
    peopleWhoTrusts = dd(lambda : [])
    peopleWhomThisTrusts = dd(lambda : [])
    s = set()
    for pair in trust:
        peopleWhoTrusts[pair[1]].append(pair[0])
        peopleWhomThisTrusts[pair[0]].append(pair[1])
        s.add(pair[1])
        s.add(pair[0])

    for p in s:
        # judges trust no body 😤
        if len(peopleWhomThisTrusts[p]) == 0:
            # p is potential judge
            # does everyone else trusts this judge?
            if len(peopleWhoTrusts[p]) == N - 1:
                return p

    return -1

    