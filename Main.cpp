#include <iostream>
#include <chrono>
#include <locale>

using namespace std;
using namespace std::chrono;

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
    cout << "���������� ������� ��������:\n";
    int temp;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++)
    {
        cout << "�������� " << i + 1 << ":\n";
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
    cout << "����� ���������� ������� ��������: " << duration.count() << " �����������\n\n";
}

void insertionSort(int arr[], int size)
{
    cout << "���������� ������� �������:\n";
    int key, j;
    auto start = high_resolution_clock::now();

    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        cout << "�������� " << i << ":\n";
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
    cout << "����� ���������� ������� �������: " << duration.count() << " �����������\n\n";
}

void selectionSort(int arr[], int size)
{
    cout << "���������� ������� ������:\n";
    int minIndex, temp;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        cout << "�������� " << i + 1 << ":\n";
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
    cout << "����� ���������� ������� ������: " << duration.count() << " �����������\n\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int array[] = { 1, 3, 5, 7, 9, 7, 5, 3, 1, 0 };
    const int size = sizeof(array) / sizeof(array[0]);

    cout << "�������� ������:\n";
    printArray(array, size);
    cout << endl;

    int arrayBubble[size];
    int arrayInsertion[size];
    int arraySelection[size];

    // �������� �������� ������ ��� ������ ����������
    for (int i = 0; i < size; i++)
    {
        arrayBubble[i] = array[i];
        arrayInsertion[i] = array[i];
        arraySelection[i] = array[i];
    }

    bubbleSort(arrayBubble, size);
    insertionSort(arrayInsertion, size);
    selectionSort(arraySelection, size);

    return 0;
}
