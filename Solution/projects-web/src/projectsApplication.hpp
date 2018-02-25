#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/Session>
#include <Wt/Dbo/backend/Sqlite3>
#include "dbo/typedefs.h"

namespace dbo = Wt::Dbo;

class projectsApplication : public Wt::WApplication
{
    public:
        projectsApplication(const Wt::WEnvironment& env);
        virtual ~projectsApplication();

    protected:

    private:
    Wt::WLineEdit *nameEdit_;
    Wt::WLineEdit *descriptionEdit_;
    Wt::WText *debugText_;

    dbo::Session session;
    dbo::backend::Sqlite3 *connector;

    void createDatabaseSession(dbo::Session &session, dbo::backend::Sqlite3 &sqlite3, bool addSchema = true) const;
    void addCategory();
    void refreshData();
};
