cmake_minimum_required(VERSION 3.16)

project(engineTest)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)




include(conan/conanbuildinfo.cmake)
conan_basic_setup()


add_executable(main)

target_sources(main PUBLIC 
            src/MainE.cpp 
            src/BitsE.cpp 
            src/PieceE.cpp
            src/SquareE.cpp   
            src/DeclarationsE.cpp
            src/DebugE.cpp        
            )
target_compile_features(main PRIVATE cxx_std_20)
target_compile_options(main PRIVATE -g -Wall -O0)
target_include_directories(main PRIVATE includes)
target_link_libraries(main ${CONAN_LIBS})

#-fno-exceptions