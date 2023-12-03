#ifndef DSAPROJECT3_STOCKS_H
#define DSAPROJECT3_STOCKS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct StockInfo {
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

    StockInfo(const string& sym, const string& n, const string& sec, float p, float pe, float dy, float es, float wl, float wh, float mc, float eb, float ps, float pb)
            : symbol(sym), name(n), sector(sec), price(p), pricePerEarnings(pe), dividendYield(dy), earningsPerShare(es),
              weekLow52(wl), weekHigh52(wh), marketCap(mc), ebitda(eb), pricePerSale(ps), pricePerBook(pb) {}

    float getPrice() const {
        return price;
    }
    // prints out the stock info
    void print() const {
        cout << "Symbol: " << symbol << ", Name: " << name << ", Sector: " << sector << ", Price: " << price
        << ", Price/Earnings: " << pricePerEarnings << ", Dividend Yield: " << dividendYield
        << ", Earnings/Share: " << earningsPerShare << ", 52 Week Low: " << weekLow52
        << ", 52 Week High: " << weekHigh52 << ", Market Cap: " << marketCap
        << ", EBITDA: " << ebitda << ", Price/Sale: " << pricePerSale << ", Price/Book: " << pricePerBook << endl;
        cout << endl;

    }
};

class Stocks {
public:
    static void insertStocks(unordered_map<string, vector<StockInfo> > &stockMap);
    void quickSort(vector<StockInfo>& stocks, int start, int end);
    static int partition(vector<StockInfo>& stocks, int start, int end);
    void heapSort(vector<StockInfo>& stocks, int n);
    void heapifyAscending(vector<StockInfo>& stocks, int n, int i);
    void quickSortDescending(vector<StockInfo> &stocks, int start, int end);
    static int partitionDescending(vector<StockInfo> &stocks, int start, int end);
    void heapSortDescending(vector<StockInfo> &stocks, int n);
    void heapifyDescending(vector<StockInfo>& stocks, int n, int i);
};


#endif //DSAPROJECT3_STOCKS_H