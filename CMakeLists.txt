cmake_minimum_required(VERSION 3.10)
set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)
include(GoogleTest)

add_subdirectory(googletest)

enable_testing()

add_subdirectory(TestExamples_GoogleTest)
add_subdirectory(TestExamples_BoostTest)
