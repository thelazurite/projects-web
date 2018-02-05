#include "ProjectsApplication.hpp"
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WEvent>
using namespace Wt;

ProjectsApplication::ProjectsApplication(const Wt::WEnvironment& env)
        : Wt::WApplication(env)
{
    setTitle("Hello world");

    root()->addWidget(new Wt::WText("Enter a name"));
    nameEdit_ =new Wt::WLineEdit();
    root()->addWidget(nameEdit_);

    Wt::WPushButton *button_ = new Wt::WPushButton("submit");
    root()->addWidget(button_);

    root()->addWidget(new Wt::WBreak());

    greeting_ = new Wt::WText();
    root()->addWidget(greeting_);

    button_->clicked().connect(this,&ProjectsApplication::greet);

}
ProjectsApplication::~ProjectsApplication()
{
    //dtor
}

void ProjectsApplication::greet()
{
    /*
     * Update the text, using text input into the nameEdit_ field.
     */
    greeting_->setText("Hello there, " + nameEdit_->text());
}
