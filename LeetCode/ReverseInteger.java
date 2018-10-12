class Solution {
    public int reverse(int x) {
        String str = String.valueOf(x);
        if(str.charAt(0) == '-'){
            StringBuilder s = new StringBuilder(str.substring(1));
            try{
                return Integer.parseInt(s.reverse().toString()) * -1;
            }catch(Exception e){
                return 0;
            }
        }
        else{
            StringBuilder s = new StringBuilder(str);
            try{
                return Integer.parseInt(s.reverse().toString());
            }catch(Exception e){
                return 0;
            }
        }
    }
}