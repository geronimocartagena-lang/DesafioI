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


)

include(GNUInstallDirs)
install(TARGETS Codigos
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
