#include "client.h"



int main() {

    const std::string server_address = "tcp://localhost:12345";

    try
    {
        yami::agent client_agent;
       
        Comunication comunication;
        int step = 0;
        
        run(client_agent, comunication, server_address, step);
      
    }
    catch (const std::exception& e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
    std::string key;
    std::getline(std::cin, key);
}