
#pragma once

template <class T>
struct Node {
    T data;
    Node<T>* previous;
    Node<T>* next;
};

template <class T>
class List {
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int amount = 0;
public:
    List() {};
    ~List();

    //Длина списка
    int size() { return this->amount; }
    void pushHead(T obj);
	void push(T obj, int num);
    void pushTail(T input_object);
    T popHead();
	T pop(int num);
    T popTail();
    T& operator[](int num);
    Node<T>* begin();
    Node<T>* end();
    void sort(int type);
    void output();
    void deleteAll();
};

template<class T>
class Iterator {
    Node<T>* current;
public:
    Iterator() { current = nullptr; }

    Iterator(Iterator& iter) { current = iter.current; }
    ~Iterator() = default;
    // Получение узла из итератора
    Node<T>* getNode() { return current; }
    // Функции сдвига итератора
    bool operator++(int i) {
        if (current == nullptr) return false;
        current = current->next;
        return true;
    }
    bool operator--(int i) {
        if (current->prev == nullptr) return false;
        current = current->prev;
        return true;
    }
    // Получение значения из итератора
    T& operator*() { return current->data; }
    // Операторы сравнения для итератора
    bool operator==(Iterator& iter) {
        if (current == nullptr && iter.current == nullptr)
            return true;
        if (current == nullptr || iter.current == nullptr)
            return false;
        if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
            return true;
        return false;
    }

    bool operator!=(Iterator& iter) {
        if (current == nullptr && iter.current == nullptr)
            return false;
        if ((current == nullptr && iter.current != nullptr) || (current != nullptr && iter.current == nullptr))
            return true;
        if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
            return false;
        return true;
    }
};

template<class T>
void List<T>::pushHead(T obj) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = obj;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
        amount++;
    } else {
        auto *node = new Node<T>;
        node->data = obj;
        node->next = head;
        node->previous = nullptr;
        head->previous = node;
        head = node;
        amount++;
    }
}

template<class T>
void List<T>::push(T obj, int num) {
	Node<T> *next = this->operator[](num);
	Node<T> *prev = this->operator[](num - 1);
	auto *node = new Node<T>;
	node->data = obj;
	node->next = next;
	next->previous = node;
	node->previous = prev;
	prev->next = node;
	amount++;
}

//Добавление в хвост
template<class T>
void List<T>::pushTail(T input_object) {
    if (head == nullptr) {
        head = new Node<T>;
        head->data = input_object;
        head->next = nullptr;
        head->previous = nullptr;
        tail = head;
        amount++;
        return;
    }
    auto *node = new Node<T>;
    node->data = input_object;
    node->next = nullptr;
    node->previous = tail;
    tail->next = node;
    tail = node;
    amount++;
}

//Удаление от головы
template<class T>
T List<T>::popHead() {
    if (!(head)) return T();
    T data = head->data;
    Node<T>* node = head;
    if (head != tail) {
        head = head->next;
        head->previous = nullptr;
        Node<T>* tmp = head;
    } else {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

template<class T>
T List<T>::pop(int num) {
	if (num == 0)  return popHead();
	if (num == amount - 1) return popTail();
	Node<T> *curr = head;
	for (int i = 0; i < num; i++)
		curr = curr->next;
	Node<T>*prev = curr->previous;
	Node<T>*next = curr->next;
	T data = curr->data;
	amount--;
	prev->next = next;
	next->previous = prev;
	delete curr;
	return data;
}


//Удаление из хвоста
template<class T>
T List<T>::popTail() {
    if (!(head)) return T();
    T data = tail->data;
    Node<T> *node = tail;
    if (tail != head) {
        tail = tail->previous;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete node;
    amount--;
    return data;
}

// Доступ к объектам с помощью индексации
template<class T>
T& List<T>::operator[](int num) {
    Node<T> *curr = head;
    if (num < 0 || num >= amount) return curr->data;
    for (int i = 0; i < num; i++)
        curr = curr->next;
    return curr->data;
}

// Функции для работы с итератором
template<class T>
Node<T>* List<T>::begin() { return head; }

template<class T>
Node<T>* List<T>::end() {
    if (tail != nullptr) return tail->next;
    return tail;
}

// Вывод на экран содержимого списка
template<class T>
void List<T>::output() {
    int i = 0;
    for (Node<T> *node = head; node != nullptr; node = node->next) {
        std::cout << "№" << i + 1 << "|" <<  node->data;
        std::cout << std::endl;
        i++;
    }
}



template<class T>
List<T>::~List() { while (this->head) { this->popHead(); } }

template<class T>
void List<T>::sort(int type) {
    switch (type) {
        case 1: {
            for (Node<T> *tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getId() > another->data.getId()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
        case 2: {
            for (Node<T> *tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getId() < another->data.getId()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
        case 3: {
            for (Node<T> *tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getSum() > another->data.getSum()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
        case 4: {
            for (Node<T> *tmp = this->head; tmp->next != nullptr; tmp = tmp->next) {
                for (Node<T> * another = this->tail; another != tmp; another = another->previous) {
                    if (tmp->data.getSum() < another->data.getSum()) {
                        auto *buf1 = new Node<T>;
                        buf1->data = tmp->data;
                        tmp->data = another->data;
                        another->data = buf1->data;
                    }
                }
            }
            break;
        }
    }
}

template<class T>
void List<T>::deleteAll() {
    while (this->head) { this->popHead(); }
}