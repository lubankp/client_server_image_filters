#include "client.h"
#include "yami.h"

int main(){

    const std::string server_address = "tcp://localhost:12345";
    int step = 0;
   
    try
    {
        Client<yami::parameters, yami::agent, yami::message_state> client(server_address, yami::replied, yami::rejected);
        client.run(step);
        
    }
    catch (const std::exception& e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
    std::string key;
    std::getline(std::cin, key);
   
}