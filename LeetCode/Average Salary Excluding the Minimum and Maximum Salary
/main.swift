class Solution {
    func average(_ salary: [Int]) -> Double {
        var sm = salary.reduce(0, +) ?? 0, mx = salary.max() ?? 0, mn = salary.min() ?? 0, n = salary.count
        sm -= mx
        sm -= mn
        return Double(Double(sm) / Double(n - 2))
    }
}