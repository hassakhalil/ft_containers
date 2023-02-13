#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <cmath>
#include <memory>
#include <exception>
#include <iostream>
#include "iterator.hpp"
#include "random_it.hpp"
#include "reverse_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
namespace ft
{
template <class T, class Allocator = std::allocator<T> >
class vector {
    public:
    //--------------------------------------------------types:
    typedef T                                                value_type;
    typedef typename Allocator::reference                    reference;
    typedef typename Allocator::const_reference              const_reference;
    typedef ft::random_it<T>                                 iterator; 
    typedef ft::random_it<const T>                           const_iterator; 
    typedef size_t                                           size_type; 
    typedef ptrdiff_t                                        difference_type;
    typedef Allocator                                        allocator_type;
    typedef typename Allocator::pointer                      pointer;
    typedef typename Allocator::const_pointer                const_pointer;
    typedef ft::reverse_iterator<iterator>                   reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>             const_reverse_iterator;
    //--------------------------------------------------construct/copy/destroy:
    explicit vector(const allocator_type& = allocator_type()){
        this->capacity_=0;
        this->size_=0;
    }
    explicit vector(size_type n, const value_type& value = T(),const allocator_type& = allocator_type()){
        this->size_=n;
        this->capacity_=n;
        this->data = this->get_allocator().allocate(n);
        for (size_type i=0;i<n;i++){
            this->get_allocator().construct(this->data+i,value);
        }
    }
    template <class InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
        size_type n=std::distance(first,last);
        this->capacity_ = n;
        this->size_ = n;
        this->data = this->get_allocator().allocate(n);
        for (size_type i = 0;i < n;i++){
            this->get_allocator().construct(this->data + i, *first);
            first++;
        }
    }
    vector(const ft::vector<T,allocator_type >& x){
        this->size_ = x.size_;
        this->capacity_=x.capacity_;
        this->data = x.get_allocator().allocate(x.capacity_);
        for (size_type i=0;i<x.size_;i++){
            this->get_allocator().construct(this->data+i,x[i]);
        }
    }
    ~vector(){
        this->clear();
        if (this->capacity_)
            this->get_allocator().deallocate(this->data,this->capacity_);
    }
    ft::vector<T,allocator_type>& operator=(const ft::vector<T,allocator_type>& x){
            if (this->capacity_){
                this->clear();
                this->get_allocator().deallocate(this->data,this->capacity_);
            }
            this->data = this->get_allocator().allocate(x.capacity_);
            this->capacity_ = x.capacity_;
            this->size_= x.size_;
            for (size_type i=0;i<x.size_;i++){
                this->get_allocator().construct(this->data+i,x[i]);
            }
            return *this;
    }
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
        size_type n = std::distance(first,last);
        this->clear();
        this->reserve(n);
        for (;first!=last;first++)
            this->get_allocator().construct(this->data + this->size_++,*first);
    }
    void assign(size_type n, const T& u){
        this->clear();
        this->reserve(n);
        for (size_type i=0;i<n;i++)
            this->get_allocator().construct(this->data + this->size_++,u);
    }
    allocator_type get_allocator() const{return this->alloc_;}
    //---------------------------------------------------iterators:
    iterator                begin()const{return iterator(this->data);}
    const_iterator          cbegin() const{return const_iterator(this->data);}
    iterator                end()const{return iterator(this->data + this->size_);}
    const_iterator          cend() const{return const_iterator(this->data + this->size_);}
    reverse_iterator        rbegin()const{return reverse_iterator(this->end());}
    const_reverse_iterator  crbegin() const{return const_reverse_iterator(this->end());}
    reverse_iterator        rend()const{return reverse_iterator(this->begin());}
    const_reverse_iterator  crend() const{return const_reverse_iterator(this->begin());}
    //---------------------------------------------------capacity:
    size_type   size() const{ return this->size_; }
    size_type   max_size() const{ return this->get_allocator().max_size(); }
    void        resize(size_type n, value_type val = value_type()){
        if (n < this->size_)
        {
            while (n != this->size_)
                this->pop_back();
        }           
        else if (n > this->size_)
        {
            while (n != this->size_)
                this->push_back(val);
        }
    }
    size_type   capacity() const{ return this->capacity_; }
    bool        empty() const{ return !this->size_; }
    void        reserve(size_type n){
        if (n > this->capacity_)
        {
            value_type* new_data = this->get_allocator().allocate(n);
            for (size_type i = 0; i < this->size_ ; i++){
                this->get_allocator().construct(new_data + i, this->data[i]);
                this->get_allocator().destroy(this->data + i);
            }
            if (this->capacity_)
                this->get_allocator().deallocate(this->data,this->capacity_);
            this->capacity_=n;
            this->data = new_data;
        }
    }
    //----------------------------------------------------element access:
    reference       operator[](size_type n){return  *(this->begin() + n);}
    const_reference operator[](size_type n) const{return *(this->begin() + n);}
    const_reference at(size_type n) const{
        if (n>=this->size_)
            throw std::out_of_range("Error: index is out of range");
        return *(this->begin() + n) ;
    }
    reference       at(size_type n){
        if (n>=this->size_)
            throw std::out_of_range("Error: index is out of range");
        return *(this->begin() + n);
    }
    reference       front(){return *this->begin();}
    const_reference front() const{return *this->begin();}
    reference       back(){return *--this->end();}
    const_reference back() const{return *--this->end();}
    //----------------------------------------------------modifiers:
    void     push_back(const value_type& x){
        if (this->size_ == this->capacity_)
        {
            if(this->capacity_)
                this->reserve(2*this->capacity_);
            else
                this->reserve(1);
        }
        this->get_allocator().construct(this->data + this->size_++, x);
    }
    void     pop_back(){
        if (this->size_)
            this->get_allocator().destroy(this->data+ --this->size_);
    }
    iterator insert(iterator position, const T& x){
        
        if (position == this->end() || (position == this->begin() && this->size_==0))
        {
            this->push_back(x);
            if (position == this->end())
                return this->end() - 1;
            else
                return this->begin();
        }
        size_type n = std::distance(this->begin(),position);
        this->insert(position, 1, x);
        return this->begin()+n;
    }
    void     insert(iterator position, size_type n, const T& x){
        if (n == 0)
            return ;
        if (position == this->end() || (position == this->begin() && this->size_==0))
        {
            for (size_type i= 0;i<n;i++)
                this->push_back(x);
            return ;
        }
        size_type new_capacity = this->capacity_;
        size_type new_size = 0;
        if (this->size_ + n > this->capacity_)
            new_capacity = 2*this->capacity_ + n;
        value_type* new_data = this->get_allocator().allocate(new_capacity);
        for (size_type i=0;i<this->size_;i++){
            if (this->data[i] != *position)
                this->get_allocator().construct(new_data + new_size++,this->data[i]);
            else{
                for(size_type j=0;j<n;j++)
                    this->get_allocator().construct(new_data + new_size++,x);
                this->get_allocator().construct(new_data + new_size++,this->data[i]);
            }
            this->get_allocator().destroy(this->data + i);
            //debug
            // std::cerr<<"(ft::vector) i == "<<i<<std::endl;
            //end debug
        }
        if (this->capacity_)
            this->get_allocator().deallocate(this->data, this->capacity_);
        this->data = new_data;
        this->size_= new_size;
        this->capacity_ = new_capacity;
    }
    template <class InputIterator>
    void     insert(iterator position,InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
        if (last == first)
            return ;
        if (position == this->end() || (this->size_==0 && position == this->end()))
        {
            for (;first!=last;first++)
                this->push_back(*first);
            return ;
        }
        std::vector<T> tmp;
        for(;first!=last;first++)
            tmp.push_back(*first);

        size_type n =  tmp.size();
        size_type new_size=0;
        size_type new_capacity=this->capacity_;
        if (this->size_ + n > new_capacity)
            new_capacity = this->capacity_ + n;
        value_type* new_data = this->get_allocator().allocate(new_capacity);
        size_type i=0;
        for (iterator it=this->begin();it!=this->end();it++)
        {
            if (it != position)           
                this->get_allocator().construct(new_data + new_size++, *it);
            else
            {
                for ( typename std::vector<T>::iterator tmp_it =tmp.begin();tmp_it!=tmp.end();tmp_it++)
                {
                    this->get_allocator().construct(new_data + new_size++,*tmp_it);
                }
                this->get_allocator().construct(new_data + new_size++, *it);
            }
            this->get_allocator().destroy(this->data + i);
            i++;
        }
        if (this->capacity_)
            this->get_allocator().deallocate(this->data, this->capacity_);
        this->data = new_data;
        this->capacity_ = new_capacity;
        this->size_ = new_size;
    }
    iterator erase(iterator position){
        if (this->size_){
            if (position == this->end()-1)
                this->pop_back();
            size_type bef = std::distance(this->begin(),position);
            for (size_type i = bef;i<this->size_-1;i++){
                this->get_allocator().destroy(this->data + i);
                this->get_allocator().construct(this->data +i,this->data[i + 1]);
            }
            if (this->size_)
                --this->size_;
            return this->begin() +bef;
        }
        return position;
    }

    iterator erase(iterator first, iterator last){
        size_type m = std::distance(this->begin(),first);
        size_type n = m;
        for(iterator it = last; it != this->end();it++){
            this->get_allocator().destroy(this->data + m);
            this->get_allocator().construct(this->data + m,*it);
            ++m;
        }
        this->size_ = this->size_ - std::distance(first,last);
        return this->begin() + n;
    }
    void     swap(ft::vector<T,Allocator >& x){
            value_type*     tmp1 = x.data;
            size_type       tmp2 = x.size_;
            size_type       tmp3 = x.capacity_;
            x.data = this->data;
            x.size_ = this->size_;
            x.capacity_= this->capacity_;
            this->data = tmp1;
            this->size_ = tmp2;
            this->capacity_ = tmp3;
    }
    void     clear(){
        size_type i = 0;
        while (i < this->size_)
        {
            this->get_allocator().destroy(this->data + i);
            i++;
        }
        this->size_ = 0;
    }
    //-----------------------------------------------------private members:
    protected:
    value_type*                 data;
    size_type                   capacity_;
    size_type                   size_;
    allocator_type              alloc_;
};
//----------------------------------------------------------non-member operators:
template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){
    if (x.size() != y.size())
        return false;
    return ft::equal(x.begin(),x.end(),y.begin());
}
template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return !(x == y);}
template <class T, class Alloc>  
bool operator<  (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return ft::lexicographical_compare(x.begin(),x.end(),y.begin(),y.end());}
template <class T, class Alloc>  
bool operator<= (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return !(x > y);}
template <class T, class Alloc>
bool operator>  (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return ft::lexicographical_compare(y.begin(),y.end(),x.begin(),x.end());}
template <class T, class Alloc>  
bool operator>= (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return !(x < y);}
// //-----------------------------------------------------------swap algorithm:
template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y){x.swap(y);}

}
#endif
