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
        string output = "";
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int v1, v2;

            if (l1) {
                v1 = l1->val;
                l1 = l1->next;
            }
            else v1 = 0;
            if (l2) {
                v2 = l2->val;
                l2 = l2->next;
            }
            else v2 = 0;

            string s = to_string((v1 + v2 + carry));

            if (stoi(s) >= 10) {
                carry = 1;
                output = s[1] + output;
            } else {
                output = s + output;
                carry = 0;
            }

            l2 = l2->next;
            l1 = l1->next;
        }

        if (carry == 1) output = "1" + output;
        // output = 103 but linked list l3 should be 3->0->1

        int headVal = output.back() - '0';
        ListNode* sum = new ListNode(headVal);

        ListNode* mover = sum;
        for (int i = output.length()-2; i > -1; i--) {
            ListNode* temp = new ListNode((output[i] - '0'));
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