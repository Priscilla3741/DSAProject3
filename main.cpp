#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// find the average for every year and then use that to use the regression point (number) for each stock and then use that to see if its good or not (neg or pos)

int main() {
    ifstream stockInfo("A.csv");

    if (!stockInfo.is_open()) {
        cout << "Error opening file A.csv" << endl;
    }

    if (stockInfo.is_open()) {
        cout << "A" << endl;
        string fileData;
        getline(stockInfo, fileData);
        while (getline(stockInfo, fileData)) {
            string d,o,h,l,c,a,v;
            istringstream stream (fileData);

            getline(stream, d, ',');
            getline(stream, o, ',');
            getline(stream, h, ',');
            getline(stream, l,',');
            getline(stream, c,',');
            getline(stream, a,',');
            getline(stream, v,',');

            int Date = stoi(d);
            float Open = stof(o);
            float High = stof(h);
            float Low = stof(l);
            float Close = stof(c);
            float AdjClose = stof(a);
            float Volume = stof(v);

            cout << "Date: " << Date << ", Open: " << Open << ", High: " << High
                 << ", Low: " << Low << ", Close: " << Close << ", AdjClose: " << AdjClose
                 << ", Volume: " << Volume << endl;
            cout << endl;

            //yourMom[stateName] = StateData(perCapitaIncome, population, medianHouseInc, numofHouseholds);
        }
        }
    return 0;
    }

