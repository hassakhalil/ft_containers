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
namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector {
    public:
    //--------------------------------------------------types:
    typedef T                                                value_type;
    typedef typename Allocator::reference                    reference;
    typedef typename Allocator::const_reference              const_reference;
    typedef ft::random_it<value_type>                        iterator; 
    typedef ft::random_it<value_type>                        const_iterator; 
    typedef size_t                                           size_type; 
    typedef ptrdiff_t                                        difference_type;
    typedef Allocator                                        allocator_type;
    typedef typename Allocator::pointer                      pointer;
    typedef typename Allocator::const_pointer                const_pointer;
    typedef ft::reverse_iterator<iterator>                   reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>             const_reverse_iterator;

    //--------------------------------------------------construct/copy/destroy:
    explicit vector(const allocator_type& = allocator_type()){
        //debug
        std::cerr<<"{ default constructor }"<<std::endl;
        // end debug
        this->data = allocator_type().allocate(2);
        this->capacity_= 2;
        this->size_ = 0;
    }
    explicit vector(size_type n, const value_type& value = T(),const allocator_type& = allocator_type()){
        //debug
        std::cerr<<"hello  from { fill constructor }"<<std::endl;
        //end debug
        this->data =allocator_type().allocate(n);
        this->capacity_ = n;
        this->size_ = 0;
        for (int i = 0;i<(int)n;i++){
            this->push_back(value);
        }
    }
    // template <class InputIterator>
    // vector(InputIterator first, InputIterator last,const allocator_type& = allocator_type()){
    //     //debug
    //     std::cerr<<"hello form { range constructor }"<<std::endl;
    //     //end debug
    //     this->capacity_ = last - first;
    //     this->data = allocator_type().allocate(this->capacity_);
    //     this->size_ = 0;
    //     iterator tmpf=first;
    //     iterator tmpl=last;

    //     while(tmpf!=tmpl){
    //         this->push_back(*tmpf);
    //         tmpf++;
    //     }
    // }
    vector(const ft::vector<T,allocator_type >& x){
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
    ft::vector<T,allocator_type>& operator=(const ft::vector<T,allocator_type>& x){
        //debug
        std::cerr<<"hello from { copy assignment operator }"<<std::endl;
        //end debug
            for(int i=0;i<(int)this->size_;i++){
                allocator_type().destroy(this->data +i);
            }
            this->size_ = 0;
            allocator_type().deallocate(this->data,this->capacity_);
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
    const_iterator          cbegin() const {return const_iterator(this->data);}
    iterator                end(){return iterator(this->data + this->size_);}
    const_iterator          cend() const {return const_iterator(this->data + this->size_);}
    reverse_iterator        rbegin(){return reverse_iterator(this->end());}
    const_reverse_iterator  crbegin() const{return const_reverse_iterator(this->end());}
    reverse_iterator        rend(){return reverse_iterator(this->begin());}
    const_reverse_iterator  crend() const{return const_reverse_iterator(this->begin());}

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
    iterator insert(iterator position, const T& x){
        value_type* ptr;
        value_type new_capacity = this->capacity_;
        if (this->size_+1>this->capacity_)
            new_capacity = this->capacity_ + this->capacity_/2;
        value_type* new_data = this->get_allocator().allocate(new_capacity);
        int j = 0;
        for (int i = 0;i<=(int)this->size_;i++)
        {
            if (this->data[i] == *position)
            {
                this->get_allocator().construct(new_data + i, x);
                ptr  = &(*(this->begin()+i));
                j=1;
                this->get_allocator().construct(new_data +i+j,this->data[i]);
            }
            else
                this->get_allocator().construct(new_data + i+j, this->data[i]);
            this->get_allocator().destroy(this->data+i);
        }
        this->get_allocator().deallocate(this->data, this->capacity_);
        this->size_ += 1;
        this->data = new_data;
        this->capacity_ = new_capacity;
        return iterator(ptr);
    }
    void     insert(iterator position, size_type n, const T& x){
        value_type new_capacity = this->capacity_;
        if (this->size_+n>this->capacity_)
            new_capacity = this->capacity_ + n +this->capacity_/2;
        value_type* new_data = this->get_allocator().allocate(new_capacity);
        int j = 0;
        for (int i = 0;i<=(int)this->size_;i++)
        {
            if (this->data[i] == *position)
            {
                for(int l=0;l<(int)n;l++){
                    this->get_allocator().construct(new_data + i+l, x);
                }
                j=n;
                this->get_allocator().construct(new_data +i+j,this->data[i]);
            }
            else
                this->get_allocator().construct(new_data + i+j, this->data[i]);
            this->get_allocator().destroy(this->data+i);
        }
        this->get_allocator().deallocate(this->data, this->capacity_);
        this->size_ += n;
        this->data = new_data;
        this->capacity_ = new_capacity;
    }
    // template <class InputIterator>
    // void     insert(iterator position,InputIterator first, InputIterator last);
    iterator erase(iterator position){
        //remove value at position
        //overwrite values by next valeus
        value_type* ptr = nullptr;
        for (int i=0;i<(int)this->size_;i++){
            if (this->data[i] == *position)
            {
                ptr = this->data +i+1;
                for (int j = i;j<(int)this->size_-1;j++)
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
        //if there is no elements left-->adjust size
        //overwrite values starting from first element
        value_type* ptr = nullptr;
        value_type n=0;
        for (int i=0;i<(int)this->size_;i++){
            if (this->data[i] == *first)
            {
                for (int j=i;j<(int)this->size_;j++){
                    if (this->data[j] == *last)
                    {
                       //overwrite values starting from first element
                       ptr = &this->data[j];
                        n = j-i;
                        for (int k=j;k<(int)this->size_;k++)
                        {
                            this->data[i] = this->data[k];
                            i++;
                        }
                        //debug
                        std::cerr<<"{ debug } : (first - last) == "<<first-last<<std::endl;
                        //end debug
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
            difference_type tmp2;
            difference_type tmp3;
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
template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){
    return equal(x.begin(),x.end(),y.begin());
}
template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){
    if (!(x == y))
        return true;
    return false;
}
template <class T, class Alloc>  
bool operator<  (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){
    return lexicographical_compare(x.begin(),x.end(),y.begin(),y.end());
}
template <class T, class Alloc>  
bool operator<= (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){
    if (x == y || x < y)
        return true;
    return false;
}
template <class T, class Alloc>
bool operator>  (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){
    if (!(x < y) && x != y)
        return true;
    return false;
}
template <class T, class Alloc>  
bool operator>= (const ft::vector<T,Alloc>& x, const ft::vector<T,Alloc>& y){
    if (x > y || x == y)
        return true;
    return false;

}

// //-----------------------------------------------------------swap algorithm:
template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y){
    x.swap(y);
}

}
#endif
