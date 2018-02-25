//
// Created by thelazurite on 23/02/18.
//

#ifndef PROJECTS_WEB_CATEGORY_HPP
#define PROJECTS_WEB_CATEGORY_HPP


#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/Types>
#include <Wt/Dbo/WtSqlTraits>
#include "typedefs.h"

namespace dbo = Wt::Dbo;

class category {
public:
    static const char* typeName;
    std::string name;
    std::string description;
    ptrCategoryLinks post;

    template<class Action>
    void persist(Action &a) {
        dbo::field(a, name, "name");
        dbo::field(a, description, "description");
        dbo::hasMany(a, post, dbo::ManyToOne, typeName);
    }
};

#endif
