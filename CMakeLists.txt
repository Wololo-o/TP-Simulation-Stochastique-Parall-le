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

set(SRC_FILES_MCT
    src/main_monte_carlo_thread.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/lib/Random/build/include)

link_directories(${CMAKE_SOURCE_DIR}/lib/Random/build/lib)

add_executable(sequentiel ${SRC_FILES})
add_executable(genStatus ${SRC_FILES_GEN})
add_executable(estimationPI ${SRC_FILES_MC})
add_executable(estimationPIThread ${SRC_FILES_MCT})

target_link_libraries(sequentiel CLHEP-Random-2.1.0.0.a)
target_link_libraries(genStatus CLHEP-Random-2.1.0.0.a)
target_link_libraries(estimationPI CLHEP-Random-2.1.0.0.a)
target_link_libraries(estimationPIThread CLHEP-Random-2.1.0.0.a)