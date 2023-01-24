#ifndef IS_INTEGRAL_H
#define IS_INTEGRAL_H


namespace ft
{
    //------------------------------itegral_constant
    template <class T, T v>
    struct integral_constant
    {
        
    };

    //---------------------------is_integral
    template <class T>
    struct is_integral:public ft::integral_constant<T,T v>
    {
        /* data */
    };
    
}
#endif