#include "projectsApplication.hpp"
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WEvent>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Sqlite3>
#include "dbo/category.hpp"
#include "dbo/activityDto.hpp"
#include "dbo/activityToCategory.hpp"

namespace dbo = Wt::Dbo;

projectsApplication::projectsApplication(const Wt::WEnvironment& env)
        : Wt::WApplication(env)
{
    setTitle("Hello world");

    connector = new dbo::backend::Sqlite3("derg.db");

    connector->setProperty("show-queries","true");
    createDatabaseSession(session, *connector);

    root()->addWidget(new Wt::WText("Name"));
    nameEdit_ = new Wt::WLineEdit();
    root()->addWidget(nameEdit_);
    root()->addWidget(new Wt::WBreak());

    root()->addWidget(new Wt::WText("Description"));
    descriptionEdit_ = new Wt::WLineEdit();
    root()->addWidget(descriptionEdit_);
    root()->addWidget(new Wt::WBreak());
    
    Wt::WPushButton *button_ = new Wt::WPushButton("submit");
    root()->addWidget(button_);

    root()->addWidget(new Wt::WBreak());

    debugText_ = new Wt::WText();
    root()->addWidget(debugText_);
    button_->clicked().connect(this, &projectsApplication::addCategory);

}

void projectsApplication::createDatabaseSession(dbo::Session &session, dbo::backend::Sqlite3 &sqlite3, bool addSchema) const {
    session.setConnection(sqlite3);
    session.mapClass<category>(category::typeName);
    session.mapClass<activityDto>(activityDto::typeName);
    session.mapClass<activityToCategory>(activityToCategory::typeName);
    if(addSchema) session.createTables();
}

projectsApplication::~projectsApplication()
{
    //dtor
}

void projectsApplication::addCategory() {

    std::cout << connector->connection() << std::endl;

    dbo::Transaction dataUpdate(session);
    dbo::ptr<category> cat = session.add(new category());

    cat.modify()->name = nameEdit_->text().toUTF8();
    cat.modify()->description = descriptionEdit_->text().toUTF8();
    dataUpdate.commit();

    refreshData();
}

void projectsApplication::refreshData()
{
    auto *refreshSession = new dbo::Session();
    createDatabaseSession(*refreshSession, *connector, false);
    dbo::Transaction dataRefresh(*refreshSession);

    debugText_->setText("");

    const ptrCategories &collection = refreshSession->find<category>().resultList();

    for(const dbo::ptr<category> &ptr : collection)
    {
        debugText_->setText(debugText_->text() + "\n<br/>" + ptr->name + " : " + ptr->description);
    }

    dataRefresh.commit();
}