vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> ans;
    // using max heap for lower half
    priority_queue<int> left;
    // using min heap for upper half
    priority_queue<int, vector<int>, greater<int>> right;
    int current = 0;
    for(auto x : A){
        // int x = A[i];
        // cin >>x;
        // case 1 : left half has more elements
        if(left.size() > right.size()){
            // new element is less than current median
            if(x < current){
                // move one element from left heap to right heap
                right.push(left.top());
                left.pop();
                // add new element into left heap
                left.push(x);
            }
            // new element is greater than or equal to current median
            else{
                // everything is OK, right heap has less elements
                // and new element is greater than current median
                // so, add it in right heap.
                right.push(x);
            }
            // update median
            current = (left.top() + right.top()) / 2;
            ans.push_back(left.top());
        }
        // case 2 : both heaps are balanced
        else if(left.size() == right.size()){
            // both heaps have same size, so just need to check if new element
            // is less than current median or greater and add accordingly
            if(x < current){
                left.push(x);
                current = left.top();
            }
            else{
                right.push(x);
                current = right.top();
            }
            ans.push_back(current);
        }
        // case 3 : right heap has more number of elements
        else{
            if(x > current){
                // move one element from right heap to left heap
                left.push(right.top());
                right.pop();
                right.push(x);
            }
            else{
                left.push(x);
            }
            current = (left.top() + right.top()) / 2;
            ans.push_back(left.top());
        }
        // ans.push_back(current);
        // cout <<current <<endl;
    }
    return ans;
}