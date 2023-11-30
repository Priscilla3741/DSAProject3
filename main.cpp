#include <iostream>
#include "Stocks.h"
using namespace std;

// using bubble sort - bubble prices from descending to ascending order
// using heap sort - build min heap and pop out minimum values until it gets to the max

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

    int choice;
    string algorithmChoice;
    cout << "Enter the number for the category you want to search: ";
    cout << "1. Price" << endl;
    cin >> choice;
    cout << "What algorithm do you want to use?" << endl;
    cout << " - Quick Sort" << endl;
    cout << " - Heap Sort" << endl;
    cin >> algorithmChoice;
    // sort the industry's sector with that algorithm

    switch (choice) {
        case 1:
            int maxPrice;
            cout << "What is the maximum amount you want to invest in?" << endl;
            cin >> maxPrice;
            // with the max price find all the stocks that match are fall under the max price
    }
    return 0;
}

