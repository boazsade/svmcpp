#pragma once
#include "types/basic_types.h"
#include <vector>
#include <array>

namespace svm
{
    template<Number Num>
    using dynamic_vector = std::vector<Num>;

    template<Number Num, std::size_t S>
    using static_vector = std::array<Num, S>;
}
