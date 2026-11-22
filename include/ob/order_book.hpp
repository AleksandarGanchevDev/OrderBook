#pragma once

#include "ob/order.hpp"

#include <functional>
#include <list>
#include <map>
#include <unordered_map>
#include <optional>

namespace ob
{
    class OrderBook
    {
    public:
        void add(const Order &order);

        bool cancel (OrderId id);

        [[nodiscard]] std::optional<Price> bestBid() const;
        [[nodiscard]] std::optional<Price> bestAsk() const;

    private:
        std::map<Price, std::list<Order>, std::greater<Price>> bids_;
        std::map<Price, std::list<Order>> asks_;
        std::unordered_map<OrderId, std::list<Order>::iterator> orders_;
    };
}