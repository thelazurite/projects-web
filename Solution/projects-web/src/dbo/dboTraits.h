//
// Created by thelazurite on 25/02/18.
//

#ifndef PROJECTS_WEB_DBOTRAITS_H
#define PROJECTS_WEB_DBOTRAITS_H

#include <Wt/Dbo/ptr>
#include "category.hpp"

namespace Wt {
    namespace Dbo {

        template<>
        struct dbo_traits<category> : public dbo_default_traits {
            static const char *versionField() {
                return 0;
            }
        };

    }
}
#endif //PROJECTS_WEB_DBOTRAITS_H
