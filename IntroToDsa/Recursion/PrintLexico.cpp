#include<bits/stdc++.h>
// https://leetcode.com/problems/lexicographical-numbers
//for submition

//     std::vector<int>arr;
//     vector<int> lexicalOrder(int n) {
//         for(int i=1;i<10;i++)
//         {
//             LexicoHelper(n,i);
//         }
//         return arr;
// }
//     void LexicoHelper(int n,int i){
//        if(i>n){
//         return;
//     }
//     arr.push_back(i);
//     for(int j=(i==0)?1:0;j<=9;j++){
//         LexicoHelper(n,10*i+j);
//     }   
//     }
void Lexico(int n,int i){
    if(i>n){
        return;
    }
    std::cout<<i<<"\n";
    for(int j=(i==0)?1:0;j<=9;j++){
        Lexico(n,10*i+j);
    }
}
int main(int argc, char const *argv[]){
    Lexico(13,0); 
    return 0;
}
