#pragma once

#include <cstdint>

namespace ob
{
    using Price = std::int64_t;
    using Quantity = std::uint32_t;
    using OrderId = std::uint64_t;

    enum class Side : std::uint8_t
    {
        Buy,
        Sell
    };
}