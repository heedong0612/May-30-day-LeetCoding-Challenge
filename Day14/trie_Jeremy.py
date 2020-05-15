class TrieNode:
    def __init__(self):
        self.isWord = False
        self.children = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        curr = self.root
        for i in word:
            if i not in curr.children:
                curr.children[i] = TrieNode()
            curr = curr.children[i]
        curr.isWord = True
            

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        curr = self.root
        for i in word:
            if i not in curr.children:
                return False
            curr = curr.children[i]
        return curr.isWord

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        curr = self.root
        for i in word:
            if i not in curr.children:
                return False
            curr = curr.children[i]
        return True

###########
# Fastest sol in py (104ms)

class Trie2:
    def __init__(self):
        self.trie = {}

    def insert(self, word: str) -> None:
        root = self.trie
        for c in word:
            if c not in root:
                root[c] = {}
            root = coot[c]
        root['#'] = '#'
    
    def search(self, word: str) -> bool:
        return self.startsWith(word + '#')
    
    def startsWith(self, prefix: str) -> bool:
        start = self.trie
        for c in prefix:
            if c not in start:
                return False
            start = start[c]
        return True