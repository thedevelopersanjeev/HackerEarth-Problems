#include <bits/stdc++.h>
using namespace std;

void urlify(char *str, int len){
    int numOfSpaces = 0;
    int i = 0, j = 0;
    // count number of spaces in the string
    for ( i = 0; i < len; ++i ) {
        if (str[i] == ' ') {
            ++numOfSpaces;
        }
    }
    // new length of string
    // ' ' will be replaced by '%20'
    int extendedLen  = len + 2 * numOfSpaces;
    i = extendedLen - 1;
    for( j = len - 1; j >= 0; --j ) {
        if ( str[j] != ' ' ) {
        	// !space
           	str[i--] = str[j];
        } else {
        	// empty space
        	// replace by '%20'
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
}

int main(){
    char str[] = "Mr John Smith    ";           
    cout << "Actual string   : " << str << endl;
    urlify(str, 13);                           
    cout << "URLified string : " << str << endl;
    return 0;
}