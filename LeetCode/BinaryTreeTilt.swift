/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    
    var ans: Int = 0
    
    func f(_ root: TreeNode?) -> Int {
        guard let root = root else {
            return 0
        }
        let left = f(root.left)
        let right = f(root.right)
        var temp = left - right
        if temp < 0 {
            temp = temp * -1
        }
        ans += temp
        return left + right + root.val
    }
    
    func findTilt(_ root: TreeNode?) -> Int {
        f(root)
        return ans
    }
}