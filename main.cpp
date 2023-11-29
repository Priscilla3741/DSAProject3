#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Stocks.h"
using namespace std;

int main() {
    ifstream stockInfo("Stocks.csv");

    if (!stockInfo.is_open()) {
        cout << "Error opening file Stocks.csv" << endl;
    }

    unordered_map<string, vector<Stock>> stockMap;

    if (stockInfo.is_open()) { // ensure file is open
        string fileData;
        getline(stockInfo, fileData);

        while (getline(stockInfo, fileData)) { // go through file
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

            // insert stock into object
            Stock stock(symbol, name, sector, price, pricePerEarnings, dividendYield, earningsPerShare,
                        weekLow52, weekHigh52, marketCap, ebitda, pricePerSale, pricePerBook);

            // push the stock into its sector group
            stockMap[sector].push_back(stock);
        }

        float desiredSector;
        cout << "Sectors: " << endl;
        cout << " - Consumer Discretionary" << endl;
        cout << " - Consumer Staples" << endl;
        cout << " - Energy" << endl;
        cout << " - Financials" << endl;
        cout << " - Health Care" << endl;
        cout << " - Industrials" << endl;
        cout << " - Information Technology" << endl;
        cout << " - Materials" << endl;
        cout << " - Real Estate" << endl;
        cout << " - Telecommunication Services" << endl;
        cout << " - Utilities" << endl;
        cout << "Enter the Sector you want to invest in: ";

        cin >> desiredSector;

        // get funcy with it:

        // get the stocks in the sector

        int choice;
        cout << "Enter the number for the category you want to search: ";
        cout << "1. Price" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                int maxPrice;
                cout << "What is the maximum amount you want to invest in?" << endl;
                cin >> maxPrice;
                // with the max price find all the stocks that match are fall under the max price
        }

// funcmaster 2000

    }

    return 0;
}

