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
            this->assign(n,value);
    }
    template <class InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type& all= allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0):capacity_(0),size_(0),alloc_(all){
        this->assign(first,last);
    }
    vector(const ft::vector<T,allocator_type >& x):capacity_(0),size_(0),alloc_(x.get_allocator()){
        this->reserve(x.size());
        this->assign(x.begin(),x.end());
    }
    ~vector(){
        this->clear();
        if (this->capacity_)
            this->alloc_.deallocate(this->data,this->capacity_);
    }
    ft::vector<T,allocator_type>& operator=(const ft::vector<T,allocator_type>& x){
        this->reserve(x.size());
        this->assign(x.begin(),x.end());
        return *this;
    }
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
        InputIterator tmp = first;
        //  InputIterator it_test=first;
        size_type n =std::distance(tmp,last);
        //test if the range is valid
        // pointer ptr_test = this->alloc_.allocate(n);
        // size_type i=0;
        // while(it_test!=last){
        //     try{
        //         this->alloc_.construct(ptr_test +i,*it_test++);
        //     }
        //     catch(...){
        //         //debug
        //         std::cout<<"(vector::assign::range) exception caught"<<std::endl;
        //         //end debug
        //         while(i){
        //             this->alloc_.destroy(ptr_test +i);
        //             i--;
        //         }
        //         this->alloc_.deallocate(ptr_test,n);
        //         throw std::exception();
        //     }
        //     i++;
        // }
        // while(i){
        //     this->alloc_.destroy(ptr_test + --i);
        // }
        // this->alloc_.deallocate(ptr_test,n);
        //end test
        this->reserve(n);
        this->clear();
        for (;first!=last;first++){
            this->alloc_.construct(this->data +this->size_,*first);
            this->size_++;   
        }
    }
    void assign(size_type n, const T& u){
        this->reserve(n);
        this->clear();
        for (size_type i=0;i<n;i++){
            this->alloc_.construct(this->data+this->size_,u);
            this->size_++;}
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
            if (n + this->size_> this->capacity_)
                this->reserve(n);
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
            pointer new_data = this->alloc_.allocate(n);
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
            (this->capacity_)?this->reserve(2*this->capacity_):this->reserve(1);
        this->alloc_.construct(this->data + this->size_, x);
        this->size_++;
    }
    void     pop_back(){
        if (this->size_)
            this->alloc_.destroy(this->data+ --this->size_);
    }
    iterator insert(iterator position, const T& x){
        size_type m = position -  this->begin();
        this->insert(position,1,x);
        return iterator(this->data+m);
    }
    void     insert(iterator position, size_type n, const T& x){
        size_type d = position - this->begin();
        if (n == 1)
        {
            if (this->size_ ==this->capacity_)
            {
                (this->capacity_)?this->reserve(2*this->capacity_):this->reserve(n);
            }
        }
        else if (this->size_ + n >this->capacity_)
        {
            if (n > this->size_)
                this->reserve(this->capacity_ + n);
            else{
                size_type i=0;
                (this->capacity_)?i=this->capacity_:i=n;
                while (i <n +this->size_)
                    i *=2;
                this->reserve(i);
            }
        }
        size_type l=this->size_;
        for(size_type h = this->size_ - d;h>0;h--){
            this->alloc_.construct(this->data + l +n-1,this->data[l-1]);
            l--;}
        l = d;
        for (size_type i = 0;i<n;i++){
            this->alloc_.construct(this->data +l+i,x);
            this->size_++;
        }
    }
    template <class InputIterator>
    void     insert(iterator position,InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
        size_type d = position - this->begin();
        ft::vector<T> tmp(first,last);
        size_type n = tmp.size();
        if (this->size_ + n >this->capacity_)
        {
            if (n > this->size_)
                this->reserve(this->capacity_ + n);
            else{
                size_type i=0;
                (this->capacity_)?i=this->capacity_:i=n;
                while (i <n +this->size_)
                    i *=2;
                this->reserve(i);
            }
        }
        size_type l=this->size_;
        for(size_type h = this->size_ - d;h>0;h--){
            this->alloc_.construct(this->data + l +n-1,this->data[l-1]);
            l--;}
        l = d;
        for (size_type i = 0;i<n;i++){
            this->alloc_.construct(this->data +l+i,tmp[i]);
            this->size_++;
        }
    }
    iterator erase(iterator position){
        size_type bef = position - this->begin();
        for (size_type i = bef;i<this->size_-1;i++){
            this->alloc_.construct(this->data +i,this->data[i + 1]);
        }
        this->resize(this->size_ - 1);
        return this->begin() + bef;
    }

    iterator erase(iterator first, iterator last){
        size_type m = first - this->begin();
        size_type n = m;
        for(iterator it = last; it != this->end();it++){
            this->alloc_.construct(this->data + m++,*it);
            }
        this->resize(this->size_ - std::distance(first,last));
        return this->begin() + n;
    }
    void     swap(ft::vector<T,Allocator >& x){
            pointer     tmp1 = x.data;
            size_type       tmp2 = x.size_;
            size_type       tmp3 = x.capacity_;
            x.data =     this->data;
            x.size_ =    this->size_;
            x.capacity_= this->capacity_;
            this->data =      tmp1;
            this->size_ =     tmp2;
            this->capacity_ = tmp3;
    }
    void     clear(){
        while (this->size_)
            this->alloc_.destroy(this->data + --this->size_);
    }
    //-----------------------------------------------------private members:
    protected:
    pointer                     data;
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
