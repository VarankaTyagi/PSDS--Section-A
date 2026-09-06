'''#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char ch) {
        if (top < 99)
            arr[++top] = ch;
    }

    char pop() {
        if (!isEmpty())
            return arr[top--];
        return '\0';
    }
'''
    char peek() {
        if (!isEmpty())
            return arr[top];
        return '\0';
    }
};
'''
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char ch : infix) {

        // Operand
        if ((ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {

            postfix += ch;
        }
       
'''
        // Opening bracket
        else if (ch == '(') {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }

            if (!s.isEmpty())
                s.pop(); // Remove '('
        }
'''
        // Operator
       ''' else {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(ch)) {

                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}'''

'''

int main() {
    string infix;

    cout << "Enter a valid infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
} '''


'''
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class IntStack {
private:
    int arr[100];
    int top;

public:
    IntStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (top < 99)
            arr[++top] = value;
    }

    int pop() {
        if (!isEmpty())
            return arr[top--];

        return -1;
    }
};

int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    IntStack s;

    for (int i = 0; i < postfix.length(); i++) {

        char ch = postfix[i];

        // If operand, convert character to integer
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }

        // If operator
        else {
            int operand2 = s.pop();
            int operand1 = s.pop();

            int result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    result = operand1 / operand2;
                    break;

                case '^':
                    result = pow(operand1, operand2);
                    break;
            }

            s.push(result);
        }
    }

    cout << "Final Result: " << s.pop() << endl;

    return 0;
}'''


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Insert a node
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Find minimum node
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node
Node* deleteNode(Node* root, int value) {

    if (root == NULL) {
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {

        // No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Only right child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Only left child
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder: Left -> Root -> Right
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {

    Node* root = NULL;
    int n, value;

    // Enter number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // Enter all values
    cout << "Enter " << n << " values: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    // Delete operation
    cout << "\n\nEnter value to delete: ";
    cin >> value;

    root = deleteNode(root, value);

    cout << "Inorder after deletion: ";
    inorder(root);

    return 0;
}