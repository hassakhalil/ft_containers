#ifndef ITERATOR_H
#define ITERATOR_H
#include <cstddef>
namespace ft
{

//----------------iterator_tags
struct random_access_iterator_tag{};
struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag{};
struct bidirectional_iterator_tag{};

//--------------------------iterator
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