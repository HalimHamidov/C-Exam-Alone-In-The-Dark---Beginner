cmake_minimum_required(VERSION 3.14)
project(reverse_bits C)

set(CMAKE_C_STANDARD 11)

add_executable(reverse_bits
        reverse_bits.c bitwise.c)
