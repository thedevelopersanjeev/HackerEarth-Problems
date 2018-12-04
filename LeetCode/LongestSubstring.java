class Solution {
    public int lengthOfLongestSubstring(String s) {
        int result = 0;
        for(int i=0; i < s.length(); i++) {
            String a = "";
        for(int j=i; j<s.length()&&!(a.contains(Character.toString(s.charAt(j)))); j++){
                a += s.charAt(j);
            }
            result = Math.max(result,a.length());
        }
        return result;       
    }
}