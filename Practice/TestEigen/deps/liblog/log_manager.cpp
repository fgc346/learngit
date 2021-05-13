#include "log_manager.h"
#include <unistd.h>
#include <string>

log_manager::log_manager()
{}
log_manager::~log_manager()
{
	log_.ClsFile( "EigenDemoClient" );
}
int log_manager::init()
{
    log_.InitLog( true, vts::log::LEVEL_INFO );
    char name[256];
    gethostname(name, sizeof(name));
    std::string logName( "EigenDemoClient_");
    logName = logName +name;
    log_.CrtFile( logName.c_str() );
    // log_.StartUpLoad( vts::log::TCP, "10.0.104.86:10086", "" );

	return 0;
}
