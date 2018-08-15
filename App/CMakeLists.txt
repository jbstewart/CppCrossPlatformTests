set(project_name SampleApp)

project(${project_name})

file(GLOB SOURCES *.cpp)

add_executable(${project_name} ${SOURCES})