import java.time.LocalDate;
public class Solution {
    public String solve(int A, int B, int C) {
        return LocalDate.of(C, B, A).getDayOfWeek().toString().toLowerCase();
    }
}
