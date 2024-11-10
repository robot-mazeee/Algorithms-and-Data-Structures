#include <iostream>
#include <string>
using std::string, std::cout;

#define NUM_CARS 10

struct Car
{
    string plate;
    Car *next;
};

int hash_func(string plate) {
    int hash_value = 0;
    int length = plate.length();

    for (int i = 0; i < length; i++) {
        hash_value += int(plate[i]);
        hash_value = (hash_value * int(plate[i])) % NUM_CARS;
    }

    return hash_value;
}

void insert(Car *cars[], Car *car) {
    int hash_value = hash_func(car->plate);
    car->next = cars[hash_value];
    cars[hash_value] = car;
}

void print_table(Car *cars[]) {
    for (int i = 0; i < NUM_CARS; i++) {
        if (cars[i] == NULL) cout << "NULL\n";
        else {
            Car *current = cars[i];
            while (current != NULL) {
                cout << current->plate << " -> ";
                current = current->next;
            }
            cout << '\n';
        }
    }
}

void remove(Car *cars[], string plate) {
    int hash_value = hash_func(plate);
    Car *current = cars[hash_value], *prev = current;

    while (current != NULL) {
        if (current->plate == plate) {
            if (cars[hash_value] == current) {
                cars[hash_value] = cars[hash_value]->next;
            }
            else {
                prev->next = current->next;
            }
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Not Found!";
}

Car *search(Car *cars[], string plate) {
    int hash_value = hash_func(plate);
    Car *current = cars[hash_value], *prev = current;

    while (current != NULL) {
        if (current->plate == plate) {
            cout << "found!" << '\n';
            return current;
        }
        prev = current;
        current = current->next;
    }

    cout << "Not Found!";
    return NULL;
}

int main() {
    Car *cars[NUM_CARS] = {NULL};

    Car car1;
    car1.plate = "AA-00-AA";
    insert(cars, &car1);

    Car car2;
    car2.plate = "BO-90-1P";
    insert(cars, &car2);

    Car car3;
    car3.plate = "BB-00-AA";
    insert(cars, &car3);

    Car car4;
    car4.plate = "CC-00-AA";
    insert(cars, &car4);

    remove(cars, "CC-00-AA");

    Car *car = search(cars, "AA-00-AA");

    print_table(cars);

    return 0;
}