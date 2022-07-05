cmake_minimum_required(VERSION 3.15)
project(coinbase_robot)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

# gather headers
file(GLOB coinbase_robot_TOP_HEADERS include/*.h)
#file(GLOB coinbase_robot_SOURCES src/*.cpp)
#file(GLOB coinbase_robot_PRIVATE_HEADERS include/*.hpp)

# dependency handling
set(OPENSSL_USE_STATIC_LIBS TRUE)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Threads REQUIRED)
find_package(cbpro++ REQUIRED)

#target_compile_options(coinbase_robot PRIVATE -Wall)
add_executable(coinbase_robot main.cpp ${coinbase_robot_TOP_HEADERS} )
target_link_libraries(coinbase_robot PUBLIC cbpro++::cbpro++)
