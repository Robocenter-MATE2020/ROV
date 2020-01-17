#ifndef LOGGING_HPP
#define LOGGING_HPP

// Закомментировать, чтобы перестать писать в файл
//#define DOFILELOGGING
// Закомментировать, чтобы перестать писать в терминал
#define DOTERMLOGGING
namespace log {
  // Фунцкия запускает логирование, просьба проверять возращаемое значение
  bool init(const char* filename = "./lastrun.log");

  void info(const char* to_log);
  void warning(const char* to_log);
  void error(const char* to_log);
  // Пишет интерпретированное значение errno
  void interprit_errno();
}

#endif
