#ifndef FILE_SEARCH_H
#define FILE_SEARCH_H

// Функция для поиска файла по имени в заданной директории и её поддиректориях.
// file_name: имя файла, которое нужно найти.
// directory: корневая директория для поиска.
// Функция возвращает 1, если файл найден, и 0 в противном случае.
int search_file(const char* file_name, const char* directory);

#endif // FILE_SEARCH_H

