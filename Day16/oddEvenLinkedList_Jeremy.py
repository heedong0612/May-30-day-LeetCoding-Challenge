# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

from queue import Queue

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        '''
        Runtime was really slow (96ms)
        Need to optimize lol
        '''
        if head == None:
            return head
        if head.next == None:
            return head
        
        num = 1
        curr = head
        qOdd, qEven = Queue(), Queue()        
        while curr != None:
            # if odd
            if num % 2 != 0:
                qOdd.put(curr)
            else:
                qEven.put(curr)
            prev = curr
            curr = curr.next
            prev.next = None
            num += 1
            
        
        curr = head
        # place odd nodes
        while qOdd.qsize() != 0:
            curr.next = qOdd.get()
            curr = curr.next
        
        while qEven.qsize() != 0:
            curr.next = qEven.get()
            curr = curr.next
        
        return head
            