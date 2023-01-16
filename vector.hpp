#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <memory>
#include <exception>
#include <iostream>
#include "iterator.hpp"

namespace ft
{
    template <typename T>
    class random_it : public ft::iterator<std::random_access_iterator_tag,T>{
            private:
            T* ptr;
            public:
            random_it():ptr(0){}
            random_it(T* p) :ptr(p){}
            random_it(const random_it& other):ptr(other.ptr){}
            random_it& operator=(const random_it& other){
                this->ptr=other.ptr;
                return this;
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
            void operator+=(ptrdiff_t n) const {
                 this->ptr = &this->ptr[n];
            }
            void operator-=(ptrdiff_t n) const {
                this->ptr =  &this->ptr[-n];
            }
    };

template <typename T, typename Allocator = std::allocator<T> >
class vector {
    public:
    //---------------------------------------------------iterator:

    //--------------------------------------------------types:
    typedef T                                                value_type;
    typedef typename Allocator::reference                    reference;
    typedef typename Allocator::const_reference              const_reference;
    typedef random_it<value_type>                            iterator; 
    typedef random_it<value_type>                            const_iterator; 
    typedef size_t                                           size_type; 
    typedef ptrdiff_t                                        difference_type;
    typedef std::allocator<value_type>                       allocator_type;
    typedef typename Allocator::pointer                      pointer;
    typedef typename Allocator::const_pointer                const_pointer;
    typedef std::reverse_iterator<iterator>                  reverse_iterator;
    typedef std::reverse_iterator<const_iterator>            const_reverse_iterator;

    //--------------------------------------------------construct/copy/destroy:
    explicit vector(const allocator_type& = allocator_type()){
        //debug
        std::cerr<<"hello from { default constructor }"<<std::endl;
        // end debug
        data = alloc_.allocate(1);
        capacity_= 2;
        size_ = 0;
    }
    // explicit vector(size_type n, const T& value = T(),const allocator_type& = allocator_type());
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last,const allocator_type& = allocator_type());
    // vector(const vector<T,allocator_type >& x);
    ~vector(){
        clear();
    }
    // vector<T,allocator_type>& operator=(const vector<T,allocator_type>& x){

    // }
    // template <class InputIterator>
    // void assign(InputIterator first, InputIterator last);
    // void assign(size_type n, const T& u);
    allocator_type get_allocator() const{
        return allocator_type();
    }

    //---------------------------------------------------iterators:
    iterator                begin(){return iterator(this->data);}
    const_iterator          begin() const {return const_iterator(this->data);}
    iterator                end(){return iterator(this->data + this->size_);}
    const_iterator          end() const {return const_iterator(this->data + this->size_);}
    // reverse_iterator        rbegin();
    // const_reverse_iterator  rbegin() const;
    // reverse_iterator        rend();
    // const_reverse_iterator  rend() const;

    //---------------------------------------------------capacity:
    size_type   size() const{ return this->size_; }
    size_type   max_size() const{ return this->alloc_.max_size(); }
    void        resize(size_type n, value_type val = value_type()){
        if (n < this->size_)
        {
            while (this->size_ > n)
            {
                alloc_.destroy(this->data + this->size_);
                this->size_--;
            }
        }
        else if (n > this->size_)
        {
            while (this->size_ < n)
            {
                this->push_back(val);
                this->size_++;
            }
        }
    }
    size_type   capacity() const{ return this->capacity_; }
    bool        empty() const{ return !this->size_; }
    void        reserve(size_type n){
        if (n > this->capacity_)
        {
            value_type* new_data = get_allocator().allocate(n);
            for (int i=0; i<(int)n ; i++){
               alloc_.construct(new_data + i, this->data[i]);
                alloc_.destroy(this->data + i);
            }
            get_allocator().deallocate(this->data,this->capacity_);
            this->data = new_data;
            this->capacity_ = n;
        }
    }

    //----------------------------------------------------element access:
    reference       operator[](size_type n){
        return this->data[n];
    }
    const_reference operator[](size_type n) const{
        return this->data[n];
    }
    const_reference at(size_type n) const{
        if (n>=this->size())
            throw std::out_of_range("Error: index is out of range");
        return this->data[n];
    }
    reference       at(size_type n){
        if (n>=this->size())
            throw std::out_of_range("Error: index is out of range");
        return this->data[n];
    }
    reference       front(){
        return this->data[0];
    }
    const_reference front() const{
            return this->data[0];
    }
    reference       back(){
            return this->data[this->size_];
    }
    const_reference back() const{
            return this->data[this->size_];
    }

    //----------------------------------------------------modifiers:
    void     push_back(const value_type& x){
        if (this->size_ ==this->capacity_)
        {
            reserve(this->capacity_ + this->capacity_/2);
            this->capacity_ += this->capacity_/2;
        }
        alloc_.construct(this->data + this->size_, x);
        this->size_++;
    }
    // void     pop_back();
    // iterator insert(iterator position, const T& x);
    // void     insert(iterator position, size_type n, const T& x);
    // template <class InputIterator>
    // void     insert(iterator position,InputIterator first, InputIterator last);
    // iterator erase(iterator position);
    // iterator erase(iterator first, iterator last);
    // template <typename T, allocator_type>
    // void     swap(vector<T,allocator_type >&);
    void     clear(){
        for (int i = 0; i<(int)this->size_ ;i++){
            alloc_.destroy(this->data + i);
        }
        get_allocator().deallocate(this->data, this->capacity_);
    }
    //-----------------------------------------------------private members:
    private:
    value_type* data;
    size_type capacity_;
    size_type size_;
    allocator_type alloc_;
};
//----------------------------------------------------------non-member operators:
// template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

// //-----------------------------------------------------------swap algorithm:
// template <class T, class Allocator>
// void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);

}
#endif
