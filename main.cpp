#include "./vector.hpp"
#include <iostream>
//std
#include <vector>
#include <iterator>

int main()
{
  //test insert
  //testing reverse_iterator
    // std::vector<int> vv;
    // std::cout<<"vv.capacity_ == "<<vv.capacity()<<std::endl;
    // ft::vector<int>  vvclone;
    // std::cout<<"vvclone.capacity_ == "<<vvclone.capacity()<<std::endl;

    // //test std::vector::erase outofrange --->segfault 
    // // vv.erase(vv.begin()+100);
    // vv.push_back(1);
    // std::cout<<"vv.capacity_ == "<<vv.capacity()<<std::endl;
    // vv.push_back(2);
    // std::cout<<"vv.capacity_ == "<<vv.capacity()<<std::endl;

    // vv.push_back(3);
    // std::cout<<"vv.capacity_ == "<<vv.capacity()<<std::endl;

    // vv.push_back(4);
    // vv.push_back(5);
    // vv.push_back(6);
    // vv.push_back(7);
    // vv.push_back(8);
    // vv.push_back(9);
    // vv.push_back(10);
    // vvclone.push_back(1);
    // std::cout<<"vvclone.capacity_ == "<<vvclone.capacity()<<std::endl;

    // vvclone.push_back(2);
    // std::cout<<"vvclone.capacity_ == "<<vvclone.capacity()<<std::endl;

    // vvclone.push_back(3);
    // std::cout<<"vvclone.capacity_ == "<<vvclone.capacity()<<std::endl;

    // vvclone.push_back(4);
    // vvclone.push_back(5);
    // vvclone.push_back(6);
    // vvclone.push_back(7);
    // vvclone.push_back(8);
    // vvclone.push_back(9);
    // vvclone.push_back(10);
    // vv.insert(vv.begin()+5,100);
    // vv.insert(vv.begin()+2,10,9999);
    // vvclone.insert(vvclone.begin()+5,100);
    // vvclone.insert(vvclone.begin()+2,10,9999);
    // vv.erase(vv.begin()+vv.size()-1);
    // vvclone.erase(vvclone.begin()+vvclone.size()-1);
    // vv.erase(vv.begin(),vv.begin()+vv.size()-1);
    // vvclone.erase(vvclone.begin(),vvclone.begin()+vvclone.size()-1);
    // vv.assign(30,77);
    // vvclone.assign(30,77);

    // // std::vector<int>::iterator tt = vv.begin();
    // ft::reverse_iterator<ft::vector<int>::iterator> rev_itclone = vvclone.rbegin();
    // std::reverse_iterator<std::vector<int>::iterator> rev_it = vv.rbegin();
    // std::cout<<"{ std::vector } capacity == "<<vv.capacity()<<std::endl;
    // std::cout<<"{ reverse iterator } == ";
    // for (int i = 0;rev_it!= vv.rend();i++)
    //   {
    //     std::cout<<*rev_it<<" ";
    //     rev_it++;
    //   }
    //   std::cout<<std::endl;
    //       std::cout<<"{ ft::vector } capacity == "<<vvclone.capacity()<<std::endl;
    // std::cout<<"{ reverse iterator(ft) } == ";
    // for (int i = 0;rev_itclone!= vvclone.rend();i++)
    //   {
    //     std::cout<<*rev_itclone<<" ";
    //     rev_itclone++;
    //   }
    //   std::cout<<std::endl;

    // while (1);
    //end test
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