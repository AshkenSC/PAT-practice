# 198

from typing import List

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        ugly_set = [1]
        pointers = [0] * len(primes)
        while len(ugly_set) < 1000:
            candidates = [ugly_set[pointers[i]] * primes[i] for i in range(len(primes))]
            new_ugly = min(candidates)
            ugly_set.append(new_ugly)
            for i in range(len(primes)):
                if new_ugly == ugly_set[pointers[i]] * primes[i]:
                    pointers[i] += 1
        
        return ugly_set[n - 1]
    

sol = Solution()
res = sol.nthSuperUglyNumber(12, [2,7,13,19])
print(res)