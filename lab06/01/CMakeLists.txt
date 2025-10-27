cmake_minimum_required(VERSION 3.10)
project(Lab06_01)

# Configurar estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Flags del compilador
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Incluir directorios
include_directories(include)

# Buscar archivos fuente
file(GLOB SOURCES "src/*.cpp")

# Crear ejecutable
add_executable(main ${SOURCES})

# Opcional: Configurar nombre del ejecutable (si quieres mantener 'main')
# set_target_properties(main PROPERTIES OUTPUT_NAME "main")