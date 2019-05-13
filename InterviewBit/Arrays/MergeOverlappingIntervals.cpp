/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool comp(Interval x, Interval y){
     return (x.start > y.start);
 }
 
 bool comp2(Interval x, Interval y){
     return (x.start < y.start);
 }
 
 vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // sort based on starting index of intervals
    sort(A.begin(), A.end(), comp);
    int j = 0;
    for(int i = 0; i < A.size(); i++){
        if(j != 0 && A[j-1].start <= A[i].end){
            while(j != 0 && A[j-1].start <= A[i].end ){
            A[j-1].end = max(A[j-1].end, A[i].end);
            A[j-1].start = min(A[j-1].start, A[i].start);
            j--;
            }
        }
        else
            A[j] = A[i];
        j++;
    }
    vector<Interval> ans;
    for(int i = 0; i < j; i++)
        ans.push_back(A[i]);
    sort(ans.begin(), ans.end(), comp2);
    return ans;
 }
