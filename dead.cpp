// Add Two Numbers

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int data) {val = data; next = nullptr;}
    ListNode(int data, ListNode* next) {val = data; next = next;}
};

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string n1 = "", n2 = "";
        while (l1 != nullptr) {
            cout << l1->val;
            n1 = to_string(l1->val) + n1;
            l1 = l1->next;
        }

        cout << endl;
        cout << n1 << endl;

        while (l2 != nullptr) {
            cout << l2->val;
            n2 = to_string(l2->val) + n2;
            l2 = l2->next;
        }
        cout << endl;
        cout << n2 << endl;
        cout << endl;

        string s = to_string(stoll(n1) + stoll(n2));
        cout << s << endl;

        int headVal = s.back() - '0';
        ListNode* sum = new ListNode(headVal);

        ListNode* mover = sum;
        for (int i = s.length()-2; i > -1; i--) {
            ListNode* temp = new ListNode((s[i] - '0'));
            mover->next = temp;
            mover = mover->next;
        }

        return sum;
    }
};

void printTheSum(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
}

int main(void) {
    vector<int> list1 = {2, 4, 3}, list2 = {5, 6, 4};

    ListNode* l1 = new ListNode(2);
    //ListNode* l2 = new ListNode(5);

    ListNode* l3 = new ListNode(9);
    
    ListNode* mover1 = l1;
    //ListNode* mover2 = l2;

    for (int i = 1; i < 50; i++) {
        ListNode* temp1 = new ListNode(list1[i]);
        //ListNode* temp2 = new ListNode(list2[i]);

        mover1->next = temp1;
        //mover2->next = temp2;

        mover1 = mover1->next;
        //mover2 = mover2->next;
    }

    Solution soln;
    // calling the function that returns sum
    ListNode* result = soln.addTwoNumbers(l1, l3);

    // printing the result
    printTheSum(result);
    return 0;
}