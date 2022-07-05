
#ifndef MARKETPAIR_H
#define MARKETPAIR_H


#include <string>

//C# TO C++ CONVERTER NOTE: The following .NET attribute has no direct equivalent in C++:
//ORIGINAL LINE: [Serializable][StructLayout(LayoutKind.Sequential)] public class MarketPair
template <class T>
	class MarketPair
	{
	public:
		std::string Symbol;
		int Index = 0;
		T BaseCurrency;
		T QuoteCurrency;
		std::string BaseCurrencySymbol;
		int BasePrecision = 0;
		std::string QuoteCurrencySymbol;
		int QuotePrecision = 0;
		bool IsBusy = false;
		std::string Exchange;
		time_t LastOrderSearch;


		MarketPair(std::string s, T bCoin, T qCoin) : BaseCurrency(bCoin), QuoteCurrency(qCoin)
		{}

		//MarketPair(MarketPair *sourceMarket, bool clone = false);
	};

		// MarketPair::MarketPair(MarketPair *sourceMarket, bool clone)
		// {
		//
		// }

#endif
