cmake_minimum_required(VERSION 2.6)
#start for win
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

#if(MSVC)
#    add_compile_options(/W4 /arch:SSE /arch:SSE2)
#    enable_testing()
#    include(GoogleTest)
#else()
#    add_compile_options(-Wall -Wextra -pedantic -Werror)
#    add_compile_options(-msse -msse2 -mssse3 -msse4 -msse4.1 -msse4.2 -ffast-math)
#    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/modules)
#endif()

# Locate GTest
if(MSVC)
	# GTest
	add_compile_options(/W4 /arch:SSE /arch:SSE2 /MT /MTd)
	enable_testing()
	find_package(GTest REQUIRED)
	include_directories(${GTEST_INCLUDE_DIRS})

	# Unit Tests
	# Add test cpp file
	add_executable( runUnitTests tests.cpp)
	# Link test executable against gtest & gtest_main
	target_link_libraries(runUnitTests ${GTEST_BOTH_LIBRARIES})
	add_test( runUnitTests runUnitTests )

else()
	find_package(GTest REQUIRED)
	include_directories(${GTEST_INCLUDE_DIRS})

	# Link runTests with what we want to test and the GTest and pthread library
	add_executable(runTests tests.cpp)
	target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

endif()
