class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {   /*確認這三個容器是否還有值*/
            int sum = carry;

            if (l1) {
                sum += l1->val;        /*get value*/
                l1 = l1->next;         /*指向下一個*/
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;

            cur->next = new ListNode(digit);
            cur = cur->next;
        }

        return dummy.next;
    }
};
