
// FIRST comparable algorithm
// heapsort, quicksort, mergesort descending order usage rates and best counters in said generation (like no comparing gen 1 to gen 7)

#include <iostream>
#include <vector>
#include <string>
#include "pokemon.h"

// Declare the readFiles function from pokeFile.cpp
std::vector<Pokemon> readFiles();
// Filter by generation
std::vector<Pokemon> filterByGen1(const std::vector<Pokemon>& pokemons) {
    std::vector<Pokemon> result;
    for (const auto& p : pokemons) {
        if (p.generation == 1) {
            result.push_back(p);
        }
    }

    std::cout << "Filtered Gen 1 count: " << result.size() << std::endl;  // ✅ Inside function
    return result;
}

// Display top N Pokémon
void displayPokemonList(const std::vector<Pokemon>& pokemons, int count) {
    for (int i = 0; i < std::min(count, (int)pokemons.size()); ++i) {
        const Pokemon& p = pokemons[i];
        std::cout << p.name << " | Atk: " << p.atk << " | BST: " << p.total
                  << " | Type: " << p.type1;
        if (!p.type2.empty()) std::cout << "/" << p.type2;
        std::cout << std::endl;
    }
}

// Quick Sort
int partition(std::vector<Pokemon>& arr, int low, int high) {
    int pivot = arr[high].atk;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].atk > pivot) { // Descending order
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<Pokemon>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(std::vector<Pokemon>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Pokemon> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].atk > R[j].atk) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<Pokemon>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

//Heap Sort
void heapify(std::vector<Pokemon>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].atk > arr[largest].atk) largest = l;
    if (r < n && arr[r].atk > arr[largest].atk) largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<Pokemon>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    // Reverse for descending order
    std::reverse(arr.begin(), arr.end());
}

int main() {
    std::vector<Pokemon> allPokemon = readFiles();

    std::cout << "Immediately after readFiles(), count = " << allPokemon.size() << std::endl;
    if (!allPokemon.empty()) {
        std::cout << "First entry: " << allPokemon[0].name << ", Gen: " << allPokemon[0].generation << std::endl;
    }
    // Filter Gen 1
    std::vector<Pokemon> gen1Pokemon = filterByGen1(allPokemon);
    std::cout << "Gen 1 count: " << gen1Pokemon.size() << std::endl;
    // Make 3 copies for each sort
    std::vector<Pokemon> quickList = gen1Pokemon;
    std::vector<Pokemon> mergeList = gen1Pokemon;
    std::vector<Pokemon> heapList = gen1Pokemon;

    quickSort(quickList, 0, quickList.size() - 1);
    mergeSort(mergeList, 0, mergeList.size() - 1);
    heapSort(heapList);

    std::cout << "Quick Sort by Attack:\n";
    displayPokemonList(quickList, 10);

    std::cout << "\nMerge Sort by Attack:\n";
    displayPokemonList(mergeList, 10);

    std::cout << "\nHeap Sort by Attack:\n";
    displayPokemonList(heapList, 10);

    return 0;
}

