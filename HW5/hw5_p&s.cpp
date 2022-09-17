#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
void mySwap(T& x,T& y)
{
    T temp;
    temp=x;
    x=y;
    y=temp;
}