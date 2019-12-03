//
//  main.cpp
//  Binary Tree
//
//  Created by Haider Ali on 11/26/19.
//  Copyright © 2019 Haider Ali. All rights reserved.
//

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* l_child;
    Node* r_child;
   
    Node(){
        l_child = nullptr;
        r_child = nullptr;
    }
};

class BST{
 public:
    Node* root = nullptr;
    Node* ploc;
    Node* loc;
    

    bool empty(){
        return root == nullptr;
    }
    
    void search(int value){
        ploc = nullptr;
        loc = root;
        
        if (empty()) {
            return;
        }
        
        while (loc != nullptr && loc->data != value) {
            
            if (value < loc->data) {
                ploc = loc;
                loc = loc->l_child;
            }
            else{
                ploc = loc;
                loc = loc->r_child;
            }
        }
    }
    
    void insertValue(int value) {
        Node* temp = new Node();
        temp->data = value;
        
        if (empty()) {
            root = temp;
        }
        else{
            search(value);
            
            if (loc != nullptr) {
                cout<<"Invalid Operation. Duplication isn't allowed";
            }
            if (value < ploc->data) {
                ploc->l_child = temp;
            }
            else{
                ploc->r_child = temp;
            }
        }
    }
    
    void remove(int data) {
        if (empty()) {
            cout<<"Tree is empty";
            return;
        }
        search(data);
        if (loc == nullptr) {
            cout<<"value not found";
        }else{
            if (ploc == nullptr) {
                
                if (loc->l_child == nullptr && loc->r_child == nullptr) {
                    delete root;
                    root = nullptr;
                }
                else if (loc->l_child != nullptr && loc->r_child == nullptr){
                    root = loc->l_child;
                    delete loc;
                    loc = nullptr;
                }
                else if (loc->l_child == nullptr && loc->r_child != nullptr){
                    root = loc->r_child;
                    delete loc;
                    loc = nullptr;
                }
                else{
                    Node *loc1 = loc->l_child;
                    Node *ploc1 = loc;
                    while (loc1->r_child != nullptr) {
                        ploc1 = loc1;
                        loc1 = loc1->r_child;
                    }
                    if (loc->l_child == loc1) {
                        loc1->r_child = loc->r_child;
                    }
                    else{
                        ploc1->r_child = loc1->l_child;
                        loc1->l_child = loc->l_child;
                        loc1->r_child = loc->r_child;
                    }
                    
                    delete root;
                    root = loc1;
                }
            }
            else if (ploc->l_child == loc){
                
                if (loc->l_child == nullptr && loc->r_child == nullptr){
                    delete loc;
                    loc = nullptr;
                    ploc->l_child = nullptr;
                }
                else if (loc->l_child != nullptr && loc->r_child == nullptr) {
                    ploc->l_child = loc->l_child;
                    delete loc;
                    loc = nullptr;
                }
                else if (loc->l_child == nullptr && loc->r_child != nullptr){
                    ploc->l_child = loc->r_child;
                    delete loc;
                    loc = nullptr;
                }
                else {
                    Node *loc1 = loc->l_child;
                    Node *ploc1 = loc;
                    while (loc1->r_child != nullptr) {
                        ploc1 = loc1;
                        loc1 = loc1->r_child;
                    }
                    if (loc->l_child == loc1) {
                        loc1->r_child = loc->r_child;
                    }
                    else{
                        ploc1->r_child = loc1->l_child;
                        loc1->l_child = loc->l_child;
                        loc1->r_child = loc->r_child;
                    }
                    
                    delete loc;
                    loc = nullptr;
                    ploc->l_child = loc1;
                    
                }
            }
            
            else if (ploc->r_child == loc){
                
                if (loc->l_child == nullptr && loc->r_child == nullptr){
                    delete loc;
                    loc = nullptr;
                    ploc->r_child = nullptr;
                }
                else if (loc->l_child != nullptr && loc->r_child == nullptr) {
                    ploc->r_child = loc->l_child;
                    delete loc;
                    loc = nullptr;
                }
                else if (loc->l_child == nullptr && loc->r_child != nullptr){
                    ploc->r_child = loc->r_child;
                    delete loc;
                    loc = nullptr;
                }
                else {
                    Node *loc1 = loc->l_child;
                    Node *ploc1 = loc;
                    while (loc1->r_child != nullptr) {
                        ploc1 = loc1;
                        loc1 = loc1->r_child;
                    }
                    if (loc->l_child == loc1) {
                        loc1->r_child = loc->r_child;
                    }
                    else{
                        ploc1->r_child = loc1->l_child;
                        loc1->l_child = loc->l_child;
                        loc1->r_child = loc->r_child;
                    }
                    delete loc;
                    loc = nullptr;
                    ploc->l_child = loc1;
                                
                }
            }
        }
    }
    
    int height(Node *temp) {

        if (temp == nullptr) {
            return 0;
        }
        else{
             int h1 =1+ height(temp->l_child);
             int h2 =1+ height(temp->r_child);
            if (h1>h2) {
                return (h1);
            }
            else return (h2);
        }
    }
    
    void print() {
        prefix(root);
        cout<<endl;
    }
    
    void prefix(Node *temp) {
        
        if (temp == nullptr) {
            return;
        }
        else{
            cout<<temp->data<<" ";
            prefix(temp->l_child);
            prefix(temp->r_child);
        }
    }
    
};

int main() {
    
    BST b;
    
    b.insertValue(30);
    b.insertValue(50);
    b.insertValue(20);
////    b.insertValue(35);
//    b.insertValue(19);
//    b.insertValue(18);
////    b.insertValue(70);
////    b.insertValue(60);
    b.print();
    b.remove(30);
    b.print();
}
