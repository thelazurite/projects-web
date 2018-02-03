SET(WT_PROJECT_SOURCE
        ProjectsApplication.h
        ProjectsApplication.cpp
)

SET(WT_PROJECT_TARGET ProjectsApplication.wt)

ADD_EXECUTABLE(${WT_PROJECT_TARGET} ${WT_PROJECT_SOURCE})