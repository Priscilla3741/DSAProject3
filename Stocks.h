//
// Created by sumye on 11/27/2023.
//

#ifndef DSAPROJECT3_STOCKS_H
#define DSAPROJECT3_STOCKS_H
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
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



class Stocks {
    void insertStocks();

    void readCSV(string file);


};


#endif //DSAPROJECT3_STOCKS_H
