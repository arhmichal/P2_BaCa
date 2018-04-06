#pragma once

#include <iostream>
#include <string>
#include <cstdarg>

#include "Logger.hpp"

#include "VariadicArgsUtils.hpp"

std::string Sum(int, const std::string*);
std::string Sum(int, ...);
void Sum(std::string*, int, const std::string*);
void Sum(std::string*, int, ...);
void Sum(std::string&, int, const std::string*);
void Sum(std::string&, int, ...);

std::string Mult(int, const std::string*);
std::string Mult(int, ...);
void Mult(std::string*, int, const std::string*);
void Mult(std::string*, int, ...);
void Mult(std::string&, int, const std::string*);
void Mult(std::string&, int, ...);

std::string Operation(std::string(*)(int, const std::string*), int, const std::string*);
std::string Operation(std::string(*)(int, const std::string*), int, ...);
void Operation(std::string*, std::string(*)(int, const std::string*), int, const std::string*);
void Operation(std::string*, std::string(*)(int, const std::string*), int, ...);
void Operation(std::string&, void(*)(std::string*, int, const std::string*), int, const std::string*);
void Operation(std::string&, void(*)(std::string*, int, const std::string*), int, ...);
