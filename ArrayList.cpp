/*
Створіть аналог масиву - списку (ArrayList) мови Java. Реалізуйте наступний функціонал:
Додавання елемента в кінець списку - метод add(item);
Вставка елемента в середину списку - метод insert(index, item);
Кількість елементів у масиві - метод size();
Видалення елементів за індексом - метод remove(index);
Зміна значення існуючого елемента - метод set(index, item);
Отримання значення заданого елемента - метод get(index);
 */

#include <stdio.h>
#include <stdlib.h>

int *add(int item, int *ptr);
int *insert(int index, int item, int *ptr);
void size();
int *remove(int index, int *ptr);
int set(int index, int item, int *ptr);
int get(int index, int *ptr);
void printArray(int *ptr);

int ARRAY_SIZE = 1;

int main(){
    int choose;
    int index, item;
    int n;
    int *ptr = static_cast<int *>(malloc(n * sizeof(int)));

    do {
        printf("\n1. add(item)\n");
        printf("2. insert(index, item)\n");
        printf("3. size()\n");
        printf("4. remove(index)\n");
        printf("5. set(index, item)\n");
        printf("6. get(index)\n");
        printf("0. ВИХІД\n");
        printf("ВИБІР: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Значення item: ");
                scanf("%d", &item);
                ptr = add(item, ptr);
                printArray(ptr);
                break;
            case 2:
                printf("Значення index: ");
                scanf("%d", &index);
                printf("Значення item: ");
                scanf("%d", &item);
                insert(index, item, ptr);
                printArray(ptr);
                break;
            case 3:
                size();
                printArray(ptr);
                break;
            case 4:
                printf("Значення index: ");
                scanf("%d", &index);
                remove(index, ptr);
                printArray(ptr);
                break;
            case 5:
                printf("Значення index: ");
                scanf("%d", &index);
                printf("Значення item: ");
                scanf("%d", &item);
                set(index, item, ptr);
                printArray(ptr);
                break;
            case 6:
                printf("Значення index: ");
                scanf("%d", &index);
                get(index, ptr);
                printArray(ptr);
                break;
            default:
                break;
        }

    } while (choose!=0);
    return 0;

}

int *add(int item, int *ptr){
    int n;
    ptr[ARRAY_SIZE-1] = item;
    ptr = static_cast<int *>(realloc(ptr, sizeof(n)));
    ARRAY_SIZE++;
    return ptr;
}

void size(){
    printf("%d\n", ARRAY_SIZE-1);
}

void printArray(int *ptr){
    for (int i = 0; i < ARRAY_SIZE-1; ++i) {
        printf("%d\t", ptr[i]);
    }
}

int *remove(int index, int *ptr){
    int n;
    if (index < ARRAY_SIZE){
        for (int i = index; i < ARRAY_SIZE-1; ++i) {
            ptr[i] = ptr[i+1];
        }
     ptr = static_cast<int *>(realloc(ptr, sizeof(n * (ARRAY_SIZE - 1))));
     ARRAY_SIZE--;
    }
    return ptr;
}

int set(int index, int item, int *ptr){
    ptr[index] = item;
}

int get(int index, int *ptr){
    printf("[%d]: %d\n", index, ptr[index]);
}

int *insert(int index, int item, int *ptr){
    int n;
    ARRAY_SIZE++;
    ptr = static_cast<int *>(realloc(ptr, sizeof(n*ARRAY_SIZE)));
    for (int i = ARRAY_SIZE-1; i > index; i--) {
        ptr[i] = ptr[i-1];
    }
    ptr[index] = item;
    return ptr;
}

