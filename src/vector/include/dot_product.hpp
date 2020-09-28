#pragma once
#include "vector.hpp"
#include <numeric>
#include <functional>
#include <span>

namespace svm
{

template<Number number> constexpr number 
    dot_product(const std::span<const number> left, const std::span<const number> right) noexcept {
        //using value_type = typename Iterator::value_type;

        return std::transform_reduce(std::begin(left), std::end(left), std::begin(right), number{},
                std::plus<number>{}, 
                std::multiplies<number>{});
}

template<Number number, typename ExecutionPolicy>
inline constexpr number 
    dot_product(ExecutionPolicy&& policy, const std::span<const number> left, const std::span<const number> right) noexcept {

        return std::transform_reduce(policy, std::begin(left), std::end(left), std::begin(right), number{},
                std::plus<number>{},
                std::multiplies<number>{}
            );
}

template<Number Num>
inline constexpr typename dynamic_vector<Num>::value_type 
    dot_product(const dynamic_vector<Num>& left, const dynamic_vector<Num>& right) noexcept {
        if (std::size(right) != std::size(left)) {
            return invalid<Num>();
        } else {
            return dot_product(left, right);
        }
}

template<Number Num, std::size_t I>
inline constexpr typename dynamic_vector<Num>::value_type 
    dot_product(const static_vector<Num, I>& left, const dynamic_vector<Num>& right) noexcept {
        if (std::size(right) != std::size(left)) {
            return invalid<Num>();
        } else {
            return dot_product(left, right);
        }
}

template<Number Num, std::size_t I>
inline constexpr typename dynamic_vector<Num>::value_type 
    dot_product(const dynamic_vector<Num>& left, const static_vector<Num, I>& right) noexcept {
        if (std::size(right) != std::size(left)) {
            return invalid<Num>();
        } else {
            return dot_product(left, right);
        }
}

template<typename ExecutionPolicy, Number Num>
inline constexpr typename dynamic_vector<Num>::value_type 
    dot_product(ExecutionPolicy&& ep, const dynamic_vector<Num>& left, const dynamic_vector<Num>& right) noexcept {
        if (std::size(right) != std::size(left)) {
            return invalid<Num>();
        } else {
            return dot_product(std::move(ep), left, right);
        }
}

template<typename ExecutionPolicy, Number number, std::size_t I>
inline constexpr typename dynamic_vector<number>::value_type 
    dot_product(ExecutionPolicy&& ep, const static_vector<number, I>& left, const dynamic_vector<number>& right) noexcept {
        if (std::size(right) != std::size(left)) {
            return invalid<number>();
        } else {
            return dot_product(std::move(ep), left, right);
        }
}

template<typename ExecutionPolicy, Number number, std::size_t I>
inline constexpr typename dynamic_vector<number>::value_type 
    dot_product(ExecutionPolicy&& ep, const dynamic_vector<number>& left, const static_vector<number, I>& right) noexcept {
        if (std::size(right) != std::size(left)) {
            return invalid<number>();
        } else {
            return dot_product(std::move(ep), left, right);
        }
}

}   // end of namespace svm

