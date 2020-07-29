#ifndef HELPERS_H
#define HELPERS_H

#include <cmath>
#include <limits>

class Helpers
{
public:
    Helpers();

    template<class T>
    bool static Equal(T, T);

    bool static Equal(double a, double b){
        return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
    }

    template<class T>
    T static Zero();

    template<class T>
    T static One();
};

template<class T>
bool Helpers::Equal(T a, T b)
{
    return a==b;
}

template<class T>
T Helpers::Zero(){
   return static_cast<T>(0);
}

template<class T>
T Helpers::One(){
   return static_cast<T>(1);
}

#endif // HELPERS_H
