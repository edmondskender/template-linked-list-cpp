//
// Created by edmond on 15.11.24.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
template<typename T>
class linked_list {
    struct node {
        node* next;
        T val;

        explicit node(const T& val) : next(nullptr), val(val) {};
    };

    node* head = nullptr;
public:
    linked_list() = default;

    explicit linked_list(const T& value) : head(new node(value)) {};

    ~linked_list() {
        if(head) {
            node* current = head;
            while(current) {
                node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }


    linked_list(const linked_list& other) {
        if(other.head) {
            node* current = other.head;
            while(current) {
                push_back(current->val);
                current = current->next;
            }
        }
    }

    linked_list& operator=(const linked_list& other) {
        if(this != &other) {
            if(head) {
                clear();
                node* current = other.head;
                while(current) {
                    push_back(current->next);
                    current = current->next;
                }
            }
        }
        return *this;
    }

    void clear() {
        node* current = head;
        while(current) {
            node* temp = current;
            current = current->next;
            delete temp;
        }
    }


    linked_list(linked_list&& other) noexcept {
        head = other.head;
        other.head = nullptr;
    }

    linked_list& operator=(linked_list&& other) noexcept {
        if(this != &other) {
            head = other.head;
            other.head = nullptr;
        }
        return *this;
    }

    void insert(size_t idx, const T& x) {
        if (idx == 0) {
            push_front(x);
            return;
        }

        if (!head) {
            throw std::out_of_range("Error: Index out of range");
        }

        node* current = head;
        for (size_t i = 1; i < idx - 1; ++i) {
            if (!current->next) {
                throw std::out_of_range("Error: Index out of range");
            }
            current = current->next;
        }

        node* new_node = new node(x);
        new_node->next = current->next;
        current->next = new_node;
    }


    void push_front(const T& x) {
        node* new_node = new node(x);
        new_node->next = head;
        head = new_node;
    }

    void push_back(const T& x) {
        node* new_node = new node(x);
        node* current = head;
        if(!current) {
            head = new_node;
        } else {
            while(current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void pop_front() {
        if(head) {
            node* to_delete = head;
            head = head->next;
            delete to_delete;
        }
    }

    void pop_back() {
        if (!head) {
            return;
        }

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }


        node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        node* to_delete = current->next;
        current->next = nullptr;
        delete to_delete;
    }


    void remove(size_t idx) {
        if (!head) {
            throw std::out_of_range("Error: Index out of range");
        }

        if (idx == 0) {
            pop_front();
            return;
        }

        node* current = head;
        for (size_t i = 1; i < idx; ++i) {
            if (!current->next) {
                throw std::out_of_range("Error: Index out of range");
            }
            current = current->next;
        }

        node* to_delete = current->next;
        if (!to_delete) {
            throw std::out_of_range("Error: Index out of range");
        }

        current->next = to_delete->next;
        delete to_delete;
    }



    friend std::ostream& operator<<(std::ostream& os, const linked_list& obj) {
        os << "[ ";
        if(obj.head) {
            node* current = obj.head;
            while(current) {
                if(current->next) {
                    os << current->val << " ] ---> [ ";
                } else {
                    os << current->val;
                }
                current = current->next;
            }
        }
        os << " ] ---|";
        return os;
    }
};

#endif //LINKED_LIST_H
