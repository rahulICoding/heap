// rahul iyer
// heap
// prints largest num as root and foes down as a tree making the largest values at the top
// mar 5

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

void print(int* heap, int temp, int indents);
void heapSort(int* heap, int counter);

int main() {
  // intializing heap variables
  int counter = 0;
  int* heap = new int[100];
  for(int i = 0; i<100; i++){ //initialize all to 0
    heap[i] = 0;
  }

  char input[10];
  bool running = true;

  // keep runnig till false
  while (running == true) {
    cout << "" << endl;
    cout << "Do you want to 'add', 'import', 'print', 'delete', or 'quit'" << endl;

    cin.get(input, 10);
    cin.ignore(1, '\n');

    if (strcmp("add", input) == 0) { // adds number
      int num;
      bool done = false;
      if (counter >= 100) { // checks if heap is full
        cout << "heap full" << endl;
      }
      else { // adds number to heap
        cout << "input num and when done input -1" << endl;
        while (done == false) {
          cin >> num;
          cin.ignore(1, '\n');
          if (num >= 1 && num <= 1000) {
            heap[counter] = num;
            counter++;
          }
          else if (num == -1) {
            done = true;
            cout << "done" << endl;
            heapSort(heap, counter);
          }
          else {
            cout << "re enter" << endl;
          }
        }
      }
    }
    else if (strcmp("import", input) == 0) { // generate num
      ifstream numbers;
      numbers.open("num.txt");
      int count = 0;

      if (counter > 100) { // heap full?
        break;
      }
      for (int i = counter; i < 20; i++) { // num to heap from files
        if (counter > 100) { //if full
          break;
        }
        else {
          numbers >> heap[i]; //count added
          counter++;
        }
      }
      numbers.close();
      heapSort(heap, counter); //heapsort
    }
    else if (strcmp("print", input) == 0) { // prints all students inputted
      if (counter == 0) { // checks if heap is empty
      }
      else { // prints heap if not empty
        cout << "print..." << endl;
        print(heap, 0, 0);
      }
    }
    else if (strcmp("delete", input) == 0) { // either deletes root or deletes whole list
      char inputDelete[10];
      cout << "do you want to delete the root or all" << endl;
      cin.get(inputDelete, 10);
      cin.ignore(1, '\n');

      if (strcmp("root", inputDelete) == 0) { // deletes root of the heap (largest num)
        if (counter == 0) { // checks if heap is empty
        }
        else { // deletes root if heap is not empty
          cout << "Deleted: " << heap[0] << endl;
          for (int i = 0; i < counter; i++) {
            heap[i] = heap[i + 1];
          }
          counter--; //subtract one count for root
          heapSort(heap, counter);
        }
      }
      else if (strcmp("all", inputDelete) == 0) { // delete list
        for (int i = 0; i < 100; i++) { //initialize all to 0 reset!
          heap[i] = 0;
        }
        counter = 0;
      }
      else {
        cout << "re enter" << endl;
      }
    }
    else if (strcmp("quit", input) == 0) { // ends program
      cout << "done" << endl;
      running = false;
    }
    else {
      cout << "re enter" << endl;
    }
  }  
  return 0;
}

void heapSort(int* heap, int heapCount) {
  for (int current = 0; current < heapCount - 1; current++) { //itereates through the heap 
    for (int next = current + 1; next < heapCount; next++) { //iterates through the help after teh current to commpare 
      if (heap[current] < heap[next]) { //swap parent with child and swaps them
        int temp = heap[current];
        heap[current] = heap[next];
        heap[next] = temp;
      }
    }
  }
}


void print(int* heap, int temp, int indent) { //print heap
  if (heap[temp] == 0) { 
    return;
  }
  indent += 5; // adds 5 spaces to indent
  print(heap, temp * 2 + 1, indent); // goes to left child and follows process
  cout << "\n" << endl; // prints new line
  for (int i = 10; i < indent; i++) { // prints spaces between nums
    cout << " ";
  }
  cout << heap[temp] << "\n"; // prints value
  print(heap, temp * 2 + 2, indent); // goes to right child and follows process
}