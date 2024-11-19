Here’s a detailed `README.md` file for your Library Management System using AVL Tree in C:

---

# 📚 Library Management System Using AVL Tree  

A Library Management System implemented in **C** using the **AVL Tree** data structure. This project demonstrates the efficient management of a library's books database, including features such as adding, removing, and searching for books.

---

## **Features**  

- **Add Books**: Insert new books into the system.  
- **Remove Books**: Delete books from the system by title or ID.  
- **Search Books**: Retrieve book details quickly using title, author, or ID.  
- **AVL Tree Integration**: Ensures balanced and efficient operations with **O(log n)** complexity.  

---

## **How It Works**  

The system uses an AVL Tree (a self-balancing binary search tree) to store book details. After every insertion or deletion, the AVL Tree is rebalanced to ensure optimal performance.  

### **AVL Tree Operations**:  
1. **Rotation**: Single and double rotations to maintain balance.  
2. **Height Management**: Keeps track of tree height for balancing.  
3. **Key Operations**: Insert, Delete, and Search.  

---

## **Tech Stack**  

- **Programming Language**: C  
- **Core Concepts**: Data Structures, Algorithms, AVL Tree  

---

## **How to Run the Program**  

### **Requirements**  
1. **C Compiler**: GCC or any standard C compiler.  
2. **IDE (Optional)**: Code::Blocks, Visual Studio Code, or any text editor.  

### **Steps**  
1. **Clone the Repository**:  
   ```bash  
   git clone https://github.com/YourUsername/LibraryManagementSystem-AVLTree.git  
   ```  

2. **Navigate to the Project Directory**:  
   ```bash  
   cd LibraryManagementSystem-AVLTree  
   ```  

3. **Compile the Code**:  
   Use the following command to compile the program:  
   ```bash  
   gcc library_management_system.c -o library_management_system  
   ```  

4. **Run the Program**:  
   Execute the compiled program:  
   ```bash  
   ./library_management_system  
   ```  

5. **Follow On-Screen Instructions**:  
   The program is interactive. Use the options provided to:  
   - Add a book  
   - Remove a book  
   - Search for a book  

---

## **Example Input/Output**  

### **Add a Book**:  
```  
Enter book title: Data Structures in C  
Enter author name: John Doe  
Enter book ID: 101  
Book added successfully!  
```  

### **Search for a Book**:  
```  
Enter search key (Title/Author/ID): 101  
Book Found:  
  Title: Data Structures in C  
  Author: John Doe  
  ID: 101  
```  

### **Remove a Book**:  
```  
Enter book ID to remove: 101  
Book removed successfully!  
```  

---

## **Contributing**  
Contributions are welcome! Feel free to fork the repository, create a new branch, and submit a pull request.  

---

## **License**  
This project is licensed under the MIT License

---

## **Contact**  
For questions or suggestions, reach out at:  
Email: aaravsaroliya@gmail.com
Github profile link: https://github.com/Aarav1611
