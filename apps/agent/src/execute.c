#include "execute.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/types.h>
#include <unistd.h>
#endif

bool execute_command(const char *command) {
  if (!command) {
    return false;
  }

#ifdef _WIN32
  STARTUPINFOA si = {};
  PROCESS_INFORMATION pi = {};
  si.cb = sizeof si;

  char *cmdline = _strdup(command);

  BOOL ok = CreateProcessA(NULL, cmdline, NULL, NULL, FALSE, CREATE_NO_WINDOW,
                           NULL, NULL, &si, &pi);

  if (!ok) {
    return false;
  }
  CloseHandle(pi.hThread);
  CloseHandle(pi.hProcess);
#else
  pid_t pid = fork();
  if (pid < 0) {
    return false;
  }

  if (pid == 0) {
    if (setsid() < 0) {
      _exit(1);
    }

    execl("/bin/sh", "sh", "-c", command, (char *)NULL);
    _exit(127);
  }
#endif

  return true;
}
