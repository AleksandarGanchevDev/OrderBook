#pragma once

#include "ob/order.hpp"

#include <functional>
#include <list>
#include <map>
#include <optional>

namespace ob
{
    class OrderBook
    {
    public:
        void add(const Order &order);

        [[nodiscard]] std::optional<Price> bestBid() const;
        [[nodiscard]] std::optional<Price> bestAsk() const;

    private:
        std::map<Price, std::list<Order>, std::greater<Price>> bids_;
        std::map<Price, std::list<Order>> asks_;
    };
}