/* worhshop.h
 * consists of Product and Workshop classes
 * Products included in Workshop class as vector of pairs
 */

#ifndef KURS_WORKSHOP_H
#define KURS_WORKSHOP_H

#include <string>
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
#include "employee.h"

/* Product
 * constructor with 2 args!
 * ++/-- change price
 */
// мб вместо ++ и -- сделать + и -
// можно сделать конструктор массива (не нужно)
using namespace std;
class Product {
    string name;
    int price;
public:
    Product(string data_name, int data_price = 0) : price(data_price) {
        name = data_name;
        price = data_price;
    }
    ~Product() = default;
    string GetName() {return name;}
    int GetPrice() const {return price;}
    Product operator++ () {++price; return *this;}
    Product operator-- () {--price; return *this;}
};

/* Workshopstd::
 * cout << Workshop_obj displays all information;
 * ++/-- change workers_num
 */

class Workshop {
    string name;
    int department;
    int workers_num;
    std::vector<std::pair<Product, int> > products;
    Workshop operator++ () {++workers_num; return *this;}
    Workshop operator-- () {--workers_num; return *this;}
    size_t& Count() {static size_t c = 0; return c;}
    size_t& ProductCount() {static size_t t = 0; return t;}
public:
    Workshop(string data_name, int data_department = 0) {
        name = move(data_name);
        department = data_department;
        workers_num = 0;
        ++Count();

    }
    ~Workshop() {--Count();};
    //геттеры
    string GetWorkshopName() {return name;}
    int GetWorkersNum() const {return workers_num;}
    int GetDepartment() const {return department;}
    int GetProductsNum() const {return products.size();}
    Product GetProduct(int i=0);
    bool DeleteProduct(int i=0);
    size_t GetCount() {return Count();}
    size_t GetProductCount() {return ProductCount();}
    size_t SetProductCount(size_t data) {ProductCount() = data; return ProductCount();}
    //сеттеры
    string SetWorkshopName(string str) {name = str; return name;}
    int SetDepartment(int data) {department = data; return data;}
    bool Hire(Employee& employee);
    bool Fire(Employee& employee);
    //vector<pair>
    std::vector<std::pair<Product, int>>& AddProduct(Product, int);
    void DisplayProducts(vector<string>& lines);
    void DisplayProducts(vector<string>& lines, ofstream& file);
    std::vector<std::pair<Product, int>>& ReleaseProducts();
    bool OutputWorkshop (bool lang, vector<string>& lines);
    bool InputWorkshop (bool lang, vector<string>& lines);
};


#endif //KURS_WORKSHOP_H
