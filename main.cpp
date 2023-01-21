#include "./vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    //test range constructor
    ft::vector<int> test(10,7);
    ft::vector<int> test2(test.begin(),test.end());
    std::cout<<"range == "; 
    for (int i = 0;i<10;i++){
        std::cout<<" "<<test2[i];
    }
    std::cout<<std::endl;
    //test end 
    while(1);
    ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
    while(1);
    ft::vector<int> vect;
    std::vector<int> v;
    ft::vector<int> a(10,55);
    ft::vector<int> b(vect);
    ft::vector<int> c;
    c = b;

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
    ft::vector<int>::const_iterator it = vect.begin();
    std::vector<int>::const_iterator it2= v.cbegin();
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