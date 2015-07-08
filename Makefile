LOGGER_DIR=/home/siddharth/Work/TakeMyStatus/Logger
INIPARSER_DIR=/home/siddharth/Work/TakeMyStatus/Utils/IniParser
DEBUG_DIR=/home/siddharth/Work/TakeMyStatus/Debug
CC=/usr/bin/g++
TakeMyStatusExe: $(LOGGER_DIR)/logger.cxx $(LOGGER_DIR)/testMain.cxx $(INIPARSER_DIR)/iniParser.cxx
	$(CC) -o $(DEBUG_DIR)/statusExe $(LOGGER_DIR)/logger.cxx $(LOGGER_DIR)/testMain.cxx $(INIPARSER_DIR)/iniParser.cxx

