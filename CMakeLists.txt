cmake_minimum_required(VERSION 3.10)
project(EgyetemiNyilvantarto)

# 1. C++ Standard beállítása (c++11-nek felel meg)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Fordítási zászlók (Flags) beállítása
# -Wall: Összes figyelmeztetés
# -Wextra: Extra figyelmeztetések
# -Werror: A figyelmeztetéseket hibának tekinti (nem enged fordítani, ha gyanús a kód)
# -g: Debug információk (hibakereséshez)
if(MSVC)
    # Ha véletlenül Visual Studio-val fordítanál
    add_compile_options(/W4 /WX /Zi)
else()
    # G++ vagy Clang esetén
    add_compile_options(-Wall -Wextra -Werror -g)
endif()

# 3. Globális definíciók
add_definitions(-DMEMTRACE)

# 4. Fejlécek helye
include_directories(include)

# 5. Forrásfájlok
set(SOURCES 
    src/main.cpp 
    src/Szemely.cpp 
    src/Hallgato.cpp 
    src/Oktato.cpp 
    src/Parser.cpp 
    src/Menu.cpp
    src/memtrace.cpp
)

# 6. Futtatható állomány létrehozása
add_executable(program.exe ${SOURCES})
