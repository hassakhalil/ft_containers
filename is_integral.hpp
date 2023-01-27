#ifndef IS_INTEGRAL_H
#define IS_INTEGRAL_H


namespace ft
{
    //---------------------------is_integral
    template <typename T >
    struct is_integral{
        bool value{false};
    };
    template <>
    struct is_integral<bool>
    {
        bool value{true};
    };
    template <>
    struct is_integral<char>
    {
        bool value{true};
    };
    template <>
    struct is_integral<char16_t>
    {
       bool value{true};
    };
    template <>
    struct is_integral<char32_t>
    {
        bool value{true};
    };
    template <>
    struct is_integral<wchar_t>
    {
        bool value{true};
    };
        template <>
    struct is_integral<signed char>
    {
        bool value{true};
    };
        template <>
    struct is_integral<short int>
    {
        bool value{true};
    };
    template <>
    struct is_integral<int>
    {
        bool value{true};
    };
    template <>
    struct is_integral<long int>
    {
        bool value{true};
    };
    template <>
    struct is_integral<long long int>
    {
        bool value{true};
    };
    template <>
    struct is_integral<unsigned char>
    {
        bool value{true};
    };
    template <>
    struct is_integral<unsigned short int>
    {
       bool value{true};
    };
    template <>
    struct is_integral<unsigned int>
    {
        bool value{true};
    };
    template <>
    struct is_integral<unsigned long int>
    {
        bool value{true};
    };
    template <>
    struct is_integral<unsigned long long int>
    {
        bool value{true};
    };




    
}
#endif