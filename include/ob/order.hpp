#pragma once

#include "ob/types.hpp"

namespace ob
{
    struct Order
    {
        OrderId id;
        Side side;
        Price price;
        Quantity quantity;
    };
}