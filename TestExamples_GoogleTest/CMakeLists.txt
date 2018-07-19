include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${gmock_SOURCE_DIR}/include)

set(test_sources
	TestCase_01.cpp
	TestCase_02.cpp
)

add_executable(gtest_examples ${test_sources})
#target_link_libraries(gtest_examples gtest_main)
target_link_libraries(gtest_examples gmock_main)
add_test(gtest_examples gtest_examples)
