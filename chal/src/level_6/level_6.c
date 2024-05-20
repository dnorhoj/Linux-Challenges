#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

char *find_connected_pid(const char *target_inode) {
  DIR *proc_dir = opendir("/proc");

  if (proc_dir == NULL) {
    perror("Failed to open /proc");
    return NULL;
  }

  struct dirent *pid_dir;
  while ((pid_dir = readdir(proc_dir)) != NULL) {
    // Check only directories with numeric names (PID directories)
    if (pid_dir->d_type != DT_DIR || !isdigit(pid_dir->d_name[0])) {
      continue;
    }


    char fd_path[256];
    snprintf(fd_path, sizeof(fd_path), "/proc/%s/fd", pid_dir->d_name);
    DIR *fd_dir = opendir(fd_path);
    if (fd_dir == NULL) {
      continue;
    }

    struct stat dir_stat;
    if (stat(fd_path, &dir_stat) == -1) {
      continue;
    }

    setuid(dir_stat.st_uid);

    struct dirent *fd_entry;
    while ((fd_entry = readdir(fd_dir)) != NULL) {
      // Only check stdin
      if (strncmp(fd_entry->d_name, "0", 2) != 0) {
        continue;
      }

      // Build path to each file descriptor link
      char fd_link[256];
      snprintf(fd_link, sizeof(fd_link), "%s/%s", fd_path, fd_entry->d_name);
      char link_target[256];
      ssize_t link_len =
          readlink(fd_link, link_target, sizeof(link_target) - 1);
      if (link_len == -1) {
        continue;
      }

      link_target[link_len] = '\0';  // Null-terminate the read link

      if (strcmp(link_target, target_inode) != 0) {
        continue;
      }

      closedir(fd_dir);
      closedir(proc_dir);
      return pid_dir->d_name;  // Exit as we found the connected PID
    }
    closedir(fd_dir);
  }

  closedir(proc_dir);

  return NULL;
}

int getflag(char *buf, int bufsize) {
  FILE *file = fopen("/home/pirat/level_6/flag", "r");

  if (!file) {
    return -1;
  }

  int len = fread(buf, 1, bufsize - 1, file);
  buf[len] = 0x00;

  return 0;
}

int main(int argc, char **argv) {
  char filebuf[256];
  int len;

  char flag[128];
  getflag(flag, sizeof(flag));

  len = readlink("/proc/self/fd/1", filebuf, sizeof(filebuf) - 1);
  if (len == -1) {
    fprintf(stderr, "Der skete en fejl (burde ikke ske)\n");
    return 1;
  }

  filebuf[len] = 0x00;

  if (strncmp(filebuf, "pipe:", 5) != 0) {
    fprintf(stderr, "Det er ikke pipe redirection!\n");
    return 1;
  }

  char *pid = find_connected_pid(filebuf);
  if (pid == NULL) {
    fprintf(stderr, "Der skete en fejl (burde ikke ske)\n");
    return 1;
  }

  char cmdlinepath[256];

  snprintf(cmdlinepath, sizeof(cmdlinepath), "/proc/%s/cmdline", pid);

  FILE *cmdline = fopen(cmdlinepath, "r");

  if (!cmdline) {
    fprintf(stderr, "Der skete en fejl (burde ikke ske)\n");
    return 1;
  }

  char cmd[256];

  len = fread(cmd, 1, sizeof(cmd) - 1, cmdline);
  cmd[len] = 0x00;

  if (strcmp("rev", cmd) != 0) {
    fprintf(stderr, "Du har pipet outputtet ind i '%s', du skal bruge 'rev' istedet.\n", cmd);
    return 1;
  }

  puts("Godt gjort! Her er flaget:");

  printf("%s\n", flag);

  return 0;
}
