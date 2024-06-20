cmake_minimum_required(VERSION 3.14)

project(qt-console-test-field LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(targetName qt-console-test-field)
list(APPEND includePaths "${CMAKE_SOURCE_DIR}/inc")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(${targetName}
  ${CMAKE_SOURCE_DIR}/src/main.cpp
)
target_link_libraries(${targetName} Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(${targetName} PRIVATE ${includePaths})

include(GNUInstallDirs)
install(TARGETS ${targetName}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
