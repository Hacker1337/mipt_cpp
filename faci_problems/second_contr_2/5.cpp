#include<iostream>

using namespace std;

// Struct to store list element
typedef struct list_element {
    int value;                  // Element value
    struct list_element* next;  // Pointer to next element
    struct list_element* prev;	// Pointer to previous element
} list_element;

// Create new element, set its value to 'i', return pointer to new element
list_element* create_list_element(int i)
{
    list_element* new_elem = new list_element;
    new_elem->value = i;
    new_elem->next = NULL;
    new_elem->prev = NULL;
    return new_elem;
}

// Insert element 'elem' into list 'root'
void insert_into_list(list_element* root, list_element* elem)
{
    std::swap(elem->value, root->value);
    elem->prev = root;
    elem->next = root->next;
    if(root->next != NULL) {
        root->next->prev = elem;
    }
    root->next = elem;
}

// Print list
void print_list(list_element* root)
{
    unsigned int i = 0;
    list_element* elem = root;
    while(elem != NULL) {
        cout << "Val[" << i << "] = " << elem->value << endl;
        elem = elem->next;
        ++i;
    }
}

// Print list
void print_list_reverse(list_element* root)
{
    unsigned int i = 0;
    list_element* elem = root;
    while(elem != NULL) {
        cout << "Val[" << i << "] = " << elem->value << endl;
        elem = elem->prev;
        ++i;
    }
}

// Delete list
void delete_list(list_element* root)
{
    list_element* elem = root;
    list_element* to_delete = NULL;
    while(elem != NULL) {
        to_delete = elem;
        elem = elem->next;
        delete to_delete;
    }
}

// TODO: implement this
void swap_elements(list_element* a, list_element* b) {
    auto aprev = a->prev;
    auto anext = a->next;
    auto bprev = b->prev;
    auto bnext = b->next;
    
    if (anext == b) 
    {
        a->prev = b;
        b->next = a;

    }
    else {
        a->prev = bprev;
        b->next = anext;
        anext->prev = b;
        bprev->next = a;
    }

    a->next = bnext;
    b->prev = aprev;
    if (aprev != NULL)
        aprev->next = b;
    if (bnext != NULL)
        bnext->prev = a;
    
}

// TODO: implement this
void fix_list(list_element* head, list_element* tail) {
    while (head != tail)
    {   
        auto next = head->next;
        auto prev = tail->prev;
        if (next != NULL) {
            if (next->prev == NULL) {
                next->prev = head;
            }
            head = next;
        }
        else if (prev != NULL)
        {
            if (prev->next == NULL)
            {
                prev->next = tail;
            }
            tail = prev;
        }
        else {
            break;
            // cerr << "Can't fix this list\n";
        }
    }
}


int main()
{
    int n = 5;
    //======================= CREATE
    list_element* head = create_list_element(0);
    list_element* tail = head;
    for(int i = 1; i < n; i++)
    {
        list_element* elem = create_list_element(i);
        insert_into_list(head, elem);
        if(head == tail) {
            tail = elem;
        }
    }

    cout << "List:" << endl;
    print_list(head);

    //======================= TEST

    int target = 2;
    cout << "We are going to break element " << target << endl;
    list_element *cur = head;
    for (int i = 0; i < n; i++) {
        if (i == target) {
            cur->next = NULL;
            cur->prev = NULL;
            break;
        }
        cur = cur->next;
    }

    cout << "Broken list view from head:" << endl;
    print_list(head);
    cout << "Broken list view from tail:" << endl;
    print_list_reverse(tail);

    cout << "We are going to fix list now" << endl;
    fix_list(head, tail);

    cout << "Fixed list view from head:" << endl;
    print_list(head);
    cout << "Fixed list view from tail:" << endl;
    print_list_reverse(tail);

    //======================= CLEAN

    delete_list(head);
    return 0;
}