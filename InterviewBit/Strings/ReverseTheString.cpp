#include <iterator>
void Solution::reverseWords(string &A) {
    string result = "";
    for(int i = A.length()-1; i>-1; --i){
        if (A[i] != ' '){
              int last = i;
              int first = i;
              while (i>-1 && A[i] != ' ')
                  --i;
              first = i + 1;
              result.append(A.begin()+first, A.begin()+last+1);
              if (i>0){
                string str = A.substr(0, i+1);
                string temp = "";
                temp.append(i+1, ' ');
                if(str != temp)
                    result += ' ';
              }
        }
    }
    A = result;
}
