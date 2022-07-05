#include <iostream>
#include <cbpro++/auth.h>
#include <cbpro++/marketdata/products.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <string>
#include <mutex>
#include <unordered_map>
#include "include/Coin.h"
#include "include/CoinbaseRobotCpp.h"


int main()
{
  std::unordered_map<std::string,Coin<std::string>> coinDict;

    Coin<string> coinADA("ADA", 1);
      Coin<string> coinUSD("USD", 2);

  MarketPair mp("ADA-USD",coinADA,coinUSD);

  coinADA.QuoteMarkets.push_back(mp);

  std::pair<std::string,Coin<std::string>> pair("ADA",coinADA);
  coinDict.insert( pair);

  for (auto item : coinDict)
  {
    for (auto m : item.second.QuoteMarkets)
    {
      cout << "market " << m.Symbol << " " << m.QuoteCurrency.Symbol << " to " << m.BaseCurrency.Symbol << endl;
    }
    cout << " name " << item.first << endl;

  }

  //  std::pair<std::string,double> myshopping ("baking powder",0.3);

  //  myrecipe.insert (myshopping);                        // copy insertion
  //  myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0));


  std::cout << "Start "  <<  std::endl;



CoinbaseRobotCpp coinBot(&coinDict);

  std::cout << "Done" << std::endl;



  return 0;
}
