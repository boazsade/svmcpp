#pragma once
#include "vector.hpp"
#include <numeric>
#include <functional>
#include <iterator>

namespace svm
{

template<std::random_access_iterator Iterator>
inline constexpr typename Iterator::value_type 
    dot_product(Iterator start1, Iterator end1, Iterator start2) noexcept {
        using value_type = typename Iterator::value_type;

        return std::transform_reduce(start1, end1, start2, value_type{},
                std::plus<value_type>{}, 
                std::multiplies<value_type>{});
}

template<std::random_access_iterator Iterator, typename ExecutionPolicy>
inline constexpr typename Iterator::value_type 
    dot_product(ExecutionPolicy&& policy, Iterator start1, Iterator end1, Iterator start2) noexcept {
        using value_type = typename Iterator::value_type;

        return std::transform_reduce(policy, start1, end1, start2, value_type{},
                std::plus<value_type>{},
                std::multiplies<value_type>{}
            );
}

inline constexpr dynamic_vector::value_type 
    dot_product(const dynamic_vector& left, const dynamic_vector& right) noexcept {
        if (std::size(vec) != std::size(left)) {
            return invalid();
        } else {
            return dot_product(std::begin(left), std::end(left), std::begin(right));
        }
}

inline constexpr dynamic_vector::value_type 
    dot_product(const static_vector& left, const dynamic_vector& right) noexcept {
        if (std::size(vec) != std::size(left)) {
            return invalid();
        } else {
            return dot_product(std::begin(left), std::end(left), std::begin(right));
        }
}

inline constexpr dynamic_vector::value_type 
    dot_product(const dynamic_vector& left, const static_vector& right) noexcept {
        if (std::size(vec) != std::size(left)) {
            return invalid();
        } else {
            return dot_product(std::begin(left), std::end(left), std::begin(right));
        }
}

template<typename ExecutionPolicy>
inline constexpr dynamic_vector::value_type 
    dot_product(ExecutionPolicy&& ep, const dynamic_vector& left, const dynamic_vector& right) noexcept {
        if (std::size(vec) != std::size(left)) {
            return invalid();
        } else {
            return dot_product(std::move(ep), std::begin(left), std::end(left), std::begin(right));
        }
}

template<typename ExecutionPolicy>
inline constexpr dynamic_vector::value_type 
    dot_product(const static_vector& left, const dynamic_vector& right) noexcept {
        if (std::size(vec) != std::size(left)) {
            return invalid();
        } else {
            return dot_product(std::move(ep), std::begin(left), std::end(left), std::begin(right));
        }
}

template<typename ExecutionPolicy>
inline constexpr dynamic_vector::value_type 
    dot_product(ExecutionPolicy&& ep, const dynamic_vector& left, const static_vector& right) noexcept {
        if (std::size(vec) != std::size(left)) {
            return invalid();
        } else {
            return dot_product(std::move(ep), std::begin(left), std::end(left), std::begin(right));
        }
}

}   // end of namespace svm

