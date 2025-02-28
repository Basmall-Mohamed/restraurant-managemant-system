#include <iostream>
#include <string>

using namespace std;

const int maxOrder = 100;
string orders[maxOrder] = { "pasta", "fries", "corndog", "pizza", "burger" };
int orderSize = 5;

void displayOrders(string orders[], int orderSize) {
    if (orderSize == 0) {
        cout << "No orders to display!" << endl;
        return;
    }

    cout << "Current orders: " << endl;
    for (int i = 0; i < orderSize; i++) {
        cout << i + 1 << ". " << orders[i] << endl;
    }
}

void addOrder(string orders[], int& orderSize) {
    if (orderSize >= maxOrder) {
        cout << "Order list is full!" << endl;
        return;
    }

    int choice;

    displayOrders(orders, orderSize);
    cout << "Enter your choice to add an order:\n";
    cin >> choice;

    string newOrder;
    switch (choice) {
    case 1: newOrder = "pasta"; break;
    case 2: newOrder = "fries"; break;
    case 3: newOrder = "corndog"; break;
    case 4: newOrder = "pizza"; break;
    case 5: newOrder = "burger"; break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }

    orders[orderSize] = newOrder;
    orderSize++;
    cout << "Order added successfully!" << endl;
}

void deleteOrder(string orders[], int& orderSize) {
    if (orderSize == 0) {
        cout << "No order to delete!" << endl;
        return;
    }

    displayOrders(orders, orderSize);

    int index;
    cout << "Enter the index to delete: ";
    cin >> index;

    if (index < 1 || index > orderSize) {
        cout << "Invalid index!" << endl;
        return;
    }

    for (int i = index - 1; i < orderSize - 1; i++) {
        orders[i] = orders[i + 1];
    }
    orderSize--;
    cout << "Order deleted successfully!" << endl;
}

void editOrder(string orders[], int orderSize) {
    if (orderSize == 0) {
        cout << "Empty list!" << endl;
        return;
    }

    displayOrders(orders, orderSize);

    int index;
    cout << "Enter the index to edit: ";
    cin >> index;

    if (index < 1 || index > orderSize) {
        cout << " OOPS! Invalid index!" << endl;
        return;
    }

    string newOrder;
    cout << "Enter the new order: ";
    cin.ignore();
    getline(cin, newOrder);

    orders[index - 1] = newOrder;
    cout << "Order updated!" << endl;
}

void searchOrders(const string orders[], int orderSize) {
    if (orderSize == 0) {
        cout << "No orders to search!" << endl;
        return;
    }

    string orderName;
    cout << "Enter the name of the order you want to search for: ";
    cin.ignore();
    getline(cin, orderName);

    bool found = false;
    for (int i = 0; i < orderSize; ++i) {
        if (orders[i] == orderName) {
            cout << "Order found at position " << (i + 1) << ": " << orders[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Order not found!" << endl;
    }
}

void calculateSales(const string orders[], const double prices[], const int quantities[], int orderSize) {
    double totalSales = 0.0;

    for (int i = 0; i < orderSize; i++) {
        double dishSales = prices[i] * quantities[i];
        totalSales += dishSales;
        cout << orders[i] << ": " << quantities[i] << " sold (" << dishSales << " L.E)\n";
    }
    cout << "Total sales: " << totalSales << " L.E\n";
}

void deleteAllOrders(string orders[], int& orderSize) {
    for (int i = 0; i < orderSize; i++) {
        orders[i] = "";
    }
    orderSize = 0;
    cout << "All orders have been deleted successfully.\n";
}

void displayOrderFrequency() {
    int pizzaCount = 0, friesCount = 0, burgerCount = 0, pastaCount = 0, corndogCount = 0;

    for (int i = 0; i < orderSize; i++) {
        if (orders[i] == "pizza") {
            pizzaCount++;

            break;
        }
        else if (orders[i] == "fries") {
            friesCount++;
        }
        else if (orders[i] == "burger") {
            burgerCount++;
        }
        else if (orders[i] == "pasta") {
            pastaCount++;
        }
        else if (orders[i] == "corndog") {
            corndogCount++;
        }
    }

    cout << "Order Frequency:\n";
    cout << "Pizza: " << pizzaCount << " times\n";
    cout << "Fries: " << friesCount << " times\n";
    cout << "Burger: " << burgerCount << " times\n";
    cout << "Pasta: " << pastaCount << " times\n";
    cout << "Corndog: " << corndogCount << " times\n";
}

void menu() {
    cout << "\nRestaurant Orders System\n";
    cout << "1. Add Order\n";
    cout << "2. Delete Order\n";
    cout << "3. Edit Order\n";
    cout << "4. Search Order\n";
    cout << "5. Calculate Sales\n";
    cout << "6. Display Orders\n";
    cout << "7. Display Order Frequency\n";
    cout << "8. Delete All Orders\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    const int dishCount = 5;
    const string dishes[dishCount] = { "Pasta", "Fries", "Corndog", "Pizza", "Burger" };
    double prices[dishCount] = { 30, 20.50, 45, 89.99, 75 };
    int quantities[dishCount] = { 0 };

    int choice;
    while (true) {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            addOrder(orders, orderSize);
            break;
        case 2:
            deleteOrder(orders, orderSize);
            break;
        case 3:
            editOrder(orders, orderSize);
            break;
        case 4:
            searchOrders(orders, orderSize);
            break;
        case 5:
            cout << "Enter quantities for the dishes:\n";
            for (int i = 0; i < dishCount; i++) {
                cout << "How many " << dishes[i] << " sold? ";
                cin >> quantities[i];
            }
            calculateSales(dishes, prices, quantities, dishCount);
            break;
        case 6:
            displayOrders(orders, orderSize);
            break;
        case 7:
            displayOrderFrequency();
            break;
        case 8:
            deleteAllOrders(orders, orderSize);
            break;
        case 9:
            cout << "Exiting the system.\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

