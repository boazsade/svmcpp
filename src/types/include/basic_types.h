#pragma once

#include <type_traits>

namespace svm
{


template<typename TypeConcept>
concept Number = is_arithmetic_v<T>;

template<Number number>
struct basic_value
{
    constexpr auto operator <=> (basic_value other) const noexcept = default;

    constexpr explicit basic_value(number v) noexcept :
       value{v}
    {
    }

   constexpr basic_value& operator = (number new_value) {
       number = std::move(new_value);
       return *this;
   }
protected:
   constexpr basic_value() noexcept = default;

   number value{}; 
};

struct degree : basic_value<int>
{
};

struct gammma : basic_value<double>
{
};

struct coefficency : basic_value<double>
{
};

struct epcilon : basic_value<double>
{
}

}   // end of namespace svn