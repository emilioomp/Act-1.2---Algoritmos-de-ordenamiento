#include <iostream>
#include <string>

using namespace std;

class Objeto
{
    private:
        
        string nombre;
        int valor;

    public:
        
        string getNombre()
        {
            return nombre;
        }

        int getValor()
        {
            return valor;
        }

        void setNombre(string nombre)
        {
            this -> nombre = nombre;
        }

        void setValor(int valor)
        {
            this -> valor = valor;
        }

        Objeto()
        {
            nombre = "";
            valor = 0;
        }

        Objeto(string nombre, int valor)
        {
            this -> nombre = nombre;
            this -> valor = valor;
        }

        bool operator< ( const Objeto& otro ) const {  
            return this->valor < otro.valor ;    
        }

        bool operator> ( const Objeto& otro ) const {  
            return this->valor > otro.valor ;    
        }

        bool operator<= ( const Objeto& otro ) const {  
            return this->valor <= otro.valor ;    
        }

};

template<class T>
void insertionSort(T *A, int n)
{	
	int i, j;
    T c;

    for(i = 0; i < n; i++){
        c = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > c) {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = c;
    }
    
    return;
}

template<class T>
void selectionSort(T *A, int n)
{
    int i, j, indexMin;
    T aux;

    for (i = 0; i < n; i++){
        indexMin = i;

        for (j = i+1; j < n; j++){
            if (A[j] < A[indexMin]){
                indexMin = j;
            }
        }

        aux = A[indexMin];
        A[indexMin] = A[i];
        A[i] = aux;
    }
    
    return;
}

template<class T>
void swapSort (T *A, int n)
{	
    int i, j;
    T aux;

    for (i = 0; i < n-1; i++){
        for (j = i+1; j < n; j++){
            if (A[i] > A[j]){
                aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
        }
    }

	return;
}

template<class T>
void bubbleSort(T *A, int n)
{	
	int i, j;
    T aux;
    bool change;

    for (i = 0; i < n-1; i++){
        change = false;

        for (j = 0; j < n-i-1; j++){
            if (A[j] > A[j+1]){
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                change = true;
            }
        }

        if (change == false){
            break;
        }
    }
    
    return;
}

template<class T>
void merge(T *A, int l, int m, int r)
{
    int i, j, k, s1, s2;

    s1 = m - l + 1;
    s2 = r - m;

    T *L = new T[s1];
    T *R = new T[s2];

    for (i = 0; i < s1; i++){
        L[i] = A[l+i];
    }

    for (j = 0; j < s2; j++){
        R[j] = A[m+j+1];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < s1 && j < s2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < s1){
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < s2){
        A[k] = R[j];
        j++;
        k++;
    }

    return;
}

template<class T>
void mergeSort(T *A, int l, int r)
{	
	int m;

    if (l < r){
        m = l + (r - l) / 2;

        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
    
    return;
}

template<class T>
int partition(T *A, int l, int r)
{
    int i, j;
    T pivot, aux;

    pivot = A[r];
    i = l - 1;

    for (j = l; j < r; j++){
        if (A[j] < pivot){
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }

    aux = A[i+1];
    A[i+1] = A[r];
    A[r] = aux;

    return (i + 1);
}


template<class T>
void quickSort(T *A, int l, int r)
{	
    int pivot;
	
    if (l < r){
        pivot = partition(A, l, r);
        quickSort(A, l, pivot - 1);
        quickSort(A, pivot + 1, r);
    }
    
    return;
}

template<class T>
void printArray (T A[], int n)
{	int i;
	cout<<"\nArreglo:\n";
	for (i = 0; i < n; i++)
	{	cout << " " << A[i].getNombre() << " - " << A[i].getValor() << " gold\n";	}
	cout<<endl;

	return;
}

int main(int argc, char* argv[])
{
    const int n = 10;

    Objeto arreglo[n] = {
        Objeto("Iron Sword", 50),
        Objeto("Leather Armor", 75),
        Objeto("Health Potion", 10),
        Objeto("Mana Potion", 12),
        Objeto("Steel Shield", 60),
        Objeto("Bow & 20 Arrows", 40),
        Objeto("Magic Ring", 120),
        Objeto("Fire Spell Scroll", 30),
        Objeto("Traveler's Boots", 25),
        Objeto("Amulet of Protection", 200)
    };

    Objeto arreglo1[n] = {
        Objeto("Iron Sword", 50),
        Objeto("Leather Armor", 75),
        Objeto("Health Potion", 10),
        Objeto("Mana Potion", 12),
        Objeto("Steel Shield", 60),
        Objeto("Bow & 20 Arrows", 40),
        Objeto("Magic Ring", 120),
        Objeto("Fire Spell Scroll", 30),
        Objeto("Traveler's Boots", 25),
        Objeto("Amulet of Protection", 200)
    };

    Objeto arreglo2[n] = {
        Objeto("Iron Sword", 50),
        Objeto("Leather Armor", 75),
        Objeto("Health Potion", 10),
        Objeto("Mana Potion", 12),
        Objeto("Steel Shield", 60),
        Objeto("Bow & 20 Arrows", 40),
        Objeto("Magic Ring", 120),
        Objeto("Fire Spell Scroll", 30),
        Objeto("Traveler's Boots", 25),
        Objeto("Amulet of Protection", 200)
    };

    Objeto arreglo3[n] = {
        Objeto("Iron Sword", 50),
        Objeto("Leather Armor", 75),
        Objeto("Health Potion", 10),
        Objeto("Mana Potion", 12),
        Objeto("Steel Shield", 60),
        Objeto("Bow & 20 Arrows", 40),
        Objeto("Magic Ring", 120),
        Objeto("Fire Spell Scroll", 30),
        Objeto("Traveler's Boots", 25),
        Objeto("Amulet of Protection", 200)
    };

    Objeto arreglo4[n] = {
        Objeto("Iron Sword", 50),
        Objeto("Leather Armor", 75),
        Objeto("Health Potion", 10),
        Objeto("Mana Potion", 12),
        Objeto("Steel Shield", 60),
        Objeto("Bow & 20 Arrows", 40),
        Objeto("Magic Ring", 120),
        Objeto("Fire Spell Scroll", 30),
        Objeto("Traveler's Boots", 25),
        Objeto("Amulet of Protection", 200)
    };

    Objeto arreglo5[n] = {
        Objeto("Iron Sword", 50),
        Objeto("Leather Armor", 75),
        Objeto("Health Potion", 10),
        Objeto("Mana Potion", 12),
        Objeto("Steel Shield", 60),
        Objeto("Bow & 20 Arrows", 40),
        Objeto("Magic Ring", 120),
        Objeto("Fire Spell Scroll", 30),
        Objeto("Traveler's Boots", 25),
        Objeto("Amulet of Protection", 200)
    };

    Objeto arreglo6[n] = {
        Objeto("Iron Sword", 50),
        Objeto("Leather Armor", 75),
        Objeto("Health Potion", 10),
        Objeto("Mana Potion", 12),
        Objeto("Steel Shield", 60),
        Objeto("Bow & 20 Arrows", 40),
        Objeto("Magic Ring", 120),
        Objeto("Fire Spell Scroll", 30),
        Objeto("Traveler's Boots", 25),
        Objeto("Amulet of Protection", 200)
    };

    printArray(arreglo, n);
	
    cout << "\n\nInsertion-Sort"<< endl;
	insertionSort(arreglo1, n);
	printArray(arreglo1, n);

    cout << "\n\nSelection-Sort"<< endl;
	selectionSort(arreglo2, n);
	printArray(arreglo2, n);

    cout << "\n\nSwap-Sort"<< endl;
	swapSort(arreglo3, n);
	printArray(arreglo3, n);

    cout << "\n\nBubble-Sort"<< endl;
	bubbleSort(arreglo4, n);
	printArray(arreglo4, n);

    cout << "\n\nMerge-Sort"<< endl;
	mergeSort(arreglo5, 0, n - 1);
	printArray(arreglo5, n);

	cout << "\n\nQuick-Sort"<< endl;
	quickSort(arreglo6, 0, n - 1);
	printArray(arreglo6, n);

}