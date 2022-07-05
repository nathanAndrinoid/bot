
#ifndef COIN_H
#define COIN_H


#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "MarketPair.h"

template <class T>
class Coin
{
public:

	int Id = 0;
	std::string Symbol;
	double minSize = 0;
	std::vector<MarketPair<Coin>> QuoteMarkets;
	std::vector<MarketPair<Coin>> BaseMarkets;

	void *pathStep;
	double dollarValue = 0.0;
	double nativeValue0 = 0.0;
	double nativeValue1 = 0.0;
	double nativeValue2 = 0.0;
	double nativeValue3 = 0.0;
	double nativeValue4 = 0.0;
	double nativeValue5 = 0.0;
	//std::vector<std::vector<PathStep*>> bestLinks;
	std::vector<double> bestValues;
	double Balance = 0;
	double rateChange = 0;
	double BalanceInDollars = 0;


	Coin(std::string name, int i) : Symbol(name)
	{

		Id = i;
	}
	//Coin(Coin *sourceCoin, bool deepClone = false);//, std::vector<MarketPair*> &marketPairs = std::vector<MarketPair*>());

	//void CopyIn(Coin *sourceCoin);
};


	// Coin::Coin()
	// {
	//
	//
	// }
	//
	// Coin::Coin(Coin *sourceCoin, bool deepClone)//, std::vector<MarketPair*> *marketPairs)
	// {
	// }
	//
	// void Coin::CopyIn(Coin *sourceCoin)
	// {
	// }

#endif
