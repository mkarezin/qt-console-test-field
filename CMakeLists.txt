cmake_minimum_required(VERSION 3.14)

project(qt-console-test-field LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(targetName qt-console-test-field)
set(testTargetName test-${targetName})
list(APPEND includePaths "${CMAKE_SOURCE_DIR}/inc")
list(APPEND sources ${CMAKE_SOURCE_DIR}/src/main.cpp
                    ${CMAKE_SOURCE_DIR}/src/logger.cpp
                    ${CMAKE_SOURCE_DIR}/src/test-qstring.cpp)
list(APPEND testSources ${CMAKE_SOURCE_DIR}/src/test-main.cpp
                        ${CMAKE_SOURCE_DIR}/src/test-of-test-qstring.cpp
                        ${CMAKE_SOURCE_DIR}/inc/test-of-test-qstring.h
                        ${CMAKE_SOURCE_DIR}/src/test-qstring.cpp
                        ${CMAKE_SOURCE_DIR}/src/test-gui.cpp
                        ${CMAKE_SOURCE_DIR}/inc/test-gui.h)
list(APPEND testIncludePaths "${CMAKE_SOURCE_DIR}/inc")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(${targetName} ${sources})
target_link_libraries(${targetName} Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(${targetName} PRIVATE ${includePaths})

add_executable(${testTargetName} ${testSources})
target_link_libraries(${testTargetName} Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(${testTargetName} Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(${testTargetName} Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(${testTargetName} PRIVATE ${testIncludePaths})

include(GNUInstallDirs)
install(TARGETS ${targetName}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
