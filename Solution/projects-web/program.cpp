#include "src/ProjectsApplication.hpp"

ProjectsApplication *createApplication(const Wt::WEnvironment& env)
{
    return new ProjectsApplication(env);
}
int main(int argc, char **argv)
{
    return Wt::WRun(argc,argv, &createApplication);
}
