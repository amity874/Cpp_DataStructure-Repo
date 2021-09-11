#include<bits/stdc++.h>
class Product{
    private:
    std::string name;
    std::string desc;
    int price;
    float discount;
    void display(){
        std::cout<<"Name"<<name;
    }
    public:
    void set_name(std::string s){
        name=s;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    Product iphone;
    return 0;
}
