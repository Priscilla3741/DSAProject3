#include <iostream>
#include "Stocks.h"
using namespace std;

// using bubble sort - bubble prices from descending to ascending order
// using heap sort - build min heap and pop out minimum values until it gets to the max

int main() {
    unordered_map<string, vector<StockInfo>> stockMap;
    Stocks stock;
    stock.insertStocks(stockMap);

    int desiredSector;
    cout << "Sectors: " << endl;
    cout << " 1. Consumer Discretionary" << endl;
    cout << " 2. Consumer Staples" << endl;
    cout << " 3. Energy" << endl;
    cout << " 4. Financials" << endl;
    cout << " 5. Health Care" << endl;
    cout << " 6. Industrials" << endl;
    cout << " 7. Information Technology" << endl;
    cout << " 8. Materials" << endl;
    cout << " 9. Real Estate" << endl;
    cout << " 10. Telecommunication Services" << endl;
    cout << " 11. Utilities" << endl;
    cout << "Enter the Sector you want to invest in: ";

    cin >> desiredSector;

    int count = 0;
    for (int i = 1; i <= 11; i++) {
        if (count == 11) {
            cout << "Invalid sector entered. Please choose a valid sector: " << endl;
            cin >> desiredSector;
        }
        if (desiredSector != i) {
            count++;
        }
    }

    string sector;
    if (desiredSector == 1) { sector = "Consumer Discretionary"; }
    if (desiredSector == 2) { sector = "Consumer Staples"; }
    if (desiredSector == 3) { sector = "Energy"; }
    if (desiredSector == 4) { sector = "Financials"; }
    if (desiredSector == 5) { sector = "Health Care"; }
    if (desiredSector == 6) { sector = "Industrials"; }
    if (desiredSector == 7) { sector = "Information Technology"; }
    if (desiredSector == 8) { sector = "Materials"; }
    if (desiredSector == 9) { sector = "Real Estate"; }
    if (desiredSector == 10) { sector = "Telecommunication Services"; }
    if (desiredSector == 11) { sector = "Utilities"; }

    vector<StockInfo>& sectorStocks = stockMap[sector];

    int algorithmChoice;
    cout << "What algorithm do you want to use?" << endl;
    cout << " 1. Quick Sort" << endl;
    cout << " 2. Heap Sort" << endl;
    cin >> algorithmChoice;

    if (algorithmChoice == 1) {
        stock.quickSort(sectorStocks, 0, sectorStocks.size() - 1);
    }
    else if (algorithmChoice == 2) {
        int n = sizeof(sectorStocks)/sizeof(sectorStocks[0].getPrice());
        stock.heapSort(sectorStocks, n);
    }
    else {
        cout << "Invalid algorithm entered. Please choose a valid algorithm: " << endl;
        cin >> algorithmChoice;
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
