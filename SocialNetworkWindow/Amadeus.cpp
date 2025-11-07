#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
#include <QCoreApplication>
using namespace std;


string run_python(const string& message) 
{
    // Build the command with absolute script path
    const string cmd = "/opt/anaconda3/bin/python3 script.py \"" + message + "\"";

    array<char, 128> buffer{};
    string result;

    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "ERROR";

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) 
    {
        result += buffer.data();
    }

    pclose(pipe);
    return result;
}

string getMessage(string user_message)
{
    string output = run_python(user_message);
    return output;
}


// int main()
// {
//     string message;
//     do
//     {
//         getline(std::cin, message);
//         if(message == "-1")
//         {
//             return 1;
//         }
//         getMessage(message);

//     }
//     while(message != "-1");
// }
