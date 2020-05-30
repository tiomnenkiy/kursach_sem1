#include "workshop.h"
#include "input.h"
#include <iostream>

using namespace std;

Product Workshop::GetProduct(int i) {
    if (products.size() < i+1) {
        return Product("none");
    }
    return products[i].first;
}

bool Workshop::DeleteProduct(int i) {
    if (products.size() < i+1) {
        return false;
    }
    products.erase(products.begin()+i);
    --ProductCount();
    return true;
}

bool Workshop::Hire(Employee& employee) {
    employee.SetDepartment(GetDepartment());
    ++(*this);
    return true;
}

bool Workshop::Fire(Employee& employee) {
    employee.SetDepartment(0);
    --(*this);
    return true;
}

vector<pair<Product, int>>& Workshop::AddProduct(Product new_product, int new_productivity) {
    products.emplace_back(std::make_pair(new_product,new_productivity) );
    ++ProductCount();
    return this->products;
}

void Workshop::DisplayProducts(vector<string>& lines) {
    if (products.empty()) {
        cout << 0 << endl;
        return;
    }
    cout << products.size() << endl;
    cout << lines.at(51) << endl;
    for (int i = 0; i < products.size(); ++i) {
        cout << products[i].first.GetName() << " " << products[i].second << " " << products[i].first.GetPrice() << endl;
    }
    cout << endl;
}

void Workshop::DisplayProducts(vector<string>& lines, ofstream& file) {
    if (products.empty()) {
        file << 0 << endl;
        return;
    }
    file << products.size() << endl;
    file << lines.at(51) << endl;
    for (int i = 0; i < products.size(); ++i) {
        file << products[i].first.GetName() << " " << products[i].second << " " << products[i].first.GetPrice() << endl;
    }
    file << endl;
}

bool Workshop::OutputWorkshop (bool lang, vector<string>& lines) {
    cout << lines.at(16) << GetWorkshopName() << endl;
    cout << lines.at(17) << GetDepartment() << endl << lines.at(18) << GetWorkersNum() << endl << lines.at(52);
    DisplayProducts(lines);
    return lang;
}

bool Workshop::InputWorkshop(bool lang, vector<string>& lines) {
    int k=10;
    do {
        cin.ignore(32767, '\n');
        cout << lines.at(44);
        getline(cin, name);
        while (name.empty()) {
            cout << lines.at(42) << endl << lines.at(43) << endl;
            getline(cin, name);
        }
        cout << endl << lines.at(45) << endl;
        do {
            cout << lines.at(46) << endl << lines.at(47) << endl << lines.at(5) << endl << lines.at(6);
            k = InputInt(lang, lines);
            if(k == 0) continue;
            if(k == 2) {
                lang = 0;
                break;
            }
            cin.ignore(32767, '\n');
            cout << endl << lines.at(48);
            string data_str;
            int data_price, data_num;
            getline(cin, data_str);
            while (data_str.empty()) {
                cout << lines.at(42) << endl << lines.at(43) << endl;
                getline(cin, data_str);
            }
            cout << endl << lines.at(49);
            data_price = InputInt(lang, lines);
            cout << endl << lines.at(50);
            data_num = InputInt(lang, lines);
            AddProduct(Product(data_str, data_price), data_num);
            cout << "\n\n";
        } while (k);
    } while (k);
    return lang;
}

std::vector<std::pair<Product, int>>& Workshop::ReleaseProducts() {
    size_t size = products.size();
    products.clear();
    SetProductCount(GetProductCount()-size);
    return this->products;
}