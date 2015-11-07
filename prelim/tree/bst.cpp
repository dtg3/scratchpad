#include <iostream>
#include <iomanip>

class Node {
public:
	Node * left;
	Node * right;
	int val;

	Node () {
		left = nullptr;
		right = nullptr;
	}

	Node(int v, Node * l, Node * r) {
		val = v;
		left = l;
		right = r;
	}
};

class BST {
public:
	BST() {
		root = nullptr;
	}

	~BST() {
		destroy(root);
	}

	BST(const BST& c) {
		root = copy(c.root);
	}

	void insert(int item) {
		Node * n = new Node(item, nullptr, nullptr);

		if (root == nullptr) {
			root = n;
			return;
		}

		Node * r = root;
		while (r != nullptr) {
			if (item <= r->val) {
				if (r->left != nullptr) {
					r = r->left;
				}
				else {
					r->left = n;
					break;
				}
			}
			else {
				if (r->right != nullptr) {
					r = r->right;
				}
				else {
					r->right = n;
					break;
				}
			}
		}
	}

	// for testing
	void print(int indent) {
		printInOrder(root, indent);
	}

private:
	Node * root;

	void destroy(Node * root) {
		if (root != nullptr) {
			destroy(root->left);
			destroy(root->right);

			delete root;
			root = nullptr;
		}
	}

	// pre-order node copy
	Node * copy(Node * root) {
		if (root != nullptr) {
			Node * r = new Node(root->val, nullptr, nullptr);
			r->left = copy(root->left);
			r->right = copy(root->right);
			return r;
		}
		return nullptr;
	}

/*
	// post-order node copy
	Node * copy(Node * root) {
		if (root != nullptr) {
			Node * left = copy(root->left);
			Node * right = copy(root->right);
			Node * r = new Node(root->val, left, right);
			return r;
		}
		return nullptr;
	}
*/

	// for testing
	void printInOrder(Node* p, int indent)
	{
	    if(p != NULL) {
	        if(p->right) {
	            printInOrder(p->right, indent+4);
	        }
	        if (indent) {
	            std::cout << std::setw(indent) << ' ';
	        }
	        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
	        std::cout<< p->val << "\n ";
	        if(p->left) {
	            std::cout << std::setw(indent) << ' ' <<" \\\n";
	            printInOrder(p->left, indent+4);
	        }
	    }
	}

};







int main() {
	BST b;
	b.insert(10);
	b.insert(5);
	b.insert(15);

	b.print(10);
	std::cerr << "--------------" << std::endl;

	BST c(b);

	b.insert(7);
	c.print(10);

}
