class Solution:
    # @param A : list of list of integers
    # @param B : integer
    # @return a list of list of integers
    def solve(self, A, B):
        A.sort(key = lambda K: K[0]**2 + K[1]**2)
        return A[:B]
