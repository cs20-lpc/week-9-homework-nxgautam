template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    this->length = 0;
    head = nullptr;
    last = nullptr;

}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if(isEmpty())
    {
        throw string("back error: queue is empty!");
    }
    return last->value;

}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    while(!isEmpty())
    {
        dequeue();
    }

}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO

    this->length = 0;
    head = last = nullptr;

    Node * curr = copyObj.head;
    while(curr != nullptr)
    {
        enqueue(curr->value);
        curr = curr->next;
    }


}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO

    if(isEmpty())
    {
       throw string ("dequeue error: queue is empty!");
    }

    Node * temp = head;
    head = head->next;
    delete temp;

    this->length--;

    if(isEmpty())
    {
        last = nullptr;
    }
    
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node * newNode = new Node(elem);

    if(isEmpty())
    {
        head = last = newNode;
    }
    else 
    {
        last->next = newNode;
        last = newNode;
    }
   
    this->length++;


}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if(isEmpty())
    {
        throw string("front error: queue is empty!");
    }

    return head->value;

}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
