class Solution {
    public boolean isPalindrome(int x) {
        String a = String.valueOf(x);
        StringBuilder builder = new StringBuilder();
        builder.append(a);
        return a.equals(builder.reverse().toString());
    }
}