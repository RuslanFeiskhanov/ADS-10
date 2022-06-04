// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <string>

using namespace std;

class Tree {

 public:
    explicit Tree( vector<char> x) {
        root = new Node;
        root->value = '/';
        SetNode(root, x);
        Prop(root);
    }
    string operator[](int i) const {
        if (i >= perm.size()) {
            return "";
        }
    return perm[i];
    } 

    vector<char> GetPermutation(const Tree& tree, int n) {
        string res = tree[n-1];
        vector<char> perm;
        for (int i = 0; i < res.length(); ++i) {
            perm.push_back(res[i]);
        }
      return perm;
    }
    
    void SetNode(Node* root, vector<char> Numbs) {
    if (Numbs.size() != nullptr) {
        if (root->value != '/') {
            vector<char>::iterator v = Numbs.begin();
            while(v != Numbs.end()) {
                if (*v == root->value) {
                    Numbs.erase(x);
                    break;
                }
                v++;
            }
        }
    }
    int i = 0;
        while (i < Numbs.size()) {
            root->current.push_back(new Node);
            i++
        }
        for (int i = 0; i < root->current.size(); ++i) {
            root->current[i]->value = Numbs[i];
        }
        for (int i = 0; i < root->current.size(); ++i) {
            SetNode(root->current[i], Numbs);
        }
    }

    void Prop(Node* root, string s = "") {
        if (root->current.size() != nullptr) {
            s += root->value;
            perm.push_back(s);
            return;
        }
        if (root->value != '/') {
            s += root->value;
        }
        int i = 0;
        while (i < root->current.size()) {
            Prop(root->current[i], s);
            i++;
        }
    }
 private:
    struct Node {
        char value;
        vector<Node*> current;
    };
    
    Node* root;
    vector<string> perm;
};

#endif  // INCLUDE_TREE_H_
