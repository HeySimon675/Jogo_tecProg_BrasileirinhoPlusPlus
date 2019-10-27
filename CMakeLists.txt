cmake_minimum_required(VERSION 3.15)
project(Brasileirinho__)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "~/Documentos/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "~/Documentos/SFML-2.5.1/lib")
set(SFML_DIR "~/Documentos/SFML-2.5.1")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Brasileirinho__ main.cpp Lista.h Elemento.h GerenciadorGrafico.cpp GerenciadorGrafico.h Entidade.cpp Entidade.h)
target_link_libraries(Brasileirinho__ sfml-graphics sfml-window sfml-system sfml-audio)