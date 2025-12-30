
class Solution{
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        for (int num : arr) {
            current->next = new ListNode(num);
            current = current->next;
        }

        return dummy->next;
    }
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        
        ListNode* dummyNode = new ListNode(0);
        ListNode* temp = dummyNode;
        while (list1 != nullptr && list2 != nullptr) {
            
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next; 
        }
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
      
        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head){
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Function to perform merge sort on a linked list
    ListNode* sortLL(ListNode* head){
        // Base case: if the list is empty or has only one node, it is already sorted, so return the head
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Find the middle of the list using the findMiddle function
        ListNode* middle = findMiddle(head);
        
        // Divide the list into two halves
        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;
        
        // Recursively sort the left and right halves
        left = sortLL(left);
        right = sortLL(right);
        
        // Merge the sorted halves using the mergeTwoSortedLinkedLists function
        return mergeTwoSortedLinkedLists(left, right);
    }
};
