#pragma once

#include <string>

namespace strSet
{
const std::string empty = "empty";
const std::string allZero = "00000";
const std::string allOne = "11111";
const std::string alternateFrom0 = "01010";
const std::string alternateFrom1 = "10101";
const std::string custom10010 = "10010";
const std::string custom01101 = "01101";
const std::string custom11001 = "11001";
const std::string custom10011 = "10011";
const std::string custom00110 = "00110";
const std::string custom01110 = "01110";
const std::string custom00101 = "00101";
const std::string custom11000 = "11000";
const std::string elem4 = "10000";
const std::string elem3 = "01000";
const std::string elem2 = "00100";
const std::string elem1 = "00010";
const std::string elem0 = "00001";
const std::string notElem0 = "11110";
const std::string notElem1 = "11101";
const std::string notElem2 = "11011";
const std::string notElem3 = "10111";
const std::string notElem4 = "01111";
}

namespace intSet
{
const int invalid = 0b100000;
const int allZero = 0b00000;
const int allOne = 0b11111;
const int alternateFrom0 = 0b01010;
const int alternateFrom1 = 0b10101;
const int custom10010 = 0b10010;
const int custom01101 = 0b01101;
const int custom11001 = 0b11001;
const int custom10011 = 0b10011;
const int custom00110 = 0b00110;
const int custom01110 = 0b01110;
const int custom00101 = 0b00101;
const int custom11000 = 0b11000;
const int custom10001 = 0b10001;
const int custom01001 = 0b01001;
const int elem4 = 0b10000;
const int elem3 = 0b01000;
const int elem2 = 0b00100;
const int elem1 = 0b00010;
const int elem0 = 0b00001;
const int notElem0 = 0b11110;
const int notElem1 = 0b11101;
const int notElem2 = 0b11011;
const int notElem3 = 0b10111;
const int notElem4 = 0b01111;
}

namespace whitespaces
{
const std::string empty = "";
const std::string noise = "   \t \t\t    \n   \r\n   \n\r  \n\n\r\n   \r\r\r\n\n\n\r\r  \t\t\t    ";
}
