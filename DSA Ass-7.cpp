#include<iostream>
#include <cmath>
using namespace std;
const int SIZE = 10;
int hashTable[SIZE];
 void intilize()
 {
  for(int i = 0; i < SIZE; i++)
   {
    hashTable[i] = -1;
   }
 }

int hashMultiplication(int key)
{
    double A = 0.6180339887;
    return floor(SIZE * fmod(key * A, 1));
}

int hashDivision(int key)
{
    return key % SIZE;
}

int linearProbing(int index)
{
    return (index + 1) % SIZE;
}

int quadraticProbing(int index, int i)
{
    return (index + i * i) % SIZE;
}

void insert(int key, int method)
 {
  int index;
  if (method == 1)
  {
   index = hashMultiplication(key);
  }
  else
  {
   index = hashDivision(key);
  }
  int originalIndex = index;
  int i = 1;
    while (hashTable[index] != -1)
    {
        if (method == 2)
            index = quadraticProbing(originalIndex, i);
        else
            index = linearProbing(index);
        i++;
    }
    hashTable[index] = key;
}

int search(int key, int method)
{
   int index;
   if (method == 1)
   {
    index = hashMultiplication(key);
   }
   else
   {
    index = hashDivision(key);
   }
    int originalIndex = index;
    int i = 1;

    while (hashTable[index] != key)
    {
        if (hashTable[index] == -1) return -1; // Not found
        if (method == 2) // Quadratic probing
            index = quadraticProbing(originalIndex, i);
        else // Linear probing
            index = linearProbing(index);
        i++;
    }
    return index;
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
        {
            cout << i << " -> empty" << endl;
        } else
        {
            cout << i << " -> " << hashTable[i] << endl;
        }
    }
}

int main() {

    int choice, key, method;
    intilize();

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Display\n4. Exit\nChoose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            cout << "Choose method (1: Multiplication, 2: Division): ";
            cin >> method;
            insert(key, method);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            cout << "Choose method (1: Multiplication, 2: Division): ";
            cin >> method;
            int result;
            result = search(key, method);
            if (result != -1)
                cout << "Key found at index " << result << endl;
            else
                cout << "Key not found" << endl;
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice, try again!" << endl;
        }
    }
}
