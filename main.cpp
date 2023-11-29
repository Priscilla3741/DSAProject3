#include <iostream>
#include "Stocks.h"
using namespace std;

// using quick sort and topological sort.

int main() {
    unordered_map<string, vector<Stock>> stockMap;
    Stocks stock;
    stock.insertStocks(stockMap);

    string desiredSector;
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

    // get the stocks in the sector
    if (desiredSector == "Consumer Discretionary" || desiredSector == "Consumer Staples" ||
        desiredSector == "Energy" || desiredSector == "Financials" ||
        desiredSector == "Health Care" || desiredSector == "Industrials" ||
        desiredSector == "Information Technology" || desiredSector == "Materials" ||
        desiredSector == "Real Estate" || desiredSector == "Telecommunication Services" ||
        desiredSector == "Utilities") {
        cout << "Sector selected: " << desiredSector << endl;
    } else {
        cout << "Invalid sector entered. Please choose a valid sector: " << endl;
        cin >> desiredSector;
    }

    for (const auto& input : stockMap) {
        const string& sectorName = input.first;
        const vector<Stock>& sectorStocks = input.second;

        for (const Stock& stock : sectorStocks) {  // analyze stock in desired sector

        }
    }

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
    return 0;
}

