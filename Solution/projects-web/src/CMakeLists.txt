SET(PROJECTS_WEB_SOURCE
        ../program.cpp
        projectsApplication.hpp projectsApplication.cpp
        dbo/typedefs.h
        dbo/category.cpp dbo/category.hpp
        dbo/activityDto.cpp dbo/activityDto.hpp
        dbo/activityToCategory.cpp dbo/activityToCategory.hpp
        dbo/account.cpp dbo/account.hpp
        dbo/user.cpp dbo/user.hpp
        dbo/schemaVersion.cpp dbo/schemaVersion.hpp
        dbo/role.cpp dbo/role.hpp dbo/typedefs.h dbo/dboTraits.h)

SET(PROJECTS_WEB_TARGET ProjectsApplication.wt)
ADD_EXECUTABLE(${PROJECTS_WEB_TARGET} ${PROJECTS_WEB_SOURCE})

set(CMAKE_MODULE_PATH /usr/lib/Wt/cmake)
FIND_PACKAGE(Wt REQUIRED)

FIND_LIBRARY(wt wt wtdbo wtdbosqlite3 wthttp)
add_library(wt STATIC IMPORTED)

set_target_properties(wt PROPERTIES IMPORT_LOCATION Wt)

target_link_libraries(${PROJECTS_WEB_TARGET} ${libs} ${Wt_LIBRARIES})

install (TARGETS ${PROJECTS_WEB_TARGET} RUNTIME DESTINATION ../bin)
