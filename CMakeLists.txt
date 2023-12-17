cmake_minimum_required(VERSION 3.10)
project(avg_test C)

# This option optimizes the code for speed at runtime
# This will make the benchmark of averagin similar for some reason
add_compile_options(-O3)

include_directories(include)
add_executable(avg_test src/avg_test.c)