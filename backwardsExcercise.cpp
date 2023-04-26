//Header files
#include <iostream>
using namespace std;

//Size of char array
const int MAXLEN = 100;

int main() {

        //Variables
        char phrase[MAXLEN];
        char backward[MAXLEN] = { '\0' };
        int length = 0;
        char* start;
        char answer;

        do {
                cout << "Enter a text: ";
                cin.getline(phrase, MAXLEN);

                length = strlen(phrase); //Take length of the phrase entered by user
                start = &phrase[length - 1]; //Assign memory address of last letter to start pointer 

                for (int i = 0; i < length; i++) {
                        backward[i] = *start; // Shift last letter of phrase to the the first slot of char array backward using pointer
                        start--; //Move pointer to previous memory address of char array phrase 
                }

                length = strlen(backward); //Take length of array backward[]
                backward[++length] = { '\0' }; //End with  {'\0'};

                cout << "The text backwards: " << backward << endl << endl;
                memset(backward, 0, sizeof backward); //Clear char array in case of reuse 

                cout << "Do you want to check another word (Y/N)? ";
                cin >> answer;
                cin.ignore(); //Clear buffer 

                cout << endl;

        } while (toupper(answer) == 'Y');

        return 0;
}
