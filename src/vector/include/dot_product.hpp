#pragma once
#include "vector.hpp"
#include <numeric>

namespace svm
{

template<typename Iterator>
inline constexpr typename Iterator::value_type 
    dot_product(Iterator start1, Iterator end1, Iterator start2) noexcept {
        return std::transform_reduce(start1, end1, start2, std::multiplies<typename Iterator::value_type>{});
}

template<typename Iterator, typename ExecutionPolicy>
inline constexpr typename Iterator::value_type 
    dot_product(ExecutionPolicy&& policy, Iterator start1, Iterator end1, Iterator start2) noexcept {
        return std::transform_reduce(policy, start1, end1, start2, std::multiplies<typename Iterator::value_type>{});
}

}   // end of namespace svm

