
 END SEMESTER PRACTICAL - DATA STRUCTURES (DS)
 Complete Program Folder  |  C + Java + Python
========================================================

READ THIS FILE FIRST.

--------------------------------------------------------
1. WHAT IS INSIDE THIS FOLDER
--------------------------------------------------------
END_SEM_PRACTICAL/
|
|-- README_FIRST.txt            <-- you are reading this
|
|-- LIST_1_LAB_INDEX/           <-- your first notebook index (40 questions)
|   |-- README.txt
|   |-- C/          Q01 ... Q40  (.c files)
|   |-- Java/       Q01 ... Q40  (.java files)
|   `-- Python/     Q01 ... Q40  (.py files)
|
`-- LIST_2_QUESTION_BANK/       <-- your second question list (29 questions)
    |-- README.txt
    |-- C/          Q01 ... Q29  (.c files)
    |-- Java/       Q01 ... Q29  (.java files)
    `-- Python/     Q01 ... Q29  (.py files)

Every program is small, self-contained and has a numbered menu
(where needed), so you can memorize the PATTERN, not the full code.

--------------------------------------------------------
2. HOW TO COMPILE AND RUN
--------------------------------------------------------
C (gcc / Dev C++ / Code::Blocks):
    gcc Q17_SinglyLinkedListAllOps.c -o Q17
    ./Q17

Java (JDK installed):
    javac Q17_SinglyLinkedListAllOps.java
    java  Q17_SinglyLinkedListAllOps
    NOTE: file name and public class name must be exactly the same.

Python 3:
    python3 Q17_SinglyLinkedListAllOps.py
    (or just: python Q17_SinglyLinkedListAllOps.py)

--------------------------------------------------------
3. ABOUT THE END-SEM PRACTICAL (how to prepare)
--------------------------------------------------------
In the end-semester practical exam, usually the examiner gives you
one program question from this same syllabus. You should be able to:

  a) Write the program on the computer within the given time.
  b) Compile it and fix small errors yourself.
  c) Run it with sample input and show correct output.
  d) Explain the logic in 2-3 simple sentences when asked.

Most-asked areas (from your two lists):
  - Arrays: insert/delete at position, merge, matrix add/mul
  - Searching & sorting: linear, binary, bubble, quick, merge
  - Stacks: push/pop/peek, infix-postfix-prefix, evaluation, reverse string
  - Queues: normal, circular, deque (array and linked list)
  - Linked lists: singly, doubly, circular - insert/delete/display/count/search
  - Trees: creation, traversal (preorder/inorder/postorder), BST
  - Graphs: adjacency matrix/list, BFS, DFS, degree
  - Dynamic memory: malloc/calloc/free, 1D and 2D arrays, polynomials,
    structures, sparse matrix

--------------------------------------------------------
4. FAST MEMORY TIPS (learn these 6 patterns)
--------------------------------------------------------
1) ARRAY INSERT AT POSITION:
   for (i = n; i >= pos; i--) a[i] = a[i-1];
   a[pos-1] = value; n++;
   ARRAY DELETE: for (i = pos; i < n; i++) a[i] = a[i+1]; n--;

2) LINEAR SEARCH: loop i=0..n-1, compare a[i] with key.
   BINARY SEARCH: low=0, high=n-1, mid=(low+high)/2, move low/high.

3) BUBBLE SORT: two loops, swap if a[j] > a[j+1].
   QUICK SORT: partition around a pivot, recurse left and right.
   MERGE SORT: split into halves, sort, then merge two sorted halves.

4) STACK: top = -1; push: a[++top] = x; pop: x = a[top--].
   QUEUE: rear = -1, front = 0; enqueue: a[++rear] = x;
   dequeue: x = a[front++].
   CIRCULAR: use (rear + 1) % SIZE and (front + 1) % SIZE.
   EMPTY (circular): front == -1.  FULL: (rear+1)%SIZE == front.

5) LINKED LIST NODE:
   struct Node { int data; struct Node *next; };
   new node = malloc(sizeof(struct Node)); ... free(old);
   Always handle: empty list, first node, last node, middle node.

6) TREE TRAVERSAL (recursive):
   preorder  = root, left, right
   inorder   = left, root, right
   postorder = left, right, root
   BFS uses a QUEUE; DFS uses a STACK (or recursion).

--------------------------------------------------------
5. EXAM DAY CHECKLIST
--------------------------------------------------------
[ ] Write a comment header with question number and title.
[ ] Use simple variable names and a menu with 0 to exit.
[ ] Handle empty/full conditions and invalid position.
[ ] Free allocated memory in C (good habit, examiners like it).
[ ] Test with: empty input, one element, many elements.
[ ] In Java, public class name = file name.
[ ] Keep print statements clear: "Enter n:", "Result:", etc.

Good luck! Revise one folder per day: arrays -> sorting -> stack/queue
-> linked list -> tree/graph -> dynamic memory.
========================================================
