#include <iostream>
#include <cstdlib>
#include "klient.h"
#include "yami.h"
#include <string>


int main(){

    const std::string server_address = "tcp://localhost:12345";

    try
    {
        yami::agent client_agent;

        yami::parameters params;

        bool getNumbers = true;
        std::string a;
        std::string b;
        int a_num;
        int b_num;
       

            std::getline(std::cin, a);
            a_num = std::stoi(a);
            std::getline(std::cin, b);
            b_num = std::stoi(b);

        

            params.set_integer("a", a_num);
            params.set_integer("b", b_num);
        
            std::unique_ptr<yami::outgoing_message> om(client_agent.send(server_address, "printer", "print", params, 0, true));
            om->wait_for_completion();

            
                const yami::message_state state = om->get_state();

                if (state == yami::replied)
                {
                    const yami::parameters& reply = om->get_reply();

                    int sum = reply.get_integer("sum");
                    int difference = reply.get_integer("difference");
                    int product = reply.get_integer("product");

                    int ratio;
                    yami::parameter_entry ratio_entry;
                    const bool ratio_defined = reply.find("ratio", ratio_entry);
                    if (ratio_defined)
                    {
                        ratio = ratio_entry.get_integer();
                    }
                    std::cout << "sum        = " << sum << '\n';
                    std::cout << "difference = " << difference << '\n';
                    std::cout << "product    = " << product << '\n';
                    std::cout << "ratio      = ";
                    if (ratio_defined)
                    {
                        std::cout << ratio;
                    }
                    else
                    {
                        std::cout << "<undefined>";
                    }


                }
                else if (state == yami::rejected)
                {
                    std::cout << "The message has been rejected: " << om->get_exception_msg();

                }
                else
                {
                    std::cout << "The message has been abandoned.";
                }

                std::cout << std::endl;

            
    }
    catch (const std::exception& e)
    {
        std::cout << "error: " << e.what() << std::endl;
    }
    std::string key;
    std::getline(std::cin, key);
}