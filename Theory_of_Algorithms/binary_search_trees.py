class Node:

    def __init__(self, item = None):
        self.item = item
        self.left = None
        self.right = None

    def printArray(self):
        if self.left:
            self.left.printArray()
        print(self.item),
        if self.right:
            self.right.printArray()

    def printTree(self):
        print(self.item)
        if self.left:
            print("left of " + str(self.item) + ": "),
            self.left.printTree()
        if self.right:
            print("right of " + str(self.item) + ": "),
            self.right.printTree()


class BinaryNode(Node):

    def prepareArray(self, data, i = 0):
        if i < len(data):
            if self.item is None:
                self.item = data[i]
            if i + 1 < len(data):
                self.left = BinaryNode()
                self.left.prepareArray(data, i * 2 + 1)
            if i + 2 < len(data):
                self.right = BinaryNode()
                self.right.prepareArray(data, i * 2 + 2)


class BinarySearchNode(Node):

    def prepareBinaryTree(self, node):
        if node is not None:
            self.insert(node.item)
            if node.left is not None:
                self.prepareBinaryTree(node.left)
            if node.right is not None:
                self.prepareBinaryTree(node.right)

    def insert(self, *data):
        for item in data:
            if self.item:
                if item < self.item:
                    if self.left is None:
                        self.left = BinarySearchNode(item)
                    else:
                        self.left.insert(item)
                elif item > self.item:
                    if self.right is None:
                        self.right = BinarySearchNode(item)
                    else:
                        self.right.insert(item)
            else:
                self.item = item

    def findRoutes(self, number, route = []):
        amount = 0
        if self.item is not None:
            route.append(self.item)
            for item in route:
                amount += item
            if amount == number:
                print("\namount = " + str(amount) + ": "),
                for item in route:
                    print(item),
            elif amount < number:
                if self.left is not None:
                    self.left.findRoutes(number, list(route))
                if self.right is not None:
                    self.right.findRoutes(number, list(route))
        if self.left is not None:
            self.left.findRoutes(number, list())
        if self.right is not None:
            self.right.findRoutes(number, list())


binaryTree = BinaryNode()
binaryTree.prepareArray([30, 19, 9, 15, 55, 24, 3, 78, 46, 41])

binarySearchTree = BinarySearchNode()
binarySearchTree.prepareBinaryTree(binaryTree)

binarySearchTree.findRoutes(12) # Number S

# binarySearchTree.printArray()
# binarySearchTree.printTree()
