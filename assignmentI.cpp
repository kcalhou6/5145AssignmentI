#include <string.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

//Each node of the linked list will be represented by the class LLInt
class LLInt {
	//Instance variables value to hold the integer value of the node
	//and *next to hold a pointer to the next node in the linked list
	private:
		int value;
		LLInt *next;

	public:
		//Default constructor, sets value to be null and *next to be the
		//null pointer
		LLInt() {
			this->value = NULL;
			this->next = nullptr;
		}
		//Overloaded constructor which takes a parameter for the value,
		//sets value to the provided value and *next to be the null pointer
		LLInt(int value) {
			this->value = value;
			this->next = nullptr;
		}
		//Overloaded constructor which takes parameters for the value and
		//next pointer, sets value to the provided value and *next to the
		//provided pointer
		LLInt(int value, LLInt * next) {
			this->value = value;
			this->next = next;
		}
		//Helper method which returns the integer value
		int getValue() {
			return value;
		}
		//Helper method which returns the next node pointer
		LLInt * getNext() {
			return next;
		}
};

//Class to provided linked list implementation
class LinkedList {
	//Instance variable *head to hold a pointer to the first node in the
	//linked list
	private:
		LLInt *head;
		
	public:
		//Default constructor for an empty linked list, sets *head to
		//the null pointer
		LinkedList() {
			head = nullptr;
		}
		//Helper method which takes a parameter for value and creates
		//a new node for the linkedList with the provided value and
		//pointer to the current head node then inserts it into the linked
		//list by marking it as the head node. 
		void insert(int value) {
			LLInt *l = new LLInt(value, head);
			head = l;
		}
		//Helper method which returns the head pointer
		LLInt * getHead() {
			return head;
		}
		//Helper method which take a parameter value and searches for a
		//node in the linked list with the provided value. Returns a
		//pointer to the LLInt if val is found in the list or nullptr if the
		//val is not found
		LLInt * find(int val) {
			LLInt *current = head;
			while(current->getNext() != NULL) {
				if(current->getValue() == val)
					return current;
				current = current->getNext();
			}
			if(current->getValue() == val)
				return current;
			return nullptr;
		}
};

int main(int argc, char *argv[])
{
	//Create an initially empty linked list
	LinkedList lL;
	
	//Setup a text file for output of search times corresponding to linked list
	//size
	ofstream statFile;
	statFile.open ("stats.txt", ios::app);
	
	//Insert command line argument #1 number of random integers into the
	//linked list with values in the range 0-1000000000000
	for (int a = 0; a < atoi(argv[1]); a++) {
		lL.insert(rand() % 1000000000000);
	}
	
	statFile << "Number of Ints: " << atoi(argv[1]) << endl;
	int search;
	//timeval start, end;
	timespec start, end;
	
	//Search for command line argument #2 number of random integers in the linked
	//list with values in a range 0-1000000000000000, and write the time each
	//search takes to the stats file
	for (int a = 0; a < atoi(argv[2]); a++) {
		search = (rand() % 1000000000000000);
		clock_gettime(CLOCK_REALTIME, &start);
		LLInt *found = lL.find(search);
		clock_gettime(CLOCK_REALTIME, &end);
		if ((end.tvnsec-start.tv_nsec) < 0)
			statFile << (ent.tv_sec - start.tv_sec - 1) << ":" << (end.tv_nsec - start.tv_nsec + 1000000000) << endl;
		else		
			statFile << (end.tv_sec - start.tv_sec) << ":" << (end.tv_nsec - start.tv_nsec) << endl;
	}
	statFile << "\n";
	statFile.close();
}
