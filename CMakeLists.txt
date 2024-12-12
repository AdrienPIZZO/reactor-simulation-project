cmake_minimum_required(VERSION 3.16)

project(Reactor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR}Charts)

set(PROJECT_SOURCES
    src/main.cpp
    src/reactorwindow.cpp
    src/reactorwindow.h
    src/reactor.cpp
    src/reactor.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Reactor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Reactor SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Reactor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Reactor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts)

if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Reactor)
endif()

set_target_properties(Reactor PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Reactor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Reactor)
endif()


#TESTS
enable_testing()

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Widgets Charts)

# Test window
add_executable(QTReactorWindowTests
    tests/TestReactorWindow.cpp
    tests/TestReactorWindow.h
    src/reactorwindow.cpp
    src/reactorwindow.h
    src/reactor.cpp
    src/reactor.h
)
target_link_libraries(QTReactorWindowTests PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts)
add_test(NAME QTReactorWindowTests COMMAND QTReactorWindowTests)

# Test reactor
add_executable(QTReactorTests
    tests/TestReactor.cpp
    tests/TestReactor.h
    src/reactor.cpp
    src/reactor.h
)
target_link_libraries(QTReactorTests PRIVATE Qt${QT_VERSION_MAJOR}::Test)
add_test(NAME QTReactorTests COMMAND QTReactorTests)
