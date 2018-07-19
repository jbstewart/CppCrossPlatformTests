# NB: The prefix "23FX4_" is used to avoid tramping on variables that might be in the calling scripts
# https://stackoverflow.com/questions/14397298/strange-function-argument-name-behaviour

function(add_tests_in_folder 23FX4_fileSpec 23FX4_testingLibs)
	file(GLOB 23FX4_testSources ${23FX4_fileSpec})
	foreach(23FX4_testSource ${23FX4_testSources})
		message(STATUS "Adding test source to Boost Tests: " ${23FX4_testSource})
		get_filename_component(23FX4_testName ${23FX4_testSource} NAME_WE)
		add_executable(${23FX4_testName} ${23FX4_testSource})
		target_link_libraries(${23FX4_testName} ${23FX4_testingLibs})
		add_test(NAME ${23FX4_testName} COMMAND ${23FX4_testName})
	endforeach(23FX4_testSource)
endfunction()
