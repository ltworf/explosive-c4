project(explosive-c4)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(explosive-c4_SRCS explosive-c4.cpp main.cpp)
qt4_automoc(${explosive-c4_SRCS})
add_executable(explosive-c4 ${explosive-c4_SRCS})
target_link_libraries(explosive-c4 ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS explosive-c4 RUNTIME DESTINATION bin)
