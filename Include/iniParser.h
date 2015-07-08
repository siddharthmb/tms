#ifndef _INI_PARSER_H
#define _INI_PARSER_H

namespace TakeMyStatus {
    namespace IniParserSpace {
        class IniParser {   // Single-ton class
            public:
                // APIs
                char * readKeyValues(const char * section, const char * key);
                static IniParser * getIniParser(char *);

                // destructor
                ~IniParser();
            private:
                IniParser();

                // members
                static IniParser * _pIniParser;
                char * m_iniFile;
                // sections
                static char * SECTION_LOGPARAMS; //= "[logparams]";
                static char * SECTION_LOGBASE;// = "[logbase]";
                
                // keys
                static char * KEY_LOG_LEVEL;// = "log_level";
        };
    } // end namespace IniParser
} // end namespace TakeMyStatus
#endif
