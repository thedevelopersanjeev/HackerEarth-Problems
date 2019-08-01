// Given a fraction in the form of num/den
// Represent it as a sum of fractions of the form 1/den
// example : 2/3 = 1/2 + 1/6
#include<bits/stdc++.h>
using namespace std;

// num : numerator of the fraction.
// den : denominator of the fraction.
void printFractions(int num, int den){
    // base condition
    if(num == 0 || den == 0)
        return;
    // handle cases like 4/16 or 3/30 or x/k.x...
    if(den%num == 0){
        cout <<"1/" <<den/num <<"\n";
        return;
    }
    // handle cases like 16/4 or 20/2 or k.x/x ...
    if(num%den == 0){
        cout <<num/den <<"\n";
        return;
    }
    // handle cases when numerator is greater than denominator
    if(num > den){
        cout <<num/den + " + ";
        printFractions(num%den, den);
        return;
    }
    // denominator is greater than numerator and
    // denominator does not divide numerator.
    int temp = den/num + 1;
    cout <<"1/" <<temp <<" + ";
    printFractions(num*temp-den, den*temp);
}

int main(){
    cout <<"Fraction : 2/3\n";
    printFractions(2, 3);
    cout <<"\nFraction : 6/14n";
    printFractions(6, 14);
    cout <<"\nFraction : 12/13\n";
    printFractions(12, 13);
    return 0;
}