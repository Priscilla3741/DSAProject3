#include <iostream>
#include <chrono>
#include "Stocks.h"
#include "HashMap.h"
using namespace std;

int main() {
    HashMap<string, vector<struct StockInfo>> stockMap;
    Stocks stock;
    stock.insertStocks(stockMap);

    // get user's desired sector
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

    do {
        cout << "Enter the number of the sector you want to invest in: ";
        cin >> desiredSector;

        if (desiredSector > 11 || desiredSector < 1) {
            cout << "Invalid sector entered. Please enter a value between 1 and 11: " << endl;
            cin >> desiredSector;
        }
    }
    while (desiredSector > 11 || desiredSector < 1);

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

    // get user's desired price range
    float minPrice;
    float maxPrice;
    do {
        cout << "What is the minimum amount you want to invest in?" << endl;
        cin >> minPrice;

        cout << "What is the maximum amount you want to invest in?" << endl;
        cin >> maxPrice;

        if (minPrice > maxPrice) {
            cout << "Invalid input. Please ensure that the minimum is less than the maximum" << endl;
        }
    }
    while (minPrice > maxPrice || maxPrice < minPrice);

    int algorithmChoice;
    do {
        cout << "What algorithm do you want to use?" << endl;
        cout << "1. Quick Sort | Ascending" << endl;
        cout << "2. Heap Sort | Ascending" << endl;
        cout << "3. Quick Sort | Descending" << endl;
        cout << "4. Heap Sort | Descending" << endl;
        cin >> algorithmChoice;

        if (algorithmChoice < 1 || algorithmChoice > 4) {
            cout << "Invalid algorithm choice. Please enter a value between 1 and 4." << endl;
        }
    }
    while (algorithmChoice < 1 || algorithmChoice > 4);

    bool continueSorting = true;

    // continues sorting if user would like to continue testing different algorithms
    while (continueSorting) {
        auto startTime = std::chrono::high_resolution_clock::now();

        if (algorithmChoice == 1) {
            stock.quickSort(sectorStocks, 0, sectorStocks.size() - 1);

            for (StockInfo &stockInSectors: sectorStocks) {
                if (stockInSectors.getPrice() >= minPrice && stockInSectors.getPrice() <= maxPrice) {
                    stockInSectors.print();
                }
            }
        } else if (algorithmChoice == 2) {
            int n = sectorStocks.size();
            stock.heapSort(sectorStocks, n);

            for (StockInfo &stockInSectors: sectorStocks) {
                if (stockInSectors.getPrice() >= minPrice && stockInSectors.getPrice() <= maxPrice) {
                    stockInSectors.print();
                }
            }
        } else if (algorithmChoice == 3) {
            stock.quickSortDescending(sectorStocks, 0, sectorStocks.size() - 1);

            for (StockInfo &stockInSectors: sectorStocks) {
                if (stockInSectors.getPrice() >= minPrice && stockInSectors.getPrice() <= maxPrice) {
                    stockInSectors.print();
                }
            }
        } else if (algorithmChoice == 4) {
            int n = sectorStocks.size();
            stock.heapSortDescending(sectorStocks, n);

            for (StockInfo &stockInSectors: sectorStocks) {
                if (stockInSectors.getPrice() >= minPrice && stockInSectors.getPrice() <= maxPrice) {
                    stockInSectors.print();
                }
            }
        }

        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
        cout << "Sorting and printing took " << duration.count() / 1e-9 << " seconds." << endl;
        cout << endl;

        // options after first run
        int choice;
        cout << "Options:" << endl;
        cout << " 1. Use another algorithm" << endl;
        cout << " 2. Start over with different industry and price range" << endl;
        cout << " 3. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    cout << "Choose another algorithm: ";
                    cin >> algorithmChoice;

                    if (algorithmChoice < 1 || algorithmChoice > 4) {
                        cout << "Invalid algorithm choice. Please enter a value between 1 and 4." << endl;
                    }
                }
                while (algorithmChoice < 1 || algorithmChoice > 4);
                break;
            case 2:
                // reset industry, price range, and any other relevant variables
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

                do {
                    cout << "Enter the number of the sector you want to invest in: ";
                    cin >> desiredSector;

                    if (desiredSector > 11 || desiredSector < 1) {
                        cout << "Invalid sector entered. Please enter a value between 1 and 11: " << endl;
                        cin >> desiredSector;
                    }
                }
                while (desiredSector > 11 || desiredSector < 1);

                // reset sectorStocks based on the new desired sector
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

                sectorStocks = stockMap[sector];

                // reset minPrice and maxPrice
                do {
                    cout << "What is the minimum amount you want to invest in?" << endl;
                    cin >> minPrice;

                    cout << "What is the maximum amount you want to invest in?" << endl;
                    cin >> maxPrice;

                    if (minPrice > maxPrice) {
                        cout << "Invalid input. Please ensure that the minimum is less than the maximum" << endl;
                    }
                }
                while (minPrice > maxPrice || maxPrice < minPrice);
                break;
            case 3:
                continueSorting = false;
                break;
            default:
                cout << "Invalid choice. Exiting.";
                continueSorting = false;
                break;
        }
    }
    return 0;
}
