#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    int data;
    struct list* nlist;
};

struct list* add(struct list* nList, int data) {
    struct list* List = malloc(sizeof(struct list));

    List->data = data;
    List->nlist = nList;

    return List;
}

struct list* delete(struct list* List, int numdel) {
    if (List == NULL) {
        return NULL;
    }
    if (numdel == 1) {
        if (List->nlist == NULL) {
            return NULL;
        }
        else {
            return List->nlist;
        }
    }
    else {
        List->nlist = delete(List->nlist, --numdel);
    }
    return List;
}

void print(struct list* List) {
    int tabnum = 0;
    if (List == NULL) {
        return NULL;
    }
    while (List != NULL) {
        for (int i = 0; i < tabnum; i++) { printf("   "); }
        printf("data: %d\n", List->data);

        for (int i = 0; i < tabnum; i++) { printf("   "); }
        printf("nlist: \n");
        tabnum++;
        List = List->nlist;
    }


}

int main() {
    struct list* List = NULL;
    int c = 0;
    while (1) {
        printf("1-add; 2-delete; 3-print\n");
        scanf("%d", &c);

        if (c == 1) {
            printf("insert data\n");
            int data;
            scanf("%d", &data);
            List = add(List, data);
        }
        else if (c == 2) {
            printf("insert num\n");
            int num;
            scanf("%d", &num);
            List = delete(List, num);
        }
        else if (c == 3) {
            print(List);
        }
        else {
            printf("wrong command\n");
        }
    }

    return 0;
}


