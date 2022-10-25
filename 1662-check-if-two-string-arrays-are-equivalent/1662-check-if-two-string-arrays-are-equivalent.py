class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        # word1.sort()
        # word2.sort()
        i = 0
        s = ""
        t = ""
        while(i<len(word1)):
            s+= word1[i]
            i+=1
        i=0
        while(i<len(word2)):
            t+= word2[i]
            i+=1
        return s==t
        