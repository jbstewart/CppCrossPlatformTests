cmake_minimum_required(VERSION 3.10)
set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GoogleTest)
include(add_tests_in_folder)


add_subdirectory(googletest)

enable_testing()

add_subdirectory(TestExamples_GoogleTest)
add_subdirectory(TestExamples_BoostTest)
