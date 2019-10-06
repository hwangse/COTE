#include<iostream>
#define null 0
using namespace std;

template<typename T>
class Tree;

template<typename T>
class TreeNode {
	friend class Tree<T>;

private: 
	T data;
	TreeNode* left;
	TreeNode* right;
public : 
	TreeNode(T data = 0, TreeNode<T>* left = null, TreeNode<T>* right = null) {
		this->data = data;
		this->left = left;
		this->right = right;
	}
	T getData() {
		return data;
	}

	
};

template<typename T>
class Tree {
private: 
	TreeNode<T>*root;
public : 
	Tree(T data = 0) {
		root = new TreeNode<T>(data);
	}

	void buildTree() {
		root->left = new TreeNode<T>('B', new TreeNode<T>('D', new TreeNode<T>('H')), new TreeNode<T>('E', new TreeNode<T>('I'), new TreeNode<T>('J')));
		root->right = new TreeNode<T>('C', new TreeNode<T>('F'), new TreeNode<T>('G', null, new TreeNode<T>('K')));
	}

	TreeNode<T>* getRoot() {
		return root;
	}

	void visit(TreeNode<T>* current) {
		cout << current->data << " ";
	}

	void preorder(TreeNode<T>* current) {
		if (current != null) {
			visit(current);
			preorder(current->left);
			preorder(current->right);
		}
	}
	void inorder(TreeNode<T>* current) {
		if (current != null) {
			inorder(current->left);
			visit(current);
			inorder(current->right);
		}
	}

	// 후위 순회 Left - Right - Current
	void postorder(TreeNode<T>* current) {
		if (current != null) {
			postorder(current->left);
			postorder(current->right);
			visit(current);
		}
	}
};

TreeNode<char>* recursive(TreeNode<char> current, char letter) {
	if (current.getData() == null) return;

}

int main() {
	int n;
	cin >> n;

	TreeNode<char>* head = NULL;

	for (int i = 0; i < n; i++) {
		TreeNode<char>root=null, left=null, right=null;
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.')
			left = TreeNode<char>(b);
		if (c != '.')
			right = TreeNode<char>(c);
		root = TreeNode<char>(a, &left, &right);

		if (i == 0) head = &root;
		else {	

		}


	}


	return 0;
}