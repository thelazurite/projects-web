#ifndef PROJECTSAPPLICATION_H
#define PROJECTSAPPLICATION_H

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>

class ProjectsApplication : public Wt::WApplication
{
    public:
        ProjectsApplication(const Wt::WEnvironment& env);
        virtual ~ProjectsApplication();

    protected:

    private:
    Wt::WLineEdit *nameEdit_;
    Wt::WText *greeting_;

    void greet();

};

#endif // PROJECTSAPPLICATION_H
