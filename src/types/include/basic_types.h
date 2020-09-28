#pragma once

#include <type_traits>
#include <limits>

namespace svm
{


template<typename TypeConcept>
concept Number = std::is_arithmetic_v<TypeConcept>;

template<Number Num>
inline constexpr const auto invalid() noexcept {
    return std::numeric_limits<Num>::max();
}

template<Number Num> inline 
constexpr const bool invalid(Number val) noexcept {
    return val == invalid<Num>();
}

template<Number number>
struct basic_value
{
    constexpr auto operator <=> (const basic_value& other) const noexcept = default;

    constexpr explicit basic_value(number v) noexcept :
       value{v}
    {
    }

   constexpr basic_value& operator = (number new_value) noexcept {
       value = std::move(new_value);
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
};

}   // end of namespace svn
