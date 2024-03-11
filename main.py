from sys import stdin, stdout
input = stdin.readline

'''
    https://open.kattis.com/problems/lyklagangriti
'''

class node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None
        self.prev = None
        
class llist:
    def __init__(self, data=None) -> None:
        self.head = node(data=data)
        self.cursor = self.head
        self.tail = self.head
    
    def append(self, data):
        new_node = node(data=data)
        new_node.prev = self.cursor
        
        front = self.cursor.next
        
        if front:
            new_node.next = front
            front.prev = new_node
        else:
            self.tail = new_node
        
        self.cursor.next = new_node
        self.cursor = new_node
    
    def move(self, direction):
        if direction == 1:
            if self.cursor.next:
                self.cursor = self.cursor.next
        else:
            if self.cursor.prev:
                self.cursor = self.cursor.prev
                
    def delete(self):
        node_to_delete = self.cursor
        
        back = node_to_delete.prev
        front = node_to_delete.next
        
        if back:
            back.next = front
            self.cursor = back
        else:
            if front:
                front.prev = None
                self.head = front
            else:
                self.head = node(None)
                self.allow = False
            self.cursor = self.head

        del node_to_delete
            
    def display(self):
        elems = []
        cursor = self.head
        while cursor.next is not None:
            cursor = cursor.next
            elems.append(cursor.data)
        
        if elems:
            print(*elems, sep='')
        

def main():
    s = input().strip()
    
    container = llist()
    for key in s:
        if key == 'L':
            container.move(-1)
        elif key == 'R':
            container.move(1)
        elif key == 'B':
            container.delete()
        else:
            container.append(key)
    
    container.display()
            
if __name__ == "__main__":
    main()