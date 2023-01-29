#ifndef LEXICOGRAHPICAL_COMPARE_H
#define LEXICOGRAHPICAL_COMPARE_H
namespace ft
{

    //--------------------------------------------std::lexicographical_compare
    template <class InputIterator1,class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2){
        while (first1 != last1 || first2!= last2){
            if (!(!(*first1<*first2) && !(*first2<*first1)))
            {
                if (*first1 > *first2)
                    return false;
            }
            first1++;
            first2++;
        }
        if (first1==last1 && first2!= last2)
            return true;
        return false;
    }
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1,InputIterator1 last1,InputIterator2 first2,InputIterator2 last2,Compare comp){
        while (first1 != last1 || first2!= last2){
            if (!(!comp(*first1,*first2) && !comp(*first2,*first1)))
            {
                if (comp(*first2, *first1))
                    return false;
            }
            first1++;
            first2++;
        }
        if (first1==last1 && first2!= last2)
            return true;
        return false;
    }
}

#endif