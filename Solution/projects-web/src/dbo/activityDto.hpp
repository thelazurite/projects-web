//
// Created by thelazurite on 23/02/18.
//

#ifndef PROJECTS_WEB_ACTIVITY_HPP
#define PROJECTS_WEB_ACTIVITY_HPP

#include <Wt/Dbo/Dbo>
#include <Wt/WDateTime>
#include "typedefs.h"

namespace dbo = Wt::Dbo;

class activityDto {
public:
    static const char*  typeName;
    std::string         name;
    std::string         description;
    int                 priority;
    Wt::WDateTime       startDate;
    Wt::WDateTime       endDate;
    ptrCategoryLinks       post;

    template<class Action>
    void persist(Action &a) {
        dbo::field(a, name, "name");
        dbo::field(a, description, "description");
        dbo::field(a, priority, "priority");
        dbo::field(a, startDate, "startDate");
        dbo::field(a, endDate, "endDate");
        dbo::hasMany(a, post, dbo::ManyToOne, typeName);
    }
};


#endif //PROJECTS_WEB_ACTIVITY_HPP
