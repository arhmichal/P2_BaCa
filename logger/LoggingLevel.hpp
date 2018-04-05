#pragma once

#include <iostream>

namespace Logger
{

enum LoggingLevel
{
    LoggingLevel_NOTE,
    LoggingLevel_INFO,
    LoggingLevel_DEBUG,
    LoggingLevel_ERROR,
    LoggingLevel_CRITICAL
};

}

std::ostream& operator<<(std::ostream& out, enum Logger::LoggingLevel lvl);

