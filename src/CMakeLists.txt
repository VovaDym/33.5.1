
cmake_minimum_required (VERSION 3.8)

project ("33.5.1")

add_executable (33.5.1 "main.cpp")

target_include_directories(33.5.1 PUBLIC ${MY_INCLUDE_DIR})

target_link_libraries(33.5.1 ${Boost_LIBRARIES})

if (MINGW)
    target_link_libraries(33.5.1 ws2_32)
endif()
