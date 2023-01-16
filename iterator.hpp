#ifndef ITERATOR_H
#define ITERATOR_H
#include <cstddef>
namespace ft
{

template<typename Category,typename T,typename Distance=ptrdiff_t,typename Pointer =T*,typename Reference =T&>
struct iterator{
    public:
    typedef T           value_type;
    typedef Distance    difference_type;
    typedef Pointer     pointer;
    typedef Reference   reference;
    typedef Category    iterator_category;
};
}
#endif