cmake_minimum_required(VERSION 3.19)

project(jingtao-variable-test)

get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

message(STATUS "---------------- split line ----------------")

execute_process(COMMAND "${CMAKE_COMMAND}" "-E" "environment")