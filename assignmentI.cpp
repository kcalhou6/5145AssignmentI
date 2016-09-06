#include <string.h>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <cstdlib>
using namespace std;

class LLInt {
	private:
		int value;
		LLInt *next;

	public:
		LLInt() {
			this->value = NULL;
			this->next = nullptr;
		}
		LLInt(int value) {
			this->value = value;
			this->next = nullptr;
		}
		LLInt(int value, LLInt * next) {
			this->value = value;
			this->next = next;
		}
		int getValue() {
			return value;
		}
		LLInt * getNext() {
			return next;
		}
};

class LinkedList {
	private:
		LLInt *head;
		int size;
		
	public:
		LinkedList() {
			head = nullptr;
		}
		void insert(int value) {
			LLInt *l = new LLInt(value, head);
			head = l;
		}
		LLInt * getHead() {
			return head;
		}
		//returns pointer to int val if val is found in the list
		//or -1 if the val is not found
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
	LinkedList lL;
	
	//Insert argv[1] # of random integers into the linked list
	for (int a = 0; a < atoi(argv[1]); a++) {
		lL.insert(rand() % 100000);
	}
	timeval start, end;
	for (int a = 0; a < atoi(argv[2]); a++) {
		gettimeofday(&start, NULL);
		LLInt *found = lL.find(rand() % 100000);
		gettimeofday(&end, NULL);
		cout << found << endl;
		cout << (end.tv_usec - start.tv_usec) << endl;
	}
}