#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "throws.h"


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
            throw Error::ARTICLE_NOT_FOUND;
        }
        else
        {
            int amountOnDatabase = productOnDatabase->second;
            if (amountOnDatabase < inAmount)
            {
                throw Error::NOT_ENOUGH_AMOUNT;
            }   
            auto productOnBasket = basket.find(inArticle);
            if (productOnBasket != basket.end())
            {
                int amountOnBasket = productOnBasket->second;

                if (amountOnDatabase < amountOnBasket + inAmount)
                {
                    throw Error::NOT_ENOUGH_AMOUNT;
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
            throw Error::ARTICLE_NOT_FOUND;
        }
            
        int amountProduct = productOnBasket->second;
        if (amountProduct < inAmount)
        {
            throw Error::NOT_ENOUGH_AMOUNT;
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
            throw Error::ARTICLE_NOT_FOUND;
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