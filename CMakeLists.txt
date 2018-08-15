cmake_minimum_required(VERSION 3.10)

message( STATUS "Foo")

set(gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(GoogleTest)
include(add_tests_in_folder)


add_subdirectory(googletest)

enable_testing()

add_subdirectory(TestExamples_GoogleTest)
if(LINUX OR NOT DEFINED INTEL_CXX)
	add_subdirectory(TestExamples_BoostTest)
	add_subdirectory(TestExamples_Catch)
endif(WIN32 AND NOT DEFINED INTEL_CXX)

#set(ALLTESTS 
#TestExamples_GoogleTest
#TestExamples_BoostTest
#TestExamples_Catch
#)
#add_custom_target(test_all DEPENDS ${ALLTESTS})
