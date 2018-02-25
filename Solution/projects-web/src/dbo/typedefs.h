//
// Created by thelazurite on 24/02/18.
//

#include <Wt/Dbo/ptr>

namespace dbo = Wt::Dbo;

class activityToCategory;
class category;
class activityDto;

typedef dbo::collection<dbo::ptr<activityToCategory>> ptrCategoryLinks;
typedef dbo::collection<dbo::ptr<category>> ptrCategories;
typedef dbo::collection<dbo::ptr<activityDto>> ptrActivities;