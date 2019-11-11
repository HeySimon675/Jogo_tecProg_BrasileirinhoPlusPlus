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

add_executable(Brasileirinho__ main.cpp Lista.h Elemento.h GerenciadorGrafico.cpp GerenciadorGrafico.h Entidade.cpp Entidade.h Jogo.cpp Jogo.h ListaEntidades.cpp ListaEntidades.h Collider.h Collider.cpp Personagem.cpp Personagem.h Jogador.cpp Jogador.h Jogador_1.cpp Jogador_1.h Jogador_2.cpp Jogador_2.h Inimigo.cpp Inimigo.h Inimigo_A.cpp Inimigo_A.h Inimigo_B.cpp Inimigo_B.h Inimigo_Boss.cpp Inimigo_Boss.h Fase.cpp Fase.h Fase_A.cpp Fase_A.h Fase_B.cpp Fase_B.h Projetil.cpp Projetil.h Projetil_Tipo_1.cpp Projetil_Tipo_1.h Projetil_Tipo_2.cpp Projetil_Tipo_2.h)
target_link_libraries(Brasileirinho__ sfml-graphics sfml-window sfml-system sfml-audio)