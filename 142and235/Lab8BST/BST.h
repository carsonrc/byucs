//
// Created by carson on 8/1/21.
//

#ifndef LAB8BST_BST_H
#define LAB8BST_BST_H

#include <sstream>
#include "BSTInterface.h"

template<typename T>
class BST : public BSTInterface<T> {
public:
    BST() = default;
    ~BST() {clearTree();};


    //Node Declaration

    struct BTNode  {
        T data;
        BTNode* left;
        BTNode* right;

        explicit BTNode(const T& the_data,
                        BTNode* left_val = NULL,
                        BTNode* right_val = NULL) :
                data(the_data), left(left_val),  right(right_val) {};
        ~BTNode() = default;

        std::string to_string() const {
            std::ostringstream os;
            os << data;
            return os.str();
        };

        std::ostream& operator<<(const BTNode node) {
            return node.to_string();
        };
    };


    /** Return true if node added to BST, else false */
    bool addNode(const T& data, BTNode*& localRoot) {      //item becomes root
        if (localRoot == nullptr) {
            localRoot = new BTNode(data);
            return true;
        }
        else if (data == localRoot->data) { //item is in tree
            return false;
        }
        else if (data < localRoot->data) {
            return addNode(data,localRoot->left);
        }
        else if (data > localRoot->data) {
            return addNode(data, localRoot->right);
        }
    };
    bool addNode(const T& data) {
        return addNode(data, this->root);
    }

    /** Return true if node removed from BST, else false */
    bool removeNode(const T& data, BTNode*& localRoot) {
        if (localRoot == nullptr) {
            return false;
        } else {
            if (data < localRoot->data) {
                return removeNode(data, localRoot->left);
            } else if (data > localRoot->data) {
                return removeNode(data, localRoot->right);
            } else {
                BTNode* oldRoot = localRoot;
                if (localRoot->left == nullptr) {
                    localRoot = localRoot->right;
                } else if (localRoot->right == nullptr){
                    localRoot = localRoot->left;
                } else {
                    replaceParent(oldRoot, oldRoot->left);
                }
                delete oldRoot;
                return true;
            }
        }
    };
    bool removeNode(const T& data) {
        return removeNode(data, this->root);
    };
    void replaceParent (BTNode*& oldRoot, BTNode*& localRoot) {
        if (localRoot->right != nullptr) {
            replaceParent(oldRoot, localRoot->right);
        } else {
            oldRoot->data = localRoot->data;
            oldRoot = localRoot;
            localRoot = localRoot->left;
        }
    };

    /** Return true if BST cleared of all nodes, else false */
    bool clearTree() {
        if (root == nullptr) {
            return true;
        } else {
            while (root != nullptr)
            removeNode(root->data);
        }
    };

    /** Return a level order traversal of a BST as a string */

    bool outLevel(BTNode* root, int level, std::stringstream& out) const {
        if (root == NULL) return false;
        if (level == 1) {
            //out << " " << root->data_;
            out << " " << root->data;
            if ((root->left != NULL) || (root->right != NULL)) return true;
            return false;
        }
        if ((level == 2) && !root->left && root->right) out << " _";
        bool left = outLevel(root->left, level - 1, out);
        bool right = outLevel(root->right, level - 1, out);
        if ((level == 2) && root->left && !root->right) out << " _";
        return left || right;
    }
    std::string outLevels(BTNode* localRoot) const{
        std::stringstream out;
        if (root == NULL) out << "empty";
        else {
            int level = 0;
            do{
                out << std::endl << "  " << ++level << ":";
            } while (outLevel(root, level, out));
        }
        return out.str();
    }

    bool find(const T& item) {
        return find(root, item);
    }

    bool find(BTNode*& localNode, const T& item) {
        if (localNode == NULL) return false;
        if (localNode->data == item) return true;
        if (item < localNode->data) return find(localNode->left, item);
        if (item > localNode->data) return find(localNode->right, item);
        return false;
    }

    std::string toString() const {
        return outLevels(root);
    };
private:
    BTNode* root = nullptr;   //the reason this is down here is to let it be defined

};


#endif //LAB8BST_BST_H
