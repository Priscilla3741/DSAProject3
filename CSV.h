//
// Created by sumye on 11/27/2023.
//

#ifndef DSAPROJECT3_CSV_H
#define DSAPROJECT3_CSV_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class CSV {
    vector<vector<string>> readCSV(const string& filename) {
        vector<vector<string>> data;

        // Open the CSV file
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return data;
        }

        string line;

        // Read each line from the file
        while (getline(file, line)) {
            vector<string> row;
            stringstream ss(line);
            string cell;

            // Split the line into cells using ',' as a delimiter
            while (getline(ss, cell, ',')) {
                row.push_back(cell);
            }

            data.push_back(row);
        }

        // Close the file
        file.close();

        return data;
    }
};


#endif //DSAPROJECT3_CSV_H
