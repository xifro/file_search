#include "file_search.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>

// Обʼявлення функції, яка приймає два параметри (імʼя шукаємого файла та
// корнева директорія)
int search_file(const char *file_name, const char *directory) {
  // функція повертає обʼєкт обʼєкт типу DIR, який є відкритою директорією, якщо
  // директорія не може бути повернена, opendir поверне null
  DIR *dir = opendir(directory);
  if (dir == NULL) {
    // fprintf(stderr, "Не вдалося відкрити директорію: %s\n", directory);
    return 0;
  }

  // обʼявлення змінної для збереження даних, entry - показник на структуру
  // struct dirent та повного шляху до елемента path
  int file_found = 0;
  struct dirent *entry;
  char path[PATH_MAX];

  // цикл, який буде перевіряти всі існуючи елементи в директорії, readdir для
  // перевірки елемента з директорії, який повертає struct dirent, якщо
  // елементів немає, повернеться значення null
  while ((entry = readdir(dir)) != NULL) {
    // Умова, яка перевіряє чи дійсно це директорія, якщо так, цикл пропускає
    // ітерацію за допомогою continue і програма переходе до наступного елементу
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    snprintf(path, PATH_MAX, "%s/%s", directory, entry->d_name);
    // функція snprintf створює повний шлях до елементу і зберегається в змінній
    // path, далі шлях використовується для рекурсивного визову функції
    // search_file

    // програма перевіряє тип елемента, якщо елемент є звичайним файлом DT_REG і
    // його імʼя співпадає, то значення змінної file_found - 1. Якщо є папкою
    // DT_DIR, то програма визиває рекурсивну функцію search_file для пошуку
    // всередині цієї папки, шляхом визову search_file з новим шляхом path
    if (entry->d_type == DT_REG && strcmp(entry->d_name, file_name) == 0) {
      printf("Файл знайдено: %s\n", path);
      file_found = 1;
    } else if (entry->d_type == DT_DIR) {
      file_found |= search_file(file_name, path);
    }
  }

  // Закриваємо директорію для звільнення ресурсів, зайнятих відкритою
  // директорією
  closedir(dir);
  // функція search_file повертає значення змінної file_found, яке вказує чи був
  // знайден файл в цій директорії
  return file_found;
}
