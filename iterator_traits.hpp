#ifndef ITERATOR_TRAITS_H
#define ITERATOR_TRAITS_H

#include "random_it.hpp"
namespace ft
{
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