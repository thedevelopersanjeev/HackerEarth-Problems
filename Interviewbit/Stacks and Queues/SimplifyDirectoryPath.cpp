string Solution::simplifyPath(string s){

    int n = s.size();
    int index = 0;
    stack<string> path;
    while(index < n){
        string curr = "";
        while(index < n && s[index] != '/'){
            curr += s[index];
            index++;
        }
        if(curr == ".")
            continue;
        else if(curr == ".."){
            if(!path.empty())
                path.pop();
        }
        else if(curr != "")
            path.push(curr);
        index++;
    }
    if(path.empty())
        return "/";
    string ans = "";
    while(!path.empty()){
        string curr = path.top();
        path.pop();
        reverse(curr.begin(), curr.end());
        ans += curr;
        ans += "/";
    }
    reverse(ans.begin(), ans.end());
    return ans;

}
