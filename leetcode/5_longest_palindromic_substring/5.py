class Solution:
    def longestPalindrome(self, s: str) -> str:
        longest_left_idx = 0
        longest_right_idx = 0
        max_len = 1
        
        # Assume each character (or pair of characters, when the (i+1)th
        # character is the same as the ith character) is the center of a new
        # palindrome. Iterate outward from the center until it stops being a
        # palindrome, and update the max length and indices corresponding to
        # the max length if it's greater than the current max length.
        for i in range(len(s) - 1):
            # First address the case where the palindrome is of odd length.
            l = i - 1
            r = i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            if (r - l - 1) > max_len:
                longest_left_idx = l + 1
                longest_right_idx = r - 1
                max_len = r - l - 1
                
            # Handle the case where the palindrome is of even length.
            if s[i] == s[i + 1]:
                l = i - 1
                r = i + 2
                while l >= 0 and r < len(s) and s[l] == s[r]:
                    l -= 1
                    r += 1
                if (r - l - 1) > max_len:
                    longest_left_idx = l + 1
                    longest_right_idx = r - 1
                    max_len = r - l - 1
                    
        return s[longest_left_idx:longest_right_idx + 1]
