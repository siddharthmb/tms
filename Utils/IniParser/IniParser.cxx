#include "../../Include/tms.h"

// definitions

char * readKeyValues(const char * pSection, const char * pKey) {
    
    char * pValue = ((void *)0); // NULL

    // read the file line by line and then string compare with the pSection parameter.
    int fdIni = open(m_filename, O_RDONLY);

    if (fdIni == -1) {
        // TODO: continue from here. Integrate log as well.
    }
}


// getIniParser
IniParser * IniParser::getIniParser(char * filename) {
    (_pIniParser == NULL) && (_pIniParser = new IniParser(filename);
    return _pIniParser;
}
