//
// Created by thelazurite on 24/02/18.
//


#include <Wt/Dbo/Dbo>
#include "category.hpp"
#include "activityDto.hpp"

namespace dbo = Wt::Dbo;

class activityToCategory {
public:
    static const char* typeName;
    dbo::ptr<category> cat;
    dbo::ptr<activityDto> act;

    template<class Action>
    void persist(Action &a) {
        dbo::belongsTo(a, cat, category::typeName);
        dbo::belongsTo(a, act, activityDto::typeName);
    }
};

typedef dbo::collection<dbo::ptr<activityToCategory>> ptrCategoryLinks;

    