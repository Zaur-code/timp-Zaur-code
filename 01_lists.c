#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
} list;


// инициализация пустого списка
void init(list *l)
{
 l->head = NULL;
}

// удалить все элементы из списка
void clean(list *l)
{
 node *var = NULL;
 while (l->head->next)
  {
    var = l->head;
    l->head = l->head->next;
    free (var);
  }
  free (l->head);
}

// проверка на пустоту списка
bool is_empty(list *l)
{
	if (l == NULL)
		return 0;
	else
		return 1;
}
// поиск элемента по значению. вернуть NULL если элемент не найден
node *find(list *l, int value)
{
  node *var = l->head;
  while (1)
  {
    if  ((var != NULL)&&(var->value != value))
    {
	var = var->next;
    }
    else 
    {
	return var;
    }
  }
}

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value)
{
 if (l->head == NULL)
 {
   node *var = (struct node*)malloc(sizeof(node));
   var->value = value;
   var->next = l->head;
   l->head = var;
   return 0;
 }
 node *var = l->head;
 while (var->next != NULL)
 {
  var = var->next;
 }
 var->next = (struct node*)malloc(sizeof(node));
 var->next->value = value;
 var->next->next = NULL;
 return 0;

}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
{
 node *var = (struct node*)malloc(sizeof(node));
 var->value = value;
 var->next = l->head;
 l->head = var;
 return 0;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int value)
{
 if (n == NULL)
	return 1;
 node *var = (struct node*)malloc(sizeof(node));
 var->value = value;
 var->next = n->next;
 n->next = var;
 return 0;
}

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_node(list *l, int value)
{
 if (l->head == NULL)
     return 1;
  node *var = l->head;
  if (var->value == value)
  {
   l->head = var->next;
   free (var);
   return 0;
  }
  while ((var->next != NULL) && (var->next->value != value))
  { 
    var = var->next;
  }
  if (var->next == NULL)
  {
   return 1;
  }
  else 
  {
   node *Temp = (struct node*)malloc(sizeof(node));
   Temp = var->next->next;
   free(var->next);
   var->next = Temp;
   return 0;
  }
}

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l)
{
  node *var = l->head;
  while (var != NULL) {
    printf("%d ", var->value); 
    var = var->next; 
  } 
  printf ("\n");
}

void pr(list *l, int a) // Задание 4
{
 if (find(l,a) != NULL)
     printf ("1 ");
     else 
         printf ("0 ");
}

node *find_number(list *l, int j) // 9 Поиск элемента
{
  node *var = l->head;
  int i = 0;
  while ((var != NULL)&&( i != j-1)) {
       var = var->next;
       ++i;
       }
  return var;
 }


int main() {
  list l; 
  int n, i, a, k1, k2, k3, z, j, x;
  (void) scanf("%d", &n);// 1 считывает количество элементов n
  init(&l);// Инициализация пустого списка
  for (i=1; i<=abs(n); ++i)
  {
   (void) scanf ("%d", &a);
   push_back (&l, a); // 2 Занесение в список
  }
  print (&l); // 3 Вывод элементов в списке
  (void) scanf("%d%d%d", &k1, &k2, &k3);
  pr(&l, k1); pr(&l, k2); pr(&l, k3); // 4
  printf ("\n");
  (void) scanf("%d", &a);
  push_back(&l, a); // 5 Вставка значения в конец списка
  print(&l);// 6 Вывод списка 
  (void) scanf ("%d", &a);
  push_front (&l, a); // добавление значения в начало списка
  print (&l);// 8 вывод списка
  (void) scanf ("%d", &j); // 9
  (void) scanf ("%d", &x);
  node *Var = find_number (&l, j);
  insert_after (Var, x);
  print (&l);  // 10 вывод списка
  (void) scanf ("%d", &z);
  remove_node (&l, z); // 11 Удаление первого элемента с значением z
  print (&l); // 12 Вывод списка
  clean (&l); // 13 Очистка списка
  bool b =  is_empty (&l); // Проверка списка
  return 0;
};
