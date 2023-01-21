#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H
#include "iterator.hpp"
#include "iterator_traits.hpp"
namespace ft
{
    template <class Iterator>
    class reverse_iterator : public ft::iterator<
    typename ft::iterator_traits<Iterator>::iterator_category,
    typename ft::iterator_traits<Iterator>::value_type,
    typename ft::iterator_traits<Iterator>::difference_type,
    typename ft::iterator_traits<Iterator>::pointer,
    typename ft::iterator_traits<Iterator>::reference >
    {
        protected:
        Iterator current;
        public:
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::reference       reference;
        typedef typename ft::iterator_traits<Iterator>::pointer         pointer;

        reverse_iterator():current(Iterator()){}
        explicit reverse_iterator(Iterator X):current(X){}
        template <class U>
        reverse_iterator(const reverse_iterator<U>& u):current(u.current){}        
    }
}

#endif