class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data) {

    // If list is empty
    if(tail == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // Create new node
    Node* newNode = new Node(data);

    // Link tail with new node
    tail->next = newNode;
    newNode->prev = tail;

    // Move tail pointer
    tail = newNode;
}
