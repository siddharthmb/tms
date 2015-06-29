#ifndef _LOGGER_H_
#define _LOGGER_H_
#include <fcntl.h>
#include <iostream>
#include <string.h>
/*
	* 0 --> no logs
	* 1 --> Fatal
	* 2 --> Critical
	* 3 --> Error
	* 4 --> Info
	* 5 --> Debug
*/
namespace TakeMyStatus {

    namespace LoggerSpace {

        class Logger {

            public:        
                static Logger * getLogger(int level = 3, std::string = "./log.txt"); // Logger will be a single-ton. We don't need multiple of 'em.
                void fatal(const char * msg);
                void critical(const char * msg);
                void error(const char * msg);                
                void info(const char * msg);
                void debug(const char * msg);
                static Logger * _pLogInstance;
            private:
                Logger(int, std::string);
                ~Logger();
                static void updateDateTime(void);
                std::string m_filename;
                int m_fd;
                int m_logLevel;
                static time_t dateTime;
        };
    }
}

#endif
