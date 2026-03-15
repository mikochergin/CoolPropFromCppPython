cmake_minimum_required(VERSION 3.14)
project(GasProcessingSimulator)

# Подключаем модуль FetchContent
include(FetchContent)

# Объявляем откуда качать CoolProp
FetchContent_Declare(
    CoolProp
    GIT_REPOSITORY https://github.com/CoolProp/CoolProp.git
    GIT_TAG        v6.4.3 # Укажите нужную стабильную версию
)

# Отключаем сборку динамической библиотеки и тестов CoolProp, 
# чтобы ускорить компиляцию и не тащить лишнее
set(COOLPROP_SHARED_LIBRARY OFF CACHE BOOL "Build shared library" FORCE)
set(COOLPROP_STATIC_LIBRARY ON CACHE BOOL "Build static library" FORCE)

# Скачиваем и делаем доступным для линковки
FetchContent_MakeAvailable(CoolProp)

# Ваш исполняемый файл или библиотека ядра
add_executable(ClientCpp ../src/client.cpp)

# Линкуем CoolProp к вашему таргету
target_link_libraries(ClientCpp PRIVATE CoolProp)