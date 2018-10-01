#include <iostream>
using namespace std;

void swap(int *x, int *y){

  int temp = *x;
  *x = *y;
  *y = temp;
}

void display(int data[], int size){

  for(int i=0;   i<size ; i++){
    cout << data[i] << " ";
  }
  cout << endl;
}

int partition(int data[], int low, int high){

  int pivot = data[high];
  int pId = low;  //Partition index

  for(int i=low; i < high ; i++){

    if(data[i] < pivot){

      swap(&data[pId], &data[i]);
      pId++;
    }
  }
  swap(&data[pId], &data[high]);
  return pId;
}

void quick_sort(int data[], int low, int high){

  if(low < high){
    int pId = partition(data, low, high);

    quick_sort(data, low, pId - 1);
    quick_sort(data, pId + 1, high);
  }
}

int main(){

  int data[] = {11, 55, 9, 44, 26, 22, 78, 0, 12, 5};
  int size = 10;
  display(data, size);
  quick_sort(data, 0, size-1);
  display(data, size);
  return 0;
}
