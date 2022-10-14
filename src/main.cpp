#include <iostream>
#include <map>
#include <fstream>
#include <boost/asio.hpp>
#include <exception>
#include "basket.h"




int main()
{
    
    Basket basket;
   
    bool exit = false;
    while (!exit)
    {
        system("cls");
        std::cout << "ONLINE STORE" << std::endl;
        basket.showDatabase();
        std::cout << std::endl;
        std::cout << "BASKET" << std::endl;
        basket.showBasket();
        std::cout << std::endl;
        std::cout << "Choose one of action: " << std::endl;
        std::cout << "1. Add product to basket;" << std::endl;
        std::cout << "2. Remove product from basket;" << std::endl;
        std::cout << "0. Exit from shop." << std::endl;

        std::string article = "";
        int amount = 0;
        int chosen;
        std::cin >> chosen;
        if (chosen == 1 || chosen == 2)
        {
            std::cout << "Enter product article:";
            std::cin >> article;
            std::cout << "Enter product amount:";
            std::cin >> amount;
        }
        try
        {
            switch (chosen)
            {
               case 1: basket.add(article, amount);
               {
                 
                   break;
               }
               case 2: basket.remove(article, amount);
               {
                   break;
               }
               case 0: exit = true;                   
               {
                   break;
               }   
               default: throw std::runtime_error("ACTION NOT FOUND");
            }   
        }
        catch (std::invalid_argument err)
        {
            boost::asio::io_context io;
            boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
            std::cout << "Invalid argument: " << err.what() << std::endl;
            
            t.wait();
            exit = false;
        }
        catch (std::runtime_error err)
        {
            boost::asio::io_context io;
            boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
            std::cout << "Runtime_error: " << err.what() << std::endl; 
            
            t.wait();
            exit = false;
        }
    }
}