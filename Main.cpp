#include <iostream>
#include <chrono>
#include <locale>

using namespace std;
using namespace std::chrono;

const int SIZE = 10;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size)
{
    cout << "Сортировка методом пузырька:\n";
    int temp;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++)
    {
        cout << "Итерация " << i + 1 << ":\n";
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            printArray(arr, size);
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Время сортировки методом пузырька: " << duration.count() << " микросекунд\n\n";
}

void insertionSort(int arr[], int size)
{
    cout << "Сортировка методом вставок:\n";
    int key, j;
    auto start = high_resolution_clock::now();

    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        cout << "Итерация " << i << ":\n";
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            printArray(arr, size);
        }
        arr[j + 1] = key;
        printArray(arr, size);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Время сортировки методом вставок: " << duration.count() << " микросекунд\n\n";
}

void selectionSort(int arr[], int size)
{
    cout << "Сортировка методом выбора:\n";
    int minIndex, temp;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        cout << "Итерация " << i + 1 << ":\n";
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            printArray(arr, size);
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        printArray(arr, size);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Время сортировки методом выбора: " << duration.count() << " микросекунд\n\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int array[SIZE] = { 1, 3, 5, 7, 9, 7, 5, 3, 1, 0 };

    cout << "Исходный массив:\n";
    printArray(array, SIZE);
    cout << endl;

    int arrayBubble[SIZE];
    int arrayInsertion[SIZE];
    int arraySelection[SIZE];

    // Копируем исходный массив для каждой сортировки
    for (int i = 0; i < SIZE; i++)
    {
        arrayBubble[i] = array[i];
        arrayInsertion[i] = array[i];
        arraySelection[i] = array[i];
    }

    bubbleSort(arrayBubble, SIZE);
    insertionSort(arrayInsertion, SIZE);
    selectionSort(arraySelection, SIZE);

    return 0;
}
