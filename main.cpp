#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// find the average for every year and then use that to use the regression point (number) for each stock and then use that to see if its good or not (neg or pos)

int main() {
    ifstream stockInfo("Stocks.csv");

    if (!stockInfo.is_open()) {
        cout << "Error opening file Stocks.csv" << endl;
    }

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

            // fix float - throws problem when the number is negative

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

            cout << "Symbol: " << symbol << ", Name: " << name << ", Sector: " << sector << ", Price: " << price << ", Price/Earnings: " << pricePerEarnings << ", Dividend Yield: " << dividendYield
                << ", Earnings/Share: " << earningsPerShare << ", 52 Week Low: " << weekLow52 << ", 52 Week High: " << weekHigh52
                << ", Market Cap: " << marketCap << ", EBITDA: " << ebitda << ", Price/Sale: " << pricePerSale << ", Price/Book: " << pricePerBook << endl;
            cout << endl;
        }
    }

    return 0;
}

