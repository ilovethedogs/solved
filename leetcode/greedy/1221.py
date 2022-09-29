class Solution:
    def balancedStringSplit(self, s: str) -> int:
        result = 0
        
        num = {
            'R': 0,
            'L': 0
        }
        for i in range(0, len(s)):
            num[s[i]] += 1
            
            if num['R'] != 0 and num['R'] == num['L']:
                result += 1
                num['R'] = 0
                num['L'] = 0
        return result