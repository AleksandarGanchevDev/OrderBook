#include <iostream>
#include <optional>

#include "ob/order_book.hpp"

void printPrice(const char *label, std::optional<ob::Price> p)
{
    std::cout << label << ": ";
    if (p)
        std::cout << *p;
    else
        std::cout << "none";
    std::cout << '\n';
}

int main()
{
    ob::OrderBook book;

    printPrice("BestBid", book.bestBid());
    printPrice("BestAsk", book.bestAsk());

    book.add({1, ob::Side::Sell, 9501, 10});
    book.add({2, ob::Side::Sell, 9501, 40});
    book.add({3, ob::Side::Buy, 9500, 25});

    printPrice("BestBid", book.bestBid());
    printPrice("BestAsk", book.bestAsk());

    std::cout << std::boolalpha;

    std::cout << "cancel 1: " << book.cancel(1) << '\n';
    printPrice("BestAsk", book.bestAsk()); // still 9501

    std::cout << "cancel 2: " << book.cancel(2) << '\n';
    printPrice("BestAsk", book.bestAsk()); // none

    std::cout << "cancel 3: " << book.cancel(3) << '\n';
    printPrice("BestBid", book.bestBid()); // none

    std::cout << "cancel 99: " << book.cancel(99) << '\n';     // false
    std::cout << "cancel 1 again: " << book.cancel(1) << '\n'; // false
    return 0;
}