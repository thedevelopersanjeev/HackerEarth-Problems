class Solution {
public:
    int romanToInt(string s) {
        int a[100]={0}, b[100][100];
    a['V'] = 5;
    a['L'] = 50;
    a['D'] = 500;
    a['I'] = 1;
    a['X'] = 10;
    a['C'] = 100;
    a['M'] = 1000;
    b['I']['V'] = -1;
    b['I']['X'] = -1;
    b['X']['L'] = -1;
    b['X']['C'] = -1;
    b['C']['D'] = -1;
    b['C']['M'] = -1;
    
    int decimal=0;
    int size = s.size();
    int fact = 1;
    for (int pos=0; pos<size; pos++) {
        if (b[s[pos]][s[pos+1]] == -1)
            fact = -1;
        else
            fact = 1;
        decimal += a[s[pos]] * fact;
    }
    return decimal;
    }
};