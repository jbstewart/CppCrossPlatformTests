include_directories("../Catch2")
include_directories("../SimpleMockExample")

include_directories("../FakeIt/single_header/catch/")
include_directories("../SimpleMockExample")

# No libraries to include!
add_tests_in_folder( *.cpp "" )
