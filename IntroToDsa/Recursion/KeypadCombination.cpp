#include<bits/stdc++.h>
using namespace std;
string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void FindCombination(string digits, int i,string osf ){
    if(i==digits.size()){
        cout<<osf<<" ";
        cout<<"\n";
        return;
    }
    string currentDigit=keypad[digits[i]-'0'];
    for(int j=0;j<currentDigit.size();j++){
        FindCombination(digits,i+1,osf+currentDigit[j]);
    }
}
int main(int argc, char const *argv[])
{
    string str="23";
    FindCombination(str,0,"");
    return 0;
}
