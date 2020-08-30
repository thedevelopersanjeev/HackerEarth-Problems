class Solution {
    func findKthNumber(_ m: Int, _ n: Int, _ k: Int) -> Int {
        var l = 1, h = m * n
        while (h - l > 1) {
            var mid = l + (h - l) / 2
            var cnt = 0
            for i in 1...m {
                cnt += min(mid / i, n)
            }
            if(cnt >= k) {
                h = mid
            }
            else {
                l = mid
            }
        }
        return h
    }
}