#include "Stocks.h"

void Stocks::insertStocks(unordered_map<string, vector<Stock>> &stockMap) {
    ifstream stockInfo("Stocks.csv");

    if (!stockInfo.is_open()) {
        cout << "Error opening file Stocks.csv" << endl;
    }

    if (stockInfo.is_open()) { // ensure file is open
        string fileData;
        getline(stockInfo, fileData);

        while (getline(stockInfo, fileData)) { // go through file
            string symbol, name, sector, sec;
            string p, pe, dy, es, wl, wh, mc, eb, ps, pb;
            istringstream stream(fileData);

            getline(stream, symbol, ',');
            getline(stream, name, ',');
            getline(stream, sector, ',');

            getline(stream, p, ',');
            getline(stream, pe, ',');
            getline(stream, dy, ',');
            getline(stream, es, ',');
            getline(stream, wl, ',');
            getline(stream, wh, ',');
            getline(stream, mc, ',');
            getline(stream, eb, ',');
            getline(stream, ps, ',');
            getline(stream, pb, ',');

            float price = stof(p);
            float pricePerEarnings = stof(pe);
            float dividendYield = stof(dy);
            float earningsPerShare = stof(es);
            float weekLow52 = stof(wl);
            float weekHigh52 = stof(wh);
            float marketCap = stof(mc);
            float ebitda = stof(eb);
            float pricePerSale = stof(ps);
            float pricePerBook = stof(pb);

            getline(stream, sec, ',');

            // insert stock into object
            Stock stock(symbol, name, sector, price, pricePerEarnings, dividendYield, earningsPerShare,
                        weekLow52, weekHigh52, marketCap, ebitda, pricePerSale, pricePerBook);

            // push the stock into its sector group
            stockMap[sector].push_back(stock);
        }
    }
}