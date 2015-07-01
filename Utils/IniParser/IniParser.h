#ifndef _INI_PARSER_H
#define _INI_PARSER_H

namespace TakeMyStatus {
    namespace IniParserSpace {
        class IniParser {
            public:
                // APIs
                char * readKeyValues(const char * section, const char * key);

                // sections
                static const char SECTION_LOGPARAMS[] = "[logparams]";
                static const char SECTION_LOGBASE[] = "[logbase]";
                
                // keys
                static const char KEY_LOG_LEVEL[] = "log_level";
        };
    } // end namespace IniParser
} // end namespace TakeMyStatus
#endif
