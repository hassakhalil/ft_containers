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
#define NAMESPACE std
int main()
{
  //   NAMESPACE::vector<int> vector(100,10);
  // std::vector<int> v;
	//   NAMESPACE::vector<int> tmp0(vector);
  //   NAMESPACE::vector<int> tmp(1000 *1, 4), tmp2(1000 *1, 5);
  //   tmp = tmp2;
  //   NAMESPACE::vector<int> tmp3(tmp);
  //   NAMESPACE::vector<int> tmp4(tmp.begin(), tmp.end());
  //   v.push_back(tmp4.size());
  //   v.push_back(tmp4.capacity());
  //   v.push_back(tmp[2]);
  //   v.push_back(tmp3[2]);
  //   v.push_back(tmp4[2]);
  //   try { NAMESPACE::vector<int> tmp5(-1, -1); }
  //   catch (std::exception &e) { v.push_back(1); }
  //   for (int i=0;i<(int)v.size();i++){
  //     std::cout<<"v["<<i<<"] == "<<v[i]<<std::endl;
  //   }
      std::vector<int> v(1000,12);
      ft::vector<int> _v(1000,12);
      std::cout<<"v.size == "<<v.size()<<" v.capacity == "<<v.capacity()<<" _v.size == "<<_v.size()<<" _v.capacity == "<<_v.capacity()<<std::endl;
      while(1);
        // std::vector<int> v;
        // std::vector<int> _v;

        // NAMESPACE::vector<int> _vector;
        // std::vector<int> vector;

        // vector.assign(1000,1);
        // _vector.assign(1000,1);
        // v.assign(273,123);
        // _v.assign(273,123);
        // // if (vector == _vector)
        // //     std::cerr<<"(main) vector == _vector"<<std::endl;
        // // else 
        // //     std::cerr<<"(main) vector != _vector"<<std::endl;

        // //debbug
        // std::cerr<<"(main) aNAMESPACEer assign"<<std::endl;
        // std::cerr<<"(main) size == "<<vector.size()<<std::endl;
        // //end debug
        // // vector.insert(vector.end()-50,4200,2);
        // // _vector.insert(_vector.end()-50,4200,2);
        // // std::cerr<<"(main) aNAMESPACEer insert"<<std::endl;

        // v.push_back(vector[212]);
        // v.push_back(vector.size());
        // v.push_back(vector.capacity());

        // _v.push_back(_vector[212]);
        // _v.push_back(_vector.size());
        // _v.push_back(_vector.capacity());
        // for (int i=0;i<(int)v.size();i++){
        //   std::cout<<"v["<<i<<"] == "<<v[i]<<" _v["<<i<<"] == "<<_v[i]<<std::endl;
        // }
        // while(1);
        // // v.push_back(v.size());

        // // // v.insert(v.end(),"last element inserted so far");
        // // std::cout<<"v.size() == "<<v.size()<<std::endl;
        // // std::cout<<"v.capacity() == "<<v.capacity()<<std::endl;
        // // // for (int i=0;i<(int)v.size();i++){
        // // //     std::cout<<"v["<<i<<"] == "<<v[i]<<std::endl;
        // // // }
        // // std::cout<<"last element == "<<v.back()<<std::endl;
        // // while(1);
        // // NAMESPACE::vector<std::string> vv;
        // // vv.insert(vv.begin(),v.begin(),v.end());
        // // std::cout<<"vv.size() == "<<vv.size()<<std::endl;
        // std::cout<<"vv.capacity() == "<<vv.capacity()<<std::endl;
        // for (int i=0;i<(int)vv.size();i++){
        //     std::cout<<"vv["<<i<<"] == "<<vv[i]<<std::endl;
        // }

//      /*
//          * strings to store the resutls
//          */
//         std::string str, NAMESPACE_str;
//         /*
//          * var to store the size and the capacity
//          */
//         NAMESPACE::vector<std::string>::size_type s, NAMESPACE_s;
//         NAMESPACE::vector<std::string>::size_type c, NAMESPACE_c;
//         NAMESPACE::vector<std::string>::iterator NAMESPACE_it;
//         std::vector<std::string>::iterator it;
//         /*
//          * bool to store the comparison
//          */
//         bool cond;

//         /*------------------------------- test 1: empty vector ----------------------------------------*/
//         // insert at the begin
//         {
//             //debug
//             std::cout<<"start of test 1"<<std::endl;
//             //end debug
//             std::vector<std::string> v;
//             NAMESPACE::vector<std::string> NAMESPACE_v;
//             it = v.insert(v.begin(), "hello");
//             //debug
//             std::cout<<"--test1 msg 1"<<std::endl;
//             //end debug
//             NAMESPACE_it = NAMESPACE_v.insert(NAMESPACE_v.begin(), "hello");
//             NAMESPACE_it->length();
//             //debug
//             std::cout<<"--test1 msg 2"<<std::endl;
//             //end debug

//             s = v.size();
//             NAMESPACE_s = NAMESPACE_v.size();
//             c = v.capacity();
//             NAMESPACE_c = NAMESPACE_v.capacity();
//                         //debug
//             std::cout<<"--test1 msg 3"<<std::endl;
//             //end debug

//             for (size_t i = 0; i < v.size(); ++i)
//                 str += v[i];
//             //debug
//             std::cout<<"--test1 msg 4"<<std::endl;
//             //end debug

//             for (size_t i = 0; i < NAMESPACE_v.size(); ++i)
//                 NAMESPACE_str += NAMESPACE_v[i];
//             cond = ((str == NAMESPACE_str) && (s == NAMESPACE_s) && (c == NAMESPACE_c) && (*NAMESPACE_it == *it));
//         }
//         // insert at the end
//         {
//                         //debug
//             std::cout<<"--test1 msg 5"<<std::endl;
//             //end debug

//             std::vector<std::string> v;
//             NAMESPACE::vector<std::string> NAMESPACE_v;

//             it = v.insert(v.end(), "hello");
//                         //debug
//             std::cout<<"--test1 msg 6"<<std::endl;
//             //end debug

//             NAMESPACE_it = NAMESPACE_v.insert(NAMESPACE_v.end(), "hello");
//             NAMESPACE_it->length();

//             str.clear();
//             NAMESPACE_str.clear();
//             //debug
//             std::cout<<"--test1 msg 7"<<std::endl;
//             //end debug

//             s = v.size();
//             NAMESPACE_s = NAMESPACE_v.size();
//             c = v.capacity();
//             NAMESPACE_c = NAMESPACE_v.capacity();
//             for (size_t i = 0; i < v.size(); ++i)
//                 str += v[i];
//             for (size_t i = 0; i < NAMESPACE_v.size(); ++i)
//                 NAMESPACE_str += NAMESPACE_v[i];
//             cond = (cond && (str == NAMESPACE_str) && (s == NAMESPACE_s) && (c == NAMESPACE_c) && (*it == *NAMESPACE_it));
//         }
//         //debug
//         std::cout<<"start of test 2"<<std::endl;
//         //end debug
//         /*---------------------------------------------------------------------------------------------------*/
//         /*------------------------------- test 2: the vector capacity >= size + the new element ----------------------------------------*/
//         {
//             std::vector<std::string> v(20, "string");
//             NAMESPACE::vector<std::string> NAMESPACE_v(20, "string");
//             NAMESPACE::vector<std::string>::iterator valid_it;

//             //debug
//             std::cout<<"test 2 msg 1"<<std::endl;
//             //end debug 
//             v.reserve(30);
//             NAMESPACE_v.reserve(30);
//             //debug
//             std::cout<<"test 2 msg 2"<<std::endl;
//             //end debug 

//             valid_it = NAMESPACE_v.begin();
//                         //debug
//             std::cout<<"test 2 msg 3"<<std::endl;
//             //end debug 

//             it = v.insert(v.begin() + 10, "hello");
//                     //debug
//             std::cout<<"test 2 msg 4"<<std::endl;
//             //end debug 

//             NAMESPACE_it = NAMESPACE_v.insert(NAMESPACE_v.begin() + 10, "hello");
//             NAMESPACE_it->length();
//             //debug
//             std::cout<<"test 2 msg 5"<<std::endl;
//             //end debug 

//             str.clear();
//             NAMESPACE_str.clear();
//             s = v.size();
//             NAMESPACE_s = NAMESPACE_v.size();
//             c = v.capacity();
//             NAMESPACE_c = NAMESPACE_v.capacity();
//                         //debug
//             std::cout<<"test 2 msg 6"<<std::endl;
//             //end debug 

//             for (size_t i = 0; i < v.size(); ++i)
//             {
//                 //debug
//                 std::cout<<"i == "<<i<<" size =="<<std::endl;
//                 //end debug
//                 str += v[i];
//             }
//                             //debug
//             std::cout<<"test 2 msg 7"<<std::endl;
//             //end debug 

//             for (size_t i = 0; i < NAMESPACE_v.size(); ++i)
//                 NAMESPACE_str += NAMESPACE_v[i];
//             cond = (cond && (str == NAMESPACE_str) && (s == NAMESPACE_s) && (c == NAMESPACE_c) && (*it == *NAMESPACE_it) && (&(*valid_it) == &(*NAMESPACE_v.begin())));
//         }
//         /*---------------------------------------------------------------------------------------------------*/
//         /*------------------------------- test 3: the vector capacity < size + the new element ----------------------------------------*/
//         {
//             //debug
//             std::cout<<" start of test 3"<<std::endl;
//             //end debug 
//             std::vector<std::string> v(20, "string");
//             NAMESPACE::vector<std::string> NAMESPACE_v(20, "string");

//             it = v.insert(v.begin() + 10, "hello");
//             NAMESPACE_it = NAMESPACE_v.insert(NAMESPACE_v.begin() + 10, "hello");
//             NAMESPACE_it->length();

//             str.clear();
//             NAMESPACE_str.clear();
//             s = v.size();
//             NAMESPACE_s = NAMESPACE_v.size();
//             c = v.capacity();
//             NAMESPACE_c = NAMESPACE_v.capacity();
//             for (size_t i = 0; i < v.size(); ++i)
//                 str += v[i];
//             for (size_t i = 0; i < NAMESPACE_v.size(); ++i)
//                 NAMESPACE_str += NAMESPACE_v[i];
//             cond = (cond && (str == NAMESPACE_str) && (s == NAMESPACE_s) && (c == NAMESPACE_c) && (*it == *NAMESPACE_it));
//         }
// //    ¬¬¬¬¬¬¬¬¬::vector<std::string> v;
// //         /*------------------ std::vectors ---------------------*/
// //         NAMESPACE::vector<std::string> NAMESPACE_v;
// //         /*
// //          * Strings to store the results
// //          */
//         std::string s1, s2, s3, NAMESPACE_s1, NAMESPACE_s2, NAMESPACE_s3;
//         /*
//          * Var to store the size and the capacity
//          */
//         size_t z1, z2, z3, NAMESPACE_z1, NAMESPACE_z2, NAMESPACE_z3;
//         size_t c1, c2, c3, NAMESPACE_c1, NAMESPACE_c2, NAMESPACE_c3;
//         NAMESPACE::vector<std::string>::iterator NAMESPACE_it;
//         // test for an empty vector
//         v.push_back("hello");
//         NAMESPACE_v.push_back("hello");
//         NAMESPACE_it = NAMESPACE_v.begin();
//         NAMESPACE_it->length();

//         z1 = v.size();
//         c1 = v.capacity();
//         NAMESPACE_z1 = NAMESPACE_v.size();
//         NAMESPACE_c1 = NAMESPACE_v.capacity();
//         for (size_t i = 0; i < v.size(); ++i)
//             s1 += v.at(i);

//         for (size_t i = 0; i < NAMESPACE_v.size(); ++i)
//             NAMESPACE_s1 += NAMESPACE_v.at(i);
//         /*---------------------------------------------*/
//         // test for a vector with capacity >= size + the new element
//         v.reserve(30);
//         NAMESPACE_v.reserve(30);
//         v.push_back("string");
//         NAMESPACE_v.push_back("string");
//         v.push_back("string");
//         NAMESPACE_v.push_back("string");

//         z2 = v.size();
//         c2 = v.capacity();
//         NAMESPACE_z2 = NAMESPACE_v.size();
//         NAMESPACE_c2 = NAMESPACE_v.capacity();
//         for (size_t i = 0; i < v.size(); ++i)
//             s2 += v.at(i);

//         for (size_t i = 0; i < NAMESPACE_v.size(); ++i)
//             NAMESPACE_s2 += NAMESPACE_v.at(i);
//         /*---------------------------------------------------------*/
//         // test for a vector with capactiy < size + the new element
//         for (size_t i = 0; i < 100; ++i)
//             v.push_back("string");

//         for (size_t i = 0; i < 100; ++i)
//             NAMESPACE_v.push_back("string");

//         z3 = v.size();
//         c3 = v.capacity();
//         NAMESPACE_z3 = NAMESPACE_v.size();
//         NAMESPACE_c3 = NAMESPACE_v.capacity();
//         for (size_t i = 0; i < v.size(); ++i)
//             s3 += v.at(i);

//         for (size_t i = 0; i < NAMESPACE_v.size(); ++i)
//             NAMESPACE_s3 += NAMESPACE_v.at(i);
//    /*------------------ std::vectors ---------------------*/
        // std::vector<std::string> v1(10, "string2");          // fill constructor
        // std::vector<std::string> v2;                         // empty constructor
        // std::vector<std::string> v3(v1.begin(), v1.end());   // range constructor with normal iterators
        // std::vector<std::string> v4(v3);                     // copy constructor
        // std::vector<std::string> v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        // /*-----------------------------------------------------*/
        // /*------------------ NAMESPACE::vectors ---------------------*/
        // NAMESPACE::vector<std::string> NAMESPACE_v1(10, "string2");
        // NAMESPACE::vector<std::string> NAMESPACE_v2;
        // NAMESPACE::vector<std::string> NAMESPACE_v3(NAMESPACE_v1.begin(), NAMESPACE_v1.end());
        // NAMESPACE::vector<std::string> NAMESPACE_v4(NAMESPACE_v1);
        // NAMESPACE::vector<std::string> NAMESPACE_v5(NAMESPACE_v1.rbegin(), NAMESPACE_v1.rend());
        // std::cout<<v1.capacity()<<" | "<<NAMESPACE_v1.capacity()<<std::endl;
        // std::cout<<v2.capacity()<<" | "<<NAMESPACE_v2.capacity()<<std::endl;
        // std::cout<<v3.capacity()<<" | "<<NAMESPACE_v3.capacity()<<std::endl;
        // std::cout<<v4.capacity()<<" | "<<NAMESPACE_v4.capacity()<<std::endl;
        // std::cout<<v5.capacity()<<" | "<<NAMESPACE_v5.capacity()<<std::endl;
        // ¬std::cout<<"front (std::vector) == "<<v2.front()<<" | size (NAMESPACE::vector) == "<<NAMESPACE_v2.size()<<std::endl;

  //testing range constructor
  /*---------------------------------- time limit test --------------------------------------------*/
  //       {
  //           time_t start, end, diff;
  //           //debug
  //           // std::cerr<<"{main} before seg"<<std::endl;
  //           //end debug
  //           std::vector<std::string> v(1e5, "range constructor test");
  //           //debug
  //           // std::cerr<<"{main} aNAMESPACEer"<<std::endl;
  //           //end debug
  //           start = get_time();
  //           std::vector<std::string> v1(v.begin(), v.end());
  //           end = get_time();
  //           diff = end - start;
  //           diff = (diff) ? (diff * 3) : 3;

  //           ualarm(diff * 1e3, 0);
  //           NAMESPACE::vector<std::string> my_v(v.begin(), v.end());
  //           ualarm(0, 0);
  //       }
  //       // /*-----------------------------------------------------------------------------------------------*/
  //       /*--------------- fill std::vector with 10 strings and NAMESPACE::vector with range of iterators ------*/
  //       std::vector<std::string> v(10, "range constructor test");
  //       NAMESPACE::vector<std::string> my_v(10, "range constructor test");
  //       //debug
  //       // std::cerr<<"{ main } before segfault"<<std::endl;
  //       //end debug

  //       NAMESPACE::vector<std::string> my_v1(my_v.begin(), my_v.end()); // this one is to check if the range works with NAMESPACE::vector
  //       // /*----------------------------------------------------------------------------------------------*/
  //       // /*--------------- declare tow strings to store the results ------*/
  //       std::string res, my_res, my_res1;
  //       // /*--------------------------------------------------------*/
  //       for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
  //           res += *it;

  //       for (NAMESPACE::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from NAMESPACE::vector
  //           my_res += *it;

  //       for (NAMESPACE::vector<std::string>::iterator it = my_v1.begin(); it != my_v1.end(); ++it) // fill my_res1 from NAMESPACE::vector
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
  //           NAMESPACE::vector<std::string> my_v(1e5, "fill constructor test");
  //           ualarm(0, 0);
  //       }
  //       /*--------------- fill tow vectors with a 10 strings ------*/
  //       NAMESPACE::vector<std::string> my_v(10, "fill constructor test");
  //       std::vector<std::string> v(10, "fill constructor test");
  //       /*---------------------------------------------------------*/
  //       /*--------------- declare tow strings to store the results ------*/
  //       std::string res, my_res;
  //       /*---------------------------------------------------------*/
  //       for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
  //           res += *it;

  //       for (NAMESPACE::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from NAMESPACE::vector
  //           my_res += *it;
  //       if(res == my_res)
  //         std::cout<<"yes they are equal"<<std::endl;
  //       else  
  //         std::cout<<"no they are not equal"<<std::endl;
  // // const int size = 5;
	// // NAMESPACE::vector<std::string> vct(1e5,"hello world!");
  // NAMESPACE::vector<std::string> vctclone(vct.begin(),vct.end());
  // std::cout<<"size = "<<vctclone.size()<<" capacity = "<<vctclone.capacity()<<std::endl;
  // for (NAMESPACE::vector<std::string>::iterator iter =vctclone.begin();iter!=vctclone.end();iter++)
  // {
  //   std::cout<<"vct[i] == "<<*iter<<" ";
  // }
  // std::cout<<std::endl;
//   while (1)
//   ;
  
  //debug iterators
    // std::cout << "{ main debug }The distance is: " << std::distance(vct.begin(),vct.end()) << std::endl;
  //end debug
	// NAMESPACE::vector<int>::iterator ittt = vct.begin();
	// NAMESPACE::vector<int>::const_iterator ite = vct.begin();

	// for (int i = 0; i < size; ++i)
	// 	ittt[i] = i;

	// *ite = 42; // < -- error
  // return 0;
  //end test
  //test insert
  //testing reverse_iterator
    // std::vector<int> vv;
    // std::cout<<"vv.capacity_ == "<<vv.capacity()<<std::endl;
    // NAMESPACE::vector<int>  vvclone;
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
    // NAMESPACE::reverse_iterator<NAMESPACE::vector<int>::iterator> rev_itclone = vvclone.rbegin();
    // std::reverse_iterator<std::vector<int>::iterator> rev_it = vv.rbegin();
    // std::cout<<"{ std::vector } capacity == "<<vv.capacity()<<std::endl;
    // std::cout<<"{ reverse iterator } == ";
    // for (int i = 0;rev_it!= vv.rend();i++)
    //   {
    //     std::cout<<*rev_it<<" ";
    //     rev_it++;
    //   }
    //   std::cout<<std::endl;
    //       std::cout<<"{ NAMESPACE::vector } capacity == "<<vvclone.capacity()<<std::endl;
    // std::cout<<"{ reverse iterator(NAMESPACE) } == ";
    // for (int i = 0;rev_itclone!= vvclone.rend();i++)
    //   {
    //     std::cout<<*rev_itclone<<" ";
    //     rev_itclone++;
    //   }
    //   std::cout<<std::endl;

    // while (1);
    //end test
    //test range constructor

//     NAMESPACE::vector<int> test(10,7);
//     NAMESPACE::vector<int> test2(test.begin(),test.end());
//     std::cout<<"{ NAMESPACE::vector } range == "; 
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
//     NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
//   NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200

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
//     NAMESPACE::vector<int> vect;
//     std::vector<int> v;
//     NAMESPACE::vector<int> a(10,55);
//     NAMESPACE::vector<int> b(vect);
//     NAMESPACE::vector<int> c;
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
//     NAMESPACE::vector<int>::const_iterator it = vect.cbegin();
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