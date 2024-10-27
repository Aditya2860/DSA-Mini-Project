#include <iostream>
#include <string>
#include <queue>
#include <list>

using namespace std;

// Define the Node for the Stack
class StackNode {
public:
    string data;
    StackNode* next;

    StackNode(string value) {
        data = value;
        next = nullptr;
    }
};

// Define the Stack class using linked list
class Stack {
private:
    StackNode* top; // Pointer to the top of the stack

public:
    Stack() : top(nullptr) {} // Constructor to initialize the stack

    // Push a new element onto the stack
    void push(string value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop an element from the stack
    string pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return "";
        }
        StackNode* temp = top;
        top = top->next;
        string poppedValue = temp->data;
        delete temp;
        return poppedValue;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        StackNode* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display all elements in reverse order (for displaying ingredients)
    void displayInReverse(StackNode* node) {
        if (node == nullptr) {
            return;
        }
        displayInReverse(node->next);
        cout << node->data << " ";
    }

    void displayIngredients() {
        displayInReverse(top);
        cout << endl;
    }
};

// Define the class for each item and its ingredients
class Item {
public:
    string name;
    Stack ingredients; // Custom stack to hold ingredients

    Item(string itemName) {
        name = itemName;
    }

    void addIngredient(string ingredient) {
        ingredients.push(ingredient);
    }

    void showIngredients() {
        cout << "Ingredients of " << name << ": ";
        ingredients.displayIngredients();
    }
};

// Define a node for queue (linked list)
class OrderNode {
public:
    Item item;
    OrderNode* next;

    OrderNode(Item item) : item(item), next(nullptr) {}
};

// Define the Queue class using linked list for orders
class OrderQueue {
private:
    OrderNode* front;
    OrderNode* rear;

public:
    OrderQueue() : front(nullptr), rear(nullptr) {}

    // Enqueue an order into the queue
    void enqueue(Item item) {
        OrderNode* newNode = new OrderNode(item);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue the prepared order
    Item dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return Item("Empty");
        }
        OrderNode* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        Item dequeuedItem = temp->item;
        delete temp;
        return dequeuedItem;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    // Display the waiting list (current queue)
    void displayQueue() {
        if (isEmpty()) {
            cout << "No orders in the waiting list.\n";
            return;
        }
        OrderNode* temp = front;
        cout << "Waiting List:\n";
        while (temp != nullptr) {
            cout << temp->item.name << " with ingredients: ";
            temp->item.showIngredients();
            temp = temp->next;
        }
        cout << endl;
    }
};

// Function to customize and prepare a burger order
Item prepareBurger() {
    Item burger("Burger");
    cout << "\nCustomizing your Burger. \nChoose ingredients: \n";
    cout << "\t1. Cheese\n\t2. Lettuce\n\t3. Tomato\n\t4. Pickles\n\t5. Onion\n";
    int choice;
    do {
        cout << "[1 for Cheese, 2 for Lettuce, 3 for Tomato, 4 for Pickles, 5 for Onion, 6 to finish]: ";
        cin >> choice;
        switch (choice) {
            case 1:
                burger.addIngredient("Cheese");
                break;
            case 2:
                burger.addIngredient("Lettuce");
                break;
            case 3:
                burger.addIngredient("Tomato");
                break;
            case 4:
                burger.addIngredient("Pickles");
                break;
            case 5:
                burger.addIngredient("Onion");
                break;
            case 6:
                cout << "Burger customization finished.\n";
                return burger;
            default:
                cout << "Invalid input!\n";
        }
    } while (choice != 6);

    return burger;
}

// Function to customize and prepare a sandwich order
Item prepareSandwich() {
    Item sandwich("Sandwich");
    cout << "\nCustomizing your Sandwich.\nChoose ingredients: \n";
    cout << "\t1. Cheese\n\t2. Lettuce\n\t3. Tomato\n\t4. Chicken\n\t5. Mayo\n";
    int choice;
    do {
        cout << "[1 for Cheese, 2 for Lettuce, 3 for Tomato, 4 for Chicken, 5 for Mayo, 6 to finish]: ";
        cin >> choice;
        switch (choice) {
            case 1:
                sandwich.addIngredient("Cheese");
                break;
            case 2:
                sandwich.addIngredient("Lettuce");
                break;
            case 3:
                sandwich.addIngredient("Tomato");
                break;
            case 4:
                sandwich.addIngredient("Chicken");
                break;
            case 5:
                sandwich.addIngredient("Mayo");
                break;
            case 6:
                cout << "Sandwich customization finished.\n";
                break;
            default:
                cout << "Invalid input!\n";
        }
    } while (choice != 6);

    return sandwich;
}

// Function to customize and prepare a pizza order
Item preparePizza() {
    Item pizza("Pizza");
    cout << "\nCustomizing your Pizza. \nChoose ingredients: \n";
    cout << "\t1. Cheese\n\t2. Pepperoni\n\t3. Mushrooms\n\t4. Olives\n\t5. Onion\n";
    int choice;
    do {
        cout << "[1 for Cheese, 2 for Pepperoni, 3 for Mushrooms, 4 for Olives, 5 for Onion, 6 to finish]: ";
        cin >> choice;
        switch (choice) {
            case 1:
                pizza.addIngredient("Cheese");
                break;
            case 2:
                pizza.addIngredient("Pepperoni");
                break;
            case 3:
                pizza.addIngredient("Mushrooms");
                break;
            case 4:
                pizza.addIngredient("Olives");
                break;
            case 5:
                pizza.addIngredient("Onions");
                break;
            case 6:
                cout << "Pizza customization finished.\n";
                break;
            default:
                cout << "Invalid input!\n";
        }
    } while (choice != 6);

    return pizza;
}

// Function to prepare a cold drink order (no customization)
Item prepareColdDrink() {
    Item coldDrink("Cold Drink");
    cout << "Preparing your cold drink...\n";
    coldDrink.addIngredient("Ice");
    coldDrink.addIngredient("Soda");
    return coldDrink;
}

// Function to customize and prepare a hot dog order
Item prepareHotDog() {
    Item hotDog("Hot Dog");
    cout << "\nCustomizing your Hot Dog. \nChoose ingredients: \n";
    cout << "\t1. Ketchup\n\t2. Mustard\n\t3. Onion\n\t4. Pickles\n\t5. Cheese\n";
    int choice;
    do {
        cout << "[1 for Ketchup, 2 for Mustard, 3 for Onion, 4 for Pickles, 5 for Cheese, 6 to finish]: ";
        cin >> choice;
        switch (choice) {
            case 1:
                hotDog.addIngredient("Ketchup");
                break;
            case 2:
                hotDog.addIngredient("Mustard");
                break;
            case 3:
                hotDog.addIngredient("Onions");
                break;
            case 4:
                hotDog.addIngredient("Pickles");
                break;
            case 5:
                hotDog.addIngredient("Cheese");
                break;
            case 6:
                cout << "Hot Dog customization finished.\n";
                break;
            default:
                cout << "Invalid input!\n";
        }
    } while (choice != 6);

    return hotDog;
}

// Function to display history of processed orders
void displayHistory(list<Item>& history) {
    if (history.empty()) {
        cout << "No orders have been processed yet.\n";
        return;
    }

    cout << "\nOrder History:\n";
    for (list<Item>::iterator it = history.begin(); it != history.end(); ++it) {
        cout << it->name << " with ingredients: ";
        it->showIngredients();
    }
    cout << endl;
}

int main() {
    OrderQueue orderQueue;
    list<Item> orderHistory; // List to store completed orders
    int choice;

    do {
        cout << "\n---- QuickBite  :The order management system ----\n";
        cout << "1. Burger\n2. Sandwich\n3. Pizza\n4. Cold-drink\n5. Hot-dog\n6. Show Order History\n7. Confirm Order\n8. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Item burger = prepareBurger();
                orderQueue.enqueue(burger);
                break;
            }
            case 2: {
                Item sandwich = prepareSandwich();
                orderQueue.enqueue(sandwich);
                break;
            }
            case 3: {
                Item pizza = preparePizza();
                orderQueue.enqueue(pizza);
                break;
            }
            case 4: {
                Item coldDrink = prepareColdDrink();
                orderQueue.enqueue(coldDrink);
                break;
            }
            case 5: {
                Item hotDog = prepareHotDog();
                orderQueue.enqueue(hotDog);
                break;
            }
            case 6: // Show Order History
                displayHistory(orderHistory);
                break;
            case 7: // Confirm and serve all orders
                cout << "Confirming your order. Items in the order:\n";
                orderQueue.displayQueue(); // Display all items
                while (!orderQueue.isEmpty()) {
                    Item preparedOrder = orderQueue.dequeue();
                    cout << "Serving order: " << preparedOrder.name << endl;
                    orderHistory.push_back(preparedOrder); // Add the served order to history
                }
                break;
            case 8:
                cout << "Exit...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8); // Corrected to exit on choice 8
    return 0;
}
