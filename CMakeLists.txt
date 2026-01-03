cmake_minimum_required(VERSION 3.31.1)
project(JournalApp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WXWIN "C:/wxwidgets/wxWidgets-3.2.9")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(WX_CONFIG "mswud")
    set(WX_SUFFIX "d")
else()
    set(WX_CONFIG "mswu")
    set(WX_SUFFIX "")
endif()

add_definitions(-D__WXMSW__ -DUNICODE -D_UNICODE)

add_executable(journalApp WIN32 
    src/main.cpp
    src/JournalApp.cpp
    src/JournalFrame.cpp
    src/JournalPanels.cpp

    src/models/JournalEntryModel.h

    external/sqlite3.c
    external/sqlite3.h
    external/json.hpp
)

target_include_directories(journalApp PRIVATE
    "${WXWIN}/include"
    "${WXWIN}/lib/vc_x64_lib/${WX_CONFIG}"
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/assets"
    "${CMAKE_SOURCE_DIR}/external"
)

target_link_directories(journalApp PRIVATE "${WXWIN}/lib/vc_x64_lib")

target_link_libraries(journalApp
    wxmsw32u${WX_SUFFIX}_core
    wxbase32u${WX_SUFFIX}
    wxmsw32u${WX_SUFFIX}_xrc
    wxbase32u${WX_SUFFIX}_xml
    wxmsw32u${WX_SUFFIX}_html
    wxpng${WX_SUFFIX}
    wxjpeg${WX_SUFFIX}
    wxtiff${WX_SUFFIX}
    wxzlib${WX_SUFFIX}
    wxregexu${WX_SUFFIX}
    wxexpat${WX_SUFFIX}
    comctl32
    rpcrt4
    winmm
    advapi32
    wsock32
)

configure_file(assets/main.xrc ${CMAKE_BINARY_DIR}/main.xrc COPYONLY)