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
    explicit vector(const allocator_type& all = allocator_type()):data(0),capacity_(0),size_(0),alloc_(all){}
    explicit vector(size_type n, const value_type& value = T(),const allocator_type& all= allocator_type()):capacity_(0),size_(0),alloc_(all){
        
            if (n > this->max_size())
            {
                //debug
                std::cout<<" size == "<<this->size_<<"capacity == "<<this->capacity_<<std::endl;
                std::cout<<"exception----------------------------"<<std::endl;
                //end debug
                throw std::bad_alloc();
            }
            this->data = this->alloc_.allocate(n);
            this->capacity_=n;
            this->size_=n;
            for (size_type i=0;i<n;i++)
                this->alloc_.construct(this->data +i, value);
            // catch(const std::exception& e){
            //     //debug
            //     std::cout << "exception: " << e.what() << std::endl;
            //     std::cout<<" size == "<<this->size_<<"capacity == "<<this->capacity_<<std::endl;
            //     //end debug
            //     this->clear();
            //     if (this->capacity_)
            //         this->alloc_.deallocate(this->data,this->capacity_);
            //     throw std::bad_alloc();}
    }
    template <class InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type& all= allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0):capacity_(0),size_(0),alloc_(all){
        InputIterator tmp = first;
        size_type n = std::distance(tmp,last);
        if (n > this->max_size())
            throw std::bad_alloc();
        this->data = this->alloc_.allocate(n);
        this->capacity_=n;
        this->size_=n;
        size_type i=0;
        for (;first!=last;first++)
            this->alloc_.construct(this->data + i++,*first);
        // }
        // else
        //     throw std::bad_alloc();
    }
    vector(const ft::vector<T,allocator_type >& x):capacity_(x.capacity()),size_(x.size()),alloc_(x.get_allocator()){
        this->data = this->alloc_.allocate(this->size_);
        for (size_type i= 0;i<this->size_;i++)
            this->alloc_.construct(this->data + i,x[i]);
    }
    ~vector(){
        while(this->size_)
            this->alloc_.destroy(this->data + --this->size_);
        if (this->capacity_)
            this->alloc_.deallocate(this->data,this->capacity_);
    }
    ft::vector<T,allocator_type>& operator=(const ft::vector<T,allocator_type>& x){
        this->clear();
        if (this->capacity_)
            this->alloc_.deallocate(this->data, this->capacity_);
        this->capacity_ = x.capacity();
        this->size_ = x.size();
        this->data = this->alloc_.allocate(this->capacity_);
        for (size_type i=0;i<this->size_;i++)
            this->alloc_.construct(this->data + i, x[i]);
        return *this;
    }
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
        this->clear();
        InputIterator tmp = first;
        size_type n =std::distance(tmp,last);
        if (n > this->max_size())
        {
            if (this->capacity_)
                this->alloc_.deallocate(this->data,this->capacity_);
            throw std::bad_alloc();
        }
        if (n <= this->max_size()){
            if (n >this->capacity_)
                this->reserve(n);
            for (;first!=last;first++)
                this->alloc_.construct(this->data +this->size_++,*first);
        }
        else
            throw std::bad_alloc();
    }
    void assign(size_type n, const T& u){
        this->clear();
        if (n >this->max_size()){
            if (this->capacity_)
                this->alloc_.deallocate(this->data,this->capacity_);
            throw std::bad_alloc();
        }
        if (n >this->capacity_)
            this->reserve(n);
        for (size_type i=0;i<n;i++)
            this->alloc_.construct(this->data+this->size_++,u);
        // }
        // else
        //     throw std::bad_alloc();
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
    size_type   max_size() const{ return this->alloc_.max_size(); }
    void        resize(size_type n, value_type val = value_type()){
        if (n < this->size_)
        {
            while (n != this->size_)
                this->pop_back();
        }           
        else if (n > this->size_)
        {
            if (n > this->max_size())
                throw std::bad_alloc();
            while (n != this->size_)
                this->push_back(val);
        }
    }
    size_type   capacity() const{ return this->capacity_; }
    bool        empty() const{ return !this->size_; }
    void        reserve(size_type n){
        if (n > this->max_size())
            throw std::length_error("length_error");
        if (n > this->capacity_ )
        {
            value_type* new_data = this->alloc_.allocate(n);
            for (size_type i = 0; i < this->size_ ; i++){
                this->alloc_.construct(new_data + i, this->data[i]);
                this->alloc_.destroy(this->data + i);
            }
            if (this->capacity_)
                this->alloc_.deallocate(this->data,this->capacity_);
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
            {
                if (2*this->capacity_ > this->max_size())
                    throw std::bad_alloc();
                this->reserve(2*this->capacity_);
            }
            else
                this->reserve(1);
        }
        this->alloc_.construct(this->data + this->size_++, x);
    }
    void     pop_back(){
        if (this->size_)
            this->alloc_.destroy(this->data+ --this->size_);
    }
    iterator insert(iterator position, const T& x){
        size_type m = abs(position -  this->begin());
        if (this->size_ + 1 >this->capacity_)
                this->reserve(2*this->capacity_);
        this->insert(this->data+m,1,x);
        return iterator(this->data+m);
    }
    void     insert(iterator position, size_type n, const T& x){
        if (this->capacity_ + n<= this->max_size()){
            size_type d = abs(position - this->begin());
            if (this->size_ + n >this->capacity_)
                this->reserve(this->capacity_ + n);
            size_type l=this->size_;
            for(size_type h = this->size_ - d;h>0;h--){
                this->alloc_.construct(this->data + l +n-1,this->data[l-1]);
                l--;}
            l = d;
            for (size_type i = 0;i<n;i++){
                this->alloc_.destroy(this->data +l+i);
                this->alloc_.construct(this->data +l+i,x);
            }
            this->size_+=n;
        }
        else
            throw std::bad_alloc();
    }
    template <class InputIterator>
    void     insert(iterator position,InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
        size_type d = abs(position - this->begin());
        ft::vector<T> tmp(first,last);
        size_type n = tmp.size();
        if(this->capacity_ + n<= this->max_size()){
            if (this->size_ + n >this->capacity_)
            {
                size_type i=this->capacity_;
                while (i <n +this->size_)
                    i *=2; 
                this->reserve(i);
            }
            size_type l=this->size_;
            for(size_type h = this->size_ - d;h>0;h--){
                this->alloc_.construct(this->data + l +n-1,this->data[l-1]);
                l--;}
            l = d;
            for (size_type i = 0;i<n;i++){
                this->alloc_.destroy(this->data +l+i);
                this->alloc_.construct(this->data +l+i,tmp[i]);
            }
            this->size_+=n;
        }
        else
            throw std::bad_alloc();
    }
    iterator erase(iterator position){
        if (this->size_){
            if (position == this->end()-1)
                this->pop_back();
            size_type bef = std::distance(this->begin(),position);
            for (size_type i = bef;i<this->size_-1;i++){
                this->alloc_.destroy(this->data + i);
                this->alloc_.construct(this->data +i,this->data[i + 1]);
            }
            --this->size_;
            return this->begin() +bef;
        }
        return position;
    }

    iterator erase(iterator first, iterator last){
        size_type m = std::distance(this->begin(),first);
        size_type n = m;
        for(iterator it = last; it != this->end();it++){
            this->alloc_.destroy(this->data + m);
            this->alloc_.construct(this->data + m++,*it);}
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
        while (this->size_)
            this->alloc_.destroy(this->data + --this->size_);
    }

    // void shrink_to_fit(){
    //     if (this->capacity_ != this->size_){
    //         value_type *new_data=0;
    //         if (this->size_)
    //             new_data = this->alloc_.allocate(this->size_);
    //         for (size_type i=0;i<this->size_;i++){
    //             this->alloc_.construct(new_data +i,data[i]);
    //             this->alloc_.destroy(this->data + i);
    //         }
    //         if (this->capacity_)
    //             this->alloc_.deallocate(this->data, this->capacity_);
    //         this->data = new_data;
    //         this->capacity_ = this->size_;
    //     }
    // }
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
