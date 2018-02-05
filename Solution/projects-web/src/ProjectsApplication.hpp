#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>

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
