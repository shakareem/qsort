# QuickSort C Library

Универсальная реализация быстрой сортировки на C с оптимизацией для маленьких массивов с помощью сортировки вставкой и поддержкой пользовательской функции сравнения через булеву функцию `less`.


---

## Функция

### Generic

```c
void quicksort(void *arr, size_t n, size_t size,
               bool (*less)(const void *, const void *));
```

### Integer

```c
void quicksort_int(int *arr, size_t n);
```

## Использование

### Сборка

```bash
make
```

### Запуск

```bash
make run
```
