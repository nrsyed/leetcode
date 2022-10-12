class Solution:
    """
    Runtime: 26 ms (98.79 %ile)
    Memory: 13.8 MB (79.33 %ile)
    """
    def letter_combinations(self, digits: str, memo: Dict[str, List[str]]):
        if digits in memo:
            combos = memo[digits]
        else:
            combos = [
                c + combo_ for c in memo[digits[0]]
                for combo_ in self.letter_combinations(digits[1:], memo)
            ]
            memo[digits] = combos
        return combos
    
    def letterCombinations(self, digits: str) -> List[str]:
        num_to_combos = {
            "": [],
            "2": list("abc"),
            "3": list("def"),
            "4": list("ghi"),
            "5": list("jkl"),
            "6": list("mno"),
            "7": list("pqrs"),
            "8": list("tuv"),
            "9": list("wxyz"),
        }
        return self.letter_combinations(digits, num_to_combos)
