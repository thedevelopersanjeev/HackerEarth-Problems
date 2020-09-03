class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size() - 1;
        if(letters[hi] <= target)
            return letters[0];
        while(hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if(letters[mid] > target)
                hi = mid;
            else
                lo = mid;
        }
        return (letters[lo] > target ? letters[lo] : letters[hi]);
    }
};