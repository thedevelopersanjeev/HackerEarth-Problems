class Solution {
    fun average(salary: IntArray): Double {
        var sm = salary.sum(); val n = salary.count() ?: 0
        val mx = salary.max() ?: 0; val mn = salary.min() ?: 0
        sm -= mx
        sm -= mn
        return (sm * 1.0) / (n - 2)
    }
}