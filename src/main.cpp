#include <iostream>
#include <map>
#include <fstream>
#include <boost/asio.hpp>
#include "basket.h"
#include "throws.h"




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

        int chosen;
        std::cin >> chosen;

        std::string article = "";
        int amount = 0;
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
            case 2: basket.remove(article, amount); break;
            case 0: exit = true;                    break;
            default: std::cout << "! Incorrect choose. Try again !";
            }
        }
        catch (Error myErr)
        {
            boost::asio::io_context io;
            boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
            
            switch (myErr)
            {
            case Error::ARTICLE_NOT_FOUND:
                
                std::cerr << "This article doesn't found" << std::endl;
                
                t.wait();
                break;

            case Error::NOT_ENOUGH_AMOUNT:
                
                std::cerr << "Not enough amount" << std::endl;
                
                t.wait();
                break;
            }
        }
    }
}
