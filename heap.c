/*
 *  File:   heap.c
 *  Author: Brett Heithold
 *  Description:
 */


#include "heap.h"
#include "queue.h"
#include "stack.h"
#include "bst.h"
#include <stdlib.h>
#include <assert.h>


struct HEAP {
    BST *tree;
    int size;
    
    // Public Methods
    void (*display)(void *, FILE *);
    int (*compare)(void *, void *);
    void (*free)(void *);
};


HEAP *newHEAP(
    void (*d)(void *, FILE *),
    int (*c)(void *, void *),
    void (*f)(void *)) {
    HEAP *h = malloc(sizeof(HEAP));
    assert(h != 0);
    h->tree = newBST(d, c, NULL, f);
    h->size = 0;
    h->display = d;
    h->compare = c;
    h->free = f;
    return h;
}


/*
 *  Method: peekHEAP
 *  Usage:  void *val = peekHEAP(h);
 *  Description:
 */
void *peekHEAP(HEAP *h) {
    // TODO: Am I correct?
    assert(h != 0);
    return getBSTroot(h->tree);
}


/*
 *  Method: sizeHEAP
 *  Usage:  int size = sizeHEAP(h);
 *  Description:
 */
int sizeHEAP(HEAP *h) {
    assert(h != 0);
    return h->size;
}


/*
 *  Method: displayHEAP
 *  Usage:  displayHEAP(h, stdout);
 *  Description:
 *  Example Output:
 */
void displayHEAP(HEAP *h, FILE *fp) {
    assert(h != 0);
    displayBST(h->tree, fp);
}


/*
 *  Method: displayHEAPdebug
 *  Usage:  displayHEAPdebug(h, stdout);
 *  Description:
 *  Example Output:
 */
void displayHEAPdebug(HEAP *h, FILE *fp) {
    assert(h != 0);
    fprintf(fp, "heap size: %d\n", h->size);
    fprintf(fp, "bst size: %d\n", sizeBST(h->tree));
    displayBSTdebug(h->tree, fp);
}
