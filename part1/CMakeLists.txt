cmake_minimum_required(VERSION 3.15)
project(DataStructures1.1)

set(CMAKE_CXX_STANDARD 11)

#Part 1 List
add_executable(ListTester LinkedList.h main1.cpp library1.h ListTester.cpp)
#Part 1 Tree
add_executable(TreeTester LinkedList.h main1.cpp library1.h TreeTester.cpp)

#Part 1 List
#add_executable(ListTester avlTree.h )