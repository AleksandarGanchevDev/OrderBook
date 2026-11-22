#include "ob/order_book.hpp"

namespace ob
{
    void OrderBook::add(const Order &order)
    {
        if (orders_.contains(order.id))
            return;

        std::list<Order> &level = (order.side == Side::Buy) ? bids_[order.price] : asks_[order.price];

        level.push_back(order);
        orders_[order.id] = std::prev(level.end());
    }

    bool OrderBook::cancel(OrderId id)
    {
        auto found = orders_.find(id);
        if (found == orders_.end())
            return false;

        auto orderIt = found->second;
        Price price = orderIt->price;
        Side side = orderIt->side;

        if (side == Side::Buy)
        {
            auto level = bids_.find(price);
            level->second.erase(orderIt);
            if (level->second.empty())
                bids_.erase(level);
        }
        else
        {
            auto level = asks_.find(price);
            level->second.erase(orderIt);
            if (level->second.empty())
                asks_.erase(level);
        }

        orders_.erase(found);

        return true;
    }

    std::optional<Price> OrderBook::bestBid() const
    {
        if (bids_.empty())
            return std::nullopt;
        return bids_.begin()->first;
    }

    std::optional<Price> OrderBook::bestAsk() const
    {
        if (asks_.empty())
            return std::nullopt;
        return asks_.begin()->first;
    }
}