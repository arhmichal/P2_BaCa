#include "LoggingLevel.hpp"

std::ostream& operator<<(std::ostream& out, enum Logger::LoggingLevel lvl)
{
    switch (lvl)
    {
        case Logger::LoggingLevel_NOTE: out << "NOTE";
            break;
        case Logger::LoggingLevel_INFO: out << "INF";
            break;
        case Logger::LoggingLevel_DEBUG: out << "DBG";
            break;
        case Logger::LoggingLevel_ERROR: out << "ERR";
            break;
        case Logger::LoggingLevel_CRITICAL: out << "CRI";
            break;
    }
    return out << "/";
}
