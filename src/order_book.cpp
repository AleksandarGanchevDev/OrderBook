#include "ob/order_book.hpp"

namespace ob
{
    void OrderBook::add(const Order &order)
    {
        if (order.side == Side::Buy)
            bids_[order.price].push_back(order);
        else
            asks_[order.price].push_back(order);
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