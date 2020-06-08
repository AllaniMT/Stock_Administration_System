#include <iostream>

#include <fstream>

using namespace std;

class Products {
  private:
    int productNumber;
  string productName;
  float productPrice, productQuantity;
  public:
    //User create new product
    void createProduct() {
      cout << "Enter the product number" << endl;
      cin >> productName;
      cout << "Enter the product name" << endl;
      cin >> productName;
      cout << "Enter the product product price " << endl;
      cin >> productPrice;
      cout << "Enter the product quantity" << endl cin >> productQuantity;
    }
  //Getting the Product information
  void showProductInfo() {
    cout << "The product number is: " << productNumber << endl;
    cout << "The product name is: " << productName << endl;
    cout << "The product product price is: " << productPrice << endl;
    cout << "The product quantity is: " << productQuantity << endl;
  }
  int getProductNumber() {
    return productNumber;
  }
  string getProductName() {
    return productName;
  }
  float getProductPrice() {
    return productPrice;
  }
  float getProductQuantity() {
    return productQuantity;
  }
};
//Create new Object from Products
Products products1;
//Create an object from fstream to read and write from the file
fstream fStreamObject;
int main() {

}
