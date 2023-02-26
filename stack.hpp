#ifndef STACK_H
#define STACK_H
#include "vector.hpp"
namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack{
        public:
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef          Container            container_type;
        protected:
        Container c;
        public:
        explicit stack(const Container& x = Container()):c(x){}
        bool empty()const{return c.empty();}
        size_type   size()const{return c.size();}
        value_type& top(){return c.back();}
        const value_type& top()const{return c.back();}
        void  push(const value_type& x){c.push_back(x);}
        void  pop(){c.pop_back();}
        // ~stack(){
        //     // c.clear();
        //     // if (c.capacity())
        //     //     c.get_allocator().deallocate()
        // }
        container_type getc()const{ return this->c;}
    };
    template <class T, class Container>
    bool operator==(const stack<T, Container>& x, const stack<T, Container>& y){return x.getc()==y.getc();}
    template <class T, class Container>
    bool operator< (const stack<T, Container>& x, const stack<T, Container>& y){return x.getc()< y.getc();}
    template <class T, class Container>
    bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y){return x.getc()!=y.getc();}
    template <class T, class Container>
    bool operator> (const stack<T, Container>& x, const stack<T, Container>& y){return x.getc()> y.getc();}
    template <class T, class Container>
    bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y){return x.getc()>= y.getc();}
    template <class T, class Container>
    bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y){return x.getc()<= y.getc();}
}

#endif