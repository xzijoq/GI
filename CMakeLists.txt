cmake_minimum_required(VERSION 3.13)

project(engineTest)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include(conan/conanbuildinfo.cmake)
conan_basic_setup()


add_executable(main)

target_sources(main PUBLIC src/main.cpp )
target_compile_features(main PRIVATE cxx_std_20)
target_compile_options(main PUBLIC -g -Wall -O0)
target_link_libraries(main ${CONAN_LIBS})