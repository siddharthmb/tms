#include "../Include/tms.h"

using namespace TakeMyStatus::LoggerSpace;

int main(int argc, char *argv[])
{
    int ret_status = 0;
    Logger * pLogger = Logger::getLogger(5); // will be called with default arguments
    pLogger->fatal("Just testing if working or not!");
    pLogger->critical("Just testing if working or not!");
    pLogger->debug("Just testing if working or not!");
    pLogger->error("Just testing if working or not!");
    pLogger->info("Just testing if working or not!");
    return ret_status;
}
