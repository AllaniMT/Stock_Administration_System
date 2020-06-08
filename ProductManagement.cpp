#include <iostream>

#include <string>

#include <fstream>

#include <conio.h>

using namespace std;

class Products {
  private:
    int productNumber;
  string productName;
  float productPrice, productQuantity;
  public:
    //User create new product
    void createProduct() {
      cout << "Enter the product number: ";
      cin >> productNumber;
      cout << "Enter the product name: ";
      cin >> productName;
      cout << "Enter the product product price: ";
      cin >> productPrice;
      cout << "Enter the product quantity: ";
      cin >> productQuantity;
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
//Store the new Product in the file
void wirteNewProduct() {
  fStreamObject.open("Stock.txt", ios::out | ios::app);
  products1.createProduct();
  fStreamObject.write((char * ) & products1, sizeof(Products));
  fStreamObject.close();
  cout << "\n\n The product is created!";
  getch();
}
//Display all the products from the file
void displayProducts() {
  cout << "All The products information: \n \n";
  fStreamObject.open("Stock.txt", ios:: in );
  while (fStreamObject.read((char * ) & products1, sizeof(Products))) {
    products1.showProductInfo();
    cout << "\n\n ============================================ \n ";
    //getch();
  }
  fStreamObject.close();
  getch();
}
// Search for a product by his  number
void searchForProduct(int theSearchedProductNumber) {

  int productExist = 0;
  fStreamObject.open("Stock.txt", ios:: in );
  while (fStreamObject.read((char * ) & products1, sizeof(Products))) {

    if (products1.getProductNumber() == theSearchedProductNumber) {

      products1.showProductInfo();
      productExist = 1;
    }
  }
  fStreamObject.close();
  if (productExist == 0) {

    cout << "\n \n Prodcut not found \n";
    getch();
  }
}
//Delete product by his number
void deleteProductFromProdutNumber() {
  int toDeleteProductNumber;
  cout << "\n \n Enter the product that you want to delete: ";
  cin >> toDeleteProductNumber;
  fStreamObject.open("Stock.txt", ios:: in | ios::out);
  fstream fStreamObject2;
  fStreamObject2.open("Stock_Replaced.txt", ios::out);
  fStreamObject.seekg(0, ios::beg);
  while (fStreamObject.read((char * ) & products1, sizeof(Products))) {
    if (products1.getProductNumber() != toDeleteProductNumber) {
      fStreamObject2.write((char * ) & products1, sizeof(Products));
    }
  }
  fStreamObject2.close();
  fStreamObject.close();
  remove("Stock.txt");
  cout << "\n \n The product is deleted!";
  getch();
}

void title() {
  cout << "\t\t\t\t\t\t Store Project";
  cout << "\n\n \t\t\t\t\t\t *** ENJOY*** ";
}
//Main function to run the system
int main() {

  char theSelectedFunctionality;
  title();
  do {
    cout << "\n\n\n Main Menu";
    cout << "\n\n\t1.Create new product";
    cout << "\n\n\t2.Display all products";
    cout << "\n\n\t3.Search for products";
    cout << "\n\n\t4.Delete product";
    cout << "\n\n\t5.Exit";
    cout << "\n\n\tEnter your choice: ";
    cin >> theSelectedFunctionality;
    //theSelectedFunctionality=getche();
    switch (theSelectedFunctionality) {
    case '1':
      wirteNewProduct();
      break;
    case '2':
      displayProducts();
      break;
    case '3':
      int Num;
      cout << "Enter The Num to Search: \t";
      cin >> Num;
      searchForProduct(Num);
      break;
    case '4':
      deleteProductFromProdutNumber();
      break;
    case '5':
      exit(0);
    default:
      cout << "Error";
      exit(0);
    }
  } while (theSelectedFunctionality != 6);

}
