#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
	struct node *prev;  // ссылка на предыдущий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
	struct node *tail;  // конец списка
} list;


// инициализация пустого списка
void init(list *l)
{
 l->tail = NULL;
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
  l->head->next = NULL;
  l->head->prev = NULL;
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
   l->head = l->tail = var; 
   l->head->prev = NULL;
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
 var->next->prev = var;
 l->tail = var->next;
 return 0;
}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value)
{
 node *var = (struct node*)malloc(sizeof(node));
 var->value = value;
 var->next = l->head;
 var->prev = NULL;
 l->head = var;
 l->head->next->prev = var;
 if (var->next == NULL)
   {
      l->tail = var;
   }
 return 0;
}

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, node *n, int value)
{
  if ((n == NULL) || (n->next == NULL)) 
  {
   push_back(l, value);
   return 0;
  }
  else 
  {
   node *var = (struct node*)malloc(sizeof(node)); 
   var->value = value; 
   var->next = n->next;
   var->prev = n;  
   n->next = var; 
   n->next->next->prev = var;
   return 0;
  }
}

// вставка значения перед указанным узлом, вернуть 0 если успешно
int insert_before(list *l, node *n, int value)
{
  if ((n == NULL) || (n->prev == NULL)) 
  {
   push_front(l, value);
   return 0;
  }
  else 
  {
   node *var = (struct node*)malloc(sizeof(node)); 
   var->value = value; 
   var->prev = n->prev;
   var->next = n;  
   n->prev = var; 
   n->prev->prev->next = var;
   return 0;
  }

}

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_first(list *l, int value)
{
  if (l->head == NULL)
     return 1;
  node *var = l->head;
  if (var->value == value)
  {
   l->head = var->next;
   var->next->prev = NULL;
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
   if (Temp == NULL)
   {
      l->tail = var;
   }
   else 
   {
     Temp->prev = var;
   }
   return 0;
  }
}

// удалить последний элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_last(list *l, int value)
{
   if (l->tail == NULL)
     return 1;
   node *var = l->tail;
   if (var->value == value)
  {
   l->tail = var->prev;
   var->prev->next = NULL;
   free (var);
   return 0;
  }
  while ((var->prev != NULL) && (var->prev->value != value))
  { 
    var = var->prev;
  }
  if (var->prev == NULL)
  {
   return 1;
  }
  else 
  {
   node *Temp = (struct node*)malloc(sizeof(node));
   Temp = var->prev->prev;
   free(var->prev);
   var->prev = Temp;
   if (Temp == NULL)
   {
      l->head = var;
   }
   else 
   {
     Temp->next = var;
   }
   return 0;
  }
}

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l)
{
  node *var = l->head;
  while (var != NULL) 
  {
    printf("%d ", var->value); 
    var = var->next; 
  } 
  printf ("\n");
}

// вывести все значения из списка в обратном порядке через пробел,
// после окончания вывода перейти на новую строку
void print_invers(list *l)
{
   node *var = l->tail;
   while (var != NULL) 
  {
    printf("%d ", var->value); 
    var = var->prev; 
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

node *find_number(list *l, int j) // Поиск элемента
{
  node *var = l->head;
  int i = 0;
  while ((var != NULL)&&( i != j-1)) 
  {
       var = var->next;
       ++i;
  }
  return var;
 }

int main() {
 list l; 
  int n, i, a, m, k1, k2, k3, z, j, x, t, u, y, r;
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
  (void) scanf("%d", &m);
  push_back(&l, m); // 5 Вставка значения в конец списка
  print_invers (&l);// 6 Вывод списка 
  (void) scanf ("%d", &t);
  push_front (&l, t); // добавление значения в начало списка
  print (&l);// 8 вывод списка
  (void) scanf ("%d", &j); // 9 Добавление значения после указанного узла
  (void) scanf ("%d", &x);
  node *Var = find_number (&l, j);
  insert_after (&l, Var, x);
  print_invers (&l);  // 10 вывод списка в обратном порядке
  (void) scanf ("%d", &u);// 11 добавление узла перед указанным узлом
  (void) scanf ("%d", &y); 
  node *VAR = find_number (&l, u);
  insert_before (&l, VAR, y);
  print (&l); // 12 вывод списка
  (void) scanf ("%d", &z); // 13 удаление первого элемента с указанным значением
  remove_first (&l, z);
  print_invers (&l); // 14 вывод списка
  (void) scanf ("%d", &r); // 15 удаление последнего элемента с указанным значением
  remove_last (&l, r); 
  print (&l); // 16 Вывод списка
  clean (&l); // 17 очистка списка
 return 0;
};
