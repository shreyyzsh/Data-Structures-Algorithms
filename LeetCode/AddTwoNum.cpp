// Add Two Numbers

#include <iostream>
#include <vector>
#include <string>

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
        int carry = 0;
        string output = "";

        while (l1 || l2) {
            int val_1 = 0, val_2 = 0;

            if (l1) {
                val_1 = l1->val;
                l1 = l1->next;
            } if (l2) {
                val_2 = l2->val;
                l2 = l2->next;
            }

            string digit_sum = to_string(carry + val_1 + val_2);
            if (stoi(digit_sum) >= 10) {
                carry = 1;
                output += digit_sum[1];
            } else {
                carry = 0;
                output += digit_sum;
            }
        }
        
        if (carry == 1) output += to_string(carry);

        ListNode* HEAD = new ListNode(output[0]);
        ListNode* mover = HEAD;
        for (int i = 0; i < output.length(); i++) {
            ListNode* temp = new ListNode(output[i]);
            mover->next = temp;

            // move to the new node
            mover = mover->next;
        }

        return HEAD;
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
    ListNode* l2 = new ListNode(5);
    
    ListNode* mover1 = l1;
    ListNode* mover2 = l2;

    for (int i = 1; i < 3; i++) {
        ListNode* temp1 = new ListNode(list1[i]);
        ListNode* temp2 = new ListNode(list2[i]);

        mover1->next = temp1;
        mover2->next = temp2;

        mover1 = mover1->next;
        mover2 = mover2->next;
    }

    Solution soln;
    // calling the function that returns sum
    ListNode* result = soln.addTwoNumbers(l1, l2);

    // printing the result
    printTheSum(result);
    return 0;
}