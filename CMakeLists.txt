cmake_minimum_required(VERSION 3.10)
set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)
include(GoogleTest)
enable_testing()

add_subdirectory(googletest)

add_subdirectory(TestExamples_GoogleTest)
