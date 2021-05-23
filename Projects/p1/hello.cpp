#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


// I did not use any outside resource aside from the professors notes and instructions.

// This is a Harry Potter reference btw. Its not a real dialogue, just a parody I came up with. It is Similar to how in one of the movies Harry was talking to a sentient diary, which actually contained the soul of the main villain of the series.

int main()

{

string YourName, MotherName;

 cout << "What is your name?"<< endl;
 getline(cin, YourName);

 cout << "Hmm interesting... So your name is " << YourName <<"." <<" Well nice to meet you " << YourName << "." << " My name is Tom Riddle." << " If you don't mind me asking, what was the name of your mother? " << endl;

 getline(cin, MotherName);


 cout << "Well, as I suspected... Ever wonder how your sweet little mother died?" << " Poor " << MotherName <<  " was killed by NONE OTHER THAN YOUR PROFESSOR DUMBLEDORE!" << endl;

return 0;

}




