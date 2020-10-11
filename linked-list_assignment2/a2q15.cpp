/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q15.cpp
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-05
 * 
 **/
#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef vector<vector<int>> int_vec_2d;
typedef vector<int>:: iterator vi_it;
typedef map<int, int>::iterator mii_it;

struct Cnode
{
    int data;
    Cnode* next;
};
Cnode* head;

void Append(Cnode** head_ref, int data)
{
    Cnode* curr_node = new Cnode();
    curr_node = *head_ref;
    for(curr_node; curr_node->next!=nullptr && curr_node->next!=*head_ref ; curr_node=curr_node->next){}
    Cnode* new_node = new Cnode();
    new_node->data = data;
    new_node->next = *head_ref;
    curr_node->next = new_node;
}

int CountNodes(Cnode** head_ref)
{
    int count = 0;
    if((*head_ref == nullptr))
        return 0;
    else
    {
        Cnode* curr_node = new Cnode();
        curr_node = *head_ref;
        
        do
        {
            count++;
            curr_node=curr_node->next;  
        } 
        while (curr_node != *head_ref);
    }
    return count;
}

int main()
{
    head = new Cnode();
    cout << "enter no of nodes: ";
    int n;
    cin >> n;
    cout << "enter data in nodes: ";
    int temp;
    head->data = temp;
    head->next = nullptr;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        Append(&head, temp);
    }
    cout << "total No. of nodes are: " << CountNodes(&head) << endl;
    return 0;

}