
 bool doesOverlap(Interval x, Interval y){
    return min(x.end, y.end) > max(x.start, y.start);
 }
 
vector<Interval> Solution::insert(vector<Interval> &Intervals, Interval newInterval) {
    vector<Interval> ans; 
    int n = Intervals.size(); 
    if (n == 0) 
    { 
        ans.push_back(newInterval); 
        return ans; 
    }
    if (newInterval.end < Intervals[0].start || 
            newInterval.start > Intervals[n - 1].end) 
    { 
        if (newInterval.end < Intervals[0].start) 
            ans.push_back(newInterval); 
  
        for (int i = 0; i < n; i++) 
            ans.push_back(Intervals[i]); 
  
        if (newInterval.start > Intervals[n - 1].end) 
            ans.push_back(newInterval); 
  
        return ans; 
    } 
  
    if (newInterval.start <= Intervals[0].start && 
        newInterval.end >= Intervals[n - 1].end) 
    { 
        ans.push_back(newInterval); 
        return ans; 
    } 
  
    bool overlap = true; 
    for (int i = 0; i < n; i++) 
    { 
        overlap = doesOverlap(Intervals[i], newInterval); 
        if (!overlap) 
        { 
            ans.push_back(Intervals[i]); 
            if (i < n && 
                newInterval.start > Intervals[i].end && 
                newInterval.end < Intervals[i + 1].start) 
                ans.push_back(newInterval); 
  
            continue; 
        } 
  
        Interval temp; 
        temp.start = min(newInterval.start, 
                         Intervals[i].start); 
  
        while (i < n && overlap) 
        { 
  
            temp.end = max(newInterval.end, 
                           Intervals[i].end); 
            if (i == n - 1) 
                overlap = false; 
            else
                overlap = doesOverlap(Intervals[i + 1], 
                                          newInterval); 
            i++; 
        } 
  
        i--; 
        ans.push_back(temp); 
    } 
  
    return ans;
}
