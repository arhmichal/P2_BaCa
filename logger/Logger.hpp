#pragma once

#include "ArhLogger.hpp"

#define ARHLOG(lvl) Logger::ArhLogger(lvl).getStream(__FILE__, __FUNCTION__, __LINE__)

#define ARHLOG_NOTE ARHLOG(Logger::LoggingLevel_NOTE)
#define ARHLOG_INF ARHLOG(Logger::LoggingLevel_INFO)
#define ARHLOG_DBG ARHLOG(Logger::LoggingLevel_DEBUG)
#define ARHLOG_ERR ARHLOG(Logger::LoggingLevel_ERROR)
#define ARHLOG_CRT ARHLOG(Logger::LoggingLevel_CRITICAL)
