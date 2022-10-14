#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>



class Basket
{
public:
    
    void showDatabase()
    {
        for (auto it = database.begin(); it != database.end(); it++)
        {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }

    void showBasket()
    {
        for (auto it = basket.begin(); it != basket.end(); it++)
        {
            std::cout << it->first << " " << it->second << std::endl;
        }
    }

    void add(std::string& inArticle, int inAmount)
    {
        auto productOnDatabase = database.find(inArticle);
        if (productOnDatabase == database.end())
        {
            throw std::invalid_argument("article");
        }
        else
        {
            int amountOnDatabase = productOnDatabase->second;
            if (amountOnDatabase < inAmount)
            {
                throw std::invalid_argument("amount");
            }   
            auto productOnBasket = basket.find(inArticle);
            if (productOnBasket != basket.end())
            {
                int amountOnBasket = productOnBasket->second;

                if (amountOnDatabase < amountOnBasket + inAmount)
                {
                    throw std::invalid_argument("amount");
                }
                else
                {
                    productOnBasket->second += inAmount;
                    productOnDatabase->second -= inAmount;
                }
            }
            else
            {
                basket.insert(std::make_pair(inArticle, inAmount));
                productOnDatabase->second -= inAmount;
            }
        }   
    }

    void remove(std::string& inArticle, int inAmount)
    {
        auto productOnBasket = basket.find(inArticle);
        if (productOnBasket == basket.end())
        {
            throw std::invalid_argument("article");
        }
            
        int amountProduct = productOnBasket->second;
        if (amountProduct < inAmount)
        {
            throw std::invalid_argument("amount");
        }   
        else
            if (amountProduct == inAmount)
            {
                basket.erase(inArticle);
            }  
            else
            {
                productOnBasket->second -= inAmount;
            }
                
        std::cout << "Product was deleted from basket" << std::endl << std::endl;

        auto productOnDatabase = database.find(inArticle);
        if (productOnDatabase == database.end())
        {
            throw std::runtime_error("ARTICLE NOT FOUND");
        }
        else
        {
            productOnDatabase->second += inAmount;
        }  
    }

    
    
private:
    std::map <std::string, int> database = {{"000001", 10},
                                            {"000002", 9},
                                            {"000003", 8},
                                            {"000004", 10}};

    std::map <std::string, int> basket;
};