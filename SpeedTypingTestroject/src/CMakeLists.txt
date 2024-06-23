# Укажите директорию заголовочных файлов
include_directories(${PROJECT_SOURCE_DIR}/include)

# Укажите все исходные файлы проекта
set(SOURCES
    main.cpp
    Window.cpp
    TypingTest.cpp
)

# Создайте исполняемый файл
add_executable(TypingSpeedTest ${SOURCES})