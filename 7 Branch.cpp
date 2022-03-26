#include <iostream>
using namespace std;
int tabs = 0;

struct Branch {
	int data;
	Branch* leftBranch;
	Branch* rightBranch;
};

void start(Branch* brnch);
void creation(int amount, int element, Branch*& brnch);
void showDetour(Branch*& brnch);
void showAdding(int element, Branch*& brnch);
void showDeletion(int element, Branch*& brnch);
void clear(Branch*& brnch);
void add(int dta, Branch*& brnch);
void print(Branch* brnch);
void detour(Branch*& brnch);
void add_el(int dta, Branch*& brnch);
Branch* delete_el(int dta, Branch*& brnch);
void isEmpty(Branch*& brnch);
void freeTree(Branch* brnch);

int main() {
	Branch* brnch = 0;

	start(brnch);

	return 0;
}

void start(Branch* brnch) {
	int amount = 0;
	int element = 0;

	creation(amount, element, brnch);
	showDetour(brnch);
	showAdding(element, brnch);
	showDeletion(element, brnch);
	clear(brnch);
}

void creation(int amount, int element, Branch*& brnch) {
	cout << "Enter amount of elements for tree: ";
	cin >> amount;
	cout << endl;

	cout << "Check tree on emptiness before creation: " << endl;
	isEmpty(brnch);
	cout << endl;

	for (int i = 0; i < amount; i++) {
		add(rand() % 100, brnch);
	}

	cout << "Check tree on emptiness after creation: " << endl;
	isEmpty(brnch);
	cout << endl;

	cout << "Print tree: " << endl;
	print(brnch);
	cout << endl;
}

void showDetour(Branch*& brnch) {
	cout << "Detour: " << endl;
	detour(brnch);
	cout << endl;
}

void showAdding(int element, Branch*& brnch) {
	cout << "Add new element: ";
	cin >> element;
	add_el(element, brnch);

	cout << "Print tree: " << endl;
	print(brnch);
	cout << endl;
}

void showDeletion(int element, Branch*& brnch) {
	cout << "Delete element: ";
	cin >> element;
	delete_el(element, brnch);

	cout << "Print tree: " << endl;
	print(brnch);
	cout << endl;
}

void clear(Branch*& brnch) {
	freeTree(brnch);
	cout << "Tree was deleted" << endl;
}

void add(int dta, Branch*& brnch) {
	if (!brnch) {
		brnch = new Branch;
		brnch->data = dta;
		brnch->leftBranch = 0;
		brnch->rightBranch = 0;
		return;
	}
	else
		if (brnch->data > dta) {
			add(dta, brnch->leftBranch);
		}
		else {
			add(dta, brnch->rightBranch);
		};
}

void print(Branch* brnch) {
	if (!brnch) {
		return;
	}
	else {
		tabs += 5;
	}

	print(brnch->leftBranch);

	for (int i = 0; i < tabs; i++) {
		cout << " ";
	}

	cout << brnch->data << endl;

	print(brnch->rightBranch);

	tabs -= 5;
	return;
}

void detour(Branch*& brnch) {
	if (brnch == NULL) {
		return;
	}
	cout << brnch->data << endl;
	detour(brnch->leftBranch);
	detour(brnch->rightBranch);
}

void add_el(int dta, Branch*& brnch) {
	if (!brnch) {
		brnch = new Branch;
		brnch->data = dta;
		brnch->leftBranch = 0;
		brnch->rightBranch = 0;
		return;
	}
	else {
		if (dta < brnch->data) {
			add_el(dta, brnch->leftBranch);
		}
		else if (dta > brnch->data) {
			add_el(dta, brnch->rightBranch);
		}
	}
}

Branch* delete_el(int dta, Branch*& brnch) {
	if (brnch == NULL) {
		return brnch;
	}

	if (dta == brnch->data) {
		Branch* temp;

		if (brnch->rightBranch == NULL) {
			temp = brnch->leftBranch;
		}
		else {
			Branch* ptr = brnch->rightBranch;

			if (ptr->leftBranch == NULL) {
				ptr->leftBranch = brnch->leftBranch;
				temp = ptr;
			}
			else {
				Branch* pmin = ptr->leftBranch;
				while (pmin->leftBranch != NULL) {
					ptr = pmin;
					pmin = ptr->leftBranch;
				}
				ptr->leftBranch = pmin->rightBranch;
				pmin->leftBranch = brnch->leftBranch;
				pmin->rightBranch = brnch->rightBranch;
				temp = pmin;
			}
		}
		delete brnch;
		return temp;
	}
	else if (dta < brnch->data) {
		brnch->leftBranch = delete_el(dta, brnch->leftBranch);
	}
	else {
		brnch->rightBranch = delete_el(dta, brnch->rightBranch);
	}
	return brnch;
}

void isEmpty(Branch*& brnch) {
	if (!brnch) {
		cout << "Tree is empty";
	}
	else {
		cout << "Tree isnt empty";
	}
}

void freeTree(Branch* brnch) {
	if (!brnch) {
		return;
	}
	freeTree(brnch->leftBranch);
	freeTree(brnch->rightBranch);
	delete brnch;
	return;
}