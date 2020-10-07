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
    func flipEquiv(_ A: TreeNode?, _ B: TreeNode?) -> Bool {
        
        if A == nil && B == nil {
            return true;
        }
        
        guard let rootA = A else {
            return false
        }
        guard let rootB = B else {
            return false
        }
        if rootA.val != rootB.val {
            return false
        }
        
        return (flipEquiv(rootA.left, rootB.left) && flipEquiv(rootA.right, rootB.right)) || (flipEquiv(rootA.left, rootB.right) && flipEquiv(rootA.right, rootB.left))
        
    }
}