#include <iostream>
#include "Stocks.h"
using namespace std;

// using quick sort and topological sort.

int main() {
    Stocks stock;
    stock.insertStocks();

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
        return 0;
    }

