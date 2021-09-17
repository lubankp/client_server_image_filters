#include "client.h"

int main(){

    const std::string server_address = "tcp://localhost:12345";
    int step = 0;
   
    try
    {
        Client client(server_address);
        client.run(step);
        
    }
    catch (const std::exception& e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
    std::string key;
    std::getline(std::cin, key);
   
}