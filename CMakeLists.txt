cmake_minimum_required(VERSION 3.25.1)

project(tp5)

add_compile_options(-Wall -Wextra -O2 -g)

set(SRC_FILES
    src/main.cpp
)

set(SRC_FILES_GEN
    src/main_gen_rand.cpp
)

set(SRC_FILES_MC
    src/main_monte_carlo.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/lib/Random/build/include)

link_directories(${CMAKE_SOURCE_DIR}/lib/Random/build/lib)

add_executable(tp5 ${SRC_FILES})
add_executable(tp5_gen ${SRC_FILES_GEN})
add_executable(tp5_mc ${SRC_FILES_MC})

target_link_libraries(tp5 CLHEP-Random-2.1.0.0.a)
target_link_libraries(tp5_gen CLHEP-Random-2.1.0.0.a)
target_link_libraries(tp5_mc CLHEP-Random-2.1.0.0.a)