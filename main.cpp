#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Stocks.h"
using namespace std;

struct Stock {
    string symbol;
    string name;
    string sector;
    float price;
    float pricePerEarnings;
    float dividendYield;
    float earningsPerShare;
    float weekLow52;
    float weekHigh52;
    float marketCap;
    float ebitda;
    float pricePerSale;
    float pricePerBook;

    Stock(const string& sym, const string& n, const string& sec, float p, float pe, float dy, float es, float wl, float wh, float mc, float eb, float ps, float pb)
            : symbol(sym), name(n), sector(sec), price(p), pricePerEarnings(pe), dividendYield(dy), earningsPerShare(es),
              weekLow52(wl), weekHigh52(wh), marketCap(mc), ebitda(eb), pricePerSale(ps), pricePerBook(pb) {}
};

int main() {
    ifstream stockInfo("Stocks.csv");

    if (!stockInfo.is_open()) {
        cout << "Error opening file Stocks.csv" << endl;
    }

    unordered_map<string, vector<Stock>> stockMap;

    if (stockInfo.is_open()) {
        string fileData;
        getline(stockInfo, fileData);

        while (getline(stockInfo, fileData)) {
            string symbol, name, sector, sec;
            string p,pe,dy,es,wl,wh,mc,eb,ps,pb;
            istringstream stream (fileData);

            getline(stream, symbol, ',');
            getline(stream, name, ',');
            getline(stream, sector, ',');

            getline(stream, p, ',');
            getline(stream, pe, ',');
            getline(stream, dy,',');
            getline(stream, es,',');
            getline(stream, wl,',');
            getline(stream, wh,',');
            getline(stream, mc,',');
            getline(stream, eb,',');
            getline(stream, ps,',');
            getline(stream, pb,',');

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

            Stock stock(symbol, name, sector, price, pricePerEarnings, dividendYield, earningsPerShare, weekLow52, weekHigh52, marketCap, ebitda, pricePerSale, pricePerBook);

            stockMap[sector].push_back(stock);
        }

//         iterate through map
//        for (const auto& inputs : stockMap) {
//            const string& secName = inputs.first;
//            const vector<Stock>& sectorStocks = inputs.second;
//        }

    }

    return 0;
}

