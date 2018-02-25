CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
SET (CMAKE_CXX_STANDARD 14)

PROJECT(PROJECTS_WEB)

set(Boost_STATIC ON)
FIND_PACKAGE (Boost REQUIRED system thread signals filesystem program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    set(libs ${libs}    ${Boost_LIBRARIES})
endif()


SET (WT_CONNECTOR "wtfcgi" CACHE STRING "Connector used (wthttp or wtfcgi)")

ADD_SUBDIRECTORY(src)

INCLUDE_DIRECTORIES(/usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)
