class Solution:
    def minimumSum(self, num: int) -> int:
        data = list(map(int, str(num)))
        data.sort()
        return 10 * (data[0] + data[1]) + data[2] + data[3]