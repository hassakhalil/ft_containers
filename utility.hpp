#ifndef UTILITY_H
#define UTILITY_H
#include "random_it.hpp"
#include "iterator.hpp"
namespace ft{

     //---------------------------is_integral
    template <typename T > struct is_integral{static const bool value=false;};
    template <> struct is_integral<bool>{static const bool value=true;};
    template <> struct is_integral<char>{static const bool value=true;};
    template <> struct is_integral<char16_t>{static const bool value=true;};
    template <> struct is_integral<char32_t>{static const bool value=true;};
    template <> struct is_integral<wchar_t>{static const bool value=true;};
    template <> struct is_integral<signed char>{static const bool value=true;};
    template <> struct is_integral<short int>{static const bool value=true;};
    template <> struct is_integral<int>{static const bool value=true;};
    template <> struct is_integral<long int>{static const bool value=true;};
    template <> struct is_integral<long long int>{static const bool value=true;};
    template <> struct is_integral<unsigned char>{static const bool value=true;};
    template <> struct is_integral<unsigned short int>{static const bool value=true;};
    template <> struct is_integral<unsigned int>{static const bool value=true;};
    template <> struct is_integral<unsigned long int>{static const bool value=true;};
    template <> struct is_integral<unsigned long long int>{static const bool value=true;};
     //-------------------------enable_if
    template <bool Cond, class T = void >
    struct enable_if{};

    template <class T>
    struct enable_if<true,T>
    {
        typedef T type;
    };
    //-------------------------------------std::equal
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            first1++;
            first2++;
        }
        return true;
    }
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred){
        while (first1 != last1)
        {
            if (!pred(*first1,*first2))
                return false;
            first1++;
            first2++;
        }
        return true;
    }
    //--------------------------------------------std::lexicographical_compare--------------------------------------------
    template <class InputIterator1,class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2){
       while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1) return false;
            else if (*first1<*first2) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,InputIterator2 first2, InputIterator2 last2,Compare comp){
       while (first1!=last1)
        {
            if (first2==last2 || !comp(*first2,*first1)) return false;
            else if (comp(*first1,*first2)) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }
    //----------------------------------------------------iterator_traits
     template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
        typedef typename Iterator::iterator_category iterator_category;
    };
    template <class T>
    struct  iterator_traits<T*>
    {
        typedef ptrdiff_t                      difference_type;
        typedef T                              value_type;
        typedef T*                             pointer;
        typedef T&                             reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };
    template <class T>
    struct iterator_traits<const T*>
    {
        typedef  ptrdiff_t                      difference_type;
        typedef  T                              value_type;
        typedef  const T*                       pointer;
        typedef  const T&                       reference;
        typedef  ft::random_access_iterator_tag iterator_category;
    };
    template <class T>
    struct iterator_traits<ft::iterator<ft::random_access_iterator_tag,T> >
    {
        typedef ptrdiff_t   difference_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag,T>::value_type        value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag,T>::pointer           pointer;
        typedef typename ft::iterator<ft::random_access_iterator_tag,T>::reference         reference;
        typedef typename ft::iterator<std::random_access_iterator_tag,T>::iterator_category iterator_category;
    };
}

#endif