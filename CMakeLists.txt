cmake_minimum_required(VERSION 3.10)

# Proje ismi
project(snake_game C)

# C standartını belirtiyoruz
set(CMAKE_C_STANDARD 99)

# SDL2 paketini buluyoruz
find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)

# SDL2 ve include klasörlerini ekliyoruz
include_directories(${SDL2_INCLUDE_DIRS} include)

# Kaynak dosyaları tanımlıyoruz
set(SOURCES main.c src/food.c src/snake.c src/game.c src/window.c)

# Çıktı dosyasını oluşturuyoruz ve kaynak dosyaları ekliyoruz
add_executable(snake_game ${SOURCES})

# SDL2 kütüphanelerini ekliyoruz
target_include_directories(snake_game PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(snake_game PRIVATE ${SDL2_LIBRARIES})

