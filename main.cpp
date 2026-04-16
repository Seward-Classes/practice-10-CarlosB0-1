#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <string>

#include "Shape.h"

using namespace std;

void printAllAreas(const vector<unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        cout << fixed << setprecision(4);
        cout << "Area: " << shape->getArea() << endl;
        cout << endl;
    }
}

int main() {
    ifstream inFile("shapes.txt");

    if (!inFile) {
        cerr << "Error: Could not open shapes.txt" << endl;
        return 1;
    }

    vector<unique_ptr<Shape>> shapes;
    string line;
    int lineNumber = 0;

    while (getline(inFile, line)) {
        lineNumber++;

        if (line.empty()) {
            continue;
        }

        istringstream iss(line);
        string type;
        iss >> type;

        if (type == "rectangle") {
            double width, height;
            if (iss >> width >> height) {
                shapes.push_back(make_unique<Rectangle>(width, height));
            } else {
                cerr << "Error on line " << lineNumber
                     << ": Invalid rectangle data" << endl;
            }
        }
        else if (type == "circle") {
            double radius;
            if (iss >> radius) {
                shapes.push_back(make_unique<Circle>(radius));
            } else {
                cerr << "Error on line " << lineNumber
                     << ": Invalid circle data" << endl;
            }
        }
        else {
            cerr << "Error on line " << lineNumber
                 << ": Unknown shape type" << endl;
        }
    }

    printAllAreas(shapes);

    return 0;
}

