#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Stocks.h"
using namespace std;

int main() {
    string sector;
    float price;
    Stocks stocks;

    stocks.readCSV("Stocks.csv");

        cout << "Sector: ";

        cin >> sector;





    return 0;
}

