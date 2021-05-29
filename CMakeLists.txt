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


	
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

	message(STATUS "Cmake curr sourc: " ${CMAKE_CURRENT_SOURCE_DIR})


	######## Installation Test

	
	set (CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install) #avoid installing in default path
	
	# helper variables
	set (LibraryName "Adder") #could be PROJECT_NAME or other 
	set(version_config "${LibraryName}ConfigVersion.cmake")
	set(project_config "${LibraryName}Config.cmake")	
	set(target_export_name "${LibraryName}Targets")
	set(config_install_dir "cmake")

	# add library
	add_library(${LibraryName} SHARED lib/adder.cpp)

	# 	update inteface locations
	target_include_directories(${LibraryName} INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
		$<INSTALL_INTERFACE:include>
	)

	# export unit
	install (TARGETS ${LibraryName}
	EXPORT ${target_export_name} # export name

	)
	
	# install header files
	install (FILES lib/adder.h
	DESTINATION include)

	# install .cmake file
	install (EXPORT ${target_export_name}	
	FILE ${target_export_name}.cmake
	DESTINATION ${config_install_dir}/${LibraryName})


	include(CMakePackageConfigHelpers)
	# generate the config file that is includes the exports
	configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
	"${CMAKE_CURRENT_BINARY_DIR}/${project_config}"
	INSTALL_DESTINATION "${config_install_dir}"
	)

	
	# generate the version file for the config file
	write_basic_package_version_file(
	  "${CMAKE_CURRENT_BINARY_DIR}/AdderConfigVersion.cmake"
	  VERSION "1.0"
	  COMPATIBILITY AnyNewerVersion
 	  )

	install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/${project_config}
  	DESTINATION cmake/${LibraryName}
  	)

	# include(InstallRequiredSystemLibraries)
	# #set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
	# set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
	# set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
	# include(CPack)
	