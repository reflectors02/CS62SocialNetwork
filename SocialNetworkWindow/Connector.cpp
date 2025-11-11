#include "Connector.h"
using namespace std;


string run_python(const string& message) 
{
    string cmd = "/opt/anaconda3/envs/Amadeus/bin/python3 Amadeus.py \"" + message + "\"";

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

