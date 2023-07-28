#include "file_search.h"
#include "stdio.h"

//в функцію main встановлюється значення file_to_find(шукаємий файл) та root_directory(корнева директорія для пошуку), далі програма визиває функцію search_file з цими параметрами і виводить повідомлення
int main() {
  const char *file_to_find = "target_file.txt";
  const char *root_directory = "/"; // Шукаємо з корневої директорії

  if (search_file(file_to_find, root_directory))
    printf("Пошук завершено.\n");
  else
    printf("Файл не знайден.\n");

  return 0;
}
