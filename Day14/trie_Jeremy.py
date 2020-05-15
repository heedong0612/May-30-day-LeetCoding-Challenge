from typing import List, Dict
class TrieNode:
    def __init__(self, char: str = '', children = [], endOfInsertedWord: bool = False):
        self.char = char
        self.children = children
        self.endOfInsertedWord = endOfInsertedWord
    
    @property
    def childrenLetters(self):
        ret = []
        for child in self.children:
            ret.append(child.val)
        return ret

    def getChild(self, val: str):
        for child in self.children:
            if child.val == val:
                return child
        return None

class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        # maybe exists?
        maybe = self.getLastNode(word)
        if maybe:
            maybe.endOfInsertedWord = True
        else:
            self.insertHelper(word)

    def insertHelper(self, word: str):
        curr = self.root
        for i in range(len(word)):
            char = word[i]
            if char in curr.childrenLetters:
                curr = curr.getChild(char)
            else:
                newNode = TrieNode(char=char)
                curr.childrenLetters.append(newNode)
                curr = curr.getChild(char)
        
        curr.endOfInsertedWord = True
                



        
    def getLastNode(self, word: str) -> TrieNode:
        '''
        If word exists (startsWith)
        return last node the word
        else
        return None
        '''
        if self.startsWith(word):
            curr = self.root
            for i in range(len(word)):
                curr = curr.getChild(word[i])
            return curr
        else:
            return None
        

            
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        return self.searchHelper(self.root, word, 0)
    
    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        return searchHelper(self.root, prefix, 0, False)
        
    def searchHelper(self, curr: TrieNode, target: str, index: int, isSearch: bool = True) -> bool:
        # last iteration
        if index == len(target) - 1:
            if isSearch:
                return curr.endOfInsertedWord
            else:
                return True

        
        # look for next char in
        char = target[index]
        if char in curr.childrenLetters:
            return self.searchHelper(curr.getChild(char), target, index+1, isSearch)
        
        # if the next char is not even in the children of curr 
        # then word doesn't exist
        return False

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)

if __name__ == "__main__":
    Trie()