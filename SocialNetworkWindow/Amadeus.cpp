#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
using namespace std;


string run_python(const string& message) 
{
    const string cmd = "python3 script.py \"" + message + "\"";

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

void getMessage(string user_message)
{
    string output = run_python(user_message);
    cout << "Python says: " << output << endl;
}


int main() 
{
    string message;
    do
    {
        getline(std::cin, message);
        if(message == "-1")
        {
            return 1;
        }
        getMessage(message);

    }
    while(message != "-1");
}