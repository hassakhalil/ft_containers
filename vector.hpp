#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
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
    explicit vector(const allocator_type& = allocator_type()):capacity_(0),size_(0){}
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
        // this->capacity_ = 0;
        // this->size_=0;
        ptrdiff_t tmp = first - last;
        if (tmp<0)
            tmp *= -1;
        this->capacity_ = tmp;
        this->size_ = tmp;
        this->data = this->get_allocator().allocate(this->capacity_);
        for (size_type i=0;i<this->capacity_;i++){
            this->get_allocator().construct(this->data + i, *first);
            first++;
        }         
        // for(;first!=last;first++){
        //     this->push_back(*first);
        // }
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
        clear();
        if (this->capacity_)
            this->get_allocator().deallocate(this->data,this->capacity_);
    }
    ft::vector<T,allocator_type>& operator=(const ft::vector<T,allocator_type>& x){
            if (this->capacity_){
                this->clear();
                this->get_allocator().deallocate(this->data,this->capacity_);
                this->capacity_ = 0;
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
    void assign(InputIterator first, InputIterator last){
        this->erase(this->begin(),this->end());
        this->insert(this->begin(),first,last);
    }
    void assign(size_type n, const T& u){
        this->erase(this->begin(),this->end());
        this->insert(this->begin(),n,u);

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
            while (this->size_ > n)
                this->pop_back();
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
            this->capacity_=n;
            if (this->capacity_ ==0)
            {
                this->data = this->get_allocator().allocate(n);
                return ;
            }
            value_type* new_data = this->get_allocator().allocate(n);
            for (size_type i=0; i<this->size_ ; i++){
                this->get_allocator().construct(new_data + i, this->data[i]);
                this->get_allocator().destroy(this->data + i);
            }
            this->get_allocator().deallocate(this->data,this->capacity_);
            this->data = new_data;
        }
    }

    //----------------------------------------------------element access:
    reference       operator[](size_type n){return  *(this->begin() + n);}
    const_reference operator[](size_type n) const{return *(this->begin() + n);}
    const_reference at(size_type n) const{
        if (n>=this->size_)
            throw std::out_of_range("Error: index is out of range");
        return *(this->begin() + n);
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
        if (this->size_ ==this->capacity_)
            reserve(2*this->capacity_ + 1);
        this->get_allocator().construct(this->data + this->size_, x);
        this->size_++;
    }
    void     pop_back(){
        if (this->size_)
        {
            --this->size_;
            this->get_allocator().destroy(this->data+this->size_);
        }
    }
    iterator insert(iterator position, const T& x){
        this->insert(position,1,x);
        return position;
    }
    void     insert(iterator position, size_type n, const T& x){
        ft::vector<value_type> tmp(n,x);
        this->insert(position,tmp.begin(),tmp.end());
    }
    template <class InputIterator>
    void     insert(iterator position,InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
        ptrdiff_t n = last -first;
        if (n < 0)
            n *= -1;
        size_type new_capacity = this->size_ + n;
        value_type* new_data = this->get_allocator().allocate(new_capacity);
        int j=0;
        for (size_type i=0;i<this->size_;i++){
            if (this->data[i] != *position)
                this->get_allocator().construct(new_data + i+j,this->data[i]);
            else{
                while(first!=last){
                    this->get_allocator().construct(new_data +i+j,*first);
                    first++;
                    j++;
                }
                this->get_allocator().construct(new_data +i+j,this->data[i]);
                i++;
            }
        }
        this->clear();
        this->get_allocator().deallocate(this->data,this->capacity_);
        this->data = new_data;
        this->size_= new_capacity;
        this->capacity_ = this->size_;
    }
    iterator erase(iterator position){
        value_type* ptr = nullptr;
        for (size_type i=0;i<this->size_;i++){
            if (this->data[i] == *position)
            {
                ptr = this->data +i+1;
                for (size_type j = i;j<this->size_-1;j++)
                {
                    this->data[j] = this->data[j+1];
                }
                this->size_--;
                break;
            }
        }
        return iterator(ptr);
    }
    iterator erase(iterator first, iterator last){
        value_type* ptr = nullptr;
        size_type n = 0;
        for (size_type i=0;i<this->size_;i++){
            if (this->data[i] == *first)
            {
                for (size_type j=i;j<this->size_;j++){
                    if (this->data[j] == *last)
                    {
                       ptr = &this->data[j];
                        n = j-i;
                        for (size_type k=j;k<this->size_;k++)
                        {
                            this->data[i] = this->data[k];
                            i++;
                        }
                        this->size_ -= n;
                        break;
                    }
                }
                break;
            }
        }
        return iterator(ptr);
    }
    void     swap(ft::vector<T,Allocator >& x){
            value_type*     tmp1;
            size_type tmp2;
            size_type tmp3;
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
        for (size_type i = 0; i<this->size_ ;i++){
            this->get_allocator().destroy(this->data + i);
        }
        this->size_=0;
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
bool operator== (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return ft::equal(x.begin(),x.end(),y.begin());}
template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return (x == y)?false:true;}
template <class T, class Alloc>  
bool operator<  (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return ft::lexicographical_compare(x.begin(),x.end(),y.begin(),y.end());}
template <class T, class Alloc>  
bool operator<= (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return (x == y || x < y)?true:false;}
template <class T, class Alloc>
bool operator>  (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return (!(x < y) && x != y)?true:false;}
template <class T, class Alloc>  
bool operator>= (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){return (x > y || x == y)?true:false;}

// //-----------------------------------------------------------swap algorithm:
template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y){x.swap(y);}

}
#endif
