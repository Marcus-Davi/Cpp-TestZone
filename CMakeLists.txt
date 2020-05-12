cmake_minimum_required(VERSION 3.8)
project (multisource)

file(GLOB cpp_list RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#add_executable(oi src/s1.cpp)
foreach(file_path ${cpp_list})
	message(STATUS ${file_path})
	string(REPLACE "src/" "" name0 ${file_path})
	string(REPLACE ".cpp" "" name ${name0})
	message(STATUS ${name})
	add_executable(${name} ${file_path})
endforeach()




# Create Symlink for compile commands for YCM
if(CMAKE_EXPORT_COMPILE_COMMANDS)
		message(STATUS "compile commands ON")
	set(comp_file "compile_commands.json")
	execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${PROJECT_BINARY_DIR}/${comp_file} ${CMAKE_SOURCE_DIR}/src/${comp_file})

	else()
			message(STATUS "compile commands OFF")
	endif()