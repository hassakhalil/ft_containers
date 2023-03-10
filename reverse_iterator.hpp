#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H
#include "iterator.hpp"
#include "iterator_traits.hpp"
namespace ft
{
    template <class Iterator>
    class reverse_iterator : public ft::iterator <
    typename ft::iterator_traits<Iterator>::iterator_category,
    typename ft::iterator_traits<Iterator>::value_type,
    typename ft::iterator_traits<Iterator>::difference_type,
    typename ft::iterator_traits<Iterator>::pointer,
    typename ft::iterator_traits<Iterator>::reference >
    {
        protected:
        Iterator current;

        public:
        typedef          Iterator                                       iterator_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::reference       reference;
        typedef typename ft::iterator_traits<Iterator>::pointer         pointer;

        reverse_iterator():current(Iterator()){}
        explicit reverse_iterator(Iterator X):current(X){}
        template <class U>
        reverse_iterator(const ft::reverse_iterator<U>& u):current(u.base()){}
        ft::reverse_iterator<Iterator>& operator=(const ft::reverse_iterator<Iterator>& other){
            this->current = other.base();
            return *this;
        }
        ~reverse_iterator(){}
        Iterator base()const{return this->current;}
        reference operator*()const{
            Iterator tmp = this->current;
            return *--tmp;
        }
        pointer operator->()const {
            Iterator tmp = this->current;
            return &(*--tmp);
        }
        ft::reverse_iterator<Iterator>& operator++(){
            --this->current;
            return *this;

        }
        ft::reverse_iterator<Iterator> operator++(int){
             ft::reverse_iterator<Iterator> tmp(*this);
            --this->current;
            return tmp;
        }
        ft::reverse_iterator<Iterator>& operator--(){
            ++this->current;
            return *this;
        }
        ft::reverse_iterator<Iterator> operator--(int){
            ft::reverse_iterator<Iterator> tmp(*this);
            ++this->current;
            return tmp;
        }
        ft::reverse_iterator<Iterator> operator+(difference_type n)const{return ft::reverse_iterator<Iterator>(this->current - n);}
        ft::reverse_iterator<Iterator>& operator+=(difference_type n){
            this->current -= n;
            return *this;
        }
        ft::reverse_iterator<Iterator> operator- (difference_type n)const{return ft::reverse_iterator<Iterator>(this->current + n);}
        ft::reverse_iterator<Iterator>& operator-=(difference_type n){
            this->current += n;
            return *this;
        }
        reference operator[](difference_type n)const{return this->current[-n-1];}
        bool operator !=(const ft::reverse_iterator<Iterator>& other){return !(this->base() == other.base());}
        bool operator==(const ft::reverse_iterator<Iterator>& other){return other.base() == this->base();}
        bool operator>(const ft::reverse_iterator<Iterator>& other){return (other.base() > this->base())?true:false;}
        bool operator>=(const ft::reverse_iterator<Iterator>& other){return other.base() >= this->base();}
        bool operator<=(const ft::reverse_iterator<Iterator>& other){return other.base() <= this->base();}
        bool operator<(const ft::reverse_iterator<Iterator>& other){return other.base() < this->base();}
        difference_type operator-(const ft::reverse_iterator<Iterator>& other){return other.base() - this->base();}
        ft::reverse_iterator<Iterator> operator+(difference_type n){return ft::reverse_iterator<Iterator>(this->base() - n);}
    };
    template <class Iterator>
    ft::reverse_iterator<Iterator> operator+(typename ft::iterator_traits<Iterator>::difference_type n,const ft::reverse_iterator<Iterator>& x){return ft::reverse_iterator<Iterator>(x.base() - n);}
}

#endif