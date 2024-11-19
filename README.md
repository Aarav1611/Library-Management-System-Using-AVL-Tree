# Library-Management-System-Using-AVL-Tree
### Library Management System Using AVL Tree

The **Library Management System** (LMS) using an **AVL Tree** is designed to manage and organize books in a library by keeping them sorted and enabling fast search, insertion, and deletion operations. AVL trees are self-balancing binary search trees, which ensure that the tree remains balanced for optimal performance.

#### Key Features:
- **Add new book**: Insert books into the library and maintain balance in the AVL tree.
- **Remove a book**: Delete books from the library with automatic rebalancing of the tree.
- **Search for a book**: Efficient search for books based on their ID or title.
- **Display books**: View a list of books sorted in ascending order.
- **Borrow and return**: Track book availability.

---

### Guide on How to Run the Program

#### Step 1: Clone or Download the Repository
1. Create a GitHub repository or use an existing one.
2. If you don't have the program yet, create the files for the **AVL Tree**, **Library Management**, and any necessary supporting files.
3. Clone or download the repository to your local machine using:
   ```bash
   git clone https://github.com/<your-github-username>/library-management-avl.git
   ```

#### Step 2: Set up the Environment
1. Make sure you have **Python** installed on your machine. If not, download and install it from the official website: [https://www.python.org/downloads/](https://www.python.org/downloads/).
2. You might also need an IDE or text editor such as **VS Code** or **PyCharm** for easier code editing.

#### Step 3: Install Dependencies (if any)
If your program has external dependencies (like libraries for database handling, etc.), install them using `pip`. For example:
   ```bash
   pip install <library-name>
   ```

#### Step 4: Understanding the File Structure
Your repository might look like this:
```
/library-management-avl
    ├── main.py
    ├── avl_tree.py
    ├── book.py
    ├── README.md
    └── requirements.txt
```

- **main.py**: The entry point of the program. It will interact with the user and perform actions like adding/removing books, borrowing, etc.
- **avl_tree.py**: Contains the AVL tree implementation with methods for insertion, deletion, and balance-checking.
- **book.py**: Defines the Book class, holding details like book ID, title, and availability status.
- **requirements.txt**: A file listing all the dependencies required to run the program.

#### Step 5: Running the Program
1. Open a terminal (or command prompt) and navigate to the directory where your repository is located:
   ```bash
   cd /path/to/library-management-avl
   ```
2. Run the main program using Python:
   ```bash
   python main.py
   ```

#### Step 6: Interacting with the Program
- **Add a new book**: You can add books by providing book details (ID, title, etc.).
- **Search for a book**: You can search using the book's title or ID.
- **Remove a book**: Books can be removed from the AVL tree with automatic balancing.
- **Borrow a book**: Mark a book as borrowed or available.

#### Step 7: Commit and Push to GitHub
1. Make changes or add new files to the repository.
2. After making changes, commit the changes using:
   ```bash
   git add .
   git commit -m "Initial commit of Library Management System with AVL Tree"
   ```
3. Push your changes to GitHub:
   ```bash
   git push origin main
   ```

#### Step 8: Documentation (README)
Make sure to update your **README.md** with instructions on:
- How to install the program
- How to use the features
- Dependencies
- Any other relevant information

---

### Sample Code Snippets

#### AVL Tree Insertion Example
```python
class AVLTree:
    def insert(self, root, book):
        if not root:
            return BookNode(book)
        if book.id < root.book.id:
            root.left = self.insert(root.left, book)
        else:
            root.right = self.insert(root.right, book)
        
        # Perform rotations and balancing
        return self.balance(root)
```

#### Main Program Flow
```python
def main():
    library = AVLTree()
    root = None
    
    while True:
        print("Library Management System")
        print("1. Add Book")
        print("2. Remove Book")
        print("3. Search Book")
        print("4. Display Books")
        choice = int(input("Enter your choice: "))
        
        if choice == 1:
            id = int(input("Enter Book ID: "))
            title = input("Enter Book Title: ")
            book = Book(id, title)
            root = library.insert(root, book)
        elif choice == 2:
            id = int(input("Enter Book ID to remove: "))
            root = library.remove(root, id)
        elif choice == 3:
            title = input("Enter Book Title to search: ")
            library.search(root, title)
        elif choice == 4:
            library.display_books(root)
        else:
            print("Invalid choice. Please try again.")
```

This should get your program up and running with AVL Tree-based library management, and the repository ready for GitHub upload.
