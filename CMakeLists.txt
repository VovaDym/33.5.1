
cmake_minimum_required (VERSION 3.8)

project ("33.5.1")

set (CMAKE_CXX_STANDARD 14)
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set (Boost_INCLUDE_DIR "C:\\boost_1_80_0")
set (Boost_LIBRARY_DIR "C:\\boost_1_80_0\\stage\\lib")
find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})


add_subdirectory(src)

target_link_libraries(33.5.1 ${Boost_LIBRARIES})
target_include_directories(33.5.1 PUBLIC ${MY_INCLUDE_DIR})

if (MINGW)
    target_link_libraries(33.5.1 ws2_32)
endif()
