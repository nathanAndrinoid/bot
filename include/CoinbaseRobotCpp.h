
#ifndef COINBASECPP_H
#define COINBASECPP_H

// #include "Models/MarketRate.h"
// #include "Models/MarketRateState.h"
// #include "Models/Coin.h"
// #include "Models/MarketPair.h"
// #include "Models/MapValue.h"
// #include "Models/MarketData.h"

#include <string>
#include <unordered_map>
#include <vector>
#include <chrono>
#include "Coin.h"

using namespace std;

	class CoinbaseRobotCpp
	{
	private:
		const std::unordered_map<std::string,Coin<std::string>>* coinDict;
		int marketCount = 0;
		bool Running = false;
		time_t appStartTime;
		//CancellationTokenSource *tokenSource;
		//CancellationToken ct;
		//std::unordered_map<std::wstring, MarketRate*> marketRateDict;
		//MarketRateState *marketRateState;
		//std::vector<Coin*> coins;
		//std::unordered_map<int, Coin*> coinDict;
		//std::unordered_map<int, MarketPair*> marketDict;
		//std::vector<MarketPair*> marketPairArray;.
		//BinaryFormatter *binaryFormatter;
		//MapValue *dValueMap;
		//std::vector<MarketRate*> marketRates;
		//MarketData *marketData;
		//std::vector<Coin*> coinArray;

		const std::string API_KEY = "2e506aa3ec83fb4164e50b79ff0a7fd4";
		const std::string API_SECRET = "YN3Zf9zH+zdi53MiKBmjWq267/j+BZQkVt/RXUNyTW+jj2TzT5m58XgTuH1LAvzApvQeaOPkZ7aOhu5WkS828A==";
		const std::string API_PASSPHRASE = "tzi4cbvjyt";

	public:


		CoinbaseRobotCpp(std::unordered_map<std::string,Coin<std::string>>* cd) : coinDict(cd)//std::unordered_map<std::string,Coin>* coinDict)
		{
			appStartTime = time(0);
			// tokenSource = new CancellationTokenSource();
			// ct = tokenSource->Token;
			// marketRateDict = std::unordered_map<std::wstring, MarketRate*>();
			// marketRateState = new MarketRateState();
			// coins = std::vector<Coin*>();
			// coinDict = std::unordered_map<int, Coin*>();
			// marketDict = std::unordered_map<int, MarketPair*>();
			// binaryFormatter = new BinaryFormatter();
			//
			// std::unordered_map<int, MarketPair*> newMarketDictionary;
			// std::vector<Coin*> newCoins;

			marketCount = 0;
			//Coin::CoinCount = 0;

			cout << "Starting model construction. " << appStartTime <<  endl;

			Auth auth(API_KEY, API_SECRET, API_PASSPHRASE, Auth::Mode::LIVE);

			std::vector<responses::product> products = marketdata::products::getProducts(auth);

			for (auto &product : products)
			{
				std::string id =  product.getId();
				std::string name = product.getDisplayName();
				std::string baseCoin = product.getBaseCurrency();
				std::string quoteCoin = product.getQuoteCurrency();
				std::string baseInc = product.getBaseIncrement();
				std::string quoteInc = product.getQuoteIncrement();
				// std::string baseMinSize;
				// try { baseMinSize = product.getBaseMinSize(); } catch (const std::exception& e) { /* */ }
				// std::string baseMaxSize;
				// try { baseMaxSize = product.getBaseMaxSize(); } catch (const std::exception& e) { /* */ }
				std::string minMarketFund = product.getMinMarketFunds();
				// std::string maxMarketFund;
				// try { maxMarketFund = product.getMaxMarketFunds(); } catch (const std::exception& e) { /* */ }
				std::string status = product.getStatus();
				std::string statusMessage = product.getStatusMessage();
				bool cancelOnly = product.getCancelOnly();
				bool limitOnly = product.getLimitOnly();
				bool postOnly = product.getPostOnly();
				bool tradingDisabled = product.getTradingDisabled();

				if (limitOnly || tradingDisabled)
					continue;

				//if (!statusMessage.empty())// || !baseMaxSize.empty())
				//std::cout << product.getId() << " statusMessage " << statusMessage << std::endl;

				CreateLinkedCoinsAndMarketPair(id, marketCount);
				++marketCount;
			}

		}

	private:
		// void InitMarketRates();
		//
		// std::vector<Coin*> LoadCoinAndMarketLists(MarketData* marketData, std::vector<MarketPair*>& marketPairArray);
		//
		 void CreateLinkedCoinsAndMarketPair(const std::string marketSymbol, int marketIndex); //, int precision)
		//
		// int CountDecimalDigits(Decimal n);
		//
		 void* FindOrCreateCoin(const std::string coinSymbol);//, std::unordered_map<int, Coin*>& coinDict, std::vector<Coin*>& coins);

	};


		//CoinbaseRobotCpp::CoinbaseRobotCpp(std::unordered_map<std::string,Coin<MarketPair*>>* coinDict)


		void CoinbaseRobotCpp::CreateLinkedCoinsAndMarketPair(const std::string marketSymbol, int marketIndex)
		{
			std::string delimiter = "-";
			std::string bCoinStr = marketSymbol.substr(0, marketSymbol.find(delimiter));
			std::string qCoinStr = marketSymbol.substr(marketSymbol.find(delimiter), marketSymbol.length());


			int coinId = 0;//Coin::CoinCount;

			cout << "Base Coin " << bCoinStr << " Quote Coin " << qCoinStr << " " << coinId << endl;

		}

		void* CoinbaseRobotCpp::FindOrCreateCoin(const std::string coinSymbol)//, std::unordered_map<int, Coin*>& coinDict, std::vector<Coin*>& coins)
		{
			return nullptr;//coin;
		}

#endif
