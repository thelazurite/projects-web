#include "ProjectsApplication.h"
#include <Wt/WText.h>
#include <c++/bits/unique_ptr.h>

ProjectsApplication::ProjectsApplication(const Wt::WEnvironment& env)
        : Wt::WApplication(env)
{
    setTitle("Hello world");

    root()->addWidget(std::make_unique<Wt::WText>("Enter a name"));
    nameEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    Wt::WPushButton *button = root()->addWidget(std::make_unique<Wt::WPushButton>("Submit"));
    root()->addWidget(std:make_unique<Wt::WBreak>());
    greeting_ = root()->addWidget(std::make_unique<Wt::WText>());
    button->clicked().connect(this, [this](){
        greeting_->setText("Submitted:" + nameEdit_->text());
    });
}
ProjectsApplication::~ProjectsApplication()
{
    //dtor
}
