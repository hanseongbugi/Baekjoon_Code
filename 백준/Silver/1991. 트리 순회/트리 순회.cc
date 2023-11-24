#include<iostream>
#include<map>
using namespace std;

map<char, pair<char, char>> tree;
int N;

void preorder(char node) {
	cout << node;
	if (tree[node].first != '.') {
		preorder(tree[node].first);
	}
	if (tree[node].second != '.') {
		preorder(tree[node].second);
	}
}

void inorder(char node) {
	if (tree[node].first != '.') {
		inorder(tree[node].first);
	}
	cout << node;
	if (tree[node].second != '.') {
		inorder(tree[node].second);
	}
}
void postorder(char node) {
	if (tree[node].first != '.') {
		postorder(tree[node].first);
	}
	if (tree[node].second != '.') {
		postorder(tree[node].second);
	}
	cout << node;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		char parent, child1, child2;
		cin >> parent >> child1 >> child2;
		tree[parent] = make_pair(child1, child2);
	}
	char key = 'A';
	preorder(key);
	cout << '\n';
	inorder(key);
	cout << '\n';
	postorder(key);
	cout << '\n';
}