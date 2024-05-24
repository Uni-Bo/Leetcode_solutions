from typing import List
from collections import Counter

class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        # Calculate the score of each word
        def word_score(word):
            return sum(score[ord(c) - ord('a')] for c in word)

        word_scores = [word_score(word) for word in words]

        # Count available letters
        letter_count = Counter(letters)

        def can_form(word, letter_count):
            word_count = Counter(word)
            for char, count in word_count.items():
                if letter_count[char] < count:
                    return False
            return True

        # Use backtracking to explore all subsets of words
        def backtrack(index, current_score, letter_count):
            if index == len(words):
                return current_score

            # Option 1: skip the current word
            max_score = backtrack(index + 1, current_score, letter_count)

            # Option 2: include the current word if possible
            word = words[index]
            if can_form(word, letter_count):
                for char in word:
                    letter_count[char] -= 1
                max_score = max(max_score, backtrack(index + 1, current_score + word_scores[index], letter_count))
                for char in word:
                    letter_count[char] += 1

            return max_score

        # Start backtracking from the first word
        return backtrack(0, 0, letter_count)

