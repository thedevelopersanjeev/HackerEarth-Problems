class Solution {
    
    fun findCost(a: IntArray, b: IntArray): Int {
        return Math.max(Math.abs(a[0] - b[0]), Math.abs(a[1] - b[1]))
    }
    
    fun minTimeToVisitAllPoints(points: Array<IntArray>): Int {
        val n = points.count()
        var ans = 0
        for (i in 0 until n - 1) {
            ans += findCost(points[i], points[i + 1])
        }
        return ans
    }
}