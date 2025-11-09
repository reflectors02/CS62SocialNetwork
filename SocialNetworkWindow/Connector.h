#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
#include <QCoreApplication>


//pre: a string is passed in as parameter
//post: runs the Amadeus.py, the message will be used as argv in the python
std::string run_python(const std::string& message);


//pre: a string user message is passed in as parameter
//post: This function returns whatever python prints in the terminal i.e. response from openrouter
std::string getMessage(std::string user_message);

#endif