#include "./vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>
// #include <vector>
int main()
{
    ft::vector<int> vect;
    std::vector<int> v;

    v.reserve(1000);
    vect.reserve(1000);
    std::cerr<< "max_size 1== "<<vect.max_size()<<"  |  "<<"max_size 2== "<<v.max_size()<<std::endl;
    std::cout<<"capacity 1 == "<<vect.capacity()<<"  |  "<<"capacity 2 == "<<v.capacity()<<std::endl;
    std::cout<<"is_empty 1 == "<<vect.empty()<<"  |  "<<"is_empty 2 == "<<v.empty()<<std::endl;
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
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    v.push_back(13);
    v.push_back(12);
    v.push_back(15);
    v.push_back(13);
    v.push_back(122);
    v.push_back(1);
    v.push_back(21);
    v.push_back(1234);

    std::cout<<"is_empty 1 == "<<vect.empty()<<"  |  is_empty 2 == "<<v.empty() <<std::endl;

    vect.resize(100,9);
    v.resize(100,9);
    std::cout<<"size 1 == "<<vect.size()<<"  |  size 2 == "<<v.size()<<std::endl;
    std::cout<<"capacity 1 == "<<vect.capacity()<<"  |  capacity 2 == "<<v.size()<<std::endl;
    for(int i =0;i<(int)vect.size();i++)
    {
        std::cout<<"vect["<<i<<"] == "<<vect[i]<< "  |  "<<"v["<<i<<"] == "<<v[i]<<std::endl;
    }
    ft::vector<int>::iterator it = vect.begin();
    std::vector<int>::iterator it2= v.begin();
    for (int i =0;it<vect.end();it++)
    {
        std::cout<<"{using iterator} "<<"vect["<<i<<"] == "<<*it<< "  |  "<<"v["<<i<<"] == "<<*it2<<std::endl;
        i++;
        it2++;
    }
    try{
        vect.at(100);
    }
    catch(std::exception& e)
    {
        std::cerr<<"Exception =="<<e.what()<<std::endl;
    }
    while(1);
}