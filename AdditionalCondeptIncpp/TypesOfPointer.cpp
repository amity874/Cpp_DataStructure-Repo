#include<bits/stdc++.h>
int function(int n){
    std::cout<<"First";
}
int function(char *ch){
    std::cout<<"Second";
}
int main(int argc, char const *argv[])
{
    std::cout<<"hello\n";
    void *ptr=new bool;
    std::cout<<sizeof(*((int*)ptr))<<"\n";
    *((long long int*)ptr)=10;
    std::cout<<*((long long int*)ptr)<<"\n";
    int* ptr1=NULL;
    char *ptr2=NULL;
    float* ptr3=nullptr;
    // std::cout<<*ptr1<<" "<<*ptr2<<" "<<*ptr3<<"\n";segmentation fault
    std::cout<<NULL<<"\n"; // it is actually going to evaluate to an integer constant 0 -> (void*)0
    // std::cout<<nullptr<<"\n";// it is a variable of type nullptr_t
    // function(nullptr);
    // function('j');
    int *p1=new int;//p1 is in stack but address stored by p1 in heap
    std::cout<<p1<<"\n";
    delete p1;
    std::cout<<p1<<"\n";
    p1=NULL;
    std::cout<<p1<<"\n";
    int *pwild;//this is called wild pointer

    return 0;
}
