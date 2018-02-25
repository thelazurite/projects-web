#include "src/projectsApplication.hpp"
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>

int main(int argc, char **argv)
{
    return Wt::WRun(argc,argv, [](const Wt::WEnvironment& env){
        return new projectsApplication(env);
    });
}
