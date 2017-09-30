#ifndef BinaryTREETEMPLATE_H
#define BinaryTREETEMPLATE_H

#include <string>

using namespace std;

// a generic binary tree class
template <class T>
class BinaryTreeTemplate
{
    // a generic node of the same type as the binary tree
    template <class K>
    class TreeNode
    {
    public:
        K data; // data the node stores
        TreeNode<K>* left; // ptr to left child
        TreeNode<K>* right; // ptr to right child

        // basic constructor, data is empty, both children null
        TreeNode()
        {
            left = nullptr;
            right = nullptr;
        }

        // data provided, children null
        TreeNode(K entry)
        {
            data = entry;
            left = nullptr;
            right = nullptr;
        }

        // data and children provided
        TreeNode(K entry, TreeNode<K>* l, TreeNode<K>* r)
        {
            data = entry;
            left = l;
            right = r;
        }

        // allows for assignment between nodes
        void operator=(TreeNode<K> &obj)
        {
            left = obj.left;
            right = obj.right;
            data = obj.data;
        }

        // destroys children, all connected nodes destroyed
        ~TreeNode()
        {
            delete left;
            delete right;
        }
    };


public:
    TreeNode<T>* head; // ptr to head node

    // basic constructor, head is null
    BinaryTreeTemplate()
    {
        head = nullptr;
    }

    // head data provided, head created
    BinaryTreeTemplate(T entry)
    {
        head = new TreeNode<T>(entry);
    }

    // deletes head, all connected nodes are destroyed
    ~BinaryTreeTemplate()
    {
        delete head;
    }

    // public add function, creates head or calls recursive overload
    bool add(T entry)
    {
        if (head == nullptr) {
            TreeNode<T>* tmp = new TreeNode<T>(entry);
            head = tmp;
            return true;
        }

        return add(entry, head);
    }

    // public search function, false on null tree or calls recursive overload
    bool contains(T entry)
    {
        if (head == nullptr) {
            return false;
        }

        return contains(entry, head);
    }

    // public delete function, false on null tree or calls recursive overload
    bool remove(T entry)
    {
        if (head == nullptr) {
            return false;
        }

        return remove(entry, head, nullptr);
    }

    // returns the data of the head
    T* getHead()
    {
        if (head == nullptr) {
            return nullptr;
        }

        return &(head->data);
    }

    // retruns minimum entry of tree
    T* getMin()
    {
        if (head == nullptr) {
            return nullptr;
        }

        TreeNode<T>* top = head;

        while (top->left != nullptr) {
            top = top->left;
        }

        return &(top->data);
    }

    // returns maximum entry of tree
    T* getMax()
    {
        if (head == nullptr) {
            return nullptr;
        }

        TreeNode<T>* top = head;

        while (top->right != nullptr) {
            top = top->right;
        }

        return &(top->data);
    }

private:
    // recursive add function
    bool add(T entry, TreeNode<T>* top)
    {
        if (entry == top->data) {

            // entry already exists, return false
            return false;

        } else if (entry < top->data) {

            // entry is less than current node, move left
            if (top->left == nullptr){

                // leftmost node, create new left child with entry
                TreeNode<T>* tmp = new TreeNode<T>(entry);
                top->left = tmp;
                return true;

            } else {

                // recursive call on left child
                return add (entry, top->left);

            }

        } else {

            // entry is greater than current node, move right
            if (top->right == nullptr){

                // rightmost node, create new right child with entry
                TreeNode<T>* tmp = new TreeNode<T>(entry);
                top->right = tmp;
                return true;

            } else {

                // recursive call on right child
                return add (entry, top->right);

            }
        }
    }

    // recursive search function
    bool contains(T entry, TreeNode<T>* top)
    {
        if (entry == top->data) {

            //entry found
            return true;

        } else if (entry < top->data) {

            // entry less than, move left
            if (top->left == nullptr) {

                // leftmost node, entry not found
                return false;

            } else {

                // recursive call on left child
                return contains (entry, top->left);

            }
        } else {

            // entry greater than, move right
            if (top->right == nullptr) {

                // rightmost node, entry not found
                return false;

            } else {

                // recursive call on right child
                return contains (entry, top->right);

            }
        }
    }

    // recursive delete function
    bool remove(T entry, TreeNode<T>* top, TreeNode<T>* parent)
    {
        if (entry == top->data) {

            // entry found, reconfigure
            reconfigure(top, parent);
            return true;

        } else if (entry < top->data) {

            // entry less than, move left<T>
            if (top->left == nullptr){

                // leftmost node, entry not found
                return false;

            } else {

                //recursive call on left child
                return remove (entry, top->left, top);

            }
        } else {

            // entry greater than, move right
            if (top->right == nullptr){

                // rightmost node, entry not found
                return false;


            } else {

                // recursive call on right child
                return remove (entry, top->right, top);

            }
        }
    }


    // deletes selected node and restructures tree
    void reconfigure (TreeNode<T>* top, TreeNode<T>* parent)
    {

        if (top->left == nullptr && top->right == nullptr) {

            // node has no children
            // remove references in parent and delete node
            if (parent != nullptr && parent->right == top) {
                parent->right = nullptr;
            } else if (parent != nullptr && parent->left == top) {
                parent->left = nullptr;
            } else {
                head = nullptr;
            }

            delete top;

        } else if (top->left != nullptr && top->right == nullptr) {

            // node has left child
            // make left replacement child in parent and delete node
            // null node's child references to avoid accidental deletion
            if (parent != nullptr && parent->right == top) {
                parent->right = top->left;
                top->left = nullptr;
            } else if (parent != nullptr && parent->left == top) {
                parent->left = top->left;
                top->left = nullptr;
            } else {
                head = top->left;
                top->left = nullptr;
            }

            delete top;

        } else if (top->left == nullptr && top->right != nullptr) {

            // node has right child
            // make right replacement child in parent and delete node
            // null node's child references to avoid accidental deletion
            if (parent != nullptr && parent->right == top) {
                parent->right = top->right;
                top->right = nullptr;
            } else if (parent != nullptr && parent->left == top) {
                parent->left = top->right;
                top->right = nullptr;
            } else {
                head = top->right;
                top->right = nullptr;
            }

            delete top;

        } else {

            // node has right and left children
            // create temporary node variables to find replacement node
            TreeNode<T>* p = top; // current parent of replacement
            TreeNode<T>* n = top->right; // replacement

            // move to the right of node, then as far left as possible
            while (n->left != nullptr) {
                p = n;
                n = n->left;
            }

            // remove references to replacement from its parent
            if (n->right != nullptr) {
                if (p->left == n) {
                    p->left = n->right;
                } else {
                    p->right = n->right;
                }
            } else {
                if (p->left == n) {
                    p->left = nullptr;
                } else {
                    p->right = nullptr;
                }
            }

            // set replacement's child referneces
            if (top->right == n) {
                n->left = top->left;
            } else {
                n->left = top->left;
                n->right = top->right;
            }

            // null node's child references to avoid accidental deletion
            top->left = nullptr;
            top->right = nullptr;

            // set replacement as new child of parent and delete node
            if (parent != nullptr && parent->right == top) {
                parent->right = n;
            } else if (parent != nullptr && parent->left == top) {
                parent->left = n;
            } else {
                head = n;
            }

            delete top;

        }
    }
};

#endif // BinaryTREETEMPLATE_H
