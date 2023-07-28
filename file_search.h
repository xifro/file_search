#ifndef FILE_SEARCH_H
#define FILE_SEARCH_H

// Функція для пошуку файла за імʼям в заданій директорії та її піддиректоріях
// file_name: Імʼя файла, який потібно знайти
// directory: Корнева директорія для пошуку
// Функція повертає 1, якщо файл знайдено, та 0 якщо не знайдено
int search_file(const char* file_name, const char* directory);

#endif // FILE_SEARCH_H

