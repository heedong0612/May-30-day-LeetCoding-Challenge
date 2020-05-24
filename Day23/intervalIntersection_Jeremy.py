from typing import List

def intervalIntersection(A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
    '''
    Didn't have to do it :(
    Got it from youtube just for the sake of submitting
    Source:
    https://www.youtube.com/watch?v=lNpoSEH388k
    '''
    a, b = 0, 0
    intervals = []
    while a < len(A) and b < len(B):
        interval_Starting, interval_Ending = max(A[a][0], B[b][0]), min(A[a][1], B[b][1])

        if interval_Starting <= interval_Ending:
            intervals.append([interval_Starting, interval_Ending])
        
        if A[a][1] < B[b][1]:
            a += 1 
        else:
            b += 1
    return intervals