#ifndef RANDOM_H
#define RANDOM_H
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include <cstddef>

namespace ft
{

    template <typename T>
    class random_it : public ft::iterator<ft::random_access_iterator_tag,T>{
            protected:
            T* ptr;
            public:
            typedef typename ft::iterator_traits<ft::iterator<ft::random_access_iterator_tag,T> >::difference_type    difference_type;
            typedef typename ft::iterator_traits<ft::iterator<ft::random_access_iterator_tag,T> >::value_type         value_type;
            typedef typename ft::iterator_traits<ft::iterator<ft::random_access_iterator_tag,T> >::pointer            pointer;
            typedef typename ft::iterator_traits<ft::iterator<ft::random_access_iterator_tag,T> >::reference          reference;
            typedef typename ft::iterator_traits<ft::iterator<ft::random_access_iterator_tag,T> >::iterator_category  iterator_category;
            T* base() const {return this->ptr;}
            random_it():ptr(nullptr){}
            random_it(T* p) :ptr(p){}
            template <typename U>
            random_it(const random_it<U>& other):ptr(other.base()){}
            random_it& operator=(const random_it& other){
                this->ptr=other.base();
                return *this;
            }
            ~random_it(){}
            random_it& operator++() {
                ++ptr;
                return *this;
            }
            random_it operator++(int) {
                random_it temp(*this);
                operator++();
                return temp;
            }
            random_it& operator--() {
                --ptr;
                return *this;
            }
            random_it operator--(int) {
                random_it temp(*this);
                operator--();
                return temp;
            }
            random_it operator+(ptrdiff_t n) const {
                return random_it(ptr + n);
            }
            random_it operator-(ptrdiff_t n) const {
                return random_it(ptr - n);
            }
            ptrdiff_t operator-(const random_it& other) const {
                return ptr - other.ptr;
            }
            T& operator*() const {
                return *ptr;
            }
            T* operator->() const {
                return ptr;
            }
            bool operator==(const random_it& other) const {
                return ptr == other.ptr;
            }
            bool operator!=(const random_it& other) const {
                return !operator==(other);
            }
            bool operator<(const random_it& other) const {
                return ptr < other.ptr;
            }
            bool operator>(const random_it& other) const {
                return other < *this;
            }
            bool operator<=(const random_it& other) const {
                return !(other < *this);
            }
            bool operator>=(const random_it& other) const {
                return !(*this < other);
            }
            T& operator[](ptrdiff_t n) const {
                return ptr[n];
            }
            void operator+=(ptrdiff_t n){
                 this->ptr = &this->ptr[n];
            }
            void operator-=(ptrdiff_t n){
                this->ptr =  &this->ptr[-n];
            }
    };
}
#endif