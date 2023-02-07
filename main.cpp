#include "./vector.hpp"
#include <iostream>

//std
#include <vector>
#include <iterator>

#include <unistd.h>
 #include <sys/time.h>
time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

int main()
{
   /*------------------ std::vectors ---------------------*/
        std::vector<std::string> v;
        /*------------------ std::vectors ---------------------*/
        ft::vector<std::string> ft_v;
        /*
         * Strings to store the results
         */
        std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
        /*
         * Var to store the size and the capacity
         */
        size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
        size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        ft::vector<std::string>::iterator ft_it;
        // test for an empty vector
        v.push_back("hello");
        ft_v.push_back("hello");
        ft_it = ft_v.begin();
        ft_it->length();

        z1 = v.size();
        c1 = v.capacity();
        ft_z1 = ft_v.size();
        ft_c1 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s1 += v.at(i);

        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s1 += ft_v.at(i);
        /*---------------------------------------------*/
        // test for a vector with capacity >= size + the new element
        v.reserve(30);
        ft_v.reserve(30);
        v.push_back("string");
        ft_v.push_back("string");
        v.push_back("string");
        ft_v.push_back("string");

        z2 = v.size();
        c2 = v.capacity();
        ft_z2 = ft_v.size();
        ft_c2 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s2 += v.at(i);

        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s2 += ft_v.at(i);
        /*---------------------------------------------------------*/
        // test for a vector with capactiy < size + the new element
        for (size_t i = 0; i < 100; ++i)
            v.push_back("string");

        for (size_t i = 0; i < 100; ++i)
            ft_v.push_back("string");

        z3 = v.size();
        c3 = v.capacity();
        ft_z3 = ft_v.size();
        ft_c3 = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            s3 += v.at(i);

        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_s3 += ft_v.at(i);
   /*------------------ std::vectors ---------------------*/
        // std::vector<std::string> v1(10, "string2");          // fill constructor
        // std::vector<std::string> v2;                         // empty constructor
        // std::vector<std::string> v3(v1.begin(), v1.end());   // range constructor with normal iterators
        // std::vector<std::string> v4(v3);                     // copy constructor
        // std::vector<std::string> v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        // /*-----------------------------------------------------*/
        // /*------------------ ft::vectors ---------------------*/
        // ft::vector<std::string> ft_v1(10, "string2");
        // ft::vector<std::string> ft_v2;
        // ft::vector<std::string> ft_v3(ft_v1.begin(), ft_v1.end());
        // ft::vector<std::string> ft_v4(ft_v1);
        // ft::vector<std::string> ft_v5(ft_v1.rbegin(), ft_v1.rend());
        // std::cout<<v1.capacity()<<" | "<<ft_v1.capacity()<<std::endl;
        // std::cout<<v2.capacity()<<" | "<<ft_v2.capacity()<<std::endl;
        // std::cout<<v3.capacity()<<" | "<<ft_v3.capacity()<<std::endl;
        // std::cout<<v4.capacity()<<" | "<<ft_v4.capacity()<<std::endl;
        // std::cout<<v5.capacity()<<" | "<<ft_v5.capacity()<<std::endl;
        // ¬std::cout<<"front (std::vector) == "<<v2.front()<<" | size (ft::vector) == "<<ft_v2.size()<<std::endl;

  //testing range constructor
  /*---------------------------------- time limit test --------------------------------------------*/
  //       {
  //           time_t start, end, diff;
  //           //debug
  //           // std::cerr<<"{main} before seg"<<std::endl;
  //           //end debug
  //           std::vector<std::string> v(1e5, "range constructor test");
  //           //debug
  //           // std::cerr<<"{main} after"<<std::endl;
  //           //end debug
  //           start = get_time();
  //           std::vector<std::string> v1(v.begin(), v.end());
  //           end = get_time();
  //           diff = end - start;
  //           diff = (diff) ? (diff * 3) : 3;

  //           ualarm(diff * 1e3, 0);
  //           ft::vector<std::string> my_v(v.begin(), v.end());
  //           ualarm(0, 0);
  //       }
  //       // /*-----------------------------------------------------------------------------------------------*/
  //       /*--------------- fill std::vector with 10 strings and ft::vector with range of iterators ------*/
  //       std::vector<std::string> v(10, "range constructor test");
  //       ft::vector<std::string> my_v(10, "range constructor test");
  //       //debug
  //       // std::cerr<<"{ main } before segfault"<<std::endl;
  //       //end debug

  //       ft::vector<std::string> my_v1(my_v.begin(), my_v.end()); // this one is to check if the range works with ft::vector
  //       // /*----------------------------------------------------------------------------------------------*/
  //       // /*--------------- declare tow strings to store the results ------*/
  //       std::string res, my_res, my_res1;
  //       // /*--------------------------------------------------------*/
  //       for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
  //           res += *it;

  //       for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
  //           my_res += *it;

  //       for (ft::vector<std::string>::iterator it = my_v1.begin(); it != my_v1.end(); ++it) // fill my_res1 from ft::vector
  //           my_res1 += *it;
  //       if(res == my_res && my_res == my_res1)
  //                 std::cout<<"yes they are equal"<<std::endl;
  //       else  
  //         std::cout<<"no they are not equal"<<std::endl;
  //       while(1)
  //       ;

  // //testing fill constructor
  // /*----------------------------------------------------------------------------------------------*/
   /*---------------------------------- time limit test --------------------------------------------*/
  //       {
  //           time_t start, end, diff;

  //           start = get_time();
  //           std::vector<std::string> v(1e5, "fill constructor test");
  //           end = get_time();
  //           diff = end - start;
  //           diff = (diff) ? (diff * 3) : 3;

  //           ualarm(diff * 1e3, 0);
  //           ft::vector<std::string> my_v(1e5, "fill constructor test");
  //           ualarm(0, 0);
  //       }
  //       /*--------------- fill tow vectors with a 10 strings ------*/
  //       ft::vector<std::string> my_v(10, "fill constructor test");
  //       std::vector<std::string> v(10, "fill constructor test");
  //       /*---------------------------------------------------------*/
  //       /*--------------- declare tow strings to store the results ------*/
  //       std::string res, my_res;
  //       /*---------------------------------------------------------*/
  //       for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
  //           res += *it;

  //       for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
  //           my_res += *it;
  //       if(res == my_res)
  //         std::cout<<"yes they are equal"<<std::endl;
  //       else  
  //         std::cout<<"no they are not equal"<<std::endl;
  // // const int size = 5;
	// // ft::vector<std::string> vct(1e5,"hello world!");
  // ft::vector<std::string> vctclone(vct.begin(),vct.end());
  // std::cout<<"size = "<<vctclone.size()<<" capacity = "<<vctclone.capacity()<<std::endl;
  // for (ft::vector<std::string>::iterator iter =vctclone.begin();iter!=vctclone.end();iter++)
  // {
  //   std::cout<<"vct[i] == "<<*iter<<" ";
  // }
  // std::cout<<std::endl;
  while (1)
  ;
  
  //debug iterators
    // std::cout << "{ main debug }The distance is: " << std::distance(vct.begin(),vct.end()) << std::endl;
  //end debug
	// ft::vector<int>::iterator ittt = vct.begin();
	// ft::vector<int>::const_iterator ite = vct.begin();

	// for (int i = 0; i < size; ++i)
	// 	ittt[i] = i;

	// *ite = 42; // < -- error
  // return 0;
  //end test
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

//     ft::vector<int> test(10,7);
//     ft::vector<int> test2(test.begin(),test.end());
//     std::cout<<"{ ft::vector } range == "; 
//     for (int i = 0;i<10;i++){
//         std::cout<<" "<<test2[i];
//     }
//     std::cout<<std::endl;
//     std::vector<int> testclone(10,7);
//     std::vector<int> test2clone(testclone.begin(),testclone.end());
//     std::cout<<"{ std::vector } range == "; 
//     for (int i = 0;i<10;i++){
//         std::cout<<" "<<test2clone[i];
//     }
//     std::cout<<std::endl;

//     //test end 
//     while(1);
//     ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';
//     while(1);
//     ft::vector<int> vect;
//     std::vector<int> v;
//     ft::vector<int> a(10,55);
//     ft::vector<int> b(vect);
//     ft::vector<int> c;
//     c = b;

//     v.reserve(1000);
//     vect.reserve(1000);
//     std::cerr<< "max_size 1== "<<vect.max_size()<<"  |  "<<"max_size 2== "<<v.max_size()<<std::endl;
//     std::cout<<"capacity 1 == "<<vect.capacity()<<"  |  "<<"capacity 2 == "<<v.capacity()<<std::endl;
//     std::cout<<"is_empty 1 == "<<vect.empty()<<"  |  "<<"is_empty 2 == "<<v.empty()<<std::endl;
//     vect.push_back(1);
//     vect.push_back(2);
//     vect.push_back(1);
//     vect.push_back(2);
//     vect.push_back(13);
//     vect.push_back(12);
//     vect.push_back(15);
//     vect.push_back(13);
//     vect.push_back(122);
//     vect.push_back(1);
//     vect.push_back(21);
//     vect.push_back(1234);
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(13);
//     v.push_back(12);
//     v.push_back(15);
//     v.push_back(13);
//     v.push_back(122);
//     v.push_back(1);
//     v.push_back(21);
//     v.push_back(1234);

//     std::cout<<"is_empty 1 == "<<vect.empty()<<"  |  is_empty 2 == "<<v.empty() <<std::endl;

//     vect.resize(100,9);
//     v.resize(100,9);
//     std::cout<<"size 1 == "<<vect.size()<<"  |  size 2 == "<<v.size()<<std::endl;
//     std::cout<<"capacity 1 == "<<vect.capacity()<<"  |  capacity 2 == "<<v.size()<<std::endl;
//     for(int i =0;i<(int)vect.size();i++)
//     {
//         std::cout<<"vect["<<i<<"] == "<<vect[i]<< "  |  "<<"v["<<i<<"] == "<<v[i]<<std::endl;
//     }
//     ft::vector<int>::const_iterator it = vect.cbegin();
//     std::vector<int>::const_iterator it2= v.cbegin();
//     for (int i =0;it<vect.cend();it++)
//     {
//         std::cout<<"{using iterator} "<<"vect["<<i<<"] == "<<*it<< "  |  "<<"v["<<i<<"] == "<<*it2<<std::endl;
//         i++;
//         it2++;
//     }
//     try{
//         vect.at(100);
//     }
//     catch(std::exception& e)
//     {
//         std::cerr<<"Exception =="<<e.what()<<std::endl;
//     }
//     while(1);
}