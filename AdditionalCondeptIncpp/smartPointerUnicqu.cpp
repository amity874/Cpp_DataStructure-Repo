#include<bits/stdc++.h>
struct temp{
    int x;
    temp(){
        std::cout<<"Constructure called \n";
    }
    ~temp(){
        std::cout<<"Destructure called \n";
    }
};

int main(int argc, char const *argv[])
{
    std::cout<<"Start\n";
    {
        std::unique_ptr<int>u1(new int(13));
        std::cout<<*u1<<"\n";
        std::unique_ptr<temp>u2(new temp());//init in heap
        temp* ptr=new temp;//init in heap
        delete ptr;
        int x;
    }
    std::unique_ptr<int> p1(new int(100));
    std::unique_ptr<temp> p2(new temp());
    p2.reset();
    // std::unique_ptr<int> p2 = p1; throws error becase unique pointer cant share memory space
    return 0;
}