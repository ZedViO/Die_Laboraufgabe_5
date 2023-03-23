cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

set(COVERAGE OFF CACHE BOOL "Coverage")

project(banking)

add_library(banking_lib STATIC  ${CMAKE_CURRENT_SOURCE_DIR}/banking/Transaction.cpp ${CMAKE_CURRENT_SOURCE_DIR}/banking/Account.cpp)     #Собираем банкинг

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/gtest gtest)  #Крадем у гуглов их либу с тестами

add_executable(run_test ${CMAKE_CURRENT_SOURCE_DIR}/gtests/Testfile.cpp)  #Наши тесты

if (COVERAGE)  #Покроем нашу лабу любовью и заботой
    target_compile_options(run_test PRIVATE --coverage)
    target_link_libraries(run_test PRIVATE --coverage)
endif()

target_link_libraries(run_test banking_lib gtest) #А не рванет? -Не должно

