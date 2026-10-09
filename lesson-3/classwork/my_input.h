#pragma once
#include <windows.h>

#include <string>

// Надежная функция для чтения русского текста с клавиатуры
inline std::string inputString() {
  wchar_t wbuf[255];
  DWORD r;
  // Читаем текст напрямую из системы в Юникоде
  ReadConsoleW(GetStdHandle(STD_INPUT_HANDLE), wbuf, 255, &r, NULL);

  // Стираем невидимые символы Enter (\r\n) в конце строки
  if (r > 0 && wbuf[r - 1] == L'\n') r--;
  if (r > 0 && wbuf[r - 1] == L'\r') r--;
  if (r == 0) return "";

  // Переводим текст в формат UTF-8, который понимает обычный std::string
  int s = WideCharToMultiByte(CP_UTF8, 0, wbuf, (int)r, NULL, 0, NULL, NULL);
  std::string str(s, 0);
  WideCharToMultiByte(CP_UTF8, 0, wbuf, (int)r, &str[0], s, NULL, NULL);
  return str;
}