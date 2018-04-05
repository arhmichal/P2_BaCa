#pragma once

#include <string>
#include <ctime>

#include "LoggingLevel.hpp"

namespace Logger
{

class ArhLogger
{
public:
    ArhLogger(LoggingLevel lvl)
        : lvl(lvl), stream(std::cerr) { }

    virtual ~ArhLogger()
    {
        stream << '\n';
        stream.flush();
    }

    std::string getTimestampString() const
    {
        char buff[20];
        struct tm* sTm;

        time_t now = time(0);
        sTm = gmtime(&now);

        strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
        return std::string(buff);
    }

    std::ostream& getStream(const std::string& fileName, const std::string& functionName, int lineNumber)
    {

        return stream << getTimestampString() << " " << lvl << " " << fileName << ":" << lineNumber << " "
                      << functionName << "()";
    }

private:
    enum LoggingLevel lvl;
    std::ostream& stream;

};

}
