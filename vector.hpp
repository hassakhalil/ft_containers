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
        std::cerr<<"{ default constructor }"<<std::endl;
        // end debug
        this->data = this->get_allocator().allocate(2);
        this->capacity_= 2;
        this->size_ = 0;
    }
    explicit vector(size_type n, const T& value = T(),const allocator_type& = allocator_type()){
        //debug
        std::cerr<<"hello  from { constructor }"<<std::endl;
        //end debug
        this->data = this->get_allocator().allocate(n);
        this->capacity_ = n;
        this->size_ = 0;
        for (int i = 0;i<(int)n;i++){
            this->push_back(value);
        }
    }
    // xtemplate <class InputIterator>
    // vector(InputIterator first, InputIterator last,const allocator_type& = allocator_type()){

    // }
    vector(const vector<T,allocator_type >& x){
        //debug
        std::cerr<<"hello  form { copy constructor }"<<std::endl;
        //end debug
        this->data = this->get_allocator().allocate(x.capacity_);
        this->capacity_ = x.capacity_;
        this->size_ = 0;
        for (int i = 0;i<(int)x.size_;i++){
                this->push_back(x.data[i]);
        }
    }
    ~vector(){
        clear();
    }
    vector<T,allocator_type>& operator=(const vector<T,allocator_type>& x){
        //debug
        std::cerr<<"hello from { copy assignment operator }"<<std::endl;
        //end debug
            for(int i=0;i<(int)this->size_;i++){
                this->get_allocator().destroy(this->data +i);
            }
            this->size_ = 0;
            this->get_allocator().deallocate(this->data,this->capacity_);
            this->data = this->get_allocator().allocate(x.capacity_);
            this->capacity_=x.capacity_;
            for(int i=0;i<(int)x.size_;i++){
                this->push_back(x.data[i]);
            }
            return *this;
    }
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
    size_type   max_size() const{ return this->get_allocator().max_size(); }
    void        resize(size_type n, value_type val = value_type()){
        if (n < this->size_)
        {
            while (this->size_ > n)
            {
                this->get_allocator().destroy(this->data + this->size_);
                this->size_--;
            }
        }
        else if (n > this->size_)
        {
            while (this->size_ < n)
                this->push_back(val);
        }
    }
    size_type   capacity() const{ return this->capacity_; }
    bool        empty() const{ return !this->size_; }
    void        reserve(size_type n){
        if (n > this->capacity_)
        {
            value_type* new_data = this->get_allocator().allocate(n);
            for (int i=0; i<(int)n ; i++){
               this->get_allocator().construct(new_data + i, this->data[i]);
                this->get_allocator().destroy(this->data + i);
            }
            this->get_allocator().deallocate(this->data,this->capacity_);
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
        this->get_allocator().construct(this->data + this->size_, x);
        this->size_++;
    }
    void     pop_back(){
        if (this->size_)
        {
            this->get_allocator().destroy(this->data+this->size_);
            this->size_--;
        }
    }
    // iterator insert(iterator position, const T& x);
    // void     insert(iterator position, size_type n, const T& x);
    // template <class InputIterator>
    // void     insert(iterator position,InputIterator first, InputIterator last);
    // iterator erase(iterator position);
    // iterator erase(iterator first, iterator last);
    // template <typename T, typename Allocator>
    void     swap(ft::vector<T,Allocator >& x){
            T*     tmp1;
            size_t tmp2;
            size_t tmp3;
            tmp1 = x.data;
            tmp2 = x.size_;
            tmp3 = x.capacity_;
            x.data = this->data;
            x.size_ = this->size_;
            x.capacity_= this->capacity_;
            this->data = tmp1;
            this->size_ = tmp2;
            this->capacity_ = tmp3;
    }
    void     clear(){
        for (int i = 0; i<(int)this->size_ ;i++){
            this->get_allocator().destroy(this->data + i);
        }
       this-> get_allocator().deallocate(this->data, this->capacity_);
    }
    
    //-----------------------------------------------------private members:
    private:
    value_type*                 data;
    size_type                   capacity_;
    size_type                   size_;
    allocator_type              alloc_;
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
