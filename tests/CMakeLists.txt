cmake_minimum_required(VERSION 3.20)
projects(orderbook CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpendatic)

add_library(ob src/order_book.cpp)
target_include_directories(ob PUBLIC include)

add_executable(demo apps/demo.cpp)
target_link_libraries(demo PRIVATE ob)