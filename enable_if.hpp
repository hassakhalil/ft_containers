#ifndef ENABLE_IF_H
#define ENABLE_IF_H

namespace ft
{    
    //-------------------------enable_if
    template <bool Cond, class T = void >
    struct enable_if{};

    template <class T>
    struct enable_if<true,T>
    {
        typedef T type;
    };
    
}

#endif