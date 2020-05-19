cmake_minimum_required(VERSION 3.8)
project (multisource)

file(GLOB cpp_list RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB c_list RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add executables for all .cpp files
foreach(file_path ${cpp_list})
	message(STATUS ${file_path})
	string(REPLACE "src/" "" name_src ${file_path})
	string(REPLACE ".cpp" "" name_final ${name_src})
	message(STATUS ${name_final})
	add_executable(${name_final} ${file_path})
endforeach()


# add executables for all .c files
foreach(file_path ${c_list})
	message(STATUS ${file_path})
	string(REPLACE "src/" "" name_src ${file_path})
	string(REPLACE ".c" "" name_final ${name_src})
	message(STATUS ${name_final})
	add_executable(${name_final} ${file_path})
endforeach()

# Create Symlink for compile commands for YCM
if(CMAKE_EXPORT_COMPILE_COMMANDS)
		message(STATUS "compile commands ON")
	set(comp_file "compile_commands.json")
	execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${PROJECT_BINARY_DIR}/${comp_file} ${CMAKE_SOURCE_DIR}/src/${comp_file})

	else()
			message(STATUS "compile commands OFF")
	endif()
