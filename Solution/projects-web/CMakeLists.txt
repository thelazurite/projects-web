CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
PROJECT(projects-web)

FIND_PACKAGE(Boost COMPONENTS system thread signals)
FIND_LIBRARY(wt wt)
FIND_LIBRARY(wthttp wthttp)

SET (CMAKE_CXX_STANDARD 14)
SET (WT_CONNECTOR "wtfcgi" CACHE STRING "Connector used (wthttp or wtfcgi)")

ADD_SUBDIRECTORY(src)

ADD_EXECUTABLE(projects-web program.c)
