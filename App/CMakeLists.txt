set(project_name SampleApp)

project(${project_name})

file(GLOB SOURCES *.cpp)

add_custom_target(RunTests
	COMMAND ../TestExamples_GoogleTest/GoogleTest_SimpleTests
)

add_executable(${project_name} ${SOURCES})