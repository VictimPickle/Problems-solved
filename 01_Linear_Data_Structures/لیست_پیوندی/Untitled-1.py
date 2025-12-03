class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        
class LinkedList:
    def __init__(self, value=None):
        if value is not None:
            newNode = Node(value)
            self.head = newNode
            self.tail = newNode
            self.length = 1
        else:
            self.head = None
            self.tail = None
            self.length = 0
    
    def printlist(self):
        temp = self.head
        while temp is not None:
            print(temp.value, end=" ")
            temp = temp.next
        print()
    
    def append(self, value):
        newnode = Node(value)
        if self.head is None:
            self.head = newnode
            self.tail = newnode
        else:
            self.tail.next = newnode
            self.tail = newnode
        self.length += 1
    
    def TwoByTwoChange(self):
        dummy = Node(0)
        dummy.next = self.head
        prev = dummy
        temp = self.head
        
        while temp is not None and temp.next is not None:
            tmp1 = temp 
            tmp2 = temp.next
            prev.next = tmp2
            tmp1.next = tmp2.next
            tmp2.next = tmp1

            prev = tmp1
            temp = tmp1.next
        
        self.head = dummy.next

x = int(input())
l = LinkedList()
i = input().split()
for j in i:
    l.append(int(j))
l.TwoByTwoChange()
l.printlist()
