SET(WT_PROJECT_SOURCE
        ../program.cpp
        ProjectsApplication.hpp
        ProjectsApplication.cpp
)

SET(WT_PROJECT_TARGET ProjectsApplication.wt)
ADD_EXECUTABLE(${WT_PROJECT_TARGET} ${WT_PROJECT_SOURCE})

set(CMAKE_MODULE_PATH /usr/lib/Wt/cmake)
FIND_PACKAGE(Wt REQUIRED)

FIND_LIBRARY(wt wt wthttp)
add_library(wt STATIC IMPORTED)
set_target_properties(wt PROPERTIES IMPORT_LOCATION ${Wt})

target_link_libraries(${WT_PROJECT_TARGET}
        ${libs}
        ${Wt_LIBRARIES})
message(${libs})