#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "logging.hpp"

// Тип времени
#define TIME_T long int

static FILE* log_file;
static TIME_T logging_start_time;

bool log::init(const char* filename) {
#ifdef DOFILELOGGING
  log_file = fopen(filename, "w");
  if(!log_file) {
    perror("[ERROR]: Failed to open logging file");
    return false;
  }
#endif

  logging_start_time = time(NULL);

  return true;
}

void log::info(const char* to_log) {
#ifdef DOTERMLOGGING
  fprintf(stdout, "[INFO] %li: %s\n", static_cast<TIME_T>(time(NULL)) - logging_start_time, to_log);
#endif
#ifdef DOFILELOGGING
  fprintf(log_file, "[INFO] %li: %s\n", static_cast<TIME_T>(time(NULL)) - logging_start_time, to_log);
#endif
}

void log::warning(const char* to_log) {
#ifdef DOTERMLOGGING
  fprintf(stderr, "[WARNING] %li: %s\n", static_cast<TIME_T>(time(NULL)) - logging_start_time, to_log);
#endif
#ifdef DOFILELOGGING
  fprintf(log_file, "[WARNING] %li: %s\n", static_cast<TIME_T>(time(NULL)) - logging_start_time, to_log);
#endif
}

void log::error(const char* to_log) {
#ifdef DOTERMLOGGING
  fprintf(stderr, "[ERROR] %li: %s\n", static_cast<TIME_T>(time(NULL)) - logging_start_time, to_log);
#endif
#ifdef DOFILELOGGING
  fprintf(log_file, "[ERROR] %li: %s\n", static_cast<TIME_T>(time(NULL)) - logging_start_time, to_log);
#endif
}

void log::interprit_errno() {
  char* error = strerror(errno);
#ifdef DOTERMLOGGING
  fprintf(stderr, "[ERROR] %li: %s\n", static_cast<TIME_T>(time(NULL)) - logging_start_time, error);
#endif
#ifdef DOFILELOGGING
  fprintf(log_file, "[ERROR] %li: %s\n", static_cast<TIME_T>(time(NULL)) - logging_start_time, error);
#endif
}
