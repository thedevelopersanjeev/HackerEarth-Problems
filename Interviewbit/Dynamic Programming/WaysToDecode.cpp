int Solution::numDecodings(string s) {

    if(s.size() == 0 || s[0] == '0') return 0;
    if(s.size() == 1) return 1;
    int arr[s.size()+1] = {0};
    arr[s.size()] = 1;
    if(s[s.size()-1] != '0') arr[s.size()-1] = 1;
    for(int i = s.size()-2; i >= 0; i--){
        if(s[i] == '0' && s[i+1] == '0') return 0;
        if(s[i+1] == '0'){
            if(s[i] == '1' || s[i] == '2'){
                arr[i] = arr[i+2];
                continue;
            }
            else return 0;
        }
        if(s[i] == '0'){
            arr[i] = 0;
            continue;
        }
        arr[i] = arr[i+1];
        if(s[i] == '1'){
            arr[i]+= arr[i+2];
        }
        else if(s[i] == '2' && (s[i+1] != '7' && s[i+1] != '8' && s[i+1] != '9')){
            arr[i]+= arr[i+2];
        }
    }
    return arr[0];

}
