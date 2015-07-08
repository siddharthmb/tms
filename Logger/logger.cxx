#include "../Include/tms.h"
// TODO: make the logger class thread safe
// file contains the definitions of all the logging functions.

namespace TakeMyStatus {
    namespace LoggerSpace {

        Logger * Logger::_pLogInstance = NULL;
        time_t Logger::dateTime = time(NULL);

        // constructor
        Logger::Logger(int level = 3, std::string logFile = "./log.txt") :
            m_logLevel(level)
            , m_filename(logFile) {
                m_fd = creat(logFile.c_str(), 0666);
                std::cout << "\nLog level set to " << m_logLevel << std::endl;
                if (m_fd == -1) {
                    std::cout << "\nCouldn't create log file: " << logFile << std::endl;
                }
                else
                    std::cout << "\nSuccessfully created log file: " << logFile <<std::endl;
            }

        // destructor
        Logger::~Logger() {
            close(m_fd);
        }

        // updateDateTime
        void Logger::updateDateTime(void) {
            dateTime = time(NULL);
            if (dateTime == ((time_t)-1)) {
                // getting current date time failed.
            }
        }

        // getLogger
        Logger * Logger::getLogger(int level, std::string filename) {
            if (_pLogInstance == NULL) {
                _pLogInstance = new Logger(level, filename);
            }
            return _pLogInstance;
        }

        // fatal: level = 1
        void Logger::fatal(const char * msg) {
            if (m_logLevel >= 1) {
                char logmsg[2048];
                char newline = '\n';
                strcpy(logmsg, (char *)ctime(&dateTime));
                // remove the \n that is returned by the ctime()
                logmsg[strlen(logmsg) - 1] = '\0';
                // attach message type
                strcat(logmsg," FATAL: ");
                strcat(logmsg,msg);

                // write to file
                if (write(m_fd, logmsg, strlen(logmsg)) == 0) {
                    std::cout << "\nFailed to log message: " << msg;
                }
                if (write(m_fd, &newline, 1) == 0) {
                    std::cout << "\nFailed to write new line character to log file!";
                }
            }
        }

        // critical: level = 2
        void Logger::critical(const char * msg) {
            if (m_logLevel >= 2) {
                char logmsg[2048];
                char newline = '\n';
                strcpy(logmsg, (char *)ctime(&dateTime));
                // remove the \n that is returned by the ctime()
                logmsg[strlen(logmsg) - 1] = '\0';
                // attach message type
                strcat(logmsg," CRITICAL: ");
                strcat(logmsg,msg);

                // write to file
                if (write(m_fd, logmsg, strlen(logmsg)) == 0) {
                    std::cout << "\nFailed to log message: " << msg;
                }
                if (write(m_fd, &newline, 1) == 0) {
                    std::cout << "\nFailed to write new line character to log file!";
                }
            }
        }

        // error: level = 3
        void Logger::error(const char * msg) {
            if (m_logLevel >= 3) {
                char logmsg[2048];
                char newline = '\n';
                strcpy(logmsg, (char *)ctime(&dateTime));
                // remove the \n that is returned by the ctime()
                logmsg[strlen(logmsg) - 1] = '\0';
                // attach message type
                strcat(logmsg," ERROR: ");
                strcat(logmsg,msg);

                // write to file
                if (write(m_fd, logmsg, strlen(logmsg)) == 0) {
                    std::cout << "\nFailed to log message: " << msg;
                }
                if (write(m_fd, &newline, 1) == 0) {
                    std::cout << "\nFailed to write new line character to log file!";
                }
            }
        }

        // info: level = 4
        void Logger::info(const char * msg) {
            if (m_logLevel >= 4) {
                char logmsg[2048];
                char newline = '\n';
                strcpy(logmsg, (char *)ctime(&dateTime));
                // remove the \n that is returned by the ctime()
                logmsg[strlen(logmsg) - 1] = '\0';
                // attach message type
                strcat(logmsg," INFO: ");
                strcat(logmsg,msg);

                // write to file
                if (write(m_fd, logmsg, strlen(logmsg)) == 0) {
                    std::cout << "\nFailed to log message: " << msg;
                }
                if (write(m_fd, &newline, 1) == 0) {
                    std::cout << "\nFailed to write new line character to log file!";
                }
            }
        }

        // debug: level = 5
        void Logger::debug(const char * msg) {
            if (m_logLevel == 5) {
                char logmsg[2048];
                char newline = '\n';
                strcpy(logmsg, (char *)ctime(&dateTime));
                // remove the \n that is returned by the ctime()
                logmsg[strlen(logmsg) - 1] = '\0';
                // attach message type
                strcat(logmsg," DEBUG: ");
                strcat(logmsg,msg);

                // write to file
                if (write(m_fd, logmsg, strlen(logmsg)) == 0) {
                    std::cout << "\nFailed to log message: " << msg;
                }
                if (write(m_fd, &newline, 1) == 0) {
                    std::cout << "\nFailed to write new line character to log file!";
                }
            }
        }
    } // end Logger namespace
} // end TakeMyStatus namespace
