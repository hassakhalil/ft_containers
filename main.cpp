#include "./vector.hpp"
#include <iostream>
// #include <vector>
int main()
{
    ft::vector<int> vect;
    vect.reserve(10);
    std::cout<<"capacity == "<<vect.capacity()<<std::endl;
    std::cout<<"is_empty == "<<vect.empty()<<std::endl;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(13);
    vect.push_back(12);
    vect.push_back(15);
    vect.push_back(13);
    vect.push_back(122);
    vect.push_back(1);
    vect.push_back(21);
    vect.push_back(1234);
    std::cout<<"is_empty == "<<vect.empty()<<std::endl;

    std::cout<<"size == "<<vect.size()<<std::endl;
    std::cout<<"capacity == "<<vect.capacity()<<std::endl;
    for(int i =0;i<(int)vect.size();i++)
    {
        std::cout<<"vect["<<i<<"] == "<<vect[i]<<std::endl;
    }
    try{
        vect.at(100);
    }
    catch(std::exception& e)
    {
        std::cerr<<"Exception =="<<e.what()<<std::endl;
    }
}