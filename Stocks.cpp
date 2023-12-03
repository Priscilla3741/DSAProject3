#include "Stocks.h"
#include <algorithm>
#include <unordered_map>
#pragma once

// reads in files
void Stocks::insertStocks(unordered_map<string, vector<StockInfo>> &stockMap) {
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
            StockInfo stock(symbol, name, sector, price, pricePerEarnings, dividendYield, earningsPerShare,
                            weekLow52, weekHigh52, marketCap, ebitda, pricePerSale, pricePerBook);

            // push the stock into its sector group
            stockMap[sector].push_back(stock);
        }
    }
}

// quick sorts sector stocks in ascending order
void Stocks::quickSort(vector<StockInfo> &stocks, int start, int end) {
    if (start < end) {
        int partitionIndex = partition(stocks, start, end);
        quickSort(stocks, start, partitionIndex - 1);
        quickSort(stocks, partitionIndex + 1, end);
    }
}

int Stocks::partition(vector<StockInfo>& stocks, int start, int end) {
    int index = 0;
    float pivotElement = stocks[end].getPrice();
    int pivotIndex = start;

    for (int i = start; i <= end; i++) {
        if (stocks[i].getPrice() < pivotElement) {
            swap(stocks[i], stocks[pivotIndex]);
            index++;
        }
    }

    pivotIndex = start + index - 1;
    swap(stocks[pivotIndex], stocks[end]);
    index++;

    for (int i = start; i < end; i++) {
        if (stocks[i].getPrice() > pivotElement) {
            swap(stocks[i], stocks[pivotIndex]);
            index++;
        }
    }

    swap(stocks[pivotIndex], stocks[end]);
    return pivotIndex;
}

// heap sorts sector stocks in ascending order
void Stocks::heapifyAscending(vector<StockInfo>& stocks, int n, int i) {
    int largest = i;
    int left = 2 * i +1;
    int right = 2 * i +2;

    if (left < n && stocks[left].getPrice() > stocks[largest].getPrice())
        largest = left;

    if (right < n && stocks[right].getPrice() > stocks[largest].getPrice())
        largest = right;

    if (largest != i) {
        swap(stocks[i], stocks[largest]);
        heapifyAscending(stocks, n, largest);
    }
}

void Stocks::heapSort(vector<StockInfo> &stocks, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyAscending(stocks, n, i);
    }
    for (int i = n - 1; i >=0; i--) {
        swap(stocks[0], stocks[i]);
        heapifyAscending(stocks, i, 0);
    }
}

// quick sorts sector stocks in descending order
void Stocks::quickSortDescending(std::vector<StockInfo> &stocks, int start, int end) {
    if (start < end) {
        int partitionIndex = partitionDescending(stocks, start, end);
        quickSortDescending(stocks, start, partitionIndex - 1);
        quickSortDescending(stocks, partitionIndex + 1, end);
    }
}

int Stocks::partitionDescending(std::vector<StockInfo> &stocks, int start, int end) {
    float pivotElement = stocks[end].getPrice();
    int pivotIndex = start;

    for (int i = start; i < end; i++) {
        if (stocks[i].getPrice() >= pivotElement) {
            swap(stocks[i], stocks[pivotIndex]);
            pivotIndex++;
        }
    }

    swap(stocks[pivotIndex], stocks[end]);
    return pivotIndex;
}

// heap sorts sector stocks in descending order
void Stocks::heapifyDescending(vector<StockInfo>& stocks, int n, int i) {
    int smallest = i;
    int left = 2 * i +1;
    int right = 2 * i +2;

    if (left < n && stocks[left].getPrice() < stocks[smallest].getPrice())
        smallest = left;

    if (right < n && stocks[right].getPrice() < stocks[smallest].getPrice())
        smallest = right;

    if (smallest != i) {
        swap(stocks[i], stocks[smallest]);
        heapifyDescending(stocks, n, smallest);
    }
}

// heap sorts sector stocks in descending order
void Stocks::heapSortDescending(std::vector<StockInfo> &stocks, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDescending(stocks, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        std::swap(stocks[0], stocks[i]);
        heapifyDescending(stocks, i, 0);
    }
}
