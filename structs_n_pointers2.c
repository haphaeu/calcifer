#include <stdio.h>
#include <stdlib.h>
#define EPS 1e-8
#define false 0
#define true 1
/*

Examples of struct and pointers to struct.

Implementing a linked list with auxuliary struct to mark
the head and tail of the list.

*/

struct point {
    double x, y;
    struct point *next;
};

struct point_list {
    struct point *head;
    struct point *tail;
};


struct point * add(double, double, struct point_list *);
int contains(double, double, struct point_list *);
void remove_xy(double, double, struct point_list *);
int count(struct point_list *);


int main(void) {
    struct point_list list = {NULL, NULL};
    struct point *ppt;

    // fill the list
    int n = 15;
    for (int i = 0; i < n; i++)
	add(i, i, &list);
    
    ppt = list.head;
    do  {
	printf("%6.2f \t %6.2f\n", ppt->x, ppt->y);
    } while (ppt = ppt->next);
    
    printf("list has %d nodes.\n", count(&list));

    printf("list has node 7 7: %s\n", contains(7, 7, &list) ? "true" : "false");
    printf("list has node 7 8: %s\n", contains(7, 8, &list) ? "true" : "false");

    remove_xy(7, 7, &list);
    printf("list has %d nodes.\n", count(&list));

    printf("list has node 7 7: %s\n", contains(7, 7, &list) ? "true" : "false");
    
    
    
}
    
struct point * add(double x, double y, struct point_list *list) {
    
    struct point *tmp;
    tmp = (struct point*) malloc(sizeof(struct point));
    tmp->x = x;
    tmp->y = y;
    tmp->next = NULL;

    if (list->head == NULL)
	list->head = tmp;
    if (list->tail != NULL)
        list->tail->next = tmp;

    list->tail = tmp;

    return tmp;
}

int contains(double x, double y, struct point_list *list) {

    if (list->head == NULL)
	return false;

    struct point *p = list->head;
    do {
	if (abs(p->x - x) < EPS && abs(p->y - y) < EPS)
	    return true;
    } while (p = p->next);
    return false;
}
    
void remove_xy(double x, double y, struct point_list *list) {

    if (list->head != NULL) {

	struct point *p = list->head;
	struct point *pp = p;
	do {
	    if (abs(p->x - x) < EPS && abs(p->y - y) < EPS) {
		if (p == list->head)
		    list->head = p->next;
		else
		    pp->next = p->next;
		break;
	    }
	    pp = p;
	} while (p = p->next);
    }
}

    

int count(struct point_list *list) {
    int c;
    struct point *node = list->head;
    for (c = 1; node = node->next; c++);
    return c;
}
