cmake_minimum_required(VERSION 3.16)

project(Codigos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Codigos


    main.cpp
    Calcularbytes.cpp
    Calcularbytes.h
    Creartablero.cpp
    Creartablero.h
    Liberartablero.cpp
    Liberartablero.h
    Obtenerficha.cpp
    Obtenerficha.h
    Colocarficha.cpp
    Colocarficha.h
    Llenartablero.cpp
    Llenartablero.h
    Mostrartablero.cpp
    Mostrartablero.h
    Mostrarbinario.cpp
    Mostrarbinario.h
    Eliminarficha.cpp
    Eliminarficha.h
    Detectarcombinaciones.cpp
    Detectarcombinaciones.h
    Reorganizartablero.cpp
    Reorganizartablero.h
    Llenarespacios.cpp
    Llenarespacios.h
    Procesarcascadas.cpp
    Procesarcascadas.h
    Agregarfila.cpp
    Agregarfila.h
    Eliminarfila.cpp
    Eliminarfila.h
    Agregarcolumna.cpp
    Agregarcolumna.h
    Eliminarcolumna.cpp
    Eliminarcolumna.h
    Mostrarmenu.cpp
    Mostrarmenu.h


)

include(GNUInstallDirs)
install(TARGETS Codigos
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
