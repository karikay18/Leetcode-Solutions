class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        ns=len(needle)
        hs=len(haystack)
        for i in range(hs - ns + 1):
            if haystack[i:i + ns] == needle:
                return i
        return -1
        