namespace ft
{
#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <memory>

//define iterator type [1]
template<
    class T
>
class iterator{
    //implement std::vector iterator (random access)
    //++/+=/--/-=/*/[]/->(for class objects)/+/-/==/!=/</<=/>/>=
    T *value;
    public:
    iterator();
    iterator(const iterator& i);
    iterator& operator =(const iterator& i);
    ~iterator();
    void setValue(T& val);
    iterator& operator++();
    iterator operator-- ();
    bool operator==(iterator other) const;
    bool operator!=(iterator other) const;
    T operator*() const ;
};


template<typename T, typename Allocator = std::allocator<T> >
class vector{
    protected:
    T* array;
    public:
    //--------------------------------Member types------------------------[2]
    typedef typename Allocator::reference reference;
    typedef typename Allocator::const_reference const_reference;
    typedef iterator iterator;
    typedef const iterator const_iterator;
    typedef std::size_t size_type;
    typedef 
    //-------------------------------Member functions--------------------[3]
    vector(){}
    //----constructors
    //----destructors
    //----(operator=)
    //----(assign)
    //----get_allocator
    //-------------------------------Element access
    //----at
    //----operator[]
    //----front
    //----back
    //----data
    //-------------------------------Iterators
    //----begin/cbegin
    //----end/cend
    //----rbegin/crbegin
    //----rend/crend
    //--------------------------------Capacity
    //----empty
    //----size
    //----max_size
    //----reserve
    //----capacity
    //----shrink_to_fit
    //--------------------------------Modifiers
    //----clear
    //----insert
    //----emplace
    //----erase
    //----push_back
    //----emplace_back
    //----pop_back
    //----resize
    //----swap
    //--------------------------------Non-member functions

    //----operator==
    //----operator!=
    //----operator<
    //----operator<=
    //----operator>
    //----operator>=
    //----operator<=>

    //----std::swap(std::vector)

    //----erase
    //----erase_if
};


#endif
}