#include <iostream>

using namespace std;
const int FIELD_SIZE = 10;
const int ARRAY_SIZE = 5;
const int START_X = 5;
const int START_Y = 0;

void display_field(int field_size, int cow_x[], int cow_y[], int array_size);
void move_cow(int cow_x[], int cow_y[], int array_size);

int main() {
    // Initialize the cows
    int cow_x[ARRAY_SIZE];
    int cow_y[ARRAY_SIZE];
    for (int i=0; i<ARRAY_SIZE; i++) {
        cow_x[i]=START_X;
        cow_y[i]=START_Y;
    }

    string s;

    // Create a loop that causes the cow to meander across the field
    for (int i = 0; i < FIELD_SIZE; i++) {
        display_field(FIELD_SIZE, cow_x, cow_y, ARRAY_SIZE);
        move_cow(cow_x, cow_y, ARRAY_SIZE);
        getline(cin,s); //Pause and wait for a key press between loop iterations
    }

    cout << "The cows have arrived." << endl;
    return 0;
}

// Here's the definition of that function we saw earlier...
void display_field(int field_size, int cow_x[], int cow_y[], int array_size) {
    //display a 'field' of X's with a single O marking the cow's location
    for (int j = 0; j < field_size; j++) {
        for (int k = 0; k < field_size; k++) {
            bool flag = false;
            for (int z = 0; z<array_size; z++) {
                if (flag == false && cow_x[z] == k && cow_y[z] == j) {
                    cout << "O";
                    flag = true;
                }
            }
            if (flag == false) {
                cout << "x";
            }
        }
        cout << endl;
    }
}

// and here's the definition of the other function
void move_cow(int cow_x[], int cow_y[], int array_size) {
    for (int i=0; i<array_size; i++) {
        int r = rand() % 3;            //generate a random number
        if (r == 0) cow_x[i]--;           //if the number is 0, move left
        if (r == 1);                   //if the number is 1, no change
        if (r == 2) cow_x[i]++;           //if the number is 2, move right
        cow_y[i]++;                       //always move one step forward
    }
}
