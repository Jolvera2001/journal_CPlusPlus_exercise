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

include_directories(
    "${WXWIN}/include"
    "${WXWIN}/lib/vc_x64_lib/${WX_CONFIG}"
    "${CMAKE_SOURCE_DIR}"
)

link_directories("${WXWIN}/lib/vc_x64_lib")

add_definitions(-D__WXMSW__ -DUNICODE -D_UNICODE)

add_executable(journalApp WIN32 
    main.cpp
    JournalApp.cpp
    JournalFrame.cpp
    JournalPanel.cpp
)

target_link_libraries(journalApp
    wxmsw32u${WX_SUFFIX}_core
    wxbase32u${WX_SUFFIX}
    wxmsw32u${WX_SUFFIX}_xrc
    wxbase32u${WX_SUFFIX}_xml
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

configure_file(main.xrc ${CMAKE_BINARY_DIR}/main.xrc COPYONLY)