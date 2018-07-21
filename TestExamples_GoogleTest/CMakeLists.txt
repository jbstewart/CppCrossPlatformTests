include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${gmock_SOURCE_DIR}/include)
include_directories("../FakeIt/single_header/gtest/")
include_directories("../SimpleMockExample")

set(requiredTestLibs gmock_main)
add_tests_in_folder( *.cpp ${requiredTestLibs})
