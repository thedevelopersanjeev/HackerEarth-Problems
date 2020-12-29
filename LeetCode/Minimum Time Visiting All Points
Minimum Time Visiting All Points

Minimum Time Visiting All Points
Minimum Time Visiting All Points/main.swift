class Solution {
    
    fileprivate func findCost(_ a: [Int], _ b: [Int]) -> Int {
        return max(abs(a[0] - b[0]), abs(a[1] - b[1]))
    }
    
    func minTimeToVisitAllPoints(_ points: [[Int]]) -> Int {
        let n = points.count
        var ans = 0
        for i in 0..<n - 1 {
            ans += findCost(points[i], points[i + 1])
        }
        return ans
    }
}