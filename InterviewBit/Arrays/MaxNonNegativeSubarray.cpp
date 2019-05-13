vector<int> Solution::maxset(vector<int> &A) {
    int n=A.size();
    int i=0,maxm=0,count=0,start=0,end=-1;
    int fstart=-1,fend=-1;
    long long int sum=0,maxsum=0;
    vector<int> res;
    while(i<n){
        if(A[i]>=0){
            sum+=A[i];
            count++;
            end++;
        }
        if(sum>maxsum){
            maxsum=sum;
            fstart=start;
            fend=end;
        }
        else if(sum==maxsum&&count>maxm){
            maxm=count;
            fstart=start;
            fend=end;
        }
        if(A[i]<0){
            count=0;
            start=i+1;end=i;
            sum=0;
        }
        i++;
    }
    if(fstart!=-1&&fend!=-1){
        for(int i=fstart;i<=fend;i++)
         res.push_back(A[i]);
    }
    return res;
}
