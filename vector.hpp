#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <memory>
#include <exception>
namespace ft
{

template <typename T, typename std::allocator<T> >
class vector {
    public:
    //---------------------------------------------------iterator:
    class iterator {
            private:
            T* ptr;
            public:
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef std::random_access_iterator_tag iterator_category;

            iterator():ptr(0){}
            iterator(T* p) :ptr(p){}
            iterator(const iterator& other):ptr(other.ptr){}
            iterator& operator=(const iterator& other){
                this->ptr=other.ptr;
                return this;
            }
            ~iterator(){}
            iterator& operator++() {
                ++ptr;
                return *this;
            }
            iterator operator++(int) {
                iterator temp(*this);
                operator++();
                return temp;
            }
            iterator& operator--() {
                --ptr;
                return *this;
            }
            iterator operator--(int) {
                iterator temp(*this);
                operator--();
                return temp;
            }
            iterator operator+(difference_type n) const {
                return iterator(ptr + n);
            }
            iterator operator-(difference_type n) const {
                return iterator(ptr - n);
            }
            difference_type operator-(const iterator& other) const {
                return ptr - other.ptr;
            }
            reference operator*() const {
                return *ptr;
            }
            pointer operator->() const {
                return ptr;
            }
            bool operator==(const iterator& other) const {
                return ptr == other.ptr;
            }
            bool operator!=(const iterator& other) const {
                return !operator==(other);
            }
            bool operator<(const iterator& other) const {
                return ptr < other.ptr;
            }
            bool operator>(const iterator& other) const {
                return other < *this;
            }
            bool operator<=(const iterator& other) const {
                return !(other < *this);
            }
            bool operator>=(const iterator& other) const {
                return !(*this < other);
            }
            reference operator[](difference_type n) const {
                return ptr[n];
            }
            void operator+=(difference_type n) const {
                 this->ptr = &this->ptr[n];
            }
            void operator-=(difference_type n) const {
                this->ptr =  &this->ptr[-n];
            }
    };

    //--------------------------------------------------types:
    typedef typename allocator<T>::reference        reference;
    typedef typename allocator<T>::const_reference  const_reference;
    typedef iterator                                iterator; 
    typedef iterator                                const_iterator; 
    typedef size_t                                  size_type; 
    typedef ptrdiff_t                               difference_type;
    typedef T                                       value_type;
    typedef std::allocator<T>                       allocator_type;
    typedef typename allocator<T>::pointer          pointer;
    typedef typename allocator<T>::const_pointer    const_pointer;
    typedef std::reverse_iterator<iterator>         reverse_iterator;
    typedef std::reverse_iterator<const_iterator>   const_reverse_iterator;

    //--------------------------------------------------construct/copy/destroy:
    explicit vector(const allocator_type& = Allocator());
    explicit vector(size_type n, const T& value = T(),const allocator_type& = Allocator());
    template <class InputIterator>
    vector(InputIterator first, InputIterator last,const allocator_type& = Allocator());
    vector(const vector<T,allocator_type >& x);
    ~vector(){
        clear();
    }
    vector<T,allocator_type>& operator=(const vector<T,allocator_type>& x){

    }
    template <class InputIterator>
    void assign(InputIterator first, InputIterator last);
    void assign(size_type n, const T& u);
    allocator_type get_allocator() const{
        return this->alloc_;
    }

    //---------------------------------------------------iterators:
    iterator                begin(){return iterator(this->data);}
    const_iterator          begin() const {return const_iterator(this->data);}
    iterator                end(){return iterator(this->data + this->size_);}
    const_iterator          end() const {return const_iterator(this->data + this->size_);}
    reverse_iterator        rbegin();
    const_reverse_iterator  rbegin() const;
    reverse_iterator        rend();
    const_reverse_iterator  rend() const;

    //---------------------------------------------------capacity:
    size_type   size() const{
        return this->size_;
    }
    size_type   max_size() const;
    void        resize(size_type sz, T c = T());
    size_type   capacity() const{
        return this->capacity_;
    }
    bool        empty() const{
        return this->size_;
    }
    void        reserve(size_type n){
        if (n > this->capacity_)
        {
            value_type* new_data = get_allocator.allocate(n);
            for (int i=0; i<(int)n ; i++){
                construct(new_data + i, this->data[i]);
                destroy(this->data + i);
            }
            get_allocator.deallocate(this->data,this->capacity_);
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
    void     push_back(const T& x){
        if (this->size_ ==this->capacity_)
            reserve(this->capacity_ + this->capacity_/2);
        construct(this->data + this->size_, x);
        this->size_++;
    }
    void     pop_back();
    iterator insert(iterator position, const T& x);
    void     insert(iterator position, size_type n, const T& x);
    template <class InputIterator>
    void     insert(iterator position,InputIterator first, InputIterator last);
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    void     swap(vector<T,allocator_type>&);
    void     clear(){
        for (int i = 0; i<(int)this->size_ ;i++){
            alloc_.destroy(this->data + i);
        }
        get_allocator.deallocate(this->data, this->capacity_);
    }
    //-----------------------------------------------------private members:
    private:
    value_type* data;
    size_type capacity_;
    size_type size_;
    allocator_type alloc_;
};
//----------------------------------------------------------non-member operators:
template <typename T, typename Alloc >
bool operator == (const ft::vector<T,Alloc >& x,const vector<T,Alloc>& y){}
template <class T, class Allocator>
bool operator < (const vector<T,allocator_type>& x,const vector<T,allocator_type>& y);
template <class T, class Allocator>
bool operator != (const vector<T,allocator_type>& x,const vector<T,allocator_type>& y);
template <class T, class Allocator>
bool operator > (const vector<T,allocator_type>& x,const vector<T,allocator_type>& y);
template <class T, class Allocator>
bool operator >= (const vector<T,allocator_type>& x,const vector<T,allocator_type>& y);
template <class T, class Allocator>
bool operator <= (const vector<T,allocator_type>& x,const vector<T,allocator_type>& y);

//-----------------------------------------------------------swap algorithm:
template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);

}
#endif
