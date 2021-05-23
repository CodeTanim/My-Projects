/*
 * CSc103 Project 4: Sorting with lists
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:

 *https://www.youtube.com/watch?v=VOQNF1VxU3Q


 *https://www.youtube.com/watch?v=njTh_OwMljA&t=136s

  * Attended peer tutoring with Samira Chowdhury to further some concepts.

 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:  18-22 hours spread out over a week.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;

/* doubly linked list node: */
struct node {
	string data;
	node* prev;
	node* next;
	node(string s="", node* p=NULL, node* n=NULL) : data(s),prev(p),next(n) {}
};



//Reverses the sorted list and prints it out. It first goes to the end of the list, then goes back by doing i->prev.
void Reverse(node *&head) {


  node* i = head;
  while(i->next!=NULL) {

      i = i->next;


}

while(i!=NULL) {


  cout << i->data<<endl;

  i = i->prev;


  }


}


// Removes/deletes the duplicates of the list
void removeduplicates(node*&head) {

  node * i = head;

while(i->next!=NULL) {

  // First checks the head case

   if(head->data == head->next->data ) {

    node * p = head;

    head->next->prev = NULL;

    head = head->next;


    //iterates i if the match is found
      i = i->next;

     delete p; // deletes the node with the duplicate


    continue;
  }

//  for all the in between and middle case
  if(i->data == i->next->data) {

   node* p = i;

    i->next->prev = i->prev;


    i->prev->next = i->next;

     i = i->next;

    delete p;



  }


  else {


//Shifts to the next node if no match is found.
     i = i->next;

    }

   }
}



//Function to display the sorted list.
void display(node*&head) {

  node *i = head;

while(i!=NULL) {

	cout << i->data <<endl;

      i = i->next;

 }

}










int main(int argc, char *argv[]) {
	/* define long options */
	static int unique=0, reverse=0;
	static struct option long_opts[] = {
		{"unique",
			no_argument,       &unique,   'u'},
		{"reverse",  no_argument,       &reverse,  'r'},
		{0,0,0,0} // this denotes the end of our options.
	};
	/* process options */
	char c; /* holds an option */
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "ur", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'u':
				unique = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case '?': /* this will catch unknown options. */
				return 1;
		}
	}
	/* NOTE: at this point, variables 'reverse' and 'unique' have been set
	 * according to the command line.  */
	/* TODO: finish writing this.  Maybe use while(getline(cin,line)) or
	 * similar to read all the lines from stdin. */

	string s,s1,s2;

	getline(cin,s);

	node* head = new node;

  head->data = s;
	head->next = NULL;
	head->prev = NULL;

  getline(cin,s1);

  node* e = new node;

  e->data = s1;

if(e->data <= head->data) {

  e->next = head;

  e->prev = NULL;

  head->prev = e;

  head = e;


}

else {


  e->prev = head;

  e->next = NULL;

  head->next = e;


}

//The lines of code above explicitly takes two nodes with string data and sorts them alphabetically.



//This is the main while loop
while(getline(cin,s2)) {
//need a pointer whose job is to just point and check the data in each node. It should start by pointing to the beginning of the list.


  //Checks the inputted string with the data at the beginning of the list and determines if a new node should become the new head.
   if(s2 <= head->data) {

     node* newnode = new node;

     newnode->data = s2;

     head->prev = newnode;

     newnode->next = head;

     head = newnode;

   }

   // If its not the head case then it means its after the head and potentially between two nodes OR after the very last node in the list.
   else {

    node* p = head->next;
//This the middle case where the new nodes might be between two other nodes
   while(p!= NULL) {

     if( s2 <=  p->data ) {


       node* newnode = new node;

       newnode->data = s2;

		   p->prev->next = newnode;

       newnode->prev = p->prev;

       p->prev = newnode;

       newnode->next = p;


       break;

     }

     //if temp->next ever reaches NULL then it means you reached the end of ur list and it means the new string line has to be sorted at the end of the list.
     else if (p->next == NULL) {

       node* newnode = new node;

       newnode->data = s2;

       p->next = newnode;

       newnode->prev = p;

       break;

     }

     //moves the temporary node along the list and connects in      a     sorted order inside the second while loop which assumes that the head is sorted and the new line doesnt satisfy the condition of the first if statement.
     p = p->next;


   }

 }


}

//cout << endl;

//All the different command line options using -u and -r for unique and reverse respectively.

if(unique == 1 && reverse != 1 ) {

  removeduplicates(head);

  display(head);

}

else if(reverse == 1 && unique !=1) {

  Reverse(head);


}

else if(unique == 1 && reverse ==1) {

  removeduplicates(head);

  Reverse(head);



}

else {


  display(head);


}

	return 0;
}
