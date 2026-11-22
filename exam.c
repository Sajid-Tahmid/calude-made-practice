/*
 * ============================================================
 * STRUCTURED PROGRAMMING LAB FINAL EXAM (BSSE 18)  -  ADVANCED
 * LIBRARY MANAGEMENT SYSTEM  -  POINTERS EDITION
 * Total Marks: 70
 * ============================================================
 *
 * DO NOT MODIFY:
 *   - constants
 *   - structure definitions
 *   - function names
 *   - function parameters
 *   - return types
 *
 * You may add helper functions if necessary.
 *
 * Implement every function marked TODO.
 *
 * HOW TO CHECK YOUR WORK
 *   Put exam.c and grader.c in the same folder, then:
 *
 *       gcc grader.c -o grader
 *       ./grader            (Windows: grader.exe)
 *
 *   The grader #includes this file, runs every function, and
 *   prints your marks and exactly which checks failed.
 *   (grader.c has its own main(); the main() below is hidden
 *   from it. To test by hand: gcc exam.c -o exam)
 *
 * RULES FOR THIS EXAM
 *   - Part B: do NOT use <string.h> functions (strlen, strcpy,
 *     strcmp ...). The whole point is to walk the pointers yourself.
 *   - A NULL pointer argument must never crash your function
 *     unless the comment says "assume non-NULL".
 *   - A function that crashes (segmentation fault), loops forever,
 *     or calls free() on a bad / already-freed pointer gets 0 for
 *     that function.
 *   - Every malloc must have a matching free where the comment
 *     says so. The grader counts allocations.
 *
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 40
#define MAX_BOOKS 100
#define DATA_FILE "library.bin"


/* ============================================================
 * DATA STRUCTURES
 * ============================================================
 */

/*
 * One book in the library.
 */
typedef struct
{
    int id;
    char title[MAX_TITLE];
    float price;
    int copies;

} Book;


/*
 * One node of a singly linked list of integers.
 */
typedef struct Node {
    int value;
    struct Node *next;
} Node;


/* ============================================================
 * PART A: POINTER BASICS
 * Marks: 10
 * ============================================================
 */


/*
 * Swap the two integers that a and b point to.
 *
 * Example:
 * int x = 3, y = 7;
 * swapInts(&x, &y);     ->  x = 7, y = 3
 *
 * Rules:
 *   - If a or b is NULL, do nothing.
 *   - swapInts(&x, &x) must leave x unchanged.
 *
 * Marks: 1
 */
void swapInts(int *a, int *b)
{
    if(a != NULL && b != NULL){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}


/*
 * Swap two POINTERS (not the integers they point to).
 *
 * pa is the address of a pointer, and so is pb.
 * After the call, the pointer that *pa names must hold what *pb
 * held, and vice versa. The integers themselves must NOT change.
 *
 * Example:
 * int x = 10, y = 20;
 * int *p = &x, *q = &y;
 * swapPointers(&p, &q);
 *
 * Now p == &y and q == &x.  x is still 10, y is still 20.
 *
 * Assume pa and pb are non-NULL.
 *
 * Marks: 1
 */
void swapPointers(int **pa, int **pb)
{
    int *temp = *pa;
    *pa = *pb;
    *pb = temp;

}


/*
 * Find the minimum and maximum of an array and return them
 * through OUTPUT POINTERS.
 *
 * Return:
 *   1 on success (outputs written)
 *   0 if n <= 0, or minOut is NULL, or maxOut is NULL.
 *     In that case do NOT modify *minOut or *maxOut.
 *
 * Example:
 * arr = {4, -2, 9, 0}, n = 4   ->  *minOut = -2, *maxOut = 9, return 1
 *
 * Marks: 2
 */
int minMax(const int arr[], int n, int *minOut, int *maxOut)
{
    /* TODO */
    return 0;
}


/*
 * Sum the integers from address 'start' up to, but NOT including,
 * address 'end'.  Both pointers point into the same array.
 *
 * Example:
 * int a[5] = {1, 2, 3, 4, 5};
 *
 * sumRange(a, a + 5)   ->  15     (the whole array)
 * sumRange(a + 1, a + 4) ->  9    (2 + 3 + 4)
 * sumRange(a + 2, a + 2) ->  0    (empty range)
 *
 * If start >= end (or either is NULL), return 0.
 *
 * Hint: no counter variable is needed; move a pointer.
 *
 * Marks: 2
 */
int sumRange(const int *start, const int *end)
{
    /* TODO */
    return 0;
}


/*
 * Reverse an array IN PLACE using two pointers: one that starts at
 * the first element and one that starts at the last element.
 *
 * Example:
 * {1, 2, 3, 4, 5}  ->  {5, 4, 3, 2, 1}
 *
 * If arr is NULL or n <= 1, do nothing.
 * Do not touch any memory outside arr[0 .. n-1].
 *
 * Marks: 2
 */
void reverseArray(int *arr, int n)
{
    /* TODO */
}


/*
 * Return a POINTER to the largest element of the array.
 * (Return the address of the element, NOT its value.)
 *
 * If the maximum appears more than once, return the FIRST one.
 * If arr is NULL or n <= 0, return NULL.
 *
 * Example:
 * int a[5] = {3, 8, 1, 8, 2};
 * findMaxPtr(a, 5)  ->  a + 1   (that is, &a[1])
 *
 * Marks: 2
 */
int *findMaxPtr(int *arr, int n)
{
    /* TODO */
    return NULL;
}


/* ============================================================
 * PART B: STRINGS WITH POINTERS
 * Marks: 12
 * ============================================================
 *
 * Reminder: do NOT use <string.h> here.
 * A string is a char array that ends with '\0'.
 * ============================================================
 */


/*
 * Return the length of the string (not counting '\0').
 * If s is NULL, return 0.
 *
 * Marks: 1
 */
int myStrLen(const char *s)
{
    /* TODO */
    return 0;
}


/*
 * Copy the string src into dst, INCLUDING the terminating '\0'.
 * Assume dst is large enough.
 * If dst or src is NULL, do nothing.
 *
 * Marks: 1
 */
void myStrCopy(char *dst, const char *src)
{
    /* TODO */
}


/*
 * Compare two strings character by character.
 *
 * Return:
 *   a negative number if a comes before b
 *   0                 if they are equal
 *   a positive number if a comes after b
 *
 * Examples:
 * ("apple", "apple")   ->  0
 * ("apple", "apricot") ->  negative   ('p' < 'r')
 * ("abc", "abcd")      ->  negative   (shorter prefix comes first)
 *
 * Assume a and b are non-NULL.
 *
 * Marks: 2
 */
int myStrCompare(const char *a, const char *b)
{
    /* TODO */
    return 0;
}


/*
 * Convert every lowercase letter 'a'-'z' in s to uppercase,
 * IN PLACE. Leave all other characters unchanged.
 * If s is NULL, do nothing.
 *
 * Example: "Hello, World 123!" -> "HELLO, WORLD 123!"
 *
 * Marks: 1
 */
void toUpperCase(char *s)
{
    /* TODO */
}


/*
 * Count the words in s.
 * A word is a maximal run of characters that are not whitespace.
 * Whitespace = ' ' (space), '\t' (tab), '\n' (newline).
 * If s is NULL, return 0.
 *
 * Examples:
 * "hello world"                      -> 2
 * "  leading and   multiple   spaces  " -> 4
 * ""                                 -> 0
 * "     "                            -> 0
 *
 * Marks: 2
 */
int countWords(const char *s)
{
    /* TODO */
    return 0;
}


/*
 * Return 1 if s is a palindrome, 0 otherwise.
 *
 * Ignore upper/lower case, and IGNORE every character that is not
 * a letter or a digit.
 *
 * Use two pointers: one moving from the front, one from the back.
 *
 * Examples:
 * "racecar"                       -> 1
 * "Was it a car or a cat I saw?"  -> 1
 * "hello"                         -> 0
 * ""                              -> 1   (nothing to compare)
 *
 * If s is NULL, return 0.
 *
 * Marks: 3
 */
int isPalindrome(const char *s)
{
    /* TODO */
    return 0;
}


/*
 * Remove EVERY occurrence of the character c from s, IN PLACE.
 * The result must still end with '\0'.
 *
 * Hint: use a "read" pointer and a "write" pointer.
 *
 * Examples:
 * "banana", 'a'  ->  "bnn"
 * "aaaa",   'a'  ->  ""
 * "xyz",    'q'  ->  "xyz"
 *
 * If s is NULL, do nothing.
 *
 * Marks: 2
 */
void removeChar(char *s, char c)
{
    /* TODO */
}


/* ============================================================
 * PART C: STRUCTURES AND POINTERS
 * Marks: 14
 * ============================================================
 */


/*
 * Fill in a Book.
 *
 * Copy id, price, copies, and the title into *b.
 * The title must fit in b->title: copy at most MAX_TITLE - 1
 * characters and always end with '\0' (truncate if too long).
 *
 * If b is NULL, do nothing.
 * If title is NULL, store the empty string "".
 *
 * Marks: 2
 */
void initBook(Book *b, int id, const char *title, float price, int copies)
{
    /* TODO */
}


/*
 * Search an array of books for the given id.
 *
 * Return a POINTER to the matching element INSIDE the array
 * (not a copy). If several books share the id, return the first.
 * Return NULL if n <= 0 or there is no match.
 *
 * The caller may modify the book through the returned pointer,
 * for example  findBookById(books, n, 5)->copies = 0;
 *
 * Marks: 2
 */
Book *findBookById(Book books[], int n, int id)
{
    /* TODO */
    return NULL;
}


/*
 * Among the books that have copies > 0, find the CHEAPEST one.
 * Return a pointer to it (inside the array).
 *
 * If two books have the same lowest price, return the first.
 * Return NULL if n <= 0 or no book has copies > 0.
 *
 * Marks: 2
 */
Book *findCheapestAvailable(Book *books, int n)
{
    /* TODO */
    return NULL;
}


/*
 * Borrow one copy of a book.
 *
 * If b and totalBorrowed are both non-NULL and b->copies > 0:
 *     b->copies decreases by 1
 *     *totalBorrowed increases by 1
 *     return 1
 * Otherwise change NOTHING and return 0.
 *
 * Marks: 2
 */
int borrowBook(Book *b, int *totalBorrowed)
{
    /* TODO */
    return 0;
}


/*
 * Sort books by price, LOWEST first.
 *
 * The sort must be STABLE: books with equal prices keep their
 * original relative order.
 * Whole Book structures must move (not just the price).
 *
 * Do nothing for n <= 1.
 *
 * Marks: 3
 */
void sortBooksByPrice(Book *books, int n)
{
    /* TODO */
}


/*
 * Remove the first book whose id matches.
 *
 * Shift every later book one position to the left so the array
 * stays packed and in the same order, then decrease *n by 1.
 *
 * Return 1 if a book was removed.
 * Return 0 (and change nothing) if no book has that id,
 * or n is NULL, or *n <= 0.
 *
 * Note that n is a POINTER: update the caller's variable via *n.
 *
 * Marks: 3
 */
int removeBook(Book books[], int *n, int id)
{
    /* TODO */
    return 0;
}


/* ============================================================
 * PART D: DYNAMIC MEMORY, LINKED LISTS, 2D ARRAYS
 * Marks: 23
 * ============================================================
 *
 * The grader counts every malloc and free you make.
 * Freed memory is poisoned, so reading a node after you have
 * freed it will crash. Free memory only once.
 * ============================================================
 */


/*
 * Allocate one Node with malloc.
 * Set value to the given value and next to NULL.
 * Return the new node (NULL if malloc fails).
 *
 * Marks: 1
 */
Node *createNode(int value)
{
    /* TODO */
    return NULL;
}


/*
 * Insert a new node holding 'value' at the FRONT of the list.
 *
 * head is the ADDRESS of the caller's head pointer, so *head is
 * the first node (or NULL for an empty list).
 * After the call, *head must point to the new node.
 *
 * Allocate exactly one node per call.
 * If head is NULL, do nothing.
 *
 * Example:  list 2 -> 1,  pushFront(&head, 3)  ->  3 -> 2 -> 1
 *
 * Marks: 2
 */
void pushFront(Node **head, int value)
{
    /* TODO */
}


/*
 * Insert a new node holding 'value' at the END of the list.
 *
 * Works on an empty list too (then *head becomes the new node).
 * Allocate exactly one node per call.
 * If head is NULL, do nothing.
 *
 * Example:  list 1 -> 2,  pushBack(&head, 3)  ->  1 -> 2 -> 3
 *
 * Marks: 3
 */
void pushBack(Node **head, int value)
{
    /* TODO */
}


/*
 * Remove the FIRST node whose value equals 'value', and free it.
 *
 * Handle all cases: removing the head, a middle node, the last
 * node, or the only node (then *head becomes NULL).
 *
 * Return 1 if a node was removed, 0 if not found.
 * If head is NULL, return 0.
 *
 * Example:  1 -> 2 -> 3 -> 2,  removeValue(&head, 2)
 *           ->  1 -> 3 -> 2   (only the FIRST 2 is removed)
 *
 * Marks: 3
 */
int removeValue(Node **head, int value)
{
    /* TODO */
    return 0;
}


/*
 * Reverse the list by RE-LINKING the existing nodes.
 * Do NOT allocate new nodes and do NOT copy values around.
 *
 * Example:  1 -> 2 -> 3 -> 4  becomes  4 -> 3 -> 2 -> 1
 *
 * After the call, *head must point to the old last node.
 * Empty list, single node, or head == NULL: nothing to do.
 *
 * Marks: 3
 */
void reverseList(Node **head)
{
    /* TODO */
}


/*
 * Free EVERY node of the list and set *head to NULL.
 * If head is NULL, or the list is empty, do nothing.
 *
 * Careful: read node->next BEFORE you free the node.
 *
 * Marks: 1
 */
void freeList(Node **head)
{
    /* TODO */
}


/*
 * Return the number of nodes in the list. (NULL -> 0)
 *
 * Marks: 1
 */
int listLength(const Node *head)
{
    /* TODO */
    return 0;
}


/*
 * Return a POINTER to the middle node of the list.
 * For an even number of nodes return the SECOND of the two
 * middle nodes. Return NULL for an empty list.
 *
 * Examples:
 *   1 -> 2 -> 3 -> 4 -> 5   ->  node 3
 *   1 -> 2 -> 3 -> 4        ->  node 3
 *   1                       ->  node 1
 *
 * Do not count the length first: use a "slow" pointer that moves
 * one step and a "fast" pointer that moves two steps.
 *
 * Marks: 2
 */
Node *findMiddle(Node *head)
{
    /* TODO */
    return NULL;
}


/*
 * Create a new array of n integers (using malloc) where
 * element i is i * i, and return it.
 *
 * Example:  n = 5  ->  {0, 1, 4, 9, 16}
 *
 * If n <= 0 return NULL. The caller will free the array.
 * Do NOT return the address of a local array.
 *
 * Marks: 2
 */
int *makeSquares(int n)
{
    /* TODO */
    return NULL;
}


/*
 * Create a rows x cols matrix of ints on the heap.
 *
 *   - Allocate ONE block of 'rows' pointers (int *), then
 *     allocate EACH row separately with its own malloc.
 *   - Fill the matrix so that m[i][j] = i * cols + j.
 *
 * Example (rows = 2, cols = 3):
 *       0 1 2
 *       3 4 5
 *
 * If rows <= 0 or cols <= 0, return NULL.
 * If any malloc fails, free everything you allocated so far and
 * return NULL.
 *
 * Marks: 3
 */
int **createMatrix(int rows, int cols)
{
    /* TODO */
    return NULL;
}


/*
 * Free a matrix made by createMatrix: free every row, then free
 * the array of row pointers. If m is NULL, do nothing.
 *
 * Marks: 1
 */
void freeMatrix(int **m, int rows)
{
    /* TODO */
}


/*
 * Return the sum of the main diagonal m[0][0] + m[1][1] + ...
 * for as many diagonal entries as exist: i from 0 while i < rows
 * and i < cols.
 *
 * Example (3 x 4 matrix with values i*4+j): 0 + 5 + 10 = 15
 *
 * If m is NULL, return 0.
 *
 * Marks: 1
 */
int sumMainDiagonal(int **m, int rows, int cols)
{
    /* TODO */
    return 0;
}


/* ============================================================
 * PART E: FUNCTION POINTERS
 * Marks: 5
 * ============================================================
 *
 * A parameter like  int (*fn)(int)  is a pointer to a function
 * that takes an int and returns an int. Call it as  fn(x).
 * ============================================================
 */


/*
 * Replace every element arr[i] by fn(arr[i]).
 *
 * Example: arr = {1, 2, 3}, fn doubles  ->  {2, 4, 6}
 *
 * If arr is NULL, n <= 0, or fn is NULL, do nothing.
 *
 * Marks: 2
 */
void mapArray(int arr[], int n, int (*fn)(int))
{
    /* TODO */
}


/*
 * Count how many elements make pred(element) return non-zero.
 *
 * Example: arr = {1, 2, 3, 4, 6}, pred = "is even"  ->  3
 *
 * If arr is NULL, n <= 0, or pred is NULL, return 0.
 *
 * Marks: 1
 */
int countIf(const int arr[], int n, int (*pred)(int))
{
    /* TODO */
    return 0;
}


/*
 * Combine all elements into one value.
 *
 *     result = init
 *     for each element x, in order:  result = op(result, x)
 *
 * Example: arr = {1, 2, 3, 4}, init = 0, op = add   ->  10
 *          arr = {1, 2, 3},    init = 100, op = subtract
 *                  ->  ((100 - 1) - 2) - 3 = 94
 *
 * If n <= 0 (or arr is NULL) return init.
 * If op is NULL, return init.
 *
 * Marks: 2
 */
int reduceArray(const int arr[], int n, int init, int (*op)(int, int))
{
    /* TODO */
    return init;
}


/* ============================================================
 * PART F: FILE PERSISTENCE WITH POINTERS
 * Marks: 6
 * ============================================================
 *
 * This time the file is BINARY (use "wb" / "rb", fwrite / fread).
 *
 * File layout:
 *     first an int holding the number of books (n),
 *     then n Book structures, back to back.
 * ============================================================
 */


/*
 * Save n books to the file.
 *
 * Write the count n first, then all n books.
 *
 * Return 1 only if everything was written successfully.
 * Return 0 if n < 0, n > MAX_BOOKS, the file cannot be opened,
 * or any write fails. Always close the file you opened.
 *
 * Marks: 2
 */
int saveBooks(const char filename[], const Book *books, int n)
{
    /* TODO */
    return 0;
}


/*
 * Load books from a file written by saveBooks.
 *
 * out is the ADDRESS of the caller's Book pointer, and n is the
 * ADDRESS of the caller's counter.
 *
 * On success:
 *   - allocate (malloc) an array of exactly 'count' Books
 *   - read the books into it
 *   - set *out to that array and *n to the count
 *   - return 1
 *   - special case: if the count in the file is 0, set *out to
 *     NULL, *n to 0, allocate nothing, and return 1
 *
 * On ANY failure, return 0 and leave *out and *n UNTOUCHED, with
 * nothing left allocated (no memory leak). Failure means:
 *   - file cannot be opened
 *   - count read from the file is < 0 or > MAX_BOOKS
 *   - the file does not contain all the books it promises
 *   - out or n is NULL
 * Always close the file you opened.
 *
 * Marks: 4
 */
int loadBooks(const char filename[], Book **out, int *n)
{
    /* TODO */
    return 0;
}


/* ============================================================
 * MAIN (hidden when the grader includes this file)
 * ============================================================
 */

#ifndef GRADER

void manualTest()
{
    /*
     * Write your own tests here, for example:
     *
     * int x = 3, y = 7;
     * swapInts(&x, &y);
     * printf("x=%d y=%d\n", x, y);
     */
}

int main()
{
    printf("============================================\n");
    printf("      LIBRARY MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("\nTo see your marks run:  gcc grader.c -o grader\n");

    manualTest();

    return 0;
}

#endif
